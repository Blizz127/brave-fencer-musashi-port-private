#ifndef BFM_PLAT_H
#define BFM_PLAT_H

/* Brave Fencer Musashi port platform layer: the one header game code needs.
 *
 *   game C  ->  bfm_plat_* (this layer)  ->  backends (PsyCross, in-house
 *                                             HLE, null, later GL/Vulkan)
 *
 * Lifecycle:
 *   BfmPlatConfig cfg; bfm_plat_config_defaults(&cfg);
 *   bfm_plat_config_load_file(&cfg, path); bfm_plat_config_apply_args(...);
 *   bfm_plat_init(&cfg);                    opens backends, console, mods
 *   bfm_plat_guest_memory_bind(&ram);       once guest RAM exists
 *   per game frame:
 *     bfm_plat_frame_begin();               input poll, hotkeys, FRAME_BEGIN
 *     ... game logic, renderer calls ...
 *     bfm_plat_frame_end(vsync_fields);     FRAME_END (cheats), present, pace
 *   bfm_plat_shutdown(); */

#include "bfm_plat_types.h"
#include "bfm_plat_config.h"
#include "bfm_plat_renderer.h"
#include "bfm_plat_audio.h"
#include "bfm_plat_input.h"
#include "bfm_plat_storage.h"
#include "bfm_plat_timing.h"
#include "bfm_plat_mods.h"
#include "bfm_plat_console.h"
#include "bfm_plat_console_ui.h"
#include "bfm_plat_events.h"

typedef struct BfmPlatStatus {
    const char *renderer;
    const char *audio;
    const char *input;
    const char *storage;         /* NULL until a disc is open */
    int mods_loaded;
    uint64_t frames;
} BfmPlatStatus;

/* Backend registration hook: backends compiled into the executable
 * (PsyCross, SDL audio, ...) register from here before selection. Defined
 * weakly-by-convention in bfm_plat_backends.c; returns count registered. */
int bfm_plat_register_builtin_backends(void);

/* The config is copied; the copy is what the console "set"/"get" edits and
 * what plugins read. The disc is opened only if cfg->disc_path is set. */
int bfm_plat_init(const BfmPlatConfig *cfg);
void bfm_plat_shutdown(void);
BfmPlatConfig *bfm_plat_config(void);

int bfm_plat_frame_begin(void);
int bfm_plat_frame_end(unsigned vsync_fields);
void bfm_plat_status(BfmPlatStatus *out);

/* Events the runtime emits from the native dispatch table. */
void bfm_plat_event_room_enter(uint32_t area, uint32_t room);
void bfm_plat_event_room_exit(uint32_t area, uint32_t room);
void bfm_plat_event_battle(int start, uint32_t encounter, int32_t result);
void bfm_plat_event_item_get(uint32_t item, int32_t count);
void bfm_plat_event_save(int load, uint32_t slot);

#endif
