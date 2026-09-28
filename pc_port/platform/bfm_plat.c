#include "bfm_plat.h"

#include <string.h>

static BfmPlatConfig cfg_copy;
static int up;
static int mods_loaded;
static uint64_t frames;

const char *bfm_plat_result_name(int r) {
    switch (r) {
    case BFM_PLAT_OK: return "ok";
    case BFM_PLAT_ERROR: return "error";
    case BFM_PLAT_UNSUPPORTED: return "unsupported";
    case BFM_PLAT_INVALID: return "invalid";
    case BFM_PLAT_NOT_FOUND: return "not found";
    case BFM_PLAT_NO_SPACE: return "no space";
    case BFM_PLAT_NOT_READY: return "not ready";
    }
    return "unknown";
}

static const char *config_lookup(const char *key) {
    return bfm_plat_config_get(&cfg_copy, key);
}

static void output_from_config(BfmPlatOutput *o) {
    memset(o, 0, sizeof *o);
    o->window_width = cfg_copy.window_width;
    o->window_height = cfg_copy.window_height;
    o->internal_scale = cfg_copy.internal_scale;
    bfm_plat_config_aspect(&cfg_copy, &o->aspect_num, &o->aspect_den);
    o->frame_rate = cfg_copy.frame_rate;
    o->fullscreen = cfg_copy.fullscreen;
    o->vsync = cfg_copy.vsync;
}

int bfm_plat_init(const BfmPlatConfig *cfg) {
    BfmPlatOutput out;
    int r;
    if (up) bfm_plat_shutdown();
    if (cfg) cfg_copy = *cfg;
    else bfm_plat_config_defaults(&cfg_copy);
    bfm_plat_register_builtin_backends();
    output_from_config(&out);
    r = bfm_plat_renderer_open(cfg_copy.renderer, &out, NULL);
    if (r != BFM_PLAT_OK) return r;
    r = bfm_plat_audio_open(cfg_copy.audio, NULL);
    if (r != BFM_PLAT_OK) return r;
    r = bfm_plat_input_open(cfg_copy.input, NULL);
    if (r != BFM_PLAT_OK) return r;
    bfm_plat_timing_init();
    bfm_plat_timing_set_fast_forward_speed(cfg_copy.fast_forward_speed);
    bfm_plat_memcard_set_dir(cfg_copy.save_dir);
    if (cfg_copy.disc_path[0]) {
        r = bfm_plat_disc_open(cfg_copy.storage, cfg_copy.disc_path);
        if (r != BFM_PLAT_OK) return r;
    }
    bfm_plat_mods_set_config_getter(config_lookup);
    bfm_plat_console_init(&cfg_copy);
    mods_loaded = 0;
    if (cfg_copy.mods_enabled) {
        BfmPlatModsOptions mo;
        memset(&mo, 0, sizeof mo);
        mo.dirs = cfg_copy.mod_dirs;
        mo.allow_plugins = 1;
        mo.dump_textures = cfg_copy.dump_textures;
        mo.dump_dir = cfg_copy.dump_dir;
        r = bfm_plat_mods_init(&mo);
        mods_loaded = r > 0 ? r : 0;
    }
    frames = 0;
    up = 1;
    return BFM_PLAT_OK;
}

void bfm_plat_shutdown(void) {
    bfm_plat_mods_shutdown();
    bfm_plat_console_shutdown();
    bfm_plat_disc_close();
    bfm_plat_input_close();
    bfm_plat_audio_close();
    bfm_plat_renderer_close();
    bfm_plat_mods_set_config_getter(NULL);
    up = 0;
}

BfmPlatConfig *bfm_plat_config(void) { return &cfg_copy; }

static void handle_hotkeys(void) {
    uint32_t held = bfm_plat_input_hotkeys();
    uint32_t pressed = bfm_plat_input_hotkeys_pressed();
    if (cfg_copy.fast_forward_toggle) {
        if (pressed & BFM_HOTKEY_FAST_FORWARD)
            bfm_plat_timing_set_fast_forward(!bfm_plat_timing_fast_forward());
    } else {
        bfm_plat_timing_set_fast_forward((held & BFM_HOTKEY_FAST_FORWARD) != 0);
    }
    if (pressed & BFM_HOTKEY_CHEAT_MENU)
        bfm_plat_cheat_menu_open(!bfm_plat_cheat_menu_is_open());
}

int bfm_plat_frame_begin(void) {
    int r;
    if (!up) return BFM_PLAT_NOT_READY;
    r = bfm_plat_input_poll();
    if (r != BFM_PLAT_OK) return r;
    handle_hotkeys();
    bfm_plat_renderer_begin_frame();
    bfm_plat_mods_emit(BFM_EVENT_FRAME_BEGIN, NULL);
    return BFM_PLAT_OK;
}

int bfm_plat_frame_end(unsigned fields) {
    int r;
    if (!up) return BFM_PLAT_NOT_READY;
    bfm_plat_mods_emit(BFM_EVENT_FRAME_END, NULL);
    bfm_plat_cheat_menu_draw();
    r = bfm_plat_renderer_present();
    bfm_plat_timing_vsync(fields ? fields : 1);
    frames++;
    return r;
}

void bfm_plat_status(BfmPlatStatus *s) {
    if (!s) return;
    s->renderer = bfm_plat_renderer_active();
    s->audio = bfm_plat_audio_active();
    s->input = bfm_plat_input_active();
    s->storage = bfm_plat_disc_backend();
    s->mods_loaded = mods_loaded;
    s->frames = frames;
}

void bfm_plat_event_room_enter(uint32_t area, uint32_t room) {
    BfmEventRoom e;
    e.area = area;
    e.room = room;
    bfm_plat_mods_emit(BFM_EVENT_ROOM_ENTER, &e);
}

void bfm_plat_event_room_exit(uint32_t area, uint32_t room) {
    BfmEventRoom e;
    e.area = area;
    e.room = room;
    bfm_plat_mods_emit(BFM_EVENT_ROOM_EXIT, &e);
}

void bfm_plat_event_battle(int start, uint32_t encounter, int32_t result) {
    BfmEventBattle e;
    e.encounter = encounter;
    e.result = start ? 0 : result;
    bfm_plat_mods_emit(start ? BFM_EVENT_BATTLE_START : BFM_EVENT_BATTLE_END, &e);
}

void bfm_plat_event_item_get(uint32_t item, int32_t count) {
    BfmEventItem e;
    e.item = item;
    e.count = count;
    bfm_plat_mods_emit(BFM_EVENT_ITEM_GET, &e);
}
