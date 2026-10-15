#include <cstdio>
#include <atomic>
#include <chrono>
#include <mutex>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <array>
#include <filesystem>
#include <numeric>
#include <stdexcept>
#include <cinttypes>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <variant>

#include "nfd.h"

#include "ultramodern/ultra64.h"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"
#define SDL_MAIN_HANDLED
#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
// Undefine x11 macros that get included by SDL_syswm.h.
#undef None
#undef Status
#undef LockMask
#undef ControlMask
#undef Success
#undef Always
#endif

#include "recompui/recompui.h"
#include "recompui/program_config.h"
#include "recompui/renderer.h"
#include "recompui/config.h"
#include "util/file.h"
#include "recompinput/input_events.h"
#include "recompinput/recompinput.h"
#include "recompinput/profiles.h"
#include "banjo_config.h"
#include "banjo_sound.h"
#include "banjo_support.h"
#include "banjo_game.h"
#include "banjo_launcher.h"
#include "recomp_data.h"
#include "ovl_patches.hpp"
#include "theme.h"
#include "librecomp/game.hpp"
#include "librecomp/mods.hpp"
#include "librecomp/helpers.hpp"

#include "../../patches/graphics.h"
#include "../../patches/input.h"
#include "../../patches/sound.h"
#include "../../patches/misc_funcs.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <timeapi.h>
#include "SDL_syswm.h"
#define APP_ICON_B 1
#define APP_ICON_K 2
#endif

#include "../../lib/rt64/src/contrib/stb/stb_image.h"

const std::string version_string = "1.0.2";

template<typename... Ts>
void exit_error(const char* str, Ts ...args) {
    // TODO pop up an error
    ((void)fprintf(stderr, str, args), ...);
    assert(false);
        
    ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
}

ultramodern::gfx_callbacks_t::gfx_data_t create_gfx() {
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) > 0) {
        exit_error("Failed to initialize SDL2: %s\n", SDL_GetError());
    }

    fprintf(stdout, "SDL Video Driver: %s\n", SDL_GetCurrentVideoDriver());

    return {};
}

ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
    if ((recompinput::players::is_single_player_mode() && controller_num == 0) ||
        (!recompinput::players::is_single_player_mode() && recompinput::players::get_player_is_assigned(controller_num))) {
        return ultramodern::input::connected_device_info_t{
            .connected_device = ultramodern::input::Device::Controller,
            .connected_pak = ultramodern::input::Pak::RumblePak,
        };
    }

    return ultramodern::input::connected_device_info_t{
        .connected_device = ultramodern::input::Device::None,
        .connected_pak = ultramodern::input::Pak::None,
    };
}

#include "icon_bytes.h"

#if defined(__gnu_linux__)
bool SetImageAsIcon(const char* filename, SDL_Window* window)
{
    // Read data
    int width, height, bytesPerPixel;
    void* data = stbi_load_from_memory(reinterpret_cast<const uint8_t*>(icon_bytes), sizeof(icon_bytes), &width, &height, &bytesPerPixel, 4);

    // Calculate pitch
    int pitch;
    pitch = width * 4;
    pitch = (pitch + 3) & ~3;

    // Setup relevance bitmask
    int Rmask, Gmask, Bmask, Amask;

#if SDL_BYTEORDER == SDL_LIL_ENDIAN
    Rmask = 0x000000FF;
    Gmask = 0x0000FF00;
    Bmask = 0x00FF0000;
    Amask = 0xFF000000;
#else
    Rmask = 0xFF000000;
    Gmask = 0x00FF0000;
    Bmask = 0x0000FF00;
    Amask = 0x000000FF;
#endif

    SDL_Surface* surface = nullptr;
    if (data != nullptr) {
        surface = SDL_CreateRGBSurfaceFrom(data, width, height, 32, pitch, Rmask, Gmask,
                            Bmask, Amask);
    }

    if (surface == nullptr) {   
        if (data != nullptr) {
            stbi_image_free(data);
        }
        return false;
	} else {
        SDL_SetWindowIcon(window,surface);
        SDL_FreeSurface(surface);
        stbi_image_free(data);
        return true;
    }
}
#endif

SDL_Window* window;

ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
    uint32_t flags = SDL_WINDOW_RESIZABLE;

#if defined(__APPLE__)
    flags |= SDL_WINDOW_METAL;
#elif defined(RT64_SDL_WINDOW_VULKAN)
    flags |= SDL_WINDOW_VULKAN;
#endif

    window = SDL_CreateWindow("Jet Force Gemini: Recompiled", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900,  flags);

    if (window == nullptr) {
        exit_error("Failed to create window: %s\n", SDL_GetError());
    }

    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(window, &wmInfo);

#if defined(_WIN32)
    // There's a 50/50 chance to choose the icon where the smallest variant is either Banjo or Kazooie alone.
    bool choose_kazooie_icon = (rand() % 2 == 0);
    HICON new_icon = LoadIcon(GetModuleHandle(NULL), choose_kazooie_icon ? MAKEINTRESOURCE(APP_ICON_K) : MAKEINTRESOURCE(APP_ICON_B));
    SendMessage(wmInfo.info.win.window, WM_SETICON, ICON_SMALL2, (LPARAM)(new_icon));
#elif defined(__linux__)
    SetImageAsIcon("icons/app.png", window);
#endif

#if defined(_WIN32)
    return ultramodern::renderer::WindowHandle{ wmInfo.info.win.window, GetCurrentThreadId() };
#elif defined(__linux__) || defined(__ANDROID__)
    return ultramodern::renderer::WindowHandle{ window };
#elif defined(__APPLE__)
    SDL_MetalView view = SDL_Metal_CreateView(window);
    return ultramodern::renderer::WindowHandle{ wmInfo.info.cocoa.window,  SDL_Metal_GetLayer(view) };
#else
    static_assert(false && "Unimplemented");
#endif
}

void update_gfx(void*) {
    recompinput::handle_events();
}

static SDL_AudioCVT audio_convert;
static SDL_AudioDeviceID audio_device = 0;

// Samples per channel per second.
static uint32_t sample_rate = 48000;
static uint32_t output_sample_rate = 48000;
// Channel count.
constexpr uint32_t input_channels = 2;
static uint32_t output_channels = 2;

// Terminology: a frame is a collection of samples for each channel. e.g. 2 input samples is one input frame. This is unrelated to graphical frames.

// Number of frames to duplicate for fixing interpolation at the start and end of a chunk.
constexpr uint32_t duplicated_input_frames = 4;
// The number of output frames to skip for playback (to avoid playing duplicate inputs twice).
static uint32_t discarded_output_frames;

constexpr uint32_t bytes_per_frame = input_channels * sizeof(float);

void queue_samples(int16_t* audio_data, size_t sample_count) {
    // JFG_NO_AUDIO test mode: no device, nothing to queue (device 0 is never passed to SDL).
    if (audio_device == 0) return;
    static const bool trace_audio = std::getenv("JFG_TRACE_AUDIO") != nullptr;
    static bool reported_audio = false;
    if (trace_audio && !reported_audio) {
        int peak = 0;
        for (size_t i = 0; i < sample_count; ++i)
            peak = std::max(peak, std::abs(int(audio_data[i])));
        if (peak != 0) {
            fprintf(stderr, "[JFG] Audio PCM: %zu samples, peak=%d.\n", sample_count, peak);
            reported_audio = true;
        }
    }
    // Buffer for holding the output of swapping the audio channels. This is reused across
    // calls to reduce runtime allocations.
    static std::vector<float> swap_buffer;
    static std::array<float, duplicated_input_frames * input_channels> duplicated_sample_buffer;

    // Make sure the swap buffer is large enough to hold the audio data, including any extra space needed for resampling.
    size_t resampled_sample_count = sample_count + duplicated_input_frames * input_channels;
    size_t max_sample_count = std::max(resampled_sample_count, resampled_sample_count * audio_convert.len_mult);
    if (max_sample_count > swap_buffer.size()) {
        swap_buffer.resize(max_sample_count);
    }
    
    // Copy the duplicated frames from last chunk into this chunk
    for (size_t i = 0; i < duplicated_input_frames * input_channels; i++) {
        swap_buffer[i] = duplicated_sample_buffer[i];
    }

    // Convert the audio from 16-bit values to floats and swap the audio channels into the
    // swap buffer to correct for the address xor caused by endianness handling.
    float cur_main_volume = static_cast<float>(recompui::config::sound::get_main_volume()) / 100.0f; // Get the current main volume, normalized to 0.0-1.0.
    for (size_t i = 0; i < sample_count; i += input_channels) {
        swap_buffer[i + 0 + duplicated_input_frames * input_channels] = audio_data[i + 1] * (0.5f / 32768.0f) * cur_main_volume;
        swap_buffer[i + 1 + duplicated_input_frames * input_channels] = audio_data[i + 0] * (0.5f / 32768.0f) * cur_main_volume;
    }
    
    // TODO handle cases where a chunk is smaller than the duplicated frame count.
    assert(sample_count > duplicated_input_frames * input_channels);

    // Copy the last converted samples into the duplicated sample buffer to reuse in resampling the next queued chunk.
    for (size_t i = 0; i < duplicated_input_frames * input_channels; i++) {
        duplicated_sample_buffer[i] = swap_buffer[i + sample_count];
    }
    
    audio_convert.buf = reinterpret_cast<Uint8*>(swap_buffer.data());
    audio_convert.len = (sample_count + duplicated_input_frames * input_channels) * sizeof(swap_buffer[0]);

    int ret = SDL_ConvertAudio(&audio_convert);

    if (ret < 0) {
        printf("Error using SDL audio converter: %s\n", SDL_GetError());
        throw std::runtime_error("Error using SDL audio converter");
    }

    uint64_t cur_queued_microseconds = uint64_t(SDL_GetQueuedAudioSize(audio_device)) / bytes_per_frame * 1000000 / sample_rate;
    uint32_t num_bytes_to_queue = audio_convert.len_cvt - output_channels * discarded_output_frames * sizeof(swap_buffer[0]);
    float* samples_to_queue = swap_buffer.data() + output_channels * discarded_output_frames / 2;

    // Prevent audio latency from building up by skipping samples in incoming audio when too many samples are already queued.
    // Skip samples based on how many microseconds of samples are queued already.
    uint32_t skip_factor = cur_queued_microseconds / 100000;
    if (skip_factor != 0) {
        uint32_t skip_ratio = 1 << skip_factor;
        num_bytes_to_queue /= skip_ratio;
        for (size_t i = 0; i < num_bytes_to_queue / (output_channels * sizeof(swap_buffer[0])); i++) {
            samples_to_queue[2 * i + 0] = samples_to_queue[2 * skip_ratio * i + 0];
            samples_to_queue[2 * i + 1] = samples_to_queue[2 * skip_ratio * i + 1];
        }
    }

    // Queue the swapped audio data.
    // Offset the data start by only half the discarded frame count as the other half of the discarded frames are at the end of the buffer.
    SDL_QueueAudio(audio_device, samples_to_queue, num_bytes_to_queue);
}

size_t get_frames_remaining() {
    constexpr float buffer_offset_frames = 1.0f;
    // Get the number of remaining buffered audio bytes.
    uint64_t buffered_byte_count = audio_device != 0 ? SDL_GetQueuedAudioSize(audio_device) : 0;

    // Scale the byte count based on the ratio of sample rates and channel counts.
    buffered_byte_count = buffered_byte_count * 2 * sample_rate / output_sample_rate / output_channels;

    // Adjust the reported count to be some number of refreshes in the future, which helps ensure that
    // there are enough samples even if the audio thread experiences a small amount of lag. This prevents
    // audio popping on games that use the buffered audio byte count to determine how many samples
    // to generate.
    uint32_t frames_per_vi = (sample_rate / 60);
    if (buffered_byte_count > (buffer_offset_frames * bytes_per_frame * frames_per_vi)) {
        buffered_byte_count -= (buffer_offset_frames * bytes_per_frame * frames_per_vi);
    }
    else {
        buffered_byte_count = 0;
    }
    // Convert from byte count to sample count.
    return static_cast<uint32_t>(buffered_byte_count / bytes_per_frame);
}

void update_audio_converter() {
    int ret = SDL_BuildAudioCVT(&audio_convert, AUDIO_F32, input_channels, sample_rate, AUDIO_F32, output_channels, output_sample_rate);

    if (ret < 0) {
        printf("Error creating SDL audio converter: %s\n", SDL_GetError());
        throw std::runtime_error("Error creating SDL audio converter");
    }

    // Calculate the number of samples to discard based on the sample rate ratio and the duplicate frame count.
    discarded_output_frames = duplicated_input_frames * output_sample_rate / sample_rate;
}

void set_frequency(uint32_t freq) {
    sample_rate = freq;
    
    update_audio_converter();
}

bool reset_audio(uint32_t output_freq) {
    SDL_AudioSpec spec_desired{
        .freq = (int)output_freq,
        .format = AUDIO_F32,
        .channels = (Uint8)output_channels,
        .silence = 0, // calculated
        .samples = 0x100, // Fairly small sample count to reduce the latency of internal buffering
        .padding = 0, // unused
        .size = 0, // calculated
        .callback = nullptr,
        .userdata = nullptr
    };

    audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, nullptr, 0);
    if (audio_device == 0) {
        // Test-only escape hatch (default off): JFG_NO_AUDIO=1 continues without audio. Without it the modal box
        // blocks the game thread, so a busy or broken audio endpoint makes every headless run hang.
        if (std::getenv("JFG_NO_AUDIO") == nullptr) {
            std::string audio_error = std::string("No audio device could be found. Please make sure an audio device is available.\nError opening audio device: ") + std::string(SDL_GetError());
            recompui::message_box(audio_error.c_str());
            return false;
        }
        fprintf(stderr, "[JFG] JFG_NO_AUDIO=1: audio device failed (%s); continuing without audio (test mode).\n", SDL_GetError());
    }

    if (audio_device != 0) {
        SDL_PauseAudioDevice(audio_device, 0);
    }

    output_sample_rate = output_freq;
    update_audio_converter();

    return true;
}

extern RspUcodeFunc n_aspMain;

RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    switch (task->t.type) {
    case M_AUDTASK:
        return n_aspMain;

    default:
        fprintf(stderr, "Unknown task: %" PRIu32 "\n", task->t.type);
        return nullptr;
    }
}

extern "C" void recomp_entrypoint(uint8_t * rdram, recomp_context * ctx);
extern "C" void jfg_on_init(uint8_t* rdram, recomp_context* ctx);
gpr get_entrypoint_address();

// array of supported GameEntry objects
std::vector<recomp::GameEntry> supported_games = {
    {
        .rom_hash = 0x44830C263C2DE108ULL, // Jet Force Gemini (USA), XXH3 of the .z64
        .internal_name = "JET FORCE GEMINI",
        .display_name = "Jet Force Gemini",
        .game_id = u8"jfg.n64.us.1.0",
        .mod_game_id = "jfg",
        // JFG saves to 1 Mbit Flash RAM (osFlash* in the decomp symbols)
        .save_type = recomp::SaveType::Flashram,
        .thumbnail_bytes = std::span<const char>(icon_bytes),
        .is_enabled = false,
        // JFG code is stored uncompressed in the ROM
        .has_compressed_code = false,
        .entrypoint_address = get_entrypoint_address(),
        .entrypoint = recomp_entrypoint,
        .on_init_callback = jfg_on_init,
    },
};

// TODO: move somewhere else
namespace banjo {
    std::string get_game_thread_name(const OSThread* t) {
        std::string name = "[Game] ";

        switch (t->id) {
            case 0:
                switch (t->priority) {
                    case 150:
                        name += "PIMGR";
                        break;

                    case 80:
                        name += "VIMGR";
                        break;

                    default:
                        name += std::to_string(t->id);
                        break;
                }
                break;
            case 1:
                name += "INIT";
                break;
            case 2:
                name += "DEFRAG";
                break;
            case 4:
                name += "AUDIO";
                break;
            case 5:
                name += "RESET";
                break;
            case 6:
                name += "MAIN";
                break;
            case 7:
                name += "CONT";
                break;
            case 8:
                name += "RUMBLE";
                break;
            default:
                name += std::to_string(t->id);
                break;
        }

        return name;
    }
}

#ifdef _WIN32

struct PreloadContext {
    HANDLE handle;
    HANDLE mapping_handle;
    SIZE_T size;
    PVOID view;
};

bool preload_executable(PreloadContext& context) {
    wchar_t module_name[MAX_PATH];
    GetModuleFileNameW(NULL, module_name, MAX_PATH);

    context.handle = CreateFileW(module_name, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (context.handle == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Failed to load executable into memory!");
        context = {};
        return false;
    }

    LARGE_INTEGER module_size;
    if (!GetFileSizeEx(context.handle, &module_size)) {
        fprintf(stderr, "Failed to get size of executable!");
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    context.size = module_size.QuadPart;

    context.mapping_handle = CreateFileMappingW(context.handle, nullptr, PAGE_READONLY, 0, 0, nullptr);
    if (context.mapping_handle == nullptr) {
        fprintf(stderr, "Failed to create file mapping of executable!");
        CloseHandle(context.handle);
        context = {};
        return EXIT_FAILURE;
    }

    context.view = MapViewOfFile(context.mapping_handle, FILE_MAP_READ, 0, 0, 0);
    if (context.view == nullptr) {
        fprintf(stderr, "Failed to map view of of executable!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    DWORD pid = GetCurrentProcessId();
    HANDLE process_handle = OpenProcess(PROCESS_SET_QUOTA | PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (process_handle == nullptr) {
        fprintf(stderr, "Failed to open own process!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    SIZE_T minimum_set_size, maximum_set_size;
    if (!GetProcessWorkingSetSize(process_handle, &minimum_set_size, &maximum_set_size)) {
        fprintf(stderr, "Failed to get working set size!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    if (!SetProcessWorkingSetSize(process_handle, minimum_set_size + context.size, maximum_set_size + context.size)) {
        fprintf(stderr, "Failed to set working set size!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    if (VirtualLock(context.view, context.size) == 0) {
        fprintf(stderr, "Failed to lock view of executable! (Error: %08lx)\n", GetLastError());
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }
    
    return true;
}

void release_preload(PreloadContext& context) {
    VirtualUnlock(context.view, context.size);
    CloseHandle(context.mapping_handle);
    CloseHandle(context.handle);
    context = {};
}

#elif defined(__linux__) || defined(APPLE)

struct PreloadContext {

};

bool preload_executable(PreloadContext& context) {
    // Preloading isn't implemented on Linux and MacOS, but it's also unnecessary there, as the OS already preloads the executable.
    // Therefore, we can just consider the executable to be preloaded.
    return true;
}

void release_preload(PreloadContext& context) {
}

#else

struct PreloadContext {};

bool preload_executable(PreloadContext& context) {
    return false;
}

void release_preload(PreloadContext& context) {
}

#endif

void enable_texture_pack(recomp::mods::ModContext& context, const recomp::mods::ModHandle& mod) {
    recompui::renderer::enable_texture_pack(context, mod);
}

void disable_texture_pack(recomp::mods::ModContext&, const recomp::mods::ModHandle& mod) {
    recompui::renderer::disable_texture_pack(mod);
}

void reorder_texture_pack(recomp::mods::ModContext&) {
    recompui::renderer::trigger_texture_pack_update();
}

static bool jfg_auto_start = false;
static bool jfg_test_start_button = false;

extern "C" void jfg_logf(const char* fmt, ...);
extern "C" void jfg_latency_event(char kind);

// ---- Mouse aim (PC port) ----
// JFG's aim mode (hold R) calls controlGetManualAim(obj, state, ...) every game frame; a [[patches.hook]] at its
// entry (JFG_Decomp/recomp/jfg.us.toml) calls jfg_mouse_aim, which adds the mouse motion collected since the
// last call to the aim yaw (state+0x11C) and pitch (state+0x1E2). The game's own clamps run after the hook.
// Motion is only collected while that hook keeps being called (i.e. while aiming), so stray motion outside aim
// mode is dropped. Enabled by the General tab "Mouse Sensitivity" option (0 = off, which also disables cursor capture).
static std::mutex jfg_mouse_mutex;
static float jfg_mouse_acc_x = 0.0f, jfg_mouse_acc_y = 0.0f;
static uint64_t jfg_mouse_last_aim_ms = 0;
static float jfg_script_mouse_dx = 0.0f, jfg_script_mouse_dy = 0.0f; // scripted test motion per poll (counts)
static uint64_t jfg_script_begin_ms = 0; // SDL ticks of the first scripted pad poll (JFG_INPUT_SCRIPT time base)
static float jfg_cam_acc_x = 0.0f, jfg_cam_acc_y = 0.0f; // mouse camera: motion since the last follow-camera frame
static uint64_t jfg_mouse_last_cam_ms = 0;  // last call of the follow-camera hook

static bool jfg_mouse_aim_enabled() {
    return recompui::config::general::has_mouse_sensitivity_option() && recompui::config::general::get_mouse_sensitivity() > 0.0;
}

static void jfg_poll_inputs() {
    recompinput::poll_inputs();
    float dx = 0.0f, dy = 0.0f;
    if (jfg_mouse_aim_enabled()) {
        recompinput::get_mouse_deltas(&dx, &dy); // already scaled by the sensitivity option
    }
    dx += jfg_script_mouse_dx;
    dy += jfg_script_mouse_dy;
    std::lock_guard lock{ jfg_mouse_mutex };
    const uint64_t now = SDL_GetTicks64();
    if (now - jfg_mouse_last_aim_ms > 250) {
        jfg_mouse_acc_x = jfg_mouse_acc_y = 0.0f; // not aiming: drop motion
    } else {
        jfg_mouse_acc_x += dx;
        jfg_mouse_acc_y += dy;
    }
    // Mouse camera: same motion, consumed by the follow-camera hook while not aiming.
    if (now - jfg_mouse_last_cam_ms > 250 || now - jfg_mouse_last_aim_ms < 150) {
        jfg_cam_acc_x = jfg_cam_acc_y = 0.0f;
    } else {
        jfg_cam_acc_x += dx;
        jfg_cam_acc_y += dy;
    }
}

extern "C" void jfg_mouse_aim(uint8_t* rdram, recomp_context* ctx) {
    // Binary angle units (65536 = 360 deg) per mouse count at 100 % sensitivity: 12 ~= 0.066 deg.
    constexpr float units_per_count = 12.0f;
    float dx, dy;
    {
        std::lock_guard lock{ jfg_mouse_mutex };
        jfg_mouse_last_aim_ms = SDL_GetTicks64();
        dx = jfg_mouse_acc_x * units_per_count;
        dy = jfg_mouse_acc_y * units_per_count;
        const int ix = int(dx), iy = int(dy);
        jfg_mouse_acc_x -= ix / units_per_count; // keep the fractional remainder
        jfg_mouse_acc_y -= iy / units_per_count;
        dx = float(ix); dy = float(iy);
    }
    if (dx == 0.0f && dy == 0.0f) return;
    const uint64_t state = ctx->r5;
    // Stick right lowers the yaw (controlGetManualAim: yawIn = -stickX), so mouse right does too.
    MEM_H(0x11C, state) = int16_t(MEM_H(0x11C, state) - int(dx));
    // Pitch: mouse up (dy < 0) aims up; verified by screenshots: a lower 0x1E2 tilts the view down.
    MEM_H(0x1E2, state) = int16_t(std::clamp(int(MEM_H(0x1E2, state)) - int(dy), -0x2AAA, 0x2AAA));
    static const bool trace = std::getenv("JFG_TRACE_INPUT") != nullptr;
    static unsigned count = 0;
    if (trace && count++ < 400) jfg_logf("[JFG] Mouse aim: d=%d,%d yaw=%d pitch=%d\n", int(dx), int(dy),
        int(MEM_H(0x11C, state)), int(MEM_H(0x1E2, state)));
}

// ---- Mouse camera (PC port, General option "Mouse Camera", default Off; env JFG_MOUSE_CAMERA=1 forces it on) ----
// Hook at the entry of func_8002CF78 (vram 0x8002CF6C), JFG's normal third-person follow camera (decomp
// charControl.c). The camera target is player + (sin(az)*d, h, -cos(az)*d) with the orbit azimuth az in state+0x104;
// when the player is not braking/walking back the camera keeps its current direction (az = angle of the current
// camera position), otherwise it blends behind the player. Mouse X rotates the current camera position around the
// player and adds the same angle to az and to the view yaw (*controlcam). The game's own smoothing, collision
// (func_8002CBD0) and height logic still run afterwards. Movement is already camera relative (stick angle minus
// *controlcam in the player overlays), so WASD then moves relative to the view and the character turns to it.
// Sample the persisted option on the game thread (joyRead) into jfg_60hz_requested. The mode the scheduler hooks
// use (jfg_60hz_active) changes only in jfg_frame_sync_limit (viFrameSync), so a toggle takes effect at one fixed
// point per VI frame instead of at the input poll. Retrace handlers still run asynchronously to that point.
static std::atomic<bool> jfg_60hz_requested{false};
static std::atomic<bool> jfg_60hz_active{false};
extern "C" int jfg_60hz_enabled() {
    return jfg_60hz_active.load(std::memory_order_relaxed);
}

// Loop timing for JFG_TRACE_LOOP=1 (steady clock, microseconds). A = joyRead -> viFrameSync entry (game logic and
// display list build). B = viFrameSync entry -> next joyRead (sync, swap, retrace waits and the short loop tail).
static double jfg_loop_last_joy_us = 0.0, jfg_loop_last_vi_us = 0.0;
static double jfg_loop_now_us() {
    return std::chrono::duration<double, std::micro>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

extern "C" void jfg_gameplay_tick(uint8_t* rdram, recomp_context* ctx) {
    bool enabled = false;
    try {
        enabled = std::get<bool>(recompui::config::get_general_config().get_option_value("jfg_60hz_gameplay"));
    } catch (...) {}
    // Explicit 0/1 override for reproducible A/B runs, without changing the saved preference.
    static const char* forced = std::getenv("JFG_60HZ_GAMEPLAY");
    if (forced) enabled = std::strcmp(forced, "1") == 0;
    jfg_60hz_requested.store(enabled, std::memory_order_relaxed);
    static const bool trace_loop = std::getenv("JFG_TRACE_LOOP") != nullptr;
    if (trace_loop) {
        const double t = jfg_loop_now_us();
        if (jfg_loop_last_vi_us != 0.0) jfg_logf("JFG_LOOP B_us=%.0f on=%d\n", t - jfg_loop_last_vi_us, enabled ? 1 : 0);
        jfg_loop_last_joy_us = t;
    }
    static const bool trace = std::getenv("JFG_TRACE_GAMEPLAY") != nullptr;
    if (!trace) return;
    static uint64_t frame_number = 0;
    const uint64_t now = SDL_GetTicks64();
    jfg_logf("JFG_GAMEPLAY frame=%llu ms=%llu on=%d delta=%d time=%d\n",
        (unsigned long long)++frame_number,
        (unsigned long long)(jfg_script_begin_ms ? now - jfg_script_begin_ms : 0), enabled,
        int(ctx->r5), int(MEM_W(0, (gpr)(int32_t)0x800FD748)));
    // Same US-ROM globals used by objGetPlayerNo (0x8000E4D0).
    const gpr list = (gpr)(int32_t)MEM_W(0, (gpr)(int32_t)0x800F2D0C);
    const int count = MEM_W(0, (gpr)(int32_t)0x800F2D10);
    for (int i = 0; list && i < count && i < 1; ++i) {
        const gpr obj = (gpr)(int32_t)MEM_W(i * 4, list);
        if (!obj) continue;
        float pos[3];
        for (int k = 0; k < 3; ++k) { uint32_t u = MEM_W(0xC + k * 4, obj); memcpy(&pos[k], &u, 4); }
        jfg_logf("JFG_PLAYER frame=%llu xyz=%.5f,%.5f,%.5f\n",
            (unsigned long long)frame_number, pos[0], pos[1], pos[2]);
    }
}

// ---- Debug quick start (--jfg-level, default off) ----
// mainChangeLevel(level, char, ...) is hooked at entry (decomp/recomp/jfg.us.toml). Its level 0x142 is the new-game
// request (ship intro). With --jfg-level the request is redirected to the chosen level and character; every other
// call passes through unchanged. Without the option nothing is changed.
static int jfg_debug_level = -1;
static int jfg_debug_char = -1;
static int jfg_test_start_char = -1; // --jfg-test-start goldwood: character for the menu-free start
static int jfg_test_start_level = -1; // goldwood-landing: request this level instead of the character's start level
extern "C" void mainGetGame(uint8_t*, recomp_context*);        // generated (RecompiledFuncs), 0x80047C0C
extern "C" void mainSetDefaultGame(uint8_t*, recomp_context*); // 0x800476F0
extern "C" void mainSetMode(uint8_t*, recomp_context*);        // 0x80047580
extern "C" int jfg_overlay_at(uint32_t addr, uint32_t* rom_out, uint32_t* base_out); // rom_decompression.cpp
extern "C" void jfg_change_level(uint8_t* rdram, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_LEVEL") != nullptr;
    const int32_t level = (int32_t)ctx->r4;
    // ra = return address (RAM). If it lies in an overlay that is loaded right now, log that overlay's ROM address
    // and RAM base, so the caller can be mapped to a function without guessing from a reused address.
    if (trace) {
        uint32_t caller_rom = 0, caller_base = 0;
        const uint32_t ra = (uint32_t)ctx->r31;
        // The word at ra-8 is the jal that made this call when it is direct: jal 0x8004665C = 0x0C011997.
        // Only read RDRAM (ra 0 at the first call would fault).
        const uint32_t call_word = (ra >= 0x80000008u && ra < 0x80800000u) ? (uint32_t)MEM_W(0, (gpr)(int32_t)(ra - 8)) : 0;
        if (jfg_overlay_at(ra, &caller_rom, &caller_base)) {
            jfg_logf("JFG_LEVEL mainChangeLevel level=0x%X char=%d a2=%d a3=%d ra=0x%08X callword=0x%08X overlay_rom=0x%08X overlay_base=0x%08X off=0x%X\n",
                level, (int32_t)ctx->r5, (int32_t)ctx->r6, (int32_t)ctx->r7, ra, call_word, caller_rom, caller_base, ra - caller_base);
        } else {
            jfg_logf("JFG_LEVEL mainChangeLevel level=0x%X char=%d a2=%d a3=%d ra=0x%08X callword=0x%08X overlay=none\n",
                level, (int32_t)ctx->r5, (int32_t)ctx->r6, (int32_t)ctx->r7, ra, call_word);
        }
    }
    // Trigger: the first character-select request (0x16D "Boy Select Sq") after the start. The verified route in
    // run_to_goldwood.ps1 never calls 0x142, so 0x142 alone would not fire. Only the first call is redirected.
    static bool redirected = false;
    if (jfg_debug_level >= 0 && !redirected && level == 0x16D) {
        redirected = true;
        const uint64_t now = SDL_GetTicks64();
        fprintf(stderr, "[JFG] --jfg-level: character select (0x16D) redirected to level 0x%X, char %d at script ms %llu.\n",
            jfg_debug_level, jfg_debug_char, (unsigned long long)(jfg_script_begin_ms ? now - jfg_script_begin_ms : 0));
        ctx->r4 = (gpr)(int32_t)jfg_debug_level;
        ctx->r5 = (gpr)(int32_t)jfg_debug_char;
    }
    // --jfg-test-start goldwood (menu-free). Trigger: the first title-page request (level 0x15D, mode 3). It comes from
    // the Rare logo page without any input (JFG_TRACE_LEVEL/JFG_TRACE_TRAP, RECOMP.md "menu-free start").
    // Instead of the title page, do what a new game plus character select do, with the game's own functions:
    //   mainSetDefaultGame(game): default game struct; per character the start level from the ROM table at
    //     0x800A3314 (char 1 = 0x16D "Boy Select Sq") into record +0x74 (decomp main.c:1629/1817).
    //   mainSetMode(0): as frontCharSelect before its level change (overlay_58.c:164).
    //   mainChangeLevel(record level, char, record region, 0x10, 1, 0): the frontCharSelect request (overlay_58.c:179).
    // The level script then continues as in a normal game (0x16D -> 0x5D -> 0x5C via animseq command 0x7A).
    // No save is read or written (mainSaveGame is not called). Arguments 5 and 6 (stack) are 1 and 0 in both calls.
    static bool test_started = false;
    // Experiment (JFG_TESTSTART_EARLY=1, test only): trigger at the main loop's level-0 request (mode 2, about 0.5 s after
    // boot) instead of the title request, to skip the logo pages. Its stack arguments are not known, so they are set
    // to the 1, 0 that the title and frontCharSelect calls pass.
    static const bool early = std::getenv("JFG_TESTSTART_EARLY") != nullptr;
    const bool early_hit = early && level == 0 && (int32_t)ctx->r7 == 2;
    if (jfg_test_start_char >= 0 && !test_started && (level == 0x15D || early_hit)) {
        test_started = true;
        if (early_hit) {
            MEM_W(0x10, ctx->r29) = 1;
            MEM_W(0x14, ctx->r29) = 0;
        }
        const recomp_context saved = *ctx;
        mainGetGame(rdram, ctx);
        const gpr game = ctx->r2;
        if ((uint32_t)game < 0x80000000u || (uint32_t)game >= 0x80800000u) {
            *ctx = saved;
            fprintf(stderr, "[JFG] --jfg-test-start: game struct pointer 0x%08X invalid, start NOT changed.\n", (uint32_t)game);
            return;
        }
        ctx->r4 = game;
        mainSetDefaultGame(rdram, ctx);
        ctx->r4 = 0;
        mainSetMode(rdram, ctx);
        const gpr record = game + jfg_test_start_char * 0x76 + 0x15C;
        uint32_t level_region = (uint16_t)MEM_HU(0x74, record);
        // goldwood-landing: skip the two cutscene levels 0x16D and 0x5D and request 0x5C with the arguments that
        // command 0x7A of 0x5D uses (region 0, mode 0x10, anim group 0; mainChangeLevel itself sets the group to 0).
        if (jfg_test_start_level >= 0) level_region = (uint32_t)jfg_test_start_level << 5;
        *ctx = saved;
        ctx->r4 = (gpr)(int32_t)(level_region >> 5);
        ctx->r5 = (gpr)jfg_test_start_char;
        ctx->r6 = (gpr)(int32_t)(level_region & 0x1F);
        ctx->r7 = 0x10;
        fprintf(stderr, "[JFG] --jfg-test-start: new default game, char %d, level 0x%X region %d (instead of title 0x15D) at %llu ms.\n",
            jfg_test_start_char, level_region >> 5, level_region & 0x1F, (unsigned long long)SDL_GetTicks64());
        if (trace) jfg_logf("JFG_TESTSTART game=0x%08X char=%d level=0x%X region=%d\n", (uint32_t)game, jfg_test_start_char,
            level_region >> 5, level_region & 0x1F);
    }
}

// Trace at the entry of TrapDanglingJump (0x80054530, the game's overlay trampoline). It tail-jumps into the target
// and keeps ra, so the "jal" at ra-8 is the call site that invoked the trampoline. JFG_TRACE_TRAP=1 only.
extern "C" void jfg_trap_trace(uint8_t* rdram, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_TRAP") != nullptr;
    if (!trace) return;
    const uint32_t ra = (uint32_t)ctx->r31;
    const uint32_t jal = ra - 8;
    uint32_t rom = 0, base = 0;
    if (jfg_overlay_at(jal, &rom, &base)) {
        jfg_logf("JFG_TRAP ra=0x%08X jal=0x%08X a0=0x%08X a1=0x%08X a2=0x%08X a3=0x%08X overlay_rom=0x%08X overlay_base=0x%08X off=0x%X\n",
            ra, jal, (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6, (uint32_t)ctx->r7, rom, base, jal - base);
    } else {
        jfg_logf("JFG_TRAP ra=0x%08X jal=0x%08X a0=0x%08X a1=0x%08X a2=0x%08X a3=0x%08X overlay=none\n",
            ra, jal, (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6, (uint32_t)ctx->r7);
    }
}

// Trace at the tail jump of TrapDanglingJump ("jr $t8" at 0x800546AC, generated code funcs_17.c): the overlay is loaded
// and t8 is the resolved target. t5 = the jal that called the trampoline, t7 = index into overlayRomTable (from the
// relocation entry), t9 = overlayRomTable[t7] = (overlay index << 20) | offset in that overlay. The overlay header
// (overlayTable at *0x800FEAA0, 32 bytes each, +4 = ROM address) gives the ROM address of the target overlay, which
// maps it to a decomp overlay without guessing. JFG_TRACE_TRAP=1 only.
extern "C" void jfg_trap_target(uint8_t* rdram, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_TRAP") != nullptr;
    if (!trace) return;
    const uint32_t t9 = (uint32_t)ctx->r25;
    const uint32_t ovl = t9 >> 20;
    const gpr header = (gpr)(int32_t)((uint32_t)MEM_W(0, (gpr)(int32_t)0x800FEAA0u) + ovl * 0x20);
    jfg_logf("JFG_TRAPTGT jal=0x%08X func_index=%u entry=0x%08X ovl=%u off=0x%X target=0x%08X ovl_base=0x%08X ovl_rom=0x%08X a0=0x%08X a1=0x%08X a2=0x%08X a3=0x%08X\n",
        (uint32_t)ctx->r13, (uint32_t)ctx->r15, t9, ovl, t9 & 0xFFFFF, (uint32_t)ctx->r24,
        (uint32_t)MEM_W(0, header), (uint32_t)MEM_W(4, header),
        (uint32_t)ctx->r4, (uint32_t)ctx->r5, (uint32_t)ctx->r6, (uint32_t)ctx->r7);
}

// Entry traces of the level loader (JFG_TRACE_LEVEL=1 only). levelInit (0x80043E3C) is called by func_80046070 with
// (D_800A323C level, D_800A3244, D_800A3240 char, D_800A3248 anim group) (decomp main.c:1530). objSetupPlayers
// (0x8000561C) is called by overlay 24 trackInit with the spawn id of the level (decomp objects.c:901).
static uint64_t jfg_trace_ms() {
    const uint64_t now = SDL_GetTicks64();
    return jfg_script_begin_ms ? now - jfg_script_begin_ms : 0;
}
extern "C" void jfg_trace_level_init(uint8_t* rdram, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_LEVEL") != nullptr;
    if (!trace) return;
    jfg_logf("JFG_LEVELINIT ms=%llu level=0x%X a1=%d char=%d animgroup=%d region_req=%d mode_req=%d ra=0x%08X\n",
        (unsigned long long)jfg_trace_ms(), (uint32_t)ctx->r4, (int32_t)ctx->r5, (int32_t)ctx->r6, (int32_t)ctx->r7,
        (int32_t)MEM_H(0, (gpr)(int32_t)0x800A3268), (int32_t)MEM_H(0, (gpr)(int32_t)0x800A3264), (uint32_t)ctx->r31);
    // JFG_DUMP_GAME=1: the whole game struct (0x538 bytes = the size the save path copies, overlay_42.c:600) at each
    // level load, to compare the state of different start paths byte by byte.
    static const bool dump = std::getenv("JFG_DUMP_GAME") != nullptr;
    if (dump) {
        const recomp_context saved = *ctx;
        mainGetGame(rdram, ctx);
        const gpr game = ctx->r2;
        *ctx = saved;
        std::string hex;
        hex.reserve(0x538 * 2);
        static const char digits[] = "0123456789ABCDEF";
        for (int i = 0; i < 0x538; ++i) {
            const uint8_t b = (uint8_t)MEM_BU(i, game);
            hex.push_back(digits[b >> 4]);
            hex.push_back(digits[b & 15]);
        }
        jfg_logf("JFG_GAMEDUMP level=0x%X game=0x%08X %s\n", (uint32_t)ctx->r4, (uint32_t)game, hex.c_str());
    }
}
extern "C" void jfg_trace_setup_players(uint8_t* rdram, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_LEVEL") != nullptr;
    if (!trace) return;
    jfg_logf("JFG_SETUPPLAYERS ms=%llu spawn=%d ra=0x%08X\n",
        (unsigned long long)jfg_trace_ms(), (int32_t)ctx->r4, (uint32_t)ctx->r31);
}

// Adaptive VI state of gameVi.c (viFrameRateReset / viFrameSync), verified against RecompiledFuncs:
// D_800FECAC_B189C = minimum frames per update (1/2/3), D_800FECAB_B189B = short-frame counter,
// D_800FECAD_B189D = "no stable frame yet" flag. viFrameSync reads the minimum at 0x80055104 (s1 = 0x800FECAC).
static constexpr int32_t kViMinFrames = (int32_t)0x800FECAC;
static constexpr int32_t kViCounter = (int32_t)0x800FECAB;
static constexpr int32_t kViStable = (int32_t)0x800FECAD;
static uint8_t jfg_vi_saved[3] = { 2, 0, 1 }; // 30 Hz values captured on enable; reset values until then

extern "C" void jfg_frame_sync_limit(uint8_t* rdram, recomp_context* ctx) {
    const bool want = jfg_60hz_requested.load(std::memory_order_relaxed);
    const bool active = jfg_60hz_active.load(std::memory_order_relaxed);
    static const bool trace_loop = std::getenv("JFG_TRACE_LOOP") != nullptr;
    if (trace_loop) {
        const double t = jfg_loop_now_us();
        if (jfg_loop_last_joy_us != 0.0) jfg_logf("JFG_LOOP A_us=%.0f on=%d\n", t - jfg_loop_last_joy_us, active ? 1 : 0);
        jfg_loop_last_vi_us = t;
    }
    // Save the 30 Hz adaptive state on enable and restore it exactly on disable (not a fixed value).
    if (want && !active) {
        jfg_vi_saved[0] = MEM_BU(0, (gpr)kViMinFrames);
        jfg_vi_saved[1] = MEM_BU(0, (gpr)kViCounter);
        jfg_vi_saved[2] = MEM_BU(0, (gpr)kViStable);
        jfg_60hz_active.store(true, std::memory_order_relaxed);
    } else if (!want && active) {
        MEM_B(0, (gpr)kViMinFrames) = (int8_t)jfg_vi_saved[0];
        MEM_B(0, (gpr)kViCounter) = (int8_t)jfg_vi_saved[1];
        MEM_B(0, (gpr)kViStable) = (int8_t)jfg_vi_saved[2];
        jfg_60hz_active.store(false, std::memory_order_relaxed);
    }
    // Leave the measured delta and the final swap/retrace wait untouched; only the minimum is forced to 1.
    if (want) MEM_B(0, (gpr)kViMinFrames) = 1;
}

static bool jfg_mouse_camera_enabled() {
    static const bool forced = std::getenv("JFG_MOUSE_CAMERA") != nullptr;
    if (!jfg_mouse_aim_enabled()) return false; // needs mouse capture (Mouse Sensitivity > 0)
    if (forced) return true;
    try {
        return std::get<uint32_t>(recompui::config::get_general_config().get_option_value("jfg_mouse_camera")) != 0;
    } catch (...) { return false; }
}

// Mouse Y: a camera height offset h (mouse down = camera higher, looking down; mouse up = lower, looking up) is
// added AFTER the follow camera ran (second hook in its caller func_8002B378 at 0x8002B814, right after the call
// returns) together with the matching extra pitch, and removed again at the next entry, so the game's own
// smoothing state never sees it.
static float jfg_cam_h = 0.0f;          // wanted height offset (world units)
static float jfg_cam_applied_h = 0.0f;  // offset currently added to controlcam y
static int jfg_cam_applied_pitch = 0;   // pitch units currently added to controlcam+0x2
static bool jfg_cam_pending = false;    // follow camera ran this frame -> apply the offset after it
static gpr jfg_cam_obj = 0;

static float jfg_getf(uint8_t* rdram, gpr base, int off) { uint32_t u = MEM_W(off, base); float f; memcpy(&f, &u, 4); return f; }
static void jfg_setf(uint8_t* rdram, gpr base, int off, float f) { uint32_t u; memcpy(&u, &f, 4); MEM_W(off, base) = u; }
static gpr jfg_controlcam(uint8_t* rdram) { return (gpr)(int32_t)MEM_W(0, (gpr)(int32_t)0x800F6DC0); }

extern "C" void jfg_mouse_camera(uint8_t* rdram, recomp_context* ctx) {
    const gpr cam = jfg_controlcam(rdram);
    if (cam == 0) return;
    // Remove last frame's height/pitch offset first (also when the option was just switched off).
    if (jfg_cam_applied_h != 0.0f || jfg_cam_applied_pitch != 0) {
        jfg_setf(rdram, cam, 0x10, jfg_getf(rdram, cam, 0x10) - jfg_cam_applied_h);
        jfg_setf(rdram, cam, 0x1C, jfg_getf(rdram, cam, 0x1C) - jfg_cam_applied_h);
        MEM_H(0x2, cam) = int16_t(MEM_H(0x2, cam) - jfg_cam_applied_pitch);
        jfg_cam_applied_h = 0.0f;
        jfg_cam_applied_pitch = 0;
    }
    jfg_cam_pending = false;
    if (!jfg_mouse_camera_enabled()) { jfg_cam_h = 0.0f; return; }
    constexpr float units_per_count = 12.0f; // binary angle units (65536 = 360 deg), same scale as mouse aim
    constexpr float height_per_count = 0.5f;
    float dx, dy;
    {
        std::lock_guard lock{ jfg_mouse_mutex };
        jfg_mouse_last_cam_ms = SDL_GetTicks64();
        dx = jfg_cam_acc_x; dy = jfg_cam_acc_y;
        jfg_cam_acc_x = jfg_cam_acc_y = 0.0f;
    }
    jfg_cam_h = std::clamp(jfg_cam_h + dy * height_per_count, -40.0f, 160.0f);
    jfg_cam_pending = true;
    jfg_cam_obj = ctx->r4;
    // + : mouse right turns the view right (runlogs\cmp_092454 = wrong sign, cmp_093109 = this sign).
    const int delta = int(dx * units_per_count);
    if (delta == 0) return;
    const gpr obj = ctx->r4, state = ctx->r5;
    const float px = jfg_getf(rdram, obj, 0xC), pz = jfg_getf(rdram, obj, 0x14);
    const float ox = jfg_getf(rdram, cam, 0xC) - px, oz = jfg_getf(rdram, cam, 0x14) - pz;
    const float a = float(delta) * (6.28318530718f / 65536.0f);
    const float c = cosf(a), sn = sinf(a);
    const float nx = ox * c - oz * sn, nz = oz * c + ox * sn; // az -> az + delta (target = (sin az, -cos az) * d)
    jfg_setf(rdram, cam, 0xC, px + nx); jfg_setf(rdram, cam, 0x14, pz + nz);
    jfg_setf(rdram, cam, 0x18, px + nx); jfg_setf(rdram, cam, 0x20, pz + nz);
    MEM_H(0x104, state) = int16_t(MEM_H(0x104, state) + delta);
    MEM_H(0x0, cam) = int16_t(MEM_H(0x0, cam) + delta);
    static const bool trace = std::getenv("JFG_TRACE_INPUT") != nullptr;
    static unsigned count = 0;
    if (trace && count++ < 400) jfg_logf("[JFG] Mouse camera: d=%d az=%d yaw=%d h=%.0f\n", delta, int(MEM_H(0x104, state)), int(MEM_H(0x0, cam)), jfg_cam_h);
}

// Runs in func_8002B378 right after any camera mode; only acts when the follow camera ran this frame.
extern "C" void jfg_mouse_camera_post(uint8_t* rdram, recomp_context* ctx) {
    if (!jfg_cam_pending) return;
    jfg_cam_pending = false;
    const gpr cam = jfg_controlcam(rdram);
    if (cam == 0 || jfg_cam_h == 0.0f) return;
    const float ddx = jfg_getf(rdram, cam, 0xC) - jfg_getf(rdram, jfg_cam_obj, 0xC);
    const float ddz = jfg_getf(rdram, cam, 0x14) - jfg_getf(rdram, jfg_cam_obj, 0x14);
    const float dist = std::max(sqrtf(ddx * ddx + ddz * ddz), 1.0f);
    // The game's pitch is Arctanf(cam_y - look_y, horizontal distance): raising the camera adds this much.
    const int pitch = int(atan2f(jfg_cam_h, dist) * (65536.0f / 6.28318530718f));
    jfg_setf(rdram, cam, 0x10, jfg_getf(rdram, cam, 0x10) + jfg_cam_h);
    jfg_setf(rdram, cam, 0x1C, jfg_getf(rdram, cam, 0x1C) + jfg_cam_h);
    MEM_H(0x2, cam) = int16_t(MEM_H(0x2, cam) + pitch);
    jfg_cam_applied_h = jfg_cam_h;
    jfg_cam_applied_pitch = pitch;
}

// Debug (env JFG_TRACE_SCALE=1): hook right after gen_anim_data in modGenAnimMatrices (s3 = model header,
// sp+0x14 = tilt/command list). Logs the tilt command list and the per-joint scale table (0x800A720C, 3 u16 per
// joint, 0 = unscaled) whenever a model has non-zero scales.
// Bounded CPU/RT64 pair capture, keyed by actual RDRAM matrix buffer address.
// Keep both generations of each double buffer for diagnosing stale-frame reads.
struct JfgMatrixSnapshot { uint32_t address, serial; std::array<float, 16> values; };
static std::mutex jfg_matrix_pair_mutex;
static std::vector<JfgMatrixSnapshot> jfg_matrix_snapshots;
static void jfg_capture_matrix_pair(uint8_t* rdram, recomp_context* ctx) {
    static const char* at = std::getenv("JFG_TRACE_MATRIX_PAIR_AT");
    static uint32_t serial = 0;
    if (!at || serial >= 6 || !jfg_script_begin_ms ||
        SDL_GetTicks64() - jfg_script_begin_ms < std::strtoull(at, nullptr, 10) ||
        MEM_BU(0x4F, ctx->r19) != 21) return;
    const gpr inst = ctx->r20;
    const int buffer = MEM_BU(0x0B, inst);
    const gpr base = (gpr)(int32_t)MEM_W(0x10 + buffer * 4, inst);
    std::lock_guard lock(jfg_matrix_pair_mutex);
    ++serial;
    jfg_logf("MTXPAIR CPU serial=%u inst=%08X buffer=%d base=%08X ms=%llu\n", serial,
        uint32_t(inst), buffer, uint32_t(base), (unsigned long long)(SDL_GetTicks64() - jfg_script_begin_ms));
    for (int joint = 0; joint < 21; ++joint) {
        JfgMatrixSnapshot snap{(uint32_t(base) & 0xFFFFFF) + uint32_t(joint * 64), serial, {}};
        for (int r = 0; r < 4; ++r) for (int c = 0; c < 4; ++c) {
            // gen_anim_data writes 4x3; conv_mult_matrix supplies the affine W column.
            snap.values[r * 4 + c] = c == 3 ? (r == 3 ? 1.0f : 0.0f) : jfg_getf(rdram, base, joint * 64 + r * 16 + c * 4);
        }
        jfg_matrix_snapshots.push_back(snap);
    }
}
extern "C" void jfg_compare_decoded_matrix(uint32_t address, uint32_t task, const float* decoded) {
    static const bool enabled = std::getenv("JFG_TRACE_MATRIX_PAIR_AT") != nullptr;
    if (!enabled) return;
    static unsigned printed = 0;
    std::lock_guard lock(jfg_matrix_pair_mutex);
    if (printed >= 252) return;
    const JfgMatrixSnapshot* best = nullptr;
    float best_error = 1e30f;
    for (const auto& snap : jfg_matrix_snapshots) {
        if (snap.address != address) continue;
        float error = 0;
        for (int i = 0; i < 16; ++i) error = std::max(error, std::abs(snap.values[i] - decoded[i]));
        if (error <= best_error) { best_error = error; best = &snap; }
    }
    if (!best) return;
    ++printed;
    std::string values;
    char pair[96];
    for (int i = 0; i < 16; ++i) {
        snprintf(pair, sizeof pair, " %.9g/%.9g", double(best->values[i]), double(decoded[i]));
        values += pair;
    }
    jfg_logf("MTXPAIR GPU task=%u addr=%08X cpu_serial=%u max_error=%.9g cpu/decoded=%s\n",
        task, address, best->serial, double(best_error), values.c_str());
}

extern "C" void jfg_trace_anim_scale(uint8_t* rdram, recomp_context* ctx) {
    jfg_capture_matrix_pair(rdram, ctx);
    static const bool enabled = std::getenv("JFG_TRACE_SCALE") != nullptr;
    static unsigned lines = 0;
    if (!enabled || lines > 300) return;
    const int count = int(MEM_B(0x4F, ctx->r19));
    const gpr table = (gpr)(int32_t)0x800A720C;
    std::string sc;
    for (int j = 0; j < count && j < 96; j++)
        for (int a = 0; a < 3; a++) {
            const uint16_t v = uint16_t(MEM_H(j * 6 + a * 2, table));
            if (v) sc += std::to_string(j) + "." + std::to_string(a) + "=" + std::to_string(v) + " ";
        }
    std::string tl;
    const gpr tilt = (gpr)(int32_t)MEM_W(0x14, ctx->r29);
    for (int i = 0; tilt && i < 40; i++) {
        const uint16_t cmd = uint16_t(MEM_H(i * 4, tilt));
        char b[24]; snprintf(b, sizeof b, "%04X:%d ", cmd, int(MEM_H(i * 4 + 2, tilt)));
        tl += b;
        if ((cmd & 0xF000) == 0x1000) break;
    }
    // JFG_DUMP_ANIM_AT=<ms in JFG_INPUT_SCRIPT time> (with JFG_TRACE_SCALE=<joints>): once, dump the animation inputs and outputs
    // of this model (s4 = model instance, see modGenAnimMatrices / gen_anim_data) as hex lines to jfg_trace.log.
    static const char* dump_at = std::getenv("JFG_DUMP_ANIM_AT");
    static int dumps = 0;
    if (dump_at && dumps < 3 && jfg_script_begin_ms && SDL_GetTicks64() - jfg_script_begin_ms >= std::strtoull(dump_at, nullptr, 10) &&
        (std::atoi(std::getenv("JFG_TRACE_SCALE")) <= 1 || count == std::atoi(std::getenv("JFG_TRACE_SCALE")))) {
        dumps++;
        const gpr inst = ctx->r20, hdr = ctx->r19;
        auto hex = [&](const char* name, gpr addr, int n) {
            std::string h; char b[4];
            for (int i = 0; i < n; i++) { snprintf(b, sizeof b, "%02X", uint8_t(MEM_BU(i, addr))); h += b; }
            jfg_logf("DUMP %s %08X %s\n", name, uint32_t(addr), h.c_str());
        };
        hex("inst", inst, 0x90);
        hex("hdr", hdr, 0x70);
        hex("ivtx", (gpr)(int32_t)MEM_W(0x04, inst), MEM_H(0x12, hdr) * 10); // per-instance vertex copy (0xBF vertex base)
        hex("groups", (gpr)(int32_t)MEM_W(0x24, hdr), (MEM_H(0x16, hdr) + 1) * 16);
        hex("xforms", (gpr)(int32_t)MEM_W(0x54, hdr), count * 16);
        const gpr ctl0 = (gpr)(int32_t)MEM_W(0x60, inst), ctl1 = (gpr)(int32_t)MEM_W(0x64, inst);
        if (ctl0) hex("anim0", ctl0 - 8, 0x100);
        if (ctl1) hex("anim1", ctl1 - 8, 0x100);
        const gpr f0 = (gpr)(int32_t)MEM_W(0x50, inst), f1 = (gpr)(int32_t)MEM_W(0x54, inst);
        if (f0) hex("frames0", f0, 0x80);
        if (f1) hex("frames1", f1, 0x80);
        hex("rottab", (gpr)(int32_t)0x800A6FCC, 0x240);
        hex("scaletab", (gpr)(int32_t)0x800A720C, 0x240);
        hex("mtx", (gpr)(int32_t)MEM_W(0x10 + MEM_B(0x0B, inst) * 4, inst), count * 64);
    }
    static const int only = std::atoi(std::getenv("JFG_TRACE_SCALE"));
    if (only > 1 && count != only) return; // JFG_TRACE_SCALE=<joint count> filters one model type
    static std::string last;
    if (tl == last) return;
    last = tl;
    lines++;
    jfg_logf("[JFG] Tilt joints=%d at %llu ms: %s | scales %s\n", count, (unsigned long long)SDL_GetTicks64(), tl.c_str(), sc.c_str());
}

// Mouse buttons (left = Z fire, right = R aim) and, while the right button aims, WASD/stick -> C buttons
// (in aim mode the stick would move the crosshair; C-left/right strafe, C-up/down step).
static void jfg_apply_mouse(uint16_t* buttons, float* x, float* y, bool script_lmb, bool script_rmb) {
    bool lmb = script_lmb, rmb = script_rmb;
    if (jfg_mouse_aim_enabled() && SDL_GetRelativeMouseMode()) {
        const uint32_t mb = SDL_GetMouseState(nullptr, nullptr);
        lmb |= (mb & SDL_BUTTON_LMASK) != 0;
        rmb |= (mb & SDL_BUTTON_RMASK) != 0;
    }
    if (lmb) *buttons |= 0x2000; // Z
    if (rmb) {
        *buttons |= 0x0010;      // R
        if (*y > 0.5f) *buttons |= 0x0008;  // C-up
        if (*y < -0.5f) *buttons |= 0x0004; // C-down
        if (*x < -0.5f) *buttons |= 0x0002; // C-left
        if (*x > 0.5f) *buttons |= 0x0001;  // C-right
        *x = *y = 0.0f;
    }
}

static bool jfg_get_input(int player, uint16_t *buttons, float *x, float *y) {
    if (get_connected_device_info(player).connected_device == ultramodern::input::Device::None) {
        *buttons = 0;
        *x = *y = 0;
        return false;
    }
    if (player == 0) jfg_latency_event('I');
    bool connected = recompinput::profiles::get_n64_input(player, buttons, x, y);
    static const bool trace_buttons = std::getenv("JFG_TRACE_BUTTONS") != nullptr;
    if (trace_buttons && player == 0) {
        static uint16_t last = 0;
        if (*buttons != last) { last = *buttons; jfg_logf("[JFG] Pad buttons %04X stick %.2f,%.2f at %llu ms\n", *buttons, *x, *y, (unsigned long long)SDL_GetTicks64()); }
    }
    // Opt-in scripted test input for pad 1: JFG_INPUT_SCRIPT="ms:KEYS[:hold_ms];..." with KEYS joined by '+'
    // (A B Z START L R CU CD CL CR DU DD DL DR, stick: UP DOWN LEFT RIGHT). Times are from the first poll.
    // Optional JFG_INPUT_REPEAT="period_ms:KEYS[:hold_ms]@from_ms-to_ms" taps a key periodically.
    bool script_lmb = false, script_rmb = false;
    if (player == 0) { jfg_script_mouse_dx = 0.0f; jfg_script_mouse_dy = 0.0f; }
    static const char* script_env = std::getenv("JFG_INPUT_SCRIPT");
    static const char* repeat_env = std::getenv("JFG_INPUT_REPEAT");
    if ((script_env || repeat_env) && player == 0) {
        struct Step { uint64_t at, hold; uint16_t buttons; float sx, sy; float mdx = 0.0f, mdy = 0.0f; bool lmb = false, rmb = false; };
        static std::vector<Step> steps;
        static Step repeat{};
        static uint64_t repeat_from = 0, repeat_to = 0;
        static bool parsed = false;
        auto parse_keys = [](const std::string& keys, Step& s) {
            static const std::pair<const char*, uint16_t> names[] = { {"A",0x8000},{"B",0x4000},{"Z",0x2000},{"START",0x1000},
                {"DU",0x0800},{"DD",0x0400},{"DL",0x0200},{"DR",0x0100},{"L",0x0020},{"R",0x0010},
                {"CU",0x0008},{"CD",0x0004},{"CL",0x0002},{"CR",0x0001} };
            size_t p = 0;
            while (p <= keys.size()) {
                size_t e = keys.find('+', p); if (e == std::string::npos) e = keys.size();
                const std::string k = keys.substr(p, e - p);
                for (auto& n : names) if (k == n.first) s.buttons |= n.second;
                if (k == "UP") s.sy = 1.0f; if (k == "DOWN") s.sy = -1.0f;
                if (k == "LEFT") s.sx = -1.0f; if (k == "RIGHT") s.sx = 1.0f;
                // mouse (tests): LMB RMB buttons, MLEFT MRIGHT MUP MDOWN = 10 counts per poll
                if (k == "LMB") s.lmb = true; if (k == "RMB") s.rmb = true;
                if (k == "MLEFT") s.mdx = -10.0f; if (k == "MRIGHT") s.mdx = 10.0f;
                if (k == "MUP") s.mdy = -10.0f; if (k == "MDOWN") s.mdy = 10.0f;
                p = e + 1;
            }
        };
        if (!parsed) {
            parsed = true;
            std::string all = script_env ? script_env : "";
            size_t p = 0;
            while (p < all.size()) {
                size_t e = all.find_first_of(";,", p); if (e == std::string::npos) e = all.size();
                const std::string item = all.substr(p, e - p);
                const size_t c1 = item.find(':');
                if (c1 != std::string::npos) {
                    Step s{ std::strtoull(item.c_str(), nullptr, 10), 300, 0, 0.0f, 0.0f };
                    const size_t c2 = item.find(':', c1 + 1);
                    parse_keys(item.substr(c1 + 1, c2 == std::string::npos ? std::string::npos : c2 - c1 - 1), s);
                    if (c2 != std::string::npos) s.hold = std::strtoull(item.c_str() + c2 + 1, nullptr, 10);
                    steps.push_back(s);
                }
                p = e + 1;
            }
            if (repeat_env) {
                std::string r = repeat_env;
                const size_t c1 = r.find(':'), at = r.find('@');
                repeat.at = std::strtoull(r.c_str(), nullptr, 10);
                repeat.hold = 150;
                const size_t c2 = r.find(':', c1 + 1);
                parse_keys(r.substr(c1 + 1, (c2 != std::string::npos && c2 < at ? c2 : at) - c1 - 1), repeat);
                if (c2 != std::string::npos && c2 < at) repeat.hold = std::strtoull(r.c_str() + c2 + 1, nullptr, 10);
                if (at != std::string::npos) {
                    repeat_from = std::strtoull(r.c_str() + at + 1, nullptr, 10);
                    const size_t dash = r.find('-', at);
                    repeat_to = dash != std::string::npos ? std::strtoull(r.c_str() + dash + 1, nullptr, 10) : UINT64_MAX;
                }
            }
            jfg_logf("[JFG] Scripted input: %zu steps%s.\n", steps.size(), repeat_env ? " + repeat" : "");
        }
        static const uint64_t begin = SDL_GetTicks64();
        jfg_script_begin_ms = begin;
        const uint64_t elapsed = SDL_GetTicks64() - begin;
        auto apply = [&](const Step& s, int index) {
            if (!connected) { *buttons = 0; *x = *y = 0; connected = true; }
            *buttons |= s.buttons;
            if (s.sx != 0.0f) *x = s.sx;
            if (s.sy != 0.0f) *y = s.sy;
            script_lmb |= s.lmb; script_rmb |= s.rmb;
            if (s.mdx != 0.0f) jfg_script_mouse_dx = s.mdx;
            if (s.mdy != 0.0f) jfg_script_mouse_dy = s.mdy;
            static int reported = -2;
            if (reported != index) { reported = index; jfg_logf("[JFG] Scripted input step %d at %llu ms: buttons=%04X stick=%.0f,%.0f\n",
                index, (unsigned long long)elapsed, s.buttons, s.sx, s.sy); }
        };
        for (size_t i = 0; i < steps.size(); i++) {
            if (elapsed >= steps[i].at && elapsed < steps[i].at + steps[i].hold) apply(steps[i], int(i));
        }
        if (repeat_env && repeat.at && elapsed >= repeat_from && elapsed < repeat_to &&
            ((elapsed - repeat_from) % repeat.at) < repeat.hold) apply(repeat, -1);
    }
    if (jfg_test_start_button && player == 0) {
        static const uint64_t begin = SDL_GetTicks64();
        static unsigned reported_pulse = 0;
        const uint64_t elapsed = SDL_GetTicks64() - begin;
        // Hold START long enough to cross several N64 controller polls. This
        // opt-in test bypasses desktop focus and short injected key presses.
        const unsigned pulse = (elapsed >= 12000 && elapsed < 12500) ? 1 :
            ((elapsed >= 22000 && elapsed < 22500) ? 2 : 0);
        if (pulse) {
            if (!connected) { *buttons = 0; *x = *y = 0; }
            *buttons |= 0x1000;
            connected = true;
            if (reported_pulse != pulse) {
                fprintf(stderr, "[JFG] Test controller: START pulse %u held for 500 ms.\n", pulse);
                reported_pulse = pulse;
            }
        }
    }
    if (player == 0 && connected) jfg_apply_mouse(buttons, x, y, script_lmb, script_rmb);
    return connected;
}

void on_launcher_init(recompui::LauncherMenu *menu) {
    auto game_options_menu = menu->init_game_options_menu(
        supported_games[0].game_id,
        supported_games[0].mod_game_id,
        supported_games[0].display_name,
        supported_games[0].thumbnail_bytes,
        recompui::GameOptionsMenuLayout::Center
    );

    game_options_menu->add_default_options();
    game_options_menu->set_width(30, recompui::Unit::Percent);

    for (auto option : game_options_menu->get_options()) {
        option->set_justify_content(recompui::JustifyContent::FlexEnd);
        option->set_border_radius(0);

        std::vector<recompui::Style *> hover_focus = {&option->hover_style, &option->focus_style};
        for (auto style : hover_focus) {
            style->set_background_color(recompui::theme::color::Transparent);
        }
    }

    recompui::Element *menu_container = menu->get_menu_container();
    menu_container->set_width(1440);
    menu_container->unset_left();
    menu_container->set_top(banjo::launcher_options_top_offset);
    menu_container->set_bottom(-banjo::launcher_options_top_offset);
    menu_container->set_right(50, recompui::Unit::Percent);
    menu_container->set_translate_2D(50.0f, 0.0f, recompui::Unit::Percent);

    game_options_menu->unset_left();
    game_options_menu->set_bottom(50.0f, recompui::Unit::Percent);
    game_options_menu->set_translate_2D(0.0f, 50.0f, recompui::Unit::Percent);
    game_options_menu->set_right(banjo::launcher_options_right_position_start);

    menu->remove_default_title();

    banjo::launcher_animation_setup(menu);
}

static void jfg_launcher_update(recompui::LauncherMenu *menu) {
    banjo::launcher_animation_update(menu);
    if (jfg_auto_start) {
        jfg_auto_start = false;
        auto game_id = supported_games[0].game_id;
        if (recomp::is_rom_valid(game_id)) {
            recompui::update_game_mod_id(supported_games[0].mod_game_id);
            recomp::start_game(game_id, {});
            recompui::hide_all_contexts();
            fprintf(stderr, "[JFG] Automatic game start requested.\n");
        }
        else {
            fprintf(stderr, "[JFG] --start-game requires an imported, validated ROM.\n");
        }
    }
}

#define REGISTER_FUNC(name) recomp::overlays::register_base_export(#name, name)

int main(int argc, char** argv) {
    // Preserve the last runtime messages even if a generated function faults.
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
    fprintf(stderr, "[JFG] Native startup reached.\n");
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--start-game") == 0) jfg_auto_start = true;
        if (strcmp(argv[i], "--jfg-level") == 0) {
            const char* name = (i + 1 < argc) ? argv[++i] : "";
            if (strcmp(name, "goldwood") == 0) {
                // Level and character that the verified run_to_goldwood route loads (JFG_TRACE_LEVEL, RECOMP.md):
                // 0x5D "Forest Day Sequence" with char 1. The name table is build/tmp/level_names.txt (decomp project).
                jfg_debug_level = 0x5D;
                jfg_debug_char = 1;
            } else {
                fprintf(stderr, "[JFG] Unknown --jfg-level '%s'. Supported: goldwood. Nothing started.\n", name);
                return EXIT_FAILURE;
            }
        }
        if (strcmp(argv[i], "--jfg-test-start") == 0) {
            const char* name = (i + 1 < argc) ? argv[++i] : "";
            if (strcmp(name, "goldwood") == 0) {
                // Char 1 (Juno): the character the verified route selects; its default start level is 0x16D.
                jfg_test_start_char = 1;
            } else if (strcmp(name, "goldwood-landing") == 0) {
                // Same, but directly to 0x5C "Forest Day Landing" (playable level), see jfg_change_level.
                jfg_test_start_char = 1;
                jfg_test_start_level = 0x5C;
            } else {
                fprintf(stderr, "[JFG] Unknown --jfg-test-start '%s'. Supported: goldwood, goldwood-landing. Nothing started.\n", name);
                return EXIT_FAILURE;
            }
            continue;
        }
        // Not implemented yet: refuse instead of silently ignoring the flag (exit code 2).
        if (strcmp(argv[i], "--jfg-skip-intro") == 0 || strcmp(argv[i], "--jfg-skip-cutscenes") == 0) {
            fprintf(stderr, "[JFG] %s is not implemented yet. Nothing started.\n", argv[i]);
            return 2;
        }
        if (strcmp(argv[i], "--test-start-button") == 0) {
            jfg_auto_start = true;
            jfg_test_start_button = true;
        }
    }
    if (jfg_test_start_char >= 0 && jfg_debug_level >= 0) {
        fprintf(stderr, "[JFG] --jfg-test-start and --jfg-level cannot be combined. Nothing started.\n");
        return EXIT_FAILURE;
    }
    (void)argc;
    (void)argv;
    recomp::Version project_version{};
    if (!recomp::Version::from_string(version_string, project_version)) {
        ultramodern::error_handling::message_box(("Invalid version string: " + version_string).c_str());
        return EXIT_FAILURE;
    }

    // Map this executable into memory and lock it, which should keep it in physical memory. This ensures
    // that there are no stutters from the OS having to load new pages of the executable whenever a new code page is run.
    PreloadContext preload_context;
    bool preloaded = preload_executable(preload_context);

    if (!preloaded) {
        fprintf(stderr, "Failed to preload executable!\n");
    }

    // Initialize random seed for icon easter egg.
    std::srand(std::time(nullptr));

#ifdef _WIN32
    // Set up high resolution timing period.
    timeBeginPeriod(1);

    // Process arguments.
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--show-console") == 0)
        {
            if (GetConsoleWindow() == nullptr)
            {
                AllocConsole();
                freopen("CONIN$", "r", stdin);
                freopen("CONOUT$", "w", stderr);
                freopen("CONOUT$", "w", stdout);
            }

            break;
        }
    }

    // Set up console output to accept UTF-8 on windows
    SetConsoleOutputCP(CP_UTF8);

    // Change to a font that supports Japanese characters
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"NSimSun");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
#endif

#ifdef _WIN32
    // Force wasapi on Windows, as there seems to be some issue with sample queueing with directsound currently.
    SDL_setenv("SDL_AUDIODRIVER", "wasapi", true);
#endif

#if defined(__linux__) && defined(RECOMP_FLATPAK)
    // When using Flatpak, applications tend to launch from the home directory by default.
    // Mods might use the current working directory to store the data, so we switch it to a directory
    // with persistent data storage and write permissions under Flatpak to ensure it works.
    std::error_code ec;
    std::filesystem::current_path("/var/data", ec);
#endif

    // Initialize native file dialogs.
    NFD_Init();

    // Initialize program settings.
    recompui::programconfig::set_program_name(banjo::program_name);
    recompui::programconfig::set_program_id(banjo::program_id);
    
    // Initialize SDL audio and set the output frequency.
    SDL_InitSubSystem(SDL_INIT_AUDIO);
    if (!reset_audio(48000)) {
        // It is not possible to initialize without an audio device.
        return EXIT_FAILURE;
    }

    // Source controller mappings file
    std::u8string controller_db_path = (recompui::file::get_program_path() / "recompcontrollerdb.txt").u8string();
    if (SDL_GameControllerAddMappingsFromFile(reinterpret_cast<const char *>(controller_db_path.c_str())) < 0) {
        fprintf(stderr, "Failed to load controller mappings: %s\n", SDL_GetError());
    }

    // Register fonts.
    recompui::register_primary_font("InterVariable.ttf", "Inter Variable");
    recompui::register_extra_font("Suplexmentary Comic NC.ttf");

    // Register configuration path.
    recomp::register_config_path(recompui::file::get_app_folder_path());

    // Register supported games and patches
    for (const auto& game : supported_games) {
        recomp::register_game(game);
    }

    recomp::mods::register_deprecated_mod("bk_recomp_mod_fov_slider", recomp::mods::DeprecationStatus::BrokenVersion, recomp::Version(1, 1, 0));

    REGISTER_FUNC(recomp_get_window_resolution);
    REGISTER_FUNC(recomp_get_target_aspect_ratio);
    REGISTER_FUNC(recomp_get_target_framerate);
    REGISTER_FUNC(recomp_get_cutscene_aspect_ratio);
    REGISTER_FUNC(recomp_get_analog_cam_enabled);
    REGISTER_FUNC(recomp_get_right_analog_inputs);
    REGISTER_FUNC(recomp_get_bgm_volume);
    // REGISTER_FUNC(recomp_get_gyro_deltas);
    // REGISTER_FUNC(recomp_get_mouse_deltas);
    REGISTER_FUNC(recomp_get_inverted_axes);
    REGISTER_FUNC(recomp_get_analog_inverted_axes);
    recompui::register_ui_exports();
    recomputil::register_data_api_exports();
    recomptheme::set_custom_theme();

    banjo::register_bk_overlays();
    banjo::register_bk_patches();

    // Register extensions for two types: Props and ActorMarkers.
    recomputil::init_extended_object_data(2);

    recompinput::players::set_single_player_mode(true);

    banjo::init_config();

    recompui::register_launcher_init_callback(on_launcher_init);
    recompui::register_launcher_update_callback(jfg_launcher_update);

    recomp::rsp::callbacks_t rsp_callbacks{
        .get_rsp_microcode = get_rsp_microcode,
    };

    ultramodern::renderer::callbacks_t renderer_callbacks{
        .create_render_context = [](uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
            auto presentation_mode = ultramodern::renderer::PresentationMode::PresentEarly;
            return recompui::renderer::create_render_context(rdram, window_handle, presentation_mode, developer_mode);
        },
    };

    ultramodern::gfx_callbacks_t gfx_callbacks{
        .create_gfx = create_gfx,
        .create_window = create_window,
        .update_gfx = update_gfx,
    };

    ultramodern::audio_callbacks_t audio_callbacks{
        .queue_samples = queue_samples,
        .get_frames_remaining = get_frames_remaining,
        .set_frequency = set_frequency,
    };

    ultramodern::input::callbacks_t input_callbacks{
        .poll_input = jfg_poll_inputs,
        .get_input = jfg_get_input,
        .set_rumble = recompinput::set_rumble,
        .get_connected_device_info = get_connected_device_info,
    };

    ultramodern::events::callbacks_t thread_callbacks{
        .vi_callback = recompinput::update_rumble,
        .gfx_init_callback = nullptr,
    };

    ultramodern::error_handling::callbacks_t error_handling_callbacks{
        .message_box = recompui::message_box,
    };

    ultramodern::threads::callbacks_t threads_callbacks{
        .get_game_thread_name = banjo::get_game_thread_name,
    };

    // Register the texture pack content type with rt64.json as its content file.
    recomp::mods::ModContentType texture_pack_content_type{
        .content_filename = "rt64.json",
        .allow_runtime_toggle = true,
        .on_enabled = enable_texture_pack,
        .on_disabled = disable_texture_pack,
        .on_reordered = reorder_texture_pack,
    };
    auto texture_pack_content_type_id = recomp::mods::register_mod_content_type(texture_pack_content_type);

    // Register the .rtz texture pack file format with the previous content type as its only allowed content type.
    recomp::mods::register_mod_container_type("rtz", std::vector{ texture_pack_content_type_id }, false);

    recomp::start(
        project_version,
        {},
        rsp_callbacks,
        renderer_callbacks,
        audio_callbacks,
        input_callbacks,
        gfx_callbacks,
        thread_callbacks,
        error_handling_callbacks,
        threads_callbacks
    );

    NFD_Quit();

    if (preloaded) {
        release_preload(preload_context);
    }

#ifdef _WIN32
    // End high resolution timing period.
    timeEndPeriod(1);
#endif

    return EXIT_SUCCESS;
}
