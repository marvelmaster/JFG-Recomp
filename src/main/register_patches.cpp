#include "ovl_patches.hpp"

#include "librecomp/overlays.hpp"
#include "librecomp/game.hpp"
#include "librecomp/sections.h"

// JFG: no function patches / mod exports yet. Everything is registered empty so the runtime is happy.
extern "C" {
    extern const char bk_patches_bin[];
    extern const size_t bk_patches_bin_size;
}

static FunctionExport export_table[] = { { nullptr, 0 } };
static const char* event_names[] = { nullptr };
static ManualPatchSymbol manual_patch_symbols[] = { { 0, nullptr } };

void banjo::register_bk_patches() {
    recomp::overlays::register_patches(bk_patches_bin, bk_patches_bin_size, nullptr, 0);
    recomp::overlays::register_base_exports(export_table);
    recomp::overlays::register_base_events(event_names);
    recomp::overlays::register_manual_patch_symbols(manual_patch_symbols);
}
