#ifndef MUSASHI_DEV_MENU_H
#define MUSASHI_DEV_MENU_H

/* Port Dev Menu (shared port spec v1, ~/release-staging/port-dev-menu):
 * a host-only playtest menu. Root: Warp > Finish Area > Cheats > Options >
 * Enhancements.
 *
 * Off unless asked: BFM_DEV_MENU=1 (or --dev-menu) enables the menu and its
 * F-keys (the packaged launch.sh sets BFM_DEV_MENU=1 unless it is 0 or the
 * dev-menu-off file exists); BFM_CHEATS=0 hard-disables everything, including the always-on
 * fast-forward and screenshot keys. Disabled, no entry point writes guest
 * RAM, consumes input or draws. Enabled with every cheat off, the per-frame
 * pass writes zero guest bytes (the retail-parity gate).
 *
 * Every action goes through the game's own state and runs only at a safe
 * point: in the field (a scene is up, game mode 9, player control unlocked
 * at player+0x4D == 1). Toggles re-apply each frame from the game's own
 * max fields; one-shots outside the field are refused with a toast. Warps
 * and area finishes are listed only once verified (dev_menu.c kWarps /
 * kFinish); until then their pages say so.
 *
 * Game state (docs/MODDING.md section 8): HP max/current 80078EB2/EB4,
 * BP max/current 80078EB6/EB8, Drans 80078E8C (cap 99999), hour 80078EB1.
 *
 * Scripted keys for headless tests: BFM_DEV_MENU_KEYS="frame:KEY,..." with
 * KEY one of TOGGLE UP DOWN OK BACK HELP GOD RESOURCE FF FFSPEED SHOT, at
 * guest VBlank `frame`. Harness only: BFM_DEV_MENU_WARP_TEST=LLLL:E warps
 * to location LLLL (hex), entrance E, at the first safe point.
 *
 * A warp is the game's own exit request: the 0x24-byte exit record the
 * attract demo uses (resident fade-out, no-op callbacks), aimed at L/E and
 * written to 80078E50, then the active exit pointer 800AE6B0. It is sent
 * only in gameplay (program state 0xB, mode 9, room live, player in
 * control and idle, no exit pending, no mode-diverting flag) and is
 * reported arrived once mode 9 resumes in L with the room live. */

#include <stddef.h>
#include <stdint.h>

typedef struct MusashiDevMenuGuest {
    void *user;
    int (*read8)(void *user, uint32_t address, uint8_t *value);
    int (*write8)(void *user, uint32_t address, uint8_t value);
    int (*read16)(void *user, uint32_t address, uint16_t *value);
    int (*write16)(void *user, uint32_t address, uint16_t value);
    int (*read32)(void *user, uint32_t address, uint32_t *value);
    int (*write32)(void *user, uint32_t address, uint32_t value);
} MusashiDevMenuGuest;

enum {
    MUSASHI_DEV_KEY_TOGGLE = 1u << 0,    /* F8 / Back+Start on one pad */
    MUSASHI_DEV_KEY_UP = 1u << 1,
    MUSASHI_DEV_KEY_DOWN = 1u << 2,
    MUSASHI_DEV_KEY_OK = 1u << 3,        /* Enter / A */
    MUSASHI_DEV_KEY_BACK = 1u << 4,      /* Esc / B */
    MUSASHI_DEV_KEY_HELP = 1u << 5,      /* F1 */
    MUSASHI_DEV_KEY_GOD = 1u << 6,       /* F2 */
    MUSASHI_DEV_KEY_RESOURCE = 1u << 7,  /* F3 */
    MUSASHI_DEV_KEY_FF = 1u << 8,        /* F6 / L3 (always) */
    MUSASHI_DEV_KEY_FF_SPEED = 1u << 9,  /* F7 */
    MUSASHI_DEV_KEY_SHOT = 1u << 10      /* F10 (always) */
};

/* Reads BFM_DEV_MENU, BFM_CHEATS and BFM_DEV_MENU_KEYS; `force_on` is
 * --dev-menu. Returns 1 when the menu is enabled. */
int musashi_dev_menu_init(const MusashiDevMenuGuest *guest, int force_on);
int musashi_dev_menu_enabled(void);
int musashi_dev_menu_hard_disabled(void);
/* 1 while the menu is on screen: the game's pad reads neutral. */
int musashi_dev_menu_is_open(void);
/* Key edges this VBlank; `held` is the fast-forward hold (Backspace / R3). */
void musashi_dev_menu_keys(unsigned pressed, int ff_hold);
/* Once per guest VBlank: scripted keys, then the cheat pass. */
void musashi_dev_menu_vblank(int in_scene, unsigned scene, unsigned mode, int in_field);

/* Host services the menu requests. */
int musashi_dev_menu_fast_forward(void);          /* 1 while fast-forwarding */
unsigned musashi_dev_menu_ff_speed(void);         /* 2, 4, 8, or 0 = uncapped */
int musashi_dev_menu_take_screenshot(void);       /* 1 once per request */
void musashi_dev_menu_toast(const char *message); /* host result line */
/* 1 once, the first time any cheat or jump has been used (§9 save note). */
int musashi_dev_menu_used(void);

/* Lines to draw, top to bottom; *highlight is the selected line or -1.
 * *badge_only is 1 when only the CHEATS marker is shown. */
size_t musashi_dev_menu_text(const char **lines, size_t max, int *highlight, int *badge_only);

/* Enhancements page: host-only presentation options, retail by default
 * (docs/GRAPHICS-ENHANCEMENTS-DESIGN.md). The host seeds the values saved
 * in config.ini; a change made in the menu is taken once (MUSASHI_DEV_ENH_*
 * bits, *out set) for the host to persist. They apply on the next launch
 * and never read or write guest memory. */
typedef struct MusashiDevMenuEnhancements {
    int renderer_gl;    /* 0 Original (cpu rasteriser), 1 gl renderer (experimental) */
    unsigned scale;     /* gl internal resolution 1..8 (1 native; the menu cycles 1..4) */
    int dither;         /* -1 auto, 0 off, 1 on (gl renderer) */
    int vsync;          /* -1 default (the driver's interval), 0 off, 1 on (gl renderer) */
    int fullscreen;     /* 1 borderless desktop fullscreen, 0 window (both renderers); the host seeds the mode in effect */
    int present_integer; /* 1 image at whole multiples of the display height, 0 fit (gl renderer) */
} MusashiDevMenuEnhancements;
enum { MUSASHI_DEV_ENH_RENDERER = 1u, MUSASHI_DEV_ENH_SCALE = 2u, MUSASHI_DEV_ENH_DITHER = 4u,
       MUSASHI_DEV_ENH_VSYNC = 8u, MUSASHI_DEV_ENH_FULLSCREEN = 16u, MUSASHI_DEV_ENH_PRESENT = 32u };
void musashi_dev_menu_set_enhancements(const MusashiDevMenuEnhancements *enh);
unsigned musashi_dev_menu_take_enhancements(MusashiDevMenuEnhancements *out);
/* The menu as positioned text for presenters without the PsyCross overlay
 * hook (the bfm_plat bridge renderers): every line of musashi_dev_menu_text
 * at (8, 8 + 12 * i), the selected row's leading space replaced by '>'.
 * Returns the number of lines emitted (0 while nothing is shown). */
typedef void (*MusashiDevMenuEmit)(void *user, int x, int y, const char *text);
size_t musashi_dev_menu_emit_text(MusashiDevMenuEmit emit, void *user);

/* Test access. */
typedef struct MusashiDevMenuState {
    int enabled, hard_disabled, open, page, selection, help;
    int god, resource, ff, ff_speed;
    unsigned vblanks, cheat_writes, one_shots, refusals;
    int warp_state;   /* 0 idle, 1 waiting for a safe point, 2 sent, 3 room changing */
    unsigned warps_done, warps_failed;
} MusashiDevMenuState;
void musashi_dev_menu_state(MusashiDevMenuState *out);
unsigned musashi_dev_menu_warp_count(void);
unsigned musashi_dev_menu_finish_count(void);
void musashi_dev_menu_reset(void);

#endif
