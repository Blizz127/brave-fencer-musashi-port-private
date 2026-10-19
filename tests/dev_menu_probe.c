/* Port Dev Menu model (shared spec v1): inert when off, hard-disable, the
 * retail-parity gate, field-only cheats through the game's own state,
 * refusals, navigation, only the verified warps in area folders. */
#include "musashi_dev_menu.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t ram[0x200000], snapshot[0x200000];
static unsigned writes;

static uint8_t *at(uint32_t a) { return &ram[a & 0x1fffffu]; }
static int r8(void *u, uint32_t a, uint8_t *v) { (void)u; *v = *at(a); return 1; }
static int w8(void *u, uint32_t a, uint8_t v) { (void)u; *at(a) = v; ++writes; return 1; }
static int r16(void *u, uint32_t a, uint16_t *v) { (void)u; memcpy(v, at(a), 2); return 1; }
static int w16(void *u, uint32_t a, uint16_t v) { (void)u; memcpy(at(a), &v, 2); ++writes; return 1; }
static int r32(void *u, uint32_t a, uint32_t *v) { (void)u; memcpy(v, at(a), 4); return 1; }
static int w32(void *u, uint32_t a, uint32_t v) { (void)u; memcpy(at(a), &v, 4); ++writes; return 1; }
static const MusashiDevMenuGuest guest = { NULL, r8, w8, r16, w16, r32, w32 };

static void put16(uint32_t a, uint16_t v) { memcpy(at(a), &v, 2); }
static void put32(uint32_t a, uint32_t v) { memcpy(at(a), &v, 4); }
static uint16_t get16(uint32_t a) { uint16_t v; memcpy(&v, at(a), 2); return v; }
static uint32_t get32(uint32_t a) { uint32_t v; memcpy(&v, at(a), 4); return v; }

static void game_state(void) {
    memset(ram, 0, sizeof ram);
    put16(0x80078eb2u, 300); put16(0x80078eb4u, 12);   /* HP max, current */
    put16(0x80078eb6u, 200); put16(0x80078eb8u, 7);    /* BP max, current */
    put32(0x80078e8cu, 95000u);                         /* Drans */
    *at(0x80078eb1u) = 22;                              /* hour */
    writes = 0;
}

static void start(const char *menu, const char *cheats, const char *keys) {
    musashi_dev_menu_reset();
    if (menu) setenv("BFM_DEV_MENU", menu, 1); else unsetenv("BFM_DEV_MENU");
    if (cheats) setenv("BFM_CHEATS", cheats, 1); else unsetenv("BFM_CHEATS");
    if (keys) setenv("BFM_DEV_MENU_KEYS", keys, 1); else unsetenv("BFM_DEV_MENU_KEYS");
    unsetenv("BFM_DEV_MENU_WARP_TEST");
    game_state();
    (void)musashi_dev_menu_init(&guest, 0);
}

static const char *highlighted(void) {
    const char *lines[24]; int hl, badge;
    size_t n = musashi_dev_menu_text(lines, 24, &hl, &badge);
    assert(n && hl >= 0 && (size_t)hl < n);
    return lines[hl];
}

/* Captures musashi_dev_menu_emit_text: positions, '>' rows, the last one. */
static struct { unsigned n, bad_pos, marked; char last_marked[64]; } cap;
static void capture(void *u, int x, int y, const char *text) {
    (void)u;
    if (x != 8 || y != 8 + 12 * (int)cap.n) ++cap.bad_pos;
    if (text[0] == '>') {
        ++cap.marked;
        snprintf(cap.last_marked, sizeof cap.last_marked, "%s", text);
    }
    ++cap.n;
}

int main(void) {
    MusashiDevMenuState st;
    const char *lines[24];
    int hl, badge;
    unsigned i;

    /* Off by default: menu keys inert, nothing drawn, nothing written. */
    start(NULL, NULL, NULL);
    for (i = 0; i < 100; ++i) {
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE | MUSASHI_DEV_KEY_OK | MUSASHI_DEV_KEY_GOD, 0);
        musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    }
    musashi_dev_menu_state(&st);
    assert(!st.enabled && !st.open && !st.god && writes == 0);
    assert(musashi_dev_menu_text(lines, 24, &hl, &badge) == 0);
    /* The always-on host keys still work without the opt-in. */
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_FF | MUSASHI_DEV_KEY_SHOT, 0);
    assert(musashi_dev_menu_fast_forward() && musashi_dev_menu_take_screenshot());
    assert(!musashi_dev_menu_take_screenshot());

    /* BFM_CHEATS=0 hard-disables everything, fast-forward included. */
    start("1", "0", NULL);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_FF | MUSASHI_DEV_KEY_TOGGLE | MUSASHI_DEV_KEY_SHOT, 1);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.hard_disabled && !st.enabled && !st.open && writes == 0);
    assert(!musashi_dev_menu_fast_forward() && !musashi_dev_menu_take_screenshot());

    /* Retail-parity gate: enabled, menu opened and browsed, every cheat off:
     * zero guest bytes change over 1000 field VBlanks. */
    start("1", NULL, NULL);
    memcpy(snapshot, ram, sizeof ram);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    for (i = 0; i < 1000; ++i) musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    assert(writes == 0 && !memcmp(snapshot, ram, sizeof ram));
    musashi_dev_menu_state(&st);
    assert(st.enabled && st.open && st.cheat_writes == 0 && !musashi_dev_menu_used());

    /* Root order and Warp / Finish Area show no unverified rows. */
    start("1", NULL, "1:TOGGLE,2:OK");
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.open && st.page == 1);                          /* WARP > */
    assert(musashi_dev_menu_warp_count() == 29 && musashi_dev_menu_finish_count() == 0);
    assert(strstr(highlighted(), "AREA 1: CASTLE"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_UP, 0);             /* wraps to BACK */
    assert(strstr(highlighted(), "BACK"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);             /* back to root, on WARP */
    assert(strstr(highlighted(), "WARP"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "FINISH AREA"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "CHEATS"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "OPTIONS"));

    /* Warp folders: root -> WARP -> folder -> room row queues a warp; BACK
     * leaves the folder for the list, then the list for the root. Every
     * page fits the 24 lines the renderer is given. */
    start("1", NULL, "1:TOGGLE,2:OK");
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    assert(musashi_dev_menu_text(lines, 24, &hl, &badge) == 3u + 3u + 1u + 2u);
    assert(strstr(lines[3], "AREA 1: CASTLE & SPIRAL TOWER >"));
    assert(strstr(lines[4], "AREA 2: GRILLIN' VILLAGE & FORESTS >"));
    assert(strstr(lines[5], "AREA 2: TWINPEAK & HELL'S VALLEY >"));
    assert(strstr(lines[6], "BACK"));
    for (i = 0; i < 3; ++i) {
        size_t rows, k;
        static const size_t expect[3] = { 10, 11, 8 };
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN * (i > 0), 0);   /* folder i */
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        rows = musashi_dev_menu_text(lines, 24, &hl, &badge);
        assert(rows == 3u + expect[i] + 1u + 2u && rows <= 24u);
        for (k = 0; k < rows; ++k) assert(strlen(lines[k]) < 56u);
        assert(strstr(lines[3 + expect[i]], "BACK") && strstr(highlighted(), lines[3]));
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_BACK, 0);             /* B: the folder list */
        assert(strstr(highlighted(), "AREA"));
        musashi_dev_menu_state(&st);
        assert(st.page == 1 && st.selection == (int)i);
    }
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);                   /* AREA 2 (twinpeak) */
    assert(strstr(highlighted(), "HELL'S VALLEY - SKULLPION"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_UP, 0);                   /* BACK row */
    assert(strstr(highlighted(), "BACK"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);                   /* to the folder list */
    musashi_dev_menu_state(&st);
    assert(st.page == 1 && st.selection == 2 && strstr(highlighted(), "TWINPEAK"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_UP, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_UP, 0);                   /* AREA 1 */
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "CASTLE (4, THRONE ROOM)"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);                   /* queues 3003.0 */
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 1 && st.refusals == 0 && writes == 0);
    put16(0x800b99deu, 0x000b); put16(0x800b99f0u, 9); *at(0x800b9a10u) = 1;
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);                       /* safe point: sent */
    assert(get16(0x80078e50u) == 0x3003 && *at(0x80078e52u) == 0);
    /* Backing out of the whole menu from a folder reaches the root first. */
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_BACK, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_BACK, 0);
    musashi_dev_menu_state(&st);
    assert(st.page == 0 && st.open && st.selection == 0);

    /* Every verified row is a known room with entrance 0; 2013 is absent. */
    start("1", NULL, NULL);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE | MUSASHI_DEV_KEY_OK, 0);
    {
        unsigned f, r, seen = 0;
        for (f = 0; f < 3; ++f) {
            musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE, 0);
            musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE, 0);       /* root, closed then open */
            musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);           /* WARP */
            for (r = 0; r < f; ++r) musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
            musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);           /* folder f */
            for (;;) {
                size_t rows = musashi_dev_menu_text(lines, 24, &hl, &badge);
                if (strstr(lines[hl], "BACK")) break;
                seen++;
                assert(!strstr(lines[hl], "TOY"));
                assert(rows <= 24u);
                musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
            }
        }
        assert(seen == musashi_dev_menu_warp_count());
    }

    /* The hard-disable still wins with the menu asked for two ways. */
    start("1", "0", "1:TOGGLE,2:OK,3:OK,4:OK");
    musashi_dev_menu_state(&st);
    assert(st.hard_disabled && !st.enabled);
    for (i = 0; i < 10; ++i) {
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE | MUSASHI_DEV_KEY_OK, 0);
        musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    }
    musashi_dev_menu_state(&st);
    assert(!st.open && st.warp_state == 0 && writes == 0);
    assert(musashi_dev_menu_text(lines, 24, &hl, &badge) == 0);
    setenv("BFM_DEV_MENU", "1", 1);
    setenv("BFM_CHEATS", "0", 1);
    musashi_dev_menu_reset();
    assert(musashi_dev_menu_init(&guest, 1) == 0);            /* --dev-menu too */
    assert(musashi_dev_menu_hard_disabled() && !musashi_dev_menu_enabled());

    /* God mode (F2): HP refilled from the game's own max, only in the field. */
    start("1", NULL, NULL);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_GOD, 0);
    musashi_dev_menu_vblank(1, 0x000b, 6, 0);                 /* not in the field */
    assert(get16(0x80078eb4u) == 12 && writes == 0);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    assert(get16(0x80078eb4u) == 300 && writes == 1);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    assert(writes == 1);                                      /* already full */
    assert(musashi_dev_menu_text(lines, 24, &hl, &badge) == 1 && badge && !strcmp(lines[0], "CHEATS"));
    assert(musashi_dev_menu_used() && !musashi_dev_menu_used());
    assert(get16(0x80078eb8u) == 7);                          /* BP untouched */

    /* One-shots: refused outside the field, bounded by the game's own cap. */
    start("1", NULL, NULL);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);             /* CHEATS > */
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "DRANS"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
    musashi_dev_menu_vblank(1, 0x000b, 7, 0);
    musashi_dev_menu_state(&st);
    assert(st.refusals == 1 && get32(0x80078e8cu) == 95000u && writes == 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    assert(get32(0x80078e8cu) == 99999u);                     /* capped */
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "TIME"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    assert(*at(0x80078eb1u) == 23);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(*at(0x80078eb1u) == 23 && st.refusals == 2);       /* never past midnight */

    /* Options: fast-forward speed cycles 2x -> 4x -> 8x -> max; help page. */
    start("1", NULL, NULL);
    assert(musashi_dev_menu_ff_speed() == 2u);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_FF_SPEED, 0);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_FF_SPEED, 0);
    assert(musashi_dev_menu_ff_speed() == 8u);
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_FF_SPEED, 0);
    assert(musashi_dev_menu_ff_speed() == 0u);
    musashi_dev_menu_keys(0, 1);
    assert(musashi_dev_menu_fast_forward());                  /* held */
    musashi_dev_menu_keys(0, 0);
    assert(!musashi_dev_menu_fast_forward());
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_HELP, 0);
    assert(musashi_dev_menu_text(lines, 24, &hl, &badge) > 8 && strstr(lines[0], "KEYS"));
    assert(writes == 0);

    /* Warp (harness request): waits outside gameplay, then hands the game
     * its own exit record and follows the room change to arrival. */
    musashi_dev_menu_reset();
    setenv("BFM_DEV_MENU", "1", 1);
    unsetenv("BFM_CHEATS");
    unsetenv("BFM_DEV_MENU_KEYS");
    setenv("BFM_DEV_MENU_WARP_TEST", "3006:1", 1);
    game_state();
    put16(0x800b99deu, 0x000b);                              /* in game */
    put16(0x800b99f0u, 7);                                   /* loading */
    put16(0x800b9a08u, 0x3005);
    (void)musashi_dev_menu_init(&guest, 0);
    for (i = 0; i < 700; ++i) musashi_dev_menu_vblank(1, 0x000b, 7, 0);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 1 && writes == 0);               /* harness waits */
    put16(0x800b99f0u, 9); *at(0x800b9a10u) = 1;
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 2);
    assert(get16(0x80078e50u) == 0x3006 && *at(0x80078e52u) == 1);
    assert(get32(0x80078e54u) == 0x800d30c8u && get32(0x80078e6cu) == 0x800d1e20u);
    assert(get32(0x800ae6b0u) == 0x80078e50u);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);                /* not taken yet */
    put16(0x800b99f0u, 10); *at(0x800b9a10u) = 0;            /* the game takes the exit */
    musashi_dev_menu_vblank(1, 0x000b, 10, 0);
    put16(0x800b99f0u, 9); put16(0x800b9a08u, 0x3006); *at(0x800b9a10u) = 1;
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 0 && st.warps_done == 1 && st.warps_failed == 0);
    assert(musashi_dev_menu_used());

    /* No such entrance, or a pending exit: refused / kept waiting. */
    musashi_dev_menu_reset();
    setenv("BFM_DEV_MENU_WARP_TEST", "3006:9", 1);
    game_state();
    (void)musashi_dev_menu_init(&guest, 0);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 0 && st.refusals == 1);
    musashi_dev_menu_reset();
    setenv("BFM_DEV_MENU_WARP_TEST", "3006:0", 1);
    game_state();
    put16(0x800b99deu, 0x000b); put16(0x800b99f0u, 9); *at(0x800b9a10u) = 1;
    put32(0x800ae6a8u, 0x80123456u);                         /* a door is already queued */
    (void)musashi_dev_menu_init(&guest, 0);
    for (i = 0; i < 10; ++i) musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 1 && writes == 0);
    unsetenv("BFM_DEV_MENU_WARP_TEST");

#ifdef MUSASHI_DEV_MENU_PRESET_TABLE
    /* Finish Area candidate 2: the developers' AREA 1..3 presets, then the
     * exit request to the area-transition demo 0x304A. */
    musashi_dev_menu_reset();
    setenv("BFM_DEV_MENU_FINISH_TEST", "2", 1);
    game_state();
    put16(0x800b99deu, 0x000b); put16(0x800b99f0u, 9); *at(0x800b9a10u) = 1;
    put16(0x8010f474u, 0x1234);                              /* a value the presets copy */
    (void)musashi_dev_menu_init(&guest, 0);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 2);
    assert(get32(0x80078e80u) == 200u);                      /* progress: Area 3 start */
    assert(get16(0x80078eb2u) == 250u && get16(0x80078eb6u) == 375u);
    assert(*at(0x800ae648u + (0x8a >> 3)) & (1u << (0x8a & 7)));  /* Area 2 core flag */
    assert(*at(0x800ae648u + (0x16 >> 3)) & (1u << (0x16 & 7)));  /* Earth Scroll flag */
    assert(get16(0x800a6588u) == 0x1234);
    assert(get16(0x80078e50u) == 0x304a && get32(0x800ae6b0u) == 0x80078e50u);
    unsetenv("BFM_DEV_MENU_FINISH_TEST");
#else
    /* A build without the preset table refuses Finish Area and writes
     * nothing. */
    musashi_dev_menu_reset();
    setenv("BFM_DEV_MENU_FINISH_TEST", "2", 1);
    game_state();
    put16(0x800b99deu, 0x000b); put16(0x800b99f0u, 9); *at(0x800b9a10u) = 1;
    (void)musashi_dev_menu_init(&guest, 0);
    musashi_dev_menu_vblank(1, 0x000b, 9, 1);
    musashi_dev_menu_state(&st);
    assert(st.warp_state == 0 && st.warps_failed == 1 && writes == 0);
    unsetenv("BFM_DEV_MENU_FINISH_TEST");
#endif

    /* Enhancements page: host-seeded values cycle in the menu and are taken
     * once for the host to persist; browsing and changing them writes no
     * guest byte, is not a cheat and leaves the save note unset. */
    {
        MusashiDevMenuEnhancements seed = { 0, 1u, -1 }, got;
        start("1", NULL, NULL);
        musashi_dev_menu_set_enhancements(&seed);
        assert(musashi_dev_menu_take_enhancements(&got) == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE, 0);
        for (i = 0; i < 4; ++i) musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        assert(strcmp(highlighted(), "  ENHANCEMENTS >") == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        assert(strcmp(highlighted(), "  RENDERER: ORIGINAL") == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        assert(strcmp(highlighted(), "  RESOLUTION: NATIVE (GL ONLY)") == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        assert(strcmp(highlighted(), "  DITHER: AUTO (GL ONLY)") == 0);
        for (i = 0; i < 1000; ++i) musashi_dev_menu_vblank(1, 0x000b, 9, 1);
        assert(musashi_dev_menu_take_enhancements(&got) == 0 && writes == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_UP, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_UP, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        assert(strcmp(highlighted(), "  RENDERER: GL (EXPERIMENTAL)") == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        assert(strcmp(highlighted(), "  RESOLUTION: 2X") == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        assert(strcmp(highlighted(), "  DITHER: OFF") == 0);
        assert(musashi_dev_menu_take_enhancements(&got) ==
               (MUSASHI_DEV_ENH_RENDERER | MUSASHI_DEV_ENH_SCALE | MUSASHI_DEV_ENH_DITHER));
        assert(got.renderer_gl == 1 && got.scale == 2u && got.dither == 0);
        assert(musashi_dev_menu_take_enhancements(&got) == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        assert(strcmp(highlighted(), "  BACK") == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        assert(strcmp(highlighted(), "  ENHANCEMENTS >") == 0);
        for (i = 0; i < 1000; ++i) musashi_dev_menu_vblank(1, 0x000b, 9, 1);
        musashi_dev_menu_state(&st);
        assert(writes == 0 && st.cheat_writes == 0 && !st.god && !st.resource);
        assert(!musashi_dev_menu_used());
        /* a seeded scale cycles 4 -> native; an out-of-range seed reads native */
        seed.scale = 4u;
        musashi_dev_menu_set_enhancements(&seed);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        assert(strcmp(highlighted(), "  RESOLUTION: NATIVE (GL ONLY)") == 0);
        assert(musashi_dev_menu_take_enhancements(&got) == MUSASHI_DEV_ENH_SCALE && got.scale == 1u);
        seed.scale = 99u;
        musashi_dev_menu_set_enhancements(&seed);
        assert(strcmp(highlighted(), "  RESOLUTION: NATIVE (GL ONLY)") == 0);
        assert(writes == 0);
    }
    puts("DEV_MENU_ENHANCE_PASS rows=3 guest_writes=0 take_once=1");

    /* Bridge/gl presenters draw the menu from musashi_dev_menu_emit_text:
     * the same lines, '>' on the selected row, nothing while the menu is off
     * or closed; switching back to the Original renderer is reachable. */
    {
        MusashiDevMenuEnhancements seed = { 1, 2u, -1 }, got;
        start(NULL, NULL, NULL);
        memset(&cap, 0, sizeof cap);
        assert(musashi_dev_menu_emit_text(capture, NULL) == 0 && cap.n == 0);
        start("1", NULL, NULL);
        musashi_dev_menu_set_enhancements(&seed);
        assert(musashi_dev_menu_emit_text(capture, NULL) == 0 && cap.n == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_TOGGLE, 0);
        for (i = 0; i < 4; ++i) musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        memset(&cap, 0, sizeof cap);
        assert(musashi_dev_menu_emit_text(capture, NULL) == musashi_dev_menu_text(lines, 24, &hl, &badge));
        assert(cap.n == 9 && cap.bad_pos == 0 && cap.marked == 1);
        assert(strcmp(cap.last_marked, "> RENDERER: GL (EXPERIMENTAL)") == 0);
        assert(musashi_dev_menu_emit_text(NULL, NULL) == 0);
        musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);
        memset(&cap, 0, sizeof cap);
        (void)musashi_dev_menu_emit_text(capture, NULL);
        assert(cap.marked == 1 && strcmp(cap.last_marked, "> RENDERER: ORIGINAL") == 0);
        assert(musashi_dev_menu_take_enhancements(&got) == MUSASHI_DEV_ENH_RENDERER);
        assert(got.renderer_gl == 0 && got.scale == 2u && got.dither == -1);
        assert(writes == 0);
    }
    puts("DEV_MENU_BRIDGE_PASS lines=9 marked=1 switch_back=1");

    puts("DEV_MENU_PASS off_inert=1 hard_disable=1 parity=1 cheats=game_state warps=29 folders=3 finish=0");
    return 0;
}
