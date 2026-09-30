/* Port Dev Menu model (shared spec v1): inert when off, hard-disable, the
 * retail-parity gate, field-only cheats through the game's own state,
 * refusals, navigation, no unverified warps. */
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
    game_state();
    (void)musashi_dev_menu_init(&guest, 0);
}

static const char *highlighted(void) {
    const char *lines[24]; int hl, badge;
    size_t n = musashi_dev_menu_text(lines, 24, &hl, &badge);
    assert(n && hl >= 0 && (size_t)hl < n);
    return lines[hl];
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
    assert(musashi_dev_menu_warp_count() == 0 && musashi_dev_menu_finish_count() == 0);
    assert(strstr(highlighted(), "BACK"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_OK, 0);             /* back to root, on WARP */
    assert(strstr(highlighted(), "WARP"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "FINISH AREA"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "CHEATS"));
    musashi_dev_menu_keys(MUSASHI_DEV_KEY_DOWN, 0);
    assert(strstr(highlighted(), "OPTIONS"));

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

    puts("DEV_MENU_PASS off_inert=1 hard_disable=1 parity=1 cheats=game_state warps=0 finish=0");
    return 0;
}
