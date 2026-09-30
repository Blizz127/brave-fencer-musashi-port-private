#ifndef MUSASHI_DEV_MENU_H
#define MUSASHI_DEV_MENU_H

/* Port Dev Menu (shared port spec v1, ~/release-staging/port-dev-menu):
 * a host-only playtest menu. Root: Warp > Finish Area > Cheats > Options.
 *
 * Off by default. BFM_DEV_MENU=1 (or --dev-menu) enables the menu and its
 * F-keys; BFM_CHEATS=0 hard-disables everything, including the always-on
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
 * guest VBlank `frame`. */

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

/* Test access. */
typedef struct MusashiDevMenuState {
    int enabled, hard_disabled, open, page, selection, help;
    int god, resource, ff, ff_speed;
    unsigned vblanks, cheat_writes, one_shots, refusals;
} MusashiDevMenuState;
void musashi_dev_menu_state(MusashiDevMenuState *out);
unsigned musashi_dev_menu_warp_count(void);
unsigned musashi_dev_menu_finish_count(void);
void musashi_dev_menu_reset(void);

#endif
