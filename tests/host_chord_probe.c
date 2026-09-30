#include "musashi_host_chord.h"
#include <assert.h>
#include <stdio.h>

static void sequence(void) {
    MusashiHostChord c = {0};
    assert(!musashi_host_chord_step(&c, 1, 0) && !c.game);
    assert(!musashi_host_chord_step(&c, 0, 17));
    assert(musashi_host_chord_step(&c, 2, 300) && !c.game);
    assert(!musashi_host_chord_step(&c, 3, 317));
    assert(!musashi_host_chord_step(&c, 0, 334));
    assert(!musashi_host_chord_step(&c, 2, 400));
    assert(musashi_host_chord_step(&c, 1, 450));
    musashi_host_chord_step(&c, 0, 500);
    assert(musashi_host_chord_step(&c, 3, 900));
    assert(!musashi_host_chord_step(&c, 3, 1500));
    musashi_host_chord_step(&c, 0, 1600);
    musashi_host_chord_step(&c, 1, 1700);
    musashi_host_chord_step(&c, 0, 1717);
    musashi_host_chord_step(&c, 0, 2000); assert(!c.game);
    musashi_host_chord_step(&c, 0, 2001); assert(c.game == 1);
    musashi_host_chord_step(&c, 0, 2018); assert(c.game == 1);
    musashi_host_chord_step(&c, 0, 2035); assert(!c.game);
    musashi_host_chord_step(&c, 2, 2100); assert(!c.game);
    musashi_host_chord_step(&c, 2, 2401); assert(c.game == 2);
    musashi_host_chord_step(&c, 2, 2600); assert(c.game == 2);
    assert(musashi_host_chord_step(&c, 3, 2700)); /* held always works */
    musashi_host_chord_step(&c, 0, 2800);
    musashi_host_chord_step(&c, 1, 3000);
    musashi_host_chord_step(&c, 0, 3017);
    assert(!musashi_host_chord_step(&c, 2, 3301)); /* outside window */
    assert(c.game == 1);
    memset(&c, 0, sizeof c);
    musashi_host_chord_step(&c, 1, 0xfffffff0u);
    assert(musashi_host_chord_step(&c, 2, 20)); /* ticks wrap */
}

static void virtual_pad(int mapped) {
    SDL_VirtualJoystickDesc d;
    SDL_GameController *pad = NULL;
    SDL_Joystick *joy;
    MusashiHostChord c = {0};
    int index, back, start;
    memset(&d, 0, sizeof d);
    d.version = SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
    d.type = mapped ? SDL_JOYSTICK_TYPE_GAMECONTROLLER : SDL_JOYSTICK_TYPE_UNKNOWN;
    d.naxes = 6; d.nbuttons = 15; d.nhats = 1;
    d.vendor_id = mapped ? 0x045e : 0x1234; d.product_id = mapped ? 0x028e : 0xabcd;
    d.name = mapped ? "Chord mapped virtual" : "Chord raw virtual";
    index = SDL_JoystickAttachVirtualEx(&d); assert(index >= 0);
    if (mapped) {
        char guid[33], mapping[512];
        SDL_JoystickGetGUIDString(SDL_JoystickGetDeviceGUID(index), guid, sizeof guid);
        snprintf(mapping, sizeof mapping, "%s,Chord test,a:b0,b:b1,x:b2,y:b3,back:b6,start:b7,leftx:a0,lefty:a1,", guid);
        assert(SDL_GameControllerAddMapping(mapping) >= 0);
        assert(SDL_IsGameController(index));
        pad = SDL_GameControllerOpen(index); assert(pad);
        joy = SDL_GameControllerGetJoystick(pad);
    } else { assert(!SDL_IsGameController(index)); joy = SDL_JoystickOpen(index); assert(joy); }
    assert(SDL_JoystickSetVirtualButton(joy, 6, 1) == 0);
    SDL_JoystickUpdate();
    back = musashi_host_pad_button(pad, joy, SDL_CONTROLLER_BUTTON_BACK);
    assert(back && !musashi_host_chord_step(&c, back, 0));
    SDL_JoystickSetVirtualButton(joy, 6, 0); SDL_JoystickUpdate();
    musashi_host_chord_step(&c, 0, 17);
    SDL_JoystickSetVirtualButton(joy, 7, 1); SDL_JoystickUpdate();
    start = musashi_host_pad_button(pad, joy, SDL_CONTROLLER_BUTTON_START);
    assert(start && musashi_host_chord_step(&c, (unsigned)start << 1, 200));
    assert(!c.game);
    SDL_JoystickSetVirtualHat(joy, 0, SDL_HAT_UP); SDL_JoystickUpdate();
    if (!mapped) assert(musashi_host_pad_button(pad, joy, SDL_CONTROLLER_BUTTON_DPAD_UP));
    if (pad) SDL_GameControllerClose(pad); else SDL_JoystickClose(joy);
    assert(SDL_JoystickDetachVirtual(index) == 0);
}
int main(void) {
    musashi_host_pad_hints();
    assert(!strcmp(SDL_GetHint("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD"), "1"));
    assert(SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) == 0);
    sequence(); virtual_pad(1); virtual_pad(0);
    SDL_Quit(); puts("host chord probe ok: mapped + raw virtual pads, timed/held chords, lone presses");
    return 0;
}
