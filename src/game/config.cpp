#include <cstdlib>
#include "banjo_config.h"
#include "recompui/recompui.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "banjo_sound.h"
#include "banjo_support.h"
#include "ultramodern/config.hpp"
#include "librecomp/files.hpp"
#include "librecomp/config.hpp"
#include "util/file.h"
#include <filesystem>
#include <fstream>
#include <iomanip>

#if defined(_WIN32)
#include <Shlobj.h>
#elif defined(__linux__)
#include <unistd.h>
#include <pwd.h>
#elif defined(__APPLE__)
#include "apple/rt64_apple.h"
#endif

static void add_general_options(recomp::config::Config &config) {
    using EnumOptionVector = const std::vector<recomp::config::ConfigOptionEnumOption>;

    config.add_bool_option(
        "jfg_60hz_gameplay", "60 Hz Gameplay",
        "Experimental: targets 60 gameplay updates per second for lower input latency. "
        "Uses the game's elapsed-retrace timestep. Some frame-based effects (including texture scrolling) "
        "may run faster; physics, enemies, cutscenes and audio sync are not fully validated. Off by default.",
        false
    );

    // JFG PC port: mouse camera (src/main/main.cpp jfg_mouse_camera, hook on the follow camera func_8002CF78).
    static EnumOptionVector jfg_mouse_camera_options = {
        {uint32_t(0), "Off", "Off"},
        {uint32_t(1), "On", "On"},
    };
    config.add_enum_option(
        "jfg_mouse_camera",
        "Mouse Camera",
        "Moving the mouse left/right turns the third-person camera around the character (outside aim mode). "
        "Movement keys then move relative to the camera, as in the original. Needs <recomp-color primary>Mouse Sensitivity</recomp-color> above 0. "
        "<recomp-color primary>Off</recomp-color> (default) keeps the original camera.",
        jfg_mouse_camera_options,
        uint32_t(0)
    );

    static EnumOptionVector note_saving_mode_options = {
        {banjo::NoteSavingMode::Off,        "Off",    "Off"},
        {banjo::NoteSavingMode::OnlyNotes,  "Notes",  "Only Notes"},
        {banjo::NoteSavingMode::OnlyJinjos, "Jinjos", "Only Jinjos"},
        // Keeping as "On" to preserve compatibility with previous configs before jinjo saving
        {banjo::NoteSavingMode::Both,       "On",     "Both"},
    };
    config.add_enum_option(
        banjo::configkeys::general::note_saving_mode,
        "Note & Jinjo Saving",
        "Saves collected notes and jinjos so that you don't need to collect them again when revisiting a level. <recomp-color primary>Both</recomp-color> is the default, while <recomp-color primary>off</recomp-color> matches the original game.<br /><br />Changing this setting will only take effect when entering/exiting a level, or restarting the game.",
        note_saving_mode_options,
        banjo::NoteSavingMode::Both
    );
    static EnumOptionVector analog_cam_mode_options = {
        {banjo::AnalogCamMode::Off, "Off", "Off"},
        {banjo::AnalogCamMode::On, "On", "On"},
    };
    config.add_enum_option(
        banjo::configkeys::general::analog_cam_mode,
        "Analog Camera",
        "Enables the analog camera.",
        analog_cam_mode_options,
        banjo::AnalogCamMode::Off
    );
    config.add_number_option(
        banjo::configkeys::general::analog_camera_sensitivity,
        "Analog Camera Sensitivity",
        "Sets the sensitivity of the right stick analog camera, if enabled.",
        1, 10, 1, 0, false, 3
    );
    config.add_option_hidden_dependency(
        banjo::configkeys::general::analog_camera_sensitivity,
        banjo::configkeys::general::analog_cam_mode,
        banjo::AnalogCamMode::Off
    );
    static EnumOptionVector camera_invert_mode_options = {
        {banjo::CameraInvertMode::InvertNone, "InvertNone", "None"},
        {banjo::CameraInvertMode::InvertX, "InvertX", "Invert X"},
        {banjo::CameraInvertMode::InvertY, "InvertY", "Invert Y"},
        {banjo::CameraInvertMode::InvertBoth, "InvertBoth", "Invert Both"}
    };
    config.add_enum_option(
        banjo::configkeys::general::third_person_camera_invert_mode,
        "Invert Camera",
        "Inverts the camera controls for the third person camera if it's enabled. <recomp-color primary>Invert X</recomp-color> is the default and matches the original game.<br /><br />If analog camera is off, only the <recomp-color primary>Invert X</recomp-color> setting will take effect.",
        camera_invert_mode_options,
        banjo::CameraInvertMode::InvertX
    );
    static EnumOptionVector first_person_invert_mode_options = {
        {banjo::CameraInvertMode::InvertNone, "InvertNone", "None"},
        {banjo::CameraInvertMode::InvertX, "InvertX", "Invert X"},
        {banjo::CameraInvertMode::InvertY, "InvertY", "Invert Y"},
        {banjo::CameraInvertMode::InvertBoth, "InvertBoth", "Invert Both"}
    };
    config.add_enum_option(
        banjo::configkeys::general::first_person_invert_mode,
        "Invert First Person View",
        "Inverts the camera controls in first person view. <recomp-color primary>Invert Y</recomp-color> is the default and matches the original game.",
        first_person_invert_mode_options,
        banjo::CameraInvertMode::InvertY
    );
    static EnumOptionVector flying_and_swimming_invert_options = {
        {banjo::CameraInvertMode::InvertNone, "InvertNone", "None"},
        {banjo::CameraInvertMode::InvertX, "InvertX", "Invert X"},
        {banjo::CameraInvertMode::InvertY, "InvertY", "Invert Y"},
        {banjo::CameraInvertMode::InvertBoth, "InvertBoth", "Invert Both"}
    };
    config.add_enum_option(
        banjo::configkeys::general::flying_and_swimming_invert_mode,
        "Invert Flying & Swimming",
        "Inverts the controls for swimming and flying. <recomp-color primary>Invert Y</recomp-color> is the default and matches the original game.",
        flying_and_swimming_invert_options,
        banjo::CameraInvertMode::InvertY
    );
}

template <typename T = uint32_t>
T get_general_config_enum_value(const std::string& option_id) {
    return static_cast<T>(std::get<uint32_t>(recompui::config::get_general_config().get_option_value(option_id)));
}

template <typename T = uint32_t>
T get_general_config_number_value(const std::string& option_id) {
    return static_cast<T>(std::get<double>(recompui::config::get_general_config().get_option_value(option_id)));
}

banjo::NoteSavingMode banjo::get_note_saving_mode() {
    return get_general_config_enum_value<banjo::NoteSavingMode>(banjo::configkeys::general::note_saving_mode);
}

banjo::CameraInvertMode banjo::get_camera_invert_mode() {
    return get_general_config_enum_value<banjo::CameraInvertMode>(banjo::configkeys::general::camera_invert_mode);
}

banjo::CameraInvertMode banjo::get_third_person_camera_mode() {
    return get_general_config_enum_value<banjo::CameraInvertMode>(banjo::configkeys::general::third_person_camera_invert_mode);
}

banjo::CameraInvertMode banjo::get_flying_and_swimming_invert_mode() {
    return get_general_config_enum_value<banjo::CameraInvertMode>(banjo::configkeys::general::flying_and_swimming_invert_mode);
}

banjo::CameraInvertMode banjo::get_first_person_invert_mode() {
    return get_general_config_enum_value<banjo::CameraInvertMode>(banjo::configkeys::general::first_person_invert_mode);
}

banjo::AnalogCamMode banjo::get_analog_cam_mode() {
    return get_general_config_enum_value<banjo::AnalogCamMode>(banjo::configkeys::general::analog_cam_mode);
}

uint32_t banjo::get_analog_cam_sensitivity() {
    return get_general_config_number_value(banjo::configkeys::general::analog_camera_sensitivity);
}

template <typename T = uint32_t>
T get_graphics_config_enum_value(const std::string& option_id) {
    return static_cast<T>(std::get<uint32_t>(recompui::config::get_graphics_config().get_option_value(option_id)));
}

static void add_sound_options(recomp::config::Config &config) {
    config.add_percent_number_option(
        banjo::configkeys::sound::bgm_volume,
        "Background Music Volume",
        "Controls the overall volume of background music.",
        100.0f
    );
}
template <typename T = uint32_t>
T get_sound_config_number_value(const std::string& option_id) {
    return static_cast<T>(std::get<double>(recompui::config::get_sound_config().get_option_value(option_id)));
}

int banjo::get_bgm_volume() {
    return get_sound_config_number_value<int>(banjo::configkeys::sound::bgm_volume);
}

static void add_graphics_options(recomp::config::Config &config) {
    using EnumOptionVector = const std::vector<recomp::config::ConfigOptionEnumOption>;
    static EnumOptionVector cutscene_aspect_ratio_mode_options = {
        {banjo::CutsceneAspectRatioMode::Original, "Original", "Original"},
        {banjo::CutsceneAspectRatioMode::Clamp16x9, "Clamp16x9", "16:9"},
        {banjo::CutsceneAspectRatioMode::Full, "Expand", "Expand"},
    };
    config.add_enum_option(
        banjo::configkeys::graphics::cutscene_aspect_ratio_mode,
        "Cutscene Aspect Ratio",
        "Sets the aspect ratio limit for cutscenes. Cutscenes have been adjusted to work in <recomp-color primary>16:9</recomp-color>, which is the default option. Wider aspect ratios may show details that weren't meant to be on-screen.",
        cutscene_aspect_ratio_mode_options,
        banjo::CutsceneAspectRatioMode::Clamp16x9
    );    
}

static void set_control_defaults() {
    using namespace recompinput;

    // Left shoulder -> C Down | Backwards eggs / zoom out
    set_default_mapping_for_controller(
        GameInput::C_DOWN,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTY, true),
            InputField::controller_digital(SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_LEFTSHOULDER)
        }
    );

    // Right shoulder -> C Up | Forwards eggs / first person
    set_default_mapping_for_controller(
        GameInput::C_UP,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTY, false),
            InputField::controller_digital(SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)
        }
    );

    // North button -> C Left | Talon trot / camera left
    set_default_mapping_for_controller(
        GameInput::C_LEFT,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTX, false),
            InputField::controller_digital(SDL_CONTROLLER_BUTTON_NORTH)
        }
    );

    // East button -> C Right | Wonderwing / camera right
    set_default_mapping_for_controller(
        GameInput::C_RIGHT,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTX, true),
            InputField::controller_digital(SDL_CONTROLLER_BUTTON_EAST)
        }
    );

    // R3 -> L | Unused in BK but can be used in mods
    set_default_mapping_for_controller(GameInput::L, { InputField::controller_digital(SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSTICK) });
}

static void set_control_descriptions() {
    // Jet Force Gemini, "Normal" control mode (charControl ControlModeNormal: Z fire, A jump, R aim).
    const char* stick = "Moves the character. While aiming (R / right mouse button) it moves the crosshair; with the mouse aim option the right mouse button turns WASD into strafing (C-Left/C-Right) and stepping (C-Up/C-Down).";
    recompinput::set_game_input_description(recompinput::GameInput::Y_AXIS_POS, stick);
    recompinput::set_game_input_description(recompinput::GameInput::Y_AXIS_NEG, stick);
    recompinput::set_game_input_description(recompinput::GameInput::X_AXIS_NEG, stick);
    recompinput::set_game_input_description(recompinput::GameInput::X_AXIS_POS, stick);
    recompinput::set_game_input_description(recompinput::GameInput::A, "Jump (default key: Space). Also selects options in menus.");
    recompinput::set_game_input_description(recompinput::GameInput::B, "Character action / back in menus.");
    recompinput::set_game_input_description(recompinput::GameInput::Z, "Fire the current weapon (also the left mouse button).");
    recompinput::set_game_input_description(recompinput::GameInput::L, "Used by some menus and actions.");
    recompinput::set_game_input_description(recompinput::GameInput::R, "Hold to aim (also the right mouse button).");
    recompinput::set_game_input_description(recompinput::GameInput::START, "Pause / weapon and item menu, skips some cutscenes.");
    recompinput::set_game_input_description(recompinput::GameInput::C_UP, "Camera and aiming controls; while aiming: step forward.");
    recompinput::set_game_input_description(recompinput::GameInput::C_DOWN, "Camera and aiming controls; while aiming: step back.");
    recompinput::set_game_input_description(recompinput::GameInput::C_LEFT, "While aiming: strafe left.");
    recompinput::set_game_input_description(recompinput::GameInput::C_RIGHT, "While aiming: strafe right.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_UP, "D-Pad.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_DOWN, "D-Pad.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_LEFT, "D-Pad.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_RIGHT, "D-Pad.");
}

banjo::CutsceneAspectRatioMode banjo::get_cutscene_aspect_ratio_mode() {
    return get_graphics_config_enum_value<banjo::CutsceneAspectRatioMode>(banjo::configkeys::graphics::cutscene_aspect_ratio_mode);
}

void banjo::init_config() {
    std::filesystem::path recomp_dir = recompui::file::get_app_folder_path();

    if (!recomp_dir.empty()) {
        std::filesystem::create_directories(recomp_dir);
    }

    recompui::config::GeneralTabOptions general_options{};
    general_options.has_rumble_strength = true;
    general_options.has_gyro_sensitivity = false;
    // JFG mouse aim (src/main/main.cpp jfg_mouse_aim): the mouse turns the aim while the game's aim mode is
    // active (hold R or the right mouse button); left click = Z (fire). 0 disables it and the cursor capture.
    general_options.has_mouse_sensitivity = std::getenv("JFG_MOUSE_OFF") == nullptr; // env: A/B test switch
    general_options.mouse_sensitivity_default = 100.0;
    general_options.mouse_sensitivity_description =
        "Mouse aiming. While aiming (hold <b>right mouse button</b> or R) the mouse turns the aim; "
        "<b>left mouse button</b> fires (Z) and WASD strafes/steps while aiming. The cursor is captured while the game runs "
        "(press Escape for the menu). <b>Setting this to zero disables mouse aiming and the cursor capture.</b>";

    auto &general_config = recompui::config::create_general_tab(general_options);
    add_general_options(general_config);

    auto &graphics_config = recompui::config::create_graphics_tab();
    add_graphics_options(graphics_config);

    set_control_defaults();
    set_control_descriptions();
    recompui::config::create_controls_tab();

    auto &sound_config = recompui::config::create_sound_tab();
    add_sound_options(sound_config);

    recompui::config::create_mods_tab();

    recompui::config::finalize();

}
