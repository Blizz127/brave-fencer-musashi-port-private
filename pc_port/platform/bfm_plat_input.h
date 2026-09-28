#ifndef BFM_PLAT_INPUT_H
#define BFM_PLAT_INPUT_H

/* Input interface: controller state by meaning (PS1 pad buttons, analog
 * sticks) plus port hotkeys (fast-forward, console, cheat menu).
 *
 * Buttons are active-high in this struct. bfm_plat_pad_to_wire() produces
 * the active-low bytes a PS1 pad returns on the SIO bus, for the libpad /
 * BIOS pad shim that the game's own pad code reads. */

#include "bfm_plat_types.h"

#define BFM_PAD_SELECT   0x0001u
#define BFM_PAD_L3       0x0002u
#define BFM_PAD_R3       0x0004u
#define BFM_PAD_START    0x0008u
#define BFM_PAD_UP       0x0010u
#define BFM_PAD_RIGHT    0x0020u
#define BFM_PAD_DOWN     0x0040u
#define BFM_PAD_LEFT     0x0080u
#define BFM_PAD_L2       0x0100u
#define BFM_PAD_R2       0x0200u
#define BFM_PAD_L1       0x0400u
#define BFM_PAD_R1       0x0800u
#define BFM_PAD_TRIANGLE 0x1000u
#define BFM_PAD_CIRCLE   0x2000u
#define BFM_PAD_CROSS    0x4000u
#define BFM_PAD_SQUARE   0x8000u

#define BFM_HOTKEY_FAST_FORWARD 0x0001u
#define BFM_HOTKEY_CONSOLE      0x0002u
#define BFM_HOTKEY_CHEAT_MENU   0x0004u
#define BFM_HOTKEY_PAUSE        0x0008u
#define BFM_HOTKEY_SCREENSHOT   0x0010u
#define BFM_HOTKEY_QUIT         0x0020u

#define BFM_PLAT_PAD_PORTS 2

typedef struct BfmPlatPad {
    uint16_t buttons;          /* BFM_PAD_* active-high */
    uint8_t lx, ly, rx, ry;    /* 0x80 = centre */
    uint8_t connected;
    uint8_t analog;            /* 1 = DualShock analog mode */
} BfmPlatPad;

/* A host binding: backend-defined host code (e.g. SDL scancode, or
 * joystick button | 0x10000) mapped to a pad button or hotkey. */
typedef struct BfmPlatBinding {
    int32_t host_code;
    uint8_t port;
    uint8_t is_hotkey;
    uint16_t mask;
} BfmPlatBinding;

typedef struct BfmPlatInputBackend {
    const char *name;
    int (*open)(void *self);
    void (*close)(void *self);
    /* Pumps host events; fills both ports and the hotkey mask. */
    int (*poll)(void *self, BfmPlatPad pads[BFM_PLAT_PAD_PORTS],
                uint32_t *hotkeys);
    /* Replace bindings (backend may ignore codes it doesn't understand). */
    int (*set_bindings)(void *self, const BfmPlatBinding *b, size_t n);
    void *self;
} BfmPlatInputBackend;

int bfm_plat_input_register(const BfmPlatInputBackend *backend);
int bfm_plat_input_open(const char *name, const char **selected);
void bfm_plat_input_close(void);
const char *bfm_plat_input_active(void);

/* Once per frame. Applies cheat/mod overrides (BFM_EVENT_INPUT) after the
 * backend, then latches the result for bfm_plat_input_pad(). */
int bfm_plat_input_poll(void);
int bfm_plat_input_pad(unsigned port, BfmPlatPad *out);
uint32_t bfm_plat_input_hotkeys(void);          /* held this frame */
uint32_t bfm_plat_input_hotkeys_pressed(void);  /* rising edge this frame */
int bfm_plat_input_set_bindings(const BfmPlatBinding *b, size_t n);

/* PS1 wire format: out[0]=0x41 digital / 0x73 analog, out[1]=0x5A,
 * out[2..3] = ~buttons (lo, hi), out[4..7] = rx, ry, lx, ly (analog only).
 * Returns bytes written (0 if disconnected). */
size_t bfm_plat_pad_to_wire(const BfmPlatPad *pad, uint8_t out[8]);

/* Built-in "scripted" backend (the default "null"): state is set by code, so
 * tests and the route autopilot can drive the game. */
void bfm_plat_input_scripted_set(unsigned port, const BfmPlatPad *pad);
void bfm_plat_input_scripted_hotkeys(uint32_t hotkeys);

void bfm_plat_input_reset(void);

#endif
