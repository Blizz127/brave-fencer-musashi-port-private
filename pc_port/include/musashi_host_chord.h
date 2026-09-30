#ifndef MUSASHI_HOST_CHORD_H
#define MUSASHI_HOST_CHORD_H
#include <SDL.h>
#include <string.h>

/* Host-only Back/Start arbitration; one step per displayed VBlank. */
typedef struct {
    unsigned previous, pending, latched;
    Uint32 since[2];
    unsigned length[2], replay[2];
    unsigned game;
} MusashiHostChord;

static inline int musashi_host_chord_step(MusashiHostChord *c, unsigned held, Uint32 now) {
    unsigned rising = held & ~c->previous, i;
    int toggle = 0;
    c->game = 0;
    if (c->latched) {
        if (!held) c->latched = 0;
        c->previous = held;
        return 0;
    }
    if (held == 3 || ((rising & 1) && (c->pending & 2) && now - c->since[1] <= 300) ||
                     ((rising & 2) && (c->pending & 1) && now - c->since[0] <= 300)) {
        c->pending = 0;
        c->replay[0] = c->replay[1] = 0;
        c->latched = 1;
        toggle = 1;
    } else {
        for (i = 0; i < 2; ++i) {
            unsigned bit = 1u << i;
            if (rising & bit) {
                c->pending |= bit;
                c->since[i] = now;
                c->length[i] = 0;
            }
            if ((c->pending & bit) && (held & bit)) ++c->length[i];
            if ((c->pending & bit) && now - c->since[i] > 300) {
                c->pending &= ~bit;
                if (!(held & bit)) c->replay[i] = c->length[i] < 2 ? 2 : c->length[i];
            }
            if ((held & bit) && !(c->pending & bit)) c->game |= bit;
            if (c->replay[i]) { c->game |= bit; --c->replay[i]; }
        }
    }
    c->previous = held;
    return toggle;
}

/* Unmapped Linux/XInput-style joystick fallback. */
static inline int musashi_host_pad_button(SDL_GameController *pad, SDL_Joystick *joy,
                                          SDL_GameControllerButton button) {
    static const int raw[] = {0, 1, 2, 3, 6, -1, 7, 9, 10, 4, 5};
    if (pad) return SDL_GameControllerGetButton(pad, button) != 0;
    if (!joy || SDL_JoystickNumButtons(joy) < 8) return 0;
    if (button >= SDL_CONTROLLER_BUTTON_DPAD_UP && button <= SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
        static const unsigned hats[] = {SDL_HAT_UP, SDL_HAT_DOWN, SDL_HAT_LEFT, SDL_HAT_RIGHT};
        return SDL_JoystickNumHats(joy) > 0 && (SDL_JoystickGetHat(joy, 0) & hats[button - SDL_CONTROLLER_BUTTON_DPAD_UP]);
    }
    return (unsigned)button < sizeof raw / sizeof raw[0] && raw[button] >= 0 &&
           raw[button] < SDL_JoystickNumButtons(joy) && SDL_JoystickGetButton(joy, raw[button]);
}
static inline int musashi_host_pad_y(SDL_GameController *pad, SDL_Joystick *joy) {
    return pad ? SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTY) :
        (joy && SDL_JoystickNumAxes(joy) > 1 ? SDL_JoystickGetAxis(joy, 1) : 0);
}
static inline void musashi_host_pad_hints(void) {
    SDL_setenv("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD", "1", 1);
    SDL_SetHint("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD", "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
}
#endif
