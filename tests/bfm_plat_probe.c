/* Probe for the bfm_plat platform layer (no SDL). Driven by
 * tests/test_bfm_plat.py: `bfm_plat_probe GROUP [ARGS...]` prints
 * "ok GROUP" on success, or "FAIL file:line: expr" and exits 1. */
#include "bfm_plat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(e) do { if (!(e)) { \
    printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #e); exit(1); } } while (0)

static void reset_all(void) {
    bfm_plat_shutdown();
    bfm_plat_mods_reset();
    bfm_plat_console_reset();
    bfm_plat_renderer_reset();
    bfm_plat_audio_reset();
    bfm_plat_input_reset();
    bfm_plat_storage_reset();
    bfm_plat_timing_set_clock(NULL);
    bfm_plat_hooks_reset();
    bfm_plat_console_ui_reset();
}

/* ------------------------------------------------------------ guest RAM */
static uint8_t ram[2u * 1024u * 1024u];
static int ram_read(void *u, uint32_t a, void *out, uint32_t n) {
    (void)u;
    a &= 0x1FFFFFu;
    if (a + n > sizeof ram) return BFM_PLAT_INVALID;
    memcpy(out, ram + a, n);
    return BFM_PLAT_OK;
}
static int ram_write(void *u, uint32_t a, const void *d, uint32_t n) {
    (void)u;
    a &= 0x1FFFFFu;
    if (a + n > sizeof ram) return BFM_PLAT_INVALID;
    memcpy(ram + a, d, n);
    return BFM_PLAT_OK;
}
static void bind_ram(void) {
    BfmPlatGuestMemory m;
    m.read = ram_read;
    m.write = ram_write;
    m.user = NULL;
    bfm_plat_guest_memory_bind(&m);
}

/* ------------------------------------------------------------- config */
static int group_config(int argc, char **argv) {
    BfmPlatConfig c;
    char path[600];
    const char *text =
        "; comment\n[video]\nwidescreen = yes\ninternal_scale = 3\n"
        "frame_rate = 60\n[timing]\nfast_forward_speed = 8\n"
        "[backends]\nrenderer = null\n[mod.hello]\ngreeting = hi there\n"
        "[video]\ninternal_scale = 99\nbroken line\n";
    CHECK(argc >= 1);
    bfm_plat_config_defaults(&c);
    CHECK(c.widescreen == 0 && c.internal_scale == 1 && c.frame_rate == 30);
    CHECK(strcmp(c.renderer, "psycross") == 0 && c.mods_enabled == 1);
    CHECK(bfm_plat_config_load_string(&c, text) == BFM_PLAT_OK);
    CHECK(c.widescreen == 1 && c.internal_scale == 3 && c.frame_rate == 60);
    CHECK(c.fast_forward_speed == 8.0);
    CHECK(strcmp(c.renderer, "null") == 0);
    CHECK(c.rejected_values == 1);           /* scale 99 kept 3 */
    CHECK(c.bad_line == 14);
    CHECK(strcmp(bfm_plat_config_get(&c, "mod.hello.greeting"), "hi there") == 0);
    {
        int n, d;
        bfm_plat_config_aspect(&c, &n, &d);
        CHECK(n == 16 && d == 9);
    }
    CHECK(bfm_plat_config_set(&c, "video.frame_rate", "45") == BFM_PLAT_INVALID);
    CHECK(c.frame_rate == 60);
    CHECK(bfm_plat_config_set(&c, "backends.audio", "Bad Name") == BFM_PLAT_INVALID);
    {
        char *args[] = {"prog", "--fps", "30", "--keep-me", "--set",
                        "debug.log_level=4", "--no-mods", "--renderer", "hle"};
        unsigned char used[9] = {0};
        CHECK(bfm_plat_config_apply_args(&c, 9, args, used) == BFM_PLAT_OK);
        CHECK(c.frame_rate == 30 && c.log_level == 4 && c.mods_enabled == 0);
        CHECK(strcmp(c.renderer, "hle") == 0);
        CHECK(used[1] && used[2] && !used[3] && used[4] && used[5] && used[6]);
    }
    {
        char *bad[] = {"prog", "--scale"};
        CHECK(bfm_plat_config_apply_args(&c, 2, bad, NULL) == BFM_PLAT_INVALID);
    }
    /* save + reload round trip, including the plugin section */
    snprintf(path, sizeof path, "%s/saved.ini", argv[0]);
    CHECK(bfm_plat_config_save_file(&c, path) == BFM_PLAT_OK);
    {
        BfmPlatConfig r;
        bfm_plat_config_defaults(&r);
        CHECK(bfm_plat_config_load_file(&r, path) == BFM_PLAT_OK);
        CHECK(r.widescreen == 1 && r.internal_scale == 3 && r.frame_rate == 30);
        CHECK(r.log_level == 4 && r.mods_enabled == 0 && r.bad_line == 0);
        CHECK(strcmp(r.renderer, "hle") == 0);
        CHECK(strcmp(bfm_plat_config_get(&r, "mod.hello.greeting"), "hi there") == 0);
        /* --config is applied before other overrides */
        {
            char *args[] = {"prog", "--scale", "2", "--config", path};
            bfm_plat_config_defaults(&r);
            CHECK(bfm_plat_config_apply_args(&r, 5, args, NULL) == BFM_PLAT_OK);
            CHECK(r.internal_scale == 2 && r.widescreen == 1);
        }
    }
    {
        BfmPlatConfig r;
        bfm_plat_config_defaults(&r);
        CHECK(bfm_plat_config_load_file(&r, "/nonexistent/x.ini") == BFM_PLAT_NOT_FOUND);
    }
    CHECK(bfm_plat_config_default_path(path, sizeof path) == BFM_PLAT_OK);
    printf("path %s\n", path);
    return 0;
}

/* ----------------------------------------------------------- renderer */
static int group_renderer(void) {
    BfmPlatOutput o;
    BfmPlatRect r = {100, 50, 4, 2};
    uint16_t px[8] = {1, 2, 3, 4, 5, 6, 7, 8}, back[8];
    BfmPlatRendererStats st;
    BfmPlatPrim p[2];
    const char *sel = NULL;
    reset_all();
    memset(&o, 0, sizeof o);
    CHECK(bfm_plat_renderer_upload_vram(&r, px) == BFM_PLAT_NOT_READY);
    CHECK(bfm_plat_renderer_open("psycross", &o, &sel) == BFM_PLAT_OK);
    CHECK(strcmp(sel, "null") == 0);          /* not built in: falls back */
    CHECK(bfm_plat_renderer_upload_vram(&r, px) == BFM_PLAT_OK);
    CHECK(bfm_plat_renderer_download_vram(&r, back) == BFM_PLAT_OK);
    CHECK(memcmp(px, back, sizeof px) == 0);
    {
        BfmPlatRect bad = {1020, 0, 8, 1}, empty = {0, 0, 0, 1};
        CHECK(bfm_plat_renderer_upload_vram(&bad, px) == BFM_PLAT_INVALID);
        CHECK(bfm_plat_renderer_upload_vram(&empty, px) == BFM_PLAT_INVALID);
    }
    memset(p, 0, sizeof p);
    p[0].kind = BFM_PRIM_POLY_FT4;
    p[1].kind = BFM_PRIM_FILL;
    p[1].v[0].x = 100; p[1].v[0].y = 50; p[1].w = 2; p[1].h = 1;
    p[1].v[0].r = 0xF8; p[1].v[0].g = 0; p[1].v[0].b = 0;
    CHECK(bfm_plat_renderer_submit(p, 2) == BFM_PLAT_OK);
    CHECK(bfm_plat_renderer_download_vram(&r, back) == BFM_PLAT_OK);
    CHECK(back[0] == 0x1F && back[1] == 0x1F && back[2] == 3);
    p[0].kind = 99;
    CHECK(bfm_plat_renderer_submit(p, 1) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_renderer_present() == BFM_PLAT_OK);
    bfm_plat_renderer_stats(&st);
    CHECK(st.uploads == 1 && st.downloads == 2 && st.prims == 2 && st.frames == 1);
    CHECK(st.prims_by_kind[BFM_PRIM_POLY_FT4] == 1);
    return 0;
}

/* Upload a known texture; the mods dir holds a replacement for it. */
static int group_texture_keep(int argc, char **argv) {
    BfmPlatModsOptions mo;
    BfmPlatOutput o;
    BfmPlatRect r = {0, 0, 2, 2};
    uint16_t px[4] = {0x1234, 0x0001, 0x7FFF, 0x0000}, back[4];
    BfmPlatRendererStats st;
    char hex[17];
    CHECK(argc >= 1);
    bfm_plat_hash_hex(bfm_plat_texture_hash(&r, px), hex);
    printf("hash %s\n", hex);
    memset(&mo, 0, sizeof mo);
    mo.dirs = argv[0];
    if (argc >= 2) { mo.dump_textures = 1; mo.dump_dir = argv[1]; }
    CHECK(bfm_plat_mods_init(&mo) >= 0);
    memset(&o, 0, sizeof o);
    CHECK(bfm_plat_renderer_open("null", &o, NULL) == BFM_PLAT_OK);
    CHECK(bfm_plat_renderer_upload_vram(&r, px) == BFM_PLAT_OK);
    CHECK(bfm_plat_renderer_download_vram(&r, back) == BFM_PLAT_OK);
    bfm_plat_renderer_stats(&st);
    printf("vram %04x %04x %04x %04x replaced %u\n", back[0], back[1], back[2],
           back[3], (unsigned)st.replaced_uploads);
    return 0;
}

static int group_texture(int argc, char **argv) {
    reset_all();
    return group_texture_keep(argc, argv);
}

/* -------------------------------------------------------------- input */
static int group_input(void) {
    BfmPlatPad pad, out;
    uint8_t wire[8];
    BfmPlatConfig c;
    reset_all();
    CHECK(bfm_plat_input_open("null", NULL) == BFM_PLAT_OK);
    memset(&pad, 0, sizeof pad);
    pad.connected = 1;
    pad.buttons = BFM_PAD_CROSS | BFM_PAD_START;
    bfm_plat_input_scripted_set(0, &pad);
    CHECK(bfm_plat_input_poll() == BFM_PLAT_OK);
    CHECK(bfm_plat_input_pad(0, &out) == BFM_PLAT_OK && out.buttons == pad.buttons);
    CHECK(bfm_plat_input_pad(2, &out) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_pad_to_wire(&out, wire) == 4);
    CHECK(wire[0] == 0x41 && wire[1] == 0x5A && wire[2] == 0xF7 && wire[3] == 0xBF);
    pad.analog = 1; pad.lx = 1; pad.ly = 2; pad.rx = 3; pad.ry = 4;
    CHECK(bfm_plat_pad_to_wire(&pad, wire) == 8);
    CHECK(wire[0] == 0x73 && wire[4] == 3 && wire[5] == 4 && wire[6] == 1 && wire[7] == 2);
    pad.connected = 0;
    CHECK(bfm_plat_pad_to_wire(&pad, wire) == 0);
    bfm_plat_input_scripted_hotkeys(BFM_HOTKEY_CONSOLE);
    CHECK(bfm_plat_input_poll() == BFM_PLAT_OK);
    CHECK(bfm_plat_input_hotkeys_pressed() == BFM_HOTKEY_CONSOLE);
    CHECK(bfm_plat_input_poll() == BFM_PLAT_OK);
    CHECK(bfm_plat_input_hotkeys_pressed() == 0 && bfm_plat_input_hotkeys() == BFM_HOTKEY_CONSOLE);

    /* Hotkeys through the frame loop: fast-forward hold, then toggle mode,
     * cheat menu toggle. */
    reset_all();
    bfm_plat_config_defaults(&c);
    c.mods_enabled = 0;
    strcpy(c.input, "null");
    CHECK(bfm_plat_init(&c) == BFM_PLAT_OK);
    {
        BfmPlatClock fake;
        extern uint64_t probe_now(void *);
        extern void probe_sleep(void *, uint64_t);
        fake.now_ns = probe_now; fake.sleep_ns = probe_sleep; fake.user = NULL;
        bfm_plat_timing_set_clock(&fake);
    }
    bfm_plat_input_scripted_hotkeys(BFM_HOTKEY_FAST_FORWARD);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(bfm_plat_timing_fast_forward() == 1);
    bfm_plat_input_scripted_hotkeys(0);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(bfm_plat_timing_fast_forward() == 0);
    bfm_plat_config()->fast_forward_toggle = 1;
    bfm_plat_input_scripted_hotkeys(BFM_HOTKEY_FAST_FORWARD | BFM_HOTKEY_CHEAT_MENU);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    bfm_plat_input_scripted_hotkeys(0);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(bfm_plat_timing_fast_forward() == 1 && bfm_plat_cheat_menu_is_open());
    CHECK(bfm_plat_frame_end(1) == BFM_PLAT_OK);
    return 0;
}

/* ------------------------------------------------------------- timing */
static uint64_t fake_ns;
static uint64_t slept_total;
uint64_t probe_now(void *u) { (void)u; return fake_ns; }
void probe_sleep(void *u, uint64_t ns) { (void)u; fake_ns += ns; slept_total += ns; }

static int group_timing(void) {
    BfmPlatClock c;
    BfmPlatTimingStats st;
    uint64_t start;
    reset_all();
    c.now_ns = probe_now; c.sleep_ns = probe_sleep; c.user = NULL;
    fake_ns = 1000000000ull;
    bfm_plat_timing_set_clock(&c);
    bfm_plat_timing_init();
    start = fake_ns;
    CHECK(bfm_plat_timing_vsync(2) == 2);
    CHECK(fake_ns - start == 2 * BFM_PLAT_NTSC_FIELD_NS);
    /* Game work that takes half a field shortens the next wait. */
    fake_ns += BFM_PLAT_NTSC_FIELD_NS / 2;
    CHECK(bfm_plat_timing_vsync(1) == 1);
    CHECK(fake_ns - start == 3 * BFM_PLAT_NTSC_FIELD_NS);
    /* Far behind: resync rather than race. */
    fake_ns += 10 * BFM_PLAT_NTSC_FIELD_NS;
    slept_total = 0;
    bfm_plat_timing_vsync(1);
    CHECK(slept_total == 0);
    bfm_plat_timing_vsync(1);
    CHECK(slept_total == BFM_PLAT_NTSC_FIELD_NS);
    /* Fast-forward 4x: a field costs a quarter. */
    bfm_plat_timing_set_fast_forward_speed(4.0);
    bfm_plat_timing_set_fast_forward(1);
    slept_total = 0;
    bfm_plat_timing_vsync(1);
    bfm_plat_timing_vsync(1);
    CHECK(slept_total == 2 * (BFM_PLAT_NTSC_FIELD_NS / 4));
    /* Uncapped. */
    bfm_plat_timing_set_fast_forward_speed(0.0);
    slept_total = 0;
    bfm_plat_timing_vsync(3);
    CHECK(slept_total == 0);
    bfm_plat_timing_stats(&st);
    CHECK(st.fast_forward == 1 && st.resyncs == 1 && st.vsyncs == 10);
    CHECK(bfm_plat_mods_event_count(BFM_EVENT_VSYNC) == 10);
    return 0;
}

/* -------------------------------------------------------------- audio */
static int group_audio(void) {
    int16_t pcm[2 * 256];
    BfmPlatAudioStatus st;
    const char *sel;
    reset_all();
    memset(pcm, 0, sizeof pcm);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_MAIN, pcm, 256) == BFM_PLAT_NOT_READY);
    CHECK(bfm_plat_audio_open("sdl", &sel) == BFM_PLAT_OK && strcmp(sel, "null") == 0);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_MAIN, pcm, 256) == BFM_PLAT_OK);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_CD, pcm, 100) == BFM_PLAT_OK);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_COUNT, pcm, 1) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_MAIN, NULL, 1) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_MAIN, pcm, BFM_PLAT_AUDIO_RATE) == BFM_PLAT_NO_SPACE);
    bfm_plat_audio_set_fast_forward(1);
    CHECK(bfm_plat_audio_queue(BFM_AUDIO_STREAM_MAIN, pcm, 256) == BFM_PLAT_OK);
    bfm_plat_audio_set_fast_forward(0);
    CHECK(bfm_plat_audio_set_volume(0.5f) == BFM_PLAT_OK);
    CHECK(bfm_plat_audio_set_volume(2.0f) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_audio_pause(1) == BFM_PLAT_OK);
    CHECK(bfm_plat_audio_status(&st) == BFM_PLAT_OK);
    CHECK(st.rate == 44100 && st.channels == 2 && st.playing == 0);
    CHECK(st.submitted_frames[0] == 256 && st.submitted_frames[1] == 100);
    CHECK(st.master_volume == 0.5f);
    return 0;
}

/* ------------------------------------------------------------ storage */
static int group_storage(int argc, char **argv) {
    uint32_t lba, size;
    uint8_t sec[2352];
    char buf[64];
    size_t got;
    BfmPlatDiscInfo info;
    CHECK(argc >= 3);           /* image path, expected file text, save dir */
    reset_all();
    CHECK(bfm_plat_disc_read(0, 1, BFM_DISC_READ_DATA, sec, sizeof sec) == BFM_PLAT_NOT_READY);
    CHECK(bfm_plat_disc_open("nope", argv[0]) == BFM_PLAT_NOT_FOUND);
    CHECK(bfm_plat_disc_open("image", "/nonexistent.bin") == BFM_PLAT_NOT_FOUND);
    CHECK(bfm_plat_disc_open("image", argv[0]) == BFM_PLAT_OK);
    CHECK(bfm_plat_disc_info(&info) == BFM_PLAT_OK);
    printf("sectors %u size %u tracks %u\n", info.sector_count, info.sector_size,
           info.track_count);
    CHECK(bfm_plat_disc_find_file("\\DATA\\HELLO.TXT;1", &lba, &size) == BFM_PLAT_OK);
    CHECK(size == strlen(argv[1]));
    CHECK(bfm_plat_disc_find_file("data/hello.txt", &lba, &size) == BFM_PLAT_OK);
    CHECK(bfm_plat_disc_find_file("DATA/MISSING.TXT", NULL, NULL) == BFM_PLAT_NOT_FOUND);
    CHECK(bfm_plat_disc_find_file("DATA", NULL, NULL) == BFM_PLAT_NOT_FOUND);
    CHECK(bfm_plat_disc_read_file("DATA/HELLO.TXT", buf, sizeof buf, &got) == BFM_PLAT_OK);
    CHECK(got == strlen(argv[1]) && memcmp(buf, argv[1], got) == 0);
    CHECK(bfm_plat_disc_read_file("DATA/HELLO.TXT", buf, 2, &got) == BFM_PLAT_NO_SPACE);
    if (info.sector_size == 2352) {
        CHECK(bfm_plat_disc_read(lba, 1, BFM_DISC_READ_RAW, sec, sizeof sec) == BFM_PLAT_OK);
        CHECK(sec[0] == 0 && sec[1] == 0xFF && sec[11] == 0);
        CHECK(memcmp(sec + 24, argv[1], strlen(argv[1])) == 0);
        CHECK(bfm_plat_disc_read(lba, 1, BFM_DISC_READ_NO_SYNC, sec, sizeof sec) == BFM_PLAT_OK);
        CHECK(memcmp(sec + 12, argv[1], strlen(argv[1])) == 0);
    } else {
        CHECK(bfm_plat_disc_read(lba, 1, BFM_DISC_READ_RAW, sec, sizeof sec) == BFM_PLAT_UNSUPPORTED);
    }
    CHECK(bfm_plat_disc_read(info.sector_count, 1, BFM_DISC_READ_DATA, sec, sizeof sec) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_disc_read(0, 2, BFM_DISC_READ_DATA, sec, sizeof sec) == BFM_PLAT_INVALID);
    {
        uint8_t m, s, f;
        bfm_plat_disc_lba_to_msf(0, &m, &s, &f);
        CHECK(m == 0 && s == 2 && f == 0);
        bfm_plat_disc_lba_to_msf(4500 - 150 + 1, &m, &s, &f);
        CHECK(m == 1 && s == 0 && f == 1);
        CHECK(bfm_plat_disc_msf_to_lba(1, 0, 1) == 4351);
    }
    /* memory cards */
    {
        static uint8_t card[BFM_MEMCARD_SIZE], back[BFM_MEMCARD_SIZE];
        unsigned i;
        CHECK(bfm_plat_memcard_set_dir(argv[2]) == BFM_PLAT_OK);
        CHECK(bfm_plat_memcard_load(0, back, sizeof back) == BFM_PLAT_NOT_FOUND);
        for (i = 0; i < sizeof card; i++) card[i] = (uint8_t)(i * 7u);
        CHECK(bfm_plat_memcard_save(1, card, sizeof card) == BFM_PLAT_OK);
        CHECK(bfm_plat_memcard_load(1, back, sizeof back) == BFM_PLAT_OK);
        CHECK(memcmp(card, back, sizeof card) == 0);
        CHECK(bfm_plat_memcard_save(2, card, sizeof card) == BFM_PLAT_INVALID);
        CHECK(bfm_plat_memcard_save(0, card, 100) == BFM_PLAT_INVALID);
    }
    return 0;
}

/* Disc file replacement: argv = image, mods dir; prints the bytes read. */
static int group_file_replace(int argc, char **argv) {
    BfmPlatModsOptions mo;
    char buf[128];
    size_t got;
    CHECK(argc >= 2);
    reset_all();
    CHECK(bfm_plat_disc_open("image", argv[0]) == BFM_PLAT_OK);
    memset(&mo, 0, sizeof mo);
    mo.dirs = argv[1];
    CHECK(bfm_plat_mods_init(&mo) >= 0);
    CHECK(bfm_plat_disc_read_file("DATA/HELLO.TXT", buf, sizeof buf - 1, &got) == BFM_PLAT_OK);
    buf[got] = '\0';
    printf("file %s\n", buf);
    return 0;
}

/* --------------------------------------------------------------- mods */
static unsigned boot_seen, rooms_seen;
static void on_boot(void *u, BfmEvent e, void *p) { (void)u; (void)e; (void)p; boot_seen++; }
static void on_room(void *u, BfmEvent e, void *p) {
    (void)u; (void)e;
    CHECK(((BfmEventRoom *)p)->room == 7);
    rooms_seen++;
}

static int static_inits;
static const BfmPluginHost *static_host;
static int static_init(const BfmPluginHost *h, BfmPluginInfo *info) {
    static_inits++;
    static_host = h;
    info->abi_version = BFM_PLUGIN_ABI_VERSION;
    return 0;
}

static int script_loads;
static char script_path[700];
static int fake_lua_load(const BfmPluginHost *h, const char *path) {
    (void)h;
    script_loads++;
    snprintf(script_path, sizeof script_path, "%s", path);
    return BFM_PLAT_OK;
}
static const BfmPlatScriptRuntime fake_lua = {"lua-test", ".lua", fake_lua_load, NULL};

static char log_buf[4096];
static void capture_log(const char *mod, int level, const char *msg) {
    size_t n = strlen(log_buf);
    (void)level;
    snprintf(log_buf + n, sizeof log_buf - n, "[%s] %s\n", mod, msg);
}

/* argv[0] = mods dir(s) prepared by pytest (hello plugin built as .so,
 * a static-plugin mod, a script mod, a disabled mod, a priority mod). */
static int group_mods(int argc, char **argv) {
    BfmPlatConfig c;
    char out[1024];
    unsigned i;
    BfmPlatPad pad, got;
    int sub;
    CHECK(argc >= 1);
    reset_all();
    bind_ram();
    CHECK(bfm_plat_mods_register_static_plugin("builtin_static", static_init, NULL) == BFM_PLAT_OK);
    CHECK(bfm_plat_mods_register_static_plugin("builtin_static", static_init, NULL) == BFM_PLAT_INVALID);
    CHECK(bfm_plat_mods_register_script_runtime(&fake_lua) == BFM_PLAT_OK);
    sub = bfm_plat_mods_subscribe(BFM_EVENT_BOOT, on_boot, NULL);
    CHECK(sub > 0);
    CHECK(bfm_plat_mods_subscribe(BFM_EVENT_COUNT, on_boot, NULL) == BFM_PLAT_INVALID);
    bfm_plat_mods_subscribe(BFM_EVENT_ROOM_ENTER, on_room, NULL);

    bfm_plat_config_defaults(&c);
    strcpy(c.mod_dirs, argv[0]);
    strcpy(c.renderer, "null");
    strcpy(c.audio, "null");
    strcpy(c.input, "null");
    CHECK(bfm_plat_config_load_string(&c, "[mod.hello]\ngreeting = howdy\n") == BFM_PLAT_OK);
    CHECK(bfm_plat_init(&c) == BFM_PLAT_OK);
    CHECK(boot_seen == 1);

    for (i = 0; i < bfm_plat_mods_count(); i++) {
        const BfmPlatModInfo *m = bfm_plat_mods_get(i);
        printf("mod %u %s prio=%d enabled=%d plugin=%d script=%d cheats=%u\n", i,
               m->name, m->priority, m->enabled, m->plugin_loaded,
               m->script_loaded, m->cheats);
    }
    CHECK(static_inits == 1 && static_host && strcmp(static_host->mod_name, "static") == 0);
    CHECK(static_host->abi_version == BFM_PLUGIN_ABI_VERSION &&
          static_host->size == sizeof(BfmPluginHost));
    CHECK(script_loads == 1 && strstr(script_path, "main.lua") != NULL);

    /* plugin console command + config section */
    CHECK(bfm_plat_console_exec("hello", out, sizeof out) == 0);
    printf("hello-reply %s\n", out);
    CHECK(bfm_plat_console_exec("nosuch", out, sizeof out) != 0);
    CHECK(bfm_plat_console_exec("help", out, sizeof out) == 0 && strstr(out, "hello -"));
    CHECK(bfm_plat_console_exec("cheats", out, sizeof out) == 0);
    CHECK(strstr(out, "turbo_cross") && strstr(out, "hp_lock"));

    /* frames + room events reach the plugin */
    bfm_plat_event_room_enter(3, 7);
    CHECK(rooms_seen == 1);
    for (i = 0; i < 5; i++) {
        CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
        CHECK(bfm_plat_frame_end(0) == BFM_PLAT_OK);
    }
    CHECK(bfm_plat_console_exec("hello", out, sizeof out) == 0);
    CHECK(strcmp(out, "howdy: 5 frames, 1 rooms") == 0);

    /* poke cheat from cheats.ini: enabled=1 in the manifest */
    ram[0x1234] = 0;
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(bfm_plat_frame_end(0) == BFM_PLAT_OK);
    CHECK(ram[0x1234] == 0x63 && ram[0x1235] == 0x00);
    CHECK(bfm_plat_console_exec("cheat hp_lock off", out, sizeof out) == 0);
    ram[0x1234] = 1;
    bfm_plat_frame_end(0);
    CHECK(ram[0x1234] == 1);

    /* peek / poke / get / set / ff */
    CHECK(bfm_plat_console_exec("poke 0x80001000 0xdeadbeef", out, sizeof out) == 0);
    CHECK(ram[0x1000] == 0xef && ram[0x1003] == 0xde);
    CHECK(bfm_plat_console_exec("peek 0x80001000 4", out, sizeof out) == 0);
    CHECK(strcmp(out, "80001000: ef be ad de") == 0);
    CHECK(bfm_plat_console_exec("poke 0x80001000 1 3", out, sizeof out) != 0);
    CHECK(bfm_plat_console_exec("get mod.hello.greeting", out, sizeof out) == 0);
    CHECK(strcmp(out, "mod.hello.greeting = howdy") == 0);
    CHECK(bfm_plat_console_exec("set video.frame_rate 60", out, sizeof out) == 0);
    CHECK(bfm_plat_config()->frame_rate == 60);
    CHECK(bfm_plat_console_exec("set video.frame_rate 50", out, sizeof out) != 0);
    CHECK(bfm_plat_console_exec("ff 2", out, sizeof out) == 0 && bfm_plat_timing_fast_forward());
    CHECK(bfm_plat_console_exec("ff", out, sizeof out) == 0 && !bfm_plat_timing_fast_forward());
    CHECK(bfm_plat_console_exec("mods", out, sizeof out) == 0 && strstr(out, "hello 1.0.0"));

    /* turbo cheat from the plugin edits input through BFM_EVENT_INPUT */
    memset(&pad, 0, sizeof pad);
    pad.connected = 1;
    pad.buttons = BFM_PAD_CROSS;
    bfm_plat_input_scripted_set(0, &pad);
    CHECK(bfm_plat_cheat_set("turbo_cross", 1) == BFM_PLAT_OK);
    {
        unsigned pressed = 0;
        for (i = 0; i < 4; i++) {
            bfm_plat_frame_begin();
            bfm_plat_input_pad(0, &got);
            pressed += (got.buttons & BFM_PAD_CROSS) != 0;
            bfm_plat_frame_end(0);
        }
        CHECK(pressed == 2);
    }

    /* cheat menu model */
    CHECK(bfm_plat_cheat_count() >= 2);
    bfm_plat_cheat_menu_move(-1);
    CHECK(bfm_plat_cheat_menu_selection() == bfm_plat_cheat_count() - 1);
    bfm_plat_cheat_menu_move(1);
    CHECK(bfm_plat_cheat_menu_selection() == 0);
    {
        int before = bfm_plat_cheat_get(0)->enabled;
        CHECK(bfm_plat_cheat_menu_toggle_selected() == BFM_PLAT_OK);
        CHECK(bfm_plat_cheat_get(0)->enabled == !before);
    }

    /* shutdown drops mod hooks + cheats but keeps ours; log captured */
    CHECK(bfm_plat_mods_unsubscribe(sub) == BFM_PLAT_OK);
    CHECK(bfm_plat_mods_unsubscribe(sub) == BFM_PLAT_NOT_FOUND);
    bfm_plat_shutdown();
    CHECK(bfm_plat_cheat_count() == 0);
    bfm_plat_mods_emit(BFM_EVENT_FRAME_END, NULL);   /* no dangling plugin hook */
    bfm_plat_event_room_enter(0, 7);
    CHECK(rooms_seen == 2);
    printf("ok-shutdown\n");

    /* no plugins allowed: native plugin refused, static still fine */
    {
        BfmPlatModsOptions mo;
        memset(&mo, 0, sizeof mo);
        mo.dirs = argv[0];
        mo.log = capture_log;
        mo.allow_plugins = 0;
        log_buf[0] = '\0';
        CHECK(bfm_plat_mods_init(&mo) >= 1);
        CHECK(strstr(log_buf, "hello_plugin' not found") != NULL);
        bfm_plat_mods_shutdown();
    }
    return 0;
}

static int group_hash(void) {
    char hex[17];
    bfm_plat_hash_hex(bfm_plat_hash64("", 0), hex);
    CHECK(strcmp(hex, "cbf29ce484222325") == 0);
    bfm_plat_hash_hex(bfm_plat_hash64("a", 1), hex);
    CHECK(strcmp(hex, "af63dc4c8601ec8c") == 0);
    bfm_plat_hash_hex(bfm_plat_hash64("foobar", 6), hex);
    CHECK(strcmp(hex, "85944171f73967e8") == 0);
    return 0;
}


/* ----------------------------------------------------------- bindings */
static int32_t fake_resolve(void *u, const char *dev, const char *name) {
    (void)u;
    if (strcmp(dev, "key") == 0 && strlen(name) == 1) return 0x100 + name[0];
    if (strcmp(dev, "key") == 0 && strcmp(name, "tab") == 0) return 9;
    if (strcmp(dev, "pad") == 0 && strcmp(name, "a") == 0) return 0x10000;
    return -1;
}

static int group_bindings(void) {
    BfmPlatConfig c;
    BfmPlatBinding b[128];
    size_t n = 0, bad = 0, i, targets;
    const BfmPlatBindingTarget *t;
    int found_cross = 0, found_ff = 0, found_p2 = 0;
    targets = bfm_plat_input_binding_targets(&t);
    CHECK(targets == 38);
    bfm_plat_config_defaults(&c);
    CHECK(bfm_plat_input_bindings_from_config(&c, fake_resolve, NULL, b, 128, &n, &bad) == BFM_PLAT_OK);
    /* p1 single-letter keys + tab + pad:a twice (p1, p2) resolve */
    for (i = 0; i < n; i++) {
        if (!b[i].is_hotkey && b[i].port == 0 && b[i].mask == BFM_PAD_CROSS && b[i].host_code == 0x100 + 'z') found_cross = 1;
        if (b[i].is_hotkey && b[i].mask == BFM_HOTKEY_FAST_FORWARD && b[i].host_code == 9) found_ff = 1;
        if (b[i].port == 1 && b[i].mask == BFM_PAD_CROSS && b[i].host_code == 0x10000) found_p2 = 1;
    }
    CHECK(found_cross && found_ff && found_p2);
    CHECK(bad > 0);
    bfm_plat_config_load_string(&c,
        "[input]\np1.cross = key:k, pad:a, bogus\np1.start =\nhotkey.console = key:c\n");
    CHECK(bfm_plat_input_bindings_from_config(&c, fake_resolve, NULL, b, 128, &n, &bad) == BFM_PLAT_OK);
    found_cross = 0;
    for (i = 0; i < n; i++) {
        CHECK(!(b[i].port == 0 && !b[i].is_hotkey && b[i].mask == BFM_PAD_START));
        if (!b[i].is_hotkey && b[i].port == 0 && b[i].mask == BFM_PAD_CROSS)
            found_cross += b[i].host_code == 0x100 + 'k' ? 1 : b[i].host_code == 0x10000 ? 2 : 100;
        if (b[i].is_hotkey && b[i].mask == BFM_HOTKEY_CONSOLE) CHECK(b[i].host_code == 0x100 + 'c');
    }
    CHECK(found_cross == 3);
    CHECK(bfm_plat_input_bindings_from_config(&c, fake_resolve, NULL, b, 2, &n, NULL) == BFM_PLAT_NO_SPACE);
    CHECK(n == 2);
    CHECK(bfm_plat_input_bindings_from_config(&c, NULL, NULL, b, 2, &n, NULL) == BFM_PLAT_INVALID);
    return 0;
}

/* --------------------------------------------------------- console UI */
static char overlay[32][160];
static int overlay_n;
static int cap_overlay(void *self, int x, int y, const char *text) {
    (void)self; (void)x; (void)y;
    if (overlay_n < 32) snprintf(overlay[overlay_n++], sizeof overlay[0], "%s", text);
    return BFM_PLAT_OK;
}
static int cap_ok(void *self) { (void)self; return BFM_PLAT_OK; }
static const BfmPlatRendererBackend capture_backend = {
    "capture", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    cap_ok, cap_overlay, NULL
};

static void type_text(const char *s) {
    char one[2] = {0, 0};
    for (; *s; s++) { one[0] = *s; bfm_plat_input_push_text(one); }
}

static int group_console_ui(void) {
    BfmPlatConfig c;
    BfmPlatPad pad, got;
    BfmPlatClock fake;
    int i;
    reset_all();
    CHECK(bfm_plat_renderer_register(&capture_backend) == BFM_PLAT_OK);
    bfm_plat_config_defaults(&c);
    c.mods_enabled = 0;
    strcpy(c.renderer, "capture");
    CHECK(bfm_plat_init(&c) == BFM_PLAT_OK);
    fake.now_ns = probe_now; fake.sleep_ns = probe_sleep; fake.user = NULL;
    bfm_plat_timing_set_clock(&fake);
    memset(&pad, 0, sizeof pad);
    pad.connected = 1;
    pad.buttons = BFM_PAD_CROSS;
    bfm_plat_input_scripted_set(0, &pad);

    /* Console hotkey opens it; text typed before opening is dropped. */
    type_text("junk");
    bfm_plat_input_scripted_hotkeys(BFM_HOTKEY_CONSOLE);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(bfm_plat_console_ui_is_open());
    CHECK(bfm_plat_input_pad(0, &got) == BFM_PLAT_OK && got.buttons == 0);
    bfm_plat_input_scripted_hotkeys(0);

    type_text("`get video.frame_rat");
    bfm_plat_input_push_key(BFM_KEY_BACKSPACE);
    type_text("te");
    bfm_plat_input_push_key(BFM_KEY_ENTER);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(strcmp(bfm_plat_console_ui_line(1), "> get video.frame_rate") == 0);
    CHECK(strcmp(bfm_plat_console_ui_line(0), "video.frame_rate = (unset)") == 0);

    /* history, cursor editing, completion */
    bfm_plat_input_push_key(BFM_KEY_UP);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(strcmp(bfm_plat_console_ui_input(), "get video.frame_rate") == 0);
    bfm_plat_input_push_key(BFM_KEY_DOWN);
    type_text("hel");
    bfm_plat_input_push_key(BFM_KEY_TAB);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(strcmp(bfm_plat_console_ui_input(), "help ") == 0);
    bfm_plat_input_push_key(BFM_KEY_LEFT);
    bfm_plat_input_push_key(BFM_KEY_LEFT);
    type_text("X");
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(strcmp(bfm_plat_console_ui_input(), "helXp ") == 0 && bfm_plat_console_ui_cursor() == 4);
    bfm_plat_input_push_key(BFM_KEY_RIGHT);
    bfm_plat_input_push_key(BFM_KEY_RIGHT);
    bfm_plat_input_push_key(BFM_KEY_RIGHT);   /* already at end: no-op */
    for (i = 0; i < 6; i++) bfm_plat_input_push_key(BFM_KEY_BACKSPACE);
    type_text("events");
    bfm_plat_input_push_key(BFM_KEY_ENTER);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(bfm_plat_console_ui_line_count() > 10);

    /* draw goes through overlay_text: scrollback then prompt */
    overlay_n = 0;
    CHECK(bfm_plat_frame_end(1) == BFM_PLAT_OK);
    CHECK(overlay_n == BFM_CONSOLE_UI_VISIBLE + 1);
    CHECK(strcmp(overlay[overlay_n - 1], "> _") == 0);

    /* long output wraps; Esc closes and releases the pads */
    {
        char longline[300];
        memset(longline, 'a', 250);
        longline[250] = '\0';
        i = (int)bfm_plat_console_ui_line_count();
        bfm_plat_console_ui_print(longline);
        CHECK(strlen(bfm_plat_console_ui_line(0)) == 250 - 2 * BFM_CONSOLE_UI_COLS);
    }
    bfm_plat_input_push_key(BFM_KEY_ESCAPE);
    CHECK(bfm_plat_frame_begin() == BFM_PLAT_OK);
    CHECK(!bfm_plat_console_ui_is_open());
    CHECK(bfm_plat_input_pad(0, &got) == BFM_PLAT_OK && got.buttons == BFM_PAD_CROSS);
    overlay_n = 0;
    bfm_plat_frame_end(1);
    CHECK(overlay_n == 0);

    /* [debug] console = 0 disables the hotkey */
    bfm_plat_config()->console = 0;
    bfm_plat_input_scripted_hotkeys(0);
    bfm_plat_frame_begin();
    bfm_plat_input_scripted_hotkeys(BFM_HOTKEY_CONSOLE);
    bfm_plat_frame_begin();
    CHECK(!bfm_plat_console_ui_is_open());
    return 0;
}

/* -------------------------------------------------------------- hooks */
static unsigned room_hits, item_hits;
static uint32_t last_room;
static void on_room_hook(void *u, BfmEvent e, void *p) {
    (void)u; (void)e;
    room_hits++;
    last_room = ((BfmEventRoom *)p)->room;
}
static void on_item_hook(void *u, BfmEvent e, void *p) {
    (void)u; (void)e;
    item_hits++;
    CHECK(((BfmEventItem *)p)->item == 0);
}
static int fill_room(void *u, BfmEvent e, BfmPlatEventPayload *p) {
    uint8_t v = 0;
    (void)u; (void)e;
    if (bfm_plat_guest_read(0x80002000, &v, 1) != BFM_PLAT_OK) return 1;
    if (v == 0xFF) return 1;       /* not a real room change */
    p->room.area = 2;
    p->room.room = v;
    return 0;
}

static int group_hooks(void) {
    BfmPlatHookSite s[3];
    char out[4096];
    reset_all();
    bind_ram();
    CHECK(strcmp(bfm_plat_event_name(BFM_EVENT_ROOM_ENTER), "room_enter") == 0);
    CHECK(bfm_plat_event_from_name("battle_end") == BFM_EVENT_BATTLE_END);
    CHECK(bfm_plat_event_from_name("nope") == BFM_EVENT_COUNT);
    {
        unsigned i;
        for (i = 0; i < BFM_EVENT_COUNT; i++)
            CHECK(bfm_plat_event_info((BfmEvent)i)->event == (BfmEvent)i);
        CHECK(bfm_plat_event_info(BFM_EVENT_COUNT) == NULL);
    }
    memset(s, 0, sizeof s);
    s[0].guest_pc = 0x80030000; s[0].event = BFM_EVENT_ITEM_GET; s[0].label = "item";
    s[1].guest_pc = 0x80010000; s[1].event = BFM_EVENT_ROOM_ENTER; s[1].label = "room"; s[1].fill = fill_room;
    s[2].guest_pc = 0x80030000; s[2].event = BFM_EVENT_ROOM_EXIT; s[2].label = "exit";
    CHECK(bfm_plat_hooks_register(s, 3) == BFM_PLAT_OK);
    {
        BfmPlatHookSite bad = s[0];
        bad.guest_pc = 0x80030002;
        CHECK(bfm_plat_hooks_register(&bad, 1) == BFM_PLAT_INVALID);
        bad.guest_pc = 0x80030004;
        bad.event = BFM_EVENT_COUNT;
        CHECK(bfm_plat_hooks_register(&bad, 1) == BFM_PLAT_INVALID);
    }
    CHECK(bfm_plat_hooks_count() == 3);
    bfm_plat_mods_subscribe(BFM_EVENT_ROOM_ENTER, on_room_hook, NULL);
    bfm_plat_mods_subscribe(BFM_EVENT_ITEM_GET, on_item_hook, NULL);
    CHECK(bfm_plat_hooks_has(0x80010000) && bfm_plat_hooks_has(0x80030000));
    CHECK(!bfm_plat_hooks_has(0x80020000));
    CHECK(bfm_plat_hooks_at(0x80020000) == 0);
    ram[0x2000] = 9;
    CHECK(bfm_plat_hooks_at(0x80010000) == 1 && room_hits == 1 && last_room == 9);
    ram[0x2000] = 0xFF;
    CHECK(bfm_plat_hooks_at(0x80010000) == 0 && room_hits == 1);
    CHECK(bfm_plat_hooks_at(0x80030000) == 2 && item_hits == 1);
    CHECK(bfm_plat_mods_event_count(BFM_EVENT_ROOM_EXIT) == 1);
    bfm_plat_console_init(NULL);
    bfm_plat_events_register_console();
    CHECK(bfm_plat_console_exec("events", out, sizeof out) == 0);
    CHECK(strstr(out, "room_enter") && strstr(out, "site 80010000 room_enter room hits=1"));
    CHECK(strstr(out, "site 80030000"));
    /* direct emitters used by hand-ported code */
    bfm_plat_event_room_enter(1, 4);
    CHECK(room_hits == 2 && last_room == 4);
    bfm_plat_event_save(0, 1);
    bfm_plat_event_save(1, 1);
    CHECK(bfm_plat_mods_event_count(BFM_EVENT_SAVE) == 1 && bfm_plat_mods_event_count(BFM_EVENT_LOAD) == 1);
    return 0;
}

#ifdef BFM_PLAT_WITH_PNG
int bfm_plat_texture_png_decode_memory(const uint8_t *, size_t, uint32_t *,
                                       uint32_t *, uint8_t **);
int bfm_plat_texture_png_register(void);
/* png FILE: prints "png W H <rgba hex>" or "png error N". */
static int group_png(int argc, char **argv) {
    FILE *f;
    static uint8_t buf[1 << 20];
    size_t n;
    uint32_t w, h, i;
    uint8_t *rgba;
    int r;
    CHECK(argc >= 1 && (f = fopen(argv[0], "rb")) != NULL);
    n = fread(buf, 1, sizeof buf, f);
    fclose(f);
    r = bfm_plat_texture_png_decode_memory(buf, n, &w, &h, &rgba);
    if (r != BFM_PLAT_OK) {
        printf("png error %d\n", r);
        return 0;
    }
    printf("png %u %u ", w, h);
    for (i = 0; i < w * h * 4u; i++) printf("%02x", rgba[i]);
    printf("\n");
    free(rgba);
    return 0;
}
#endif

int main(int argc, char **argv) {
    const char *g;
    int r;
    if (argc < 2) {
        printf("usage: %s GROUP [ARGS]\n", argv[0]);
        return 2;
    }
    g = argv[1];
    if (strcmp(g, "config") == 0) r = group_config(argc - 2, argv + 2);
    else if (strcmp(g, "renderer") == 0) r = group_renderer();
    else if (strcmp(g, "texture") == 0) r = group_texture(argc - 2, argv + 2);
    else if (strcmp(g, "input") == 0) r = group_input();
    else if (strcmp(g, "timing") == 0) r = group_timing();
    else if (strcmp(g, "audio") == 0) r = group_audio();
    else if (strcmp(g, "storage") == 0) r = group_storage(argc - 2, argv + 2);
    else if (strcmp(g, "file_replace") == 0) r = group_file_replace(argc - 2, argv + 2);
    else if (strcmp(g, "mods") == 0) r = group_mods(argc - 2, argv + 2);
    else if (strcmp(g, "hash") == 0) r = group_hash();
    else if (strcmp(g, "bindings") == 0) r = group_bindings();
    else if (strcmp(g, "console_ui") == 0) r = group_console_ui();
    else if (strcmp(g, "hooks") == 0) r = group_hooks();
#ifdef BFM_PLAT_WITH_PNG
    else if (strcmp(g, "png") == 0) r = group_png(argc - 2, argv + 2);
    else if (strcmp(g, "texture_png") == 0) {
        reset_all();
        bfm_plat_texture_png_register();
        r = group_texture_keep(argc - 2, argv + 2);
    }
#endif
    else { printf("unknown group %s\n", g); return 2; }
    reset_all();
    if (r == 0) printf("ok %s\n", g);
    return r;
}
