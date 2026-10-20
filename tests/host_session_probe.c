/* Host session helper for the owner handheld gate: Gamescope detection (parity
 * with the launcher's SteamGameMode.DetectGamescope vectors), the window-mode
 * precedence, and the 4:3 fit rectangle. Pure logic, no display needed. */
#include "musashi_host_session.h"

#include <stdio.h>
#include <string.h>

static int failures;
#define CHECK(cond) do { if (!(cond)) { ++failures; \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); } } while (0)

/* A tiny fake environment: up to 8 NAME=VALUE pairs. */
static const char *fake[8][2];
static unsigned fake_n;
static const char *fake_env(const char *name) {
    unsigned i;
    for (i = 0; i < fake_n; ++i)
        if (strcmp(fake[i][0], name) == 0) return fake[i][1];
    return NULL;
}
static void env_clear(void) { fake_n = 0; }
static void env_set(const char *n, const char *v) { fake[fake_n][0] = n; fake[fake_n][1] = v; ++fake_n; }

static MusashiHostSession detect(int is_linux) {
    MusashiHostSession s;
    musashi_host_session_detect(fake_env, is_linux, &s);
    return s;
}

static void one(const char *name, const char *value, int expected, const char *because) {
    MusashiHostSession s;
    env_clear();
    env_set(name, value);
    s = detect(1);
    if (s.gamescope != expected || strcmp(s.because, because) != 0) {
        ++failures;
        fprintf(stderr, "FAIL detect %s=%s: gamescope=%d because=%s (want %d %s)\n",
                name, value, s.gamescope, s.because, expected, because);
    }
}

static void detection(void) {
    MusashiHostSession s;
    /* The launcher's GamescopeHandoffTests vectors. */
    one("GAMESCOPE_WAYLAND_DISPLAY", "gamescope-0", 1, "GAMESCOPE_WAYLAND_DISPLAY");
    one("XDG_CURRENT_DESKTOP", "gamescope", 1, "XDG_CURRENT_DESKTOP");
    one("XDG_CURRENT_DESKTOP", "KDE:gamescope", 1, "XDG_CURRENT_DESKTOP");
    one("XDG_SESSION_DESKTOP", "Gamescope", 1, "XDG_SESSION_DESKTOP");
    one("XDG_CURRENT_DESKTOP", "KDE", 0, "none");
    one("XDG_CURRENT_DESKTOP", "GNOME", 0, "none");
    one("SteamDeck", "1", 0, "none");
    one("SteamGamepadUI", "1", 0, "none");
    one("GAMESCOPE_WAYLAND_DISPLAY", "", 0, "none");
    one("GAMESCOPE_WAYLAND_DISPLAY", "  ", 0, "none");

    env_clear(); env_set("SteamDeck", "1"); env_set("SteamGamepadUI", "1");
    s = detect(1);
    CHECK(s.gamescope == 1 && strcmp(s.because, "SteamDeck+SteamGamepadUI") == 0);
    CHECK(s.steam_deck == 1 && s.steam_gamepad_ui == 1);

    /* SteamDeck=1 is recorded even when it does not decide. */
    env_clear(); env_set("SteamDeck", "1"); env_set("XDG_CURRENT_DESKTOP", "KDE");
    s = detect(1);
    CHECK(s.gamescope == 0 && s.steam_deck == 1 && s.steam_gamepad_ui == 0);

    /* Off Linux it is never a gamescope session, whatever the variables say. */
    env_clear(); env_set("GAMESCOPE_WAYLAND_DISPLAY", "gamescope-0");
    s = detect(0);
    CHECK(s.gamescope == 0 && strcmp(s.because, "not linux") == 0);

    /* The override beats everything, in both directions. */
    env_clear(); env_set("GAMESCOPE_WAYLAND_DISPLAY", "gamescope-0"); env_set("BFM_GAMESCOPE", "0");
    s = detect(1);
    CHECK(s.gamescope == 0 && strcmp(s.because, "BFM_GAMESCOPE=0") == 0);
    env_clear(); env_set("BFM_GAMESCOPE", "1");
    s = detect(1);
    CHECK(s.gamescope == 1 && strcmp(s.because, "BFM_GAMESCOPE=1") == 0);
    /* Anything but exactly 0 or 1 is not an override. */
    env_clear(); env_set("BFM_GAMESCOPE", "yes"); env_set("GAMESCOPE_WAYLAND_DISPLAY", "gamescope-0");
    s = detect(1);
    CHECK(s.gamescope == 1 && strcmp(s.because, "GAMESCOPE_WAYLAND_DISPLAY") == 0);

    /* No environment at all, and a NULL lookup. */
    env_clear();
    s = detect(1);
    CHECK(s.gamescope == 0 && strcmp(s.because, "none") == 0);
    musashi_host_session_detect(NULL, 1, &s);
    CHECK(s.gamescope == 0 && strcmp(s.because, "none") == 0);
}

static void flags(void) {
    CHECK(musashi_host_flag(NULL) == -1);
    CHECK(musashi_host_flag("") == -1);
    CHECK(musashi_host_flag("1") == 1 && musashi_host_flag("TRUE") == 1 &&
          musashi_host_flag("On") == 1 && musashi_host_flag("yes") == 1);
    CHECK(musashi_host_flag("0") == 0 && musashi_host_flag("False") == 0 &&
          musashi_host_flag("off") == 0 && musashi_host_flag("NO") == 0);
    CHECK(musashi_host_flag("auto") == -1 && musashi_host_flag("2") == -1 &&
          musashi_host_flag("maybe") == -1);
}

static void decide_case(const char *envv, int cfg, int gamescope, int want, const char *reason) {
    MusashiWindowDecision d = musashi_host_window_decide(envv, cfg, gamescope);
    if (d.fullscreen != want || strcmp(d.reason, reason) != 0) {
        ++failures;
        fprintf(stderr, "FAIL decide env=%s cfg=%d gamescope=%d: %d %s (want %d %s)\n",
                envv ? envv : "(null)", cfg, gamescope, d.fullscreen, d.reason, want, reason);
    }
}

static void window_decision(void) {
    /* Today's behaviour is the default everywhere that is not Gamescope. */
    decide_case(NULL, -1, 0, 0, "default");
    decide_case("", -1, 0, 0, "default");
    decide_case("auto", -1, 0, 0, "default");
    /* Gamescope alone turns fullscreen on. */
    decide_case(NULL, -1, 1, 0, "gamescope-windowed");   /* r51: no automatic fullscreen */
    decide_case("auto", -1, 1, 0, "gamescope-windowed");
    /* An explicit config value wins over Gamescope, in both directions. */
    decide_case(NULL, 0, 1, 0, "config video.fullscreen=0");
    decide_case(NULL, 1, 0, 1, "config video.fullscreen=1");
    /* The environment wins over the config and over Gamescope. */
    decide_case("0", 1, 1, 0, "BFM_FULLSCREEN=0");
    decide_case("1", 0, 0, 1, "BFM_FULLSCREEN=1");
    decide_case("false", -1, 1, 0, "BFM_FULLSCREEN=0");
    decide_case("true", -1, 0, 1, "BFM_FULLSCREEN=1");
    /* A config value outside 0/1 is "unset". */
    decide_case(NULL, 7, 1, 0, "gamescope-windowed");
    decide_case(NULL, -5, 0, 0, "default");
}

static void fit_case(int dw, int dh, int ex, int ey, int ew, int eh, int bars) {
    int x, y, w, h, r = musashi_host_fit_rect(dw, dh, 4, 3, &x, &y, &w, &h);
    if (x != ex || y != ey || w != ew || h != eh || r != bars) {
        ++failures;
        fprintf(stderr, "FAIL fit %dx%d: %d,%d %dx%d bars=%d (want %d,%d %dx%d bars=%d)\n",
                dw, dh, x, y, w, h, r, ex, ey, ew, eh, bars);
    }
}

static void fit_rect(void) {
    int x, y, w, h;
    /* Exact 4:3 is a no-op, at any scale. */
    fit_case(1280, 960, 0, 0, 1280, 960, 0);
    fit_case(640, 480, 0, 0, 640, 480, 0);
    fit_case(1024, 768, 0, 0, 1024, 768, 0);
    fit_case(2880, 2160, 0, 0, 2880, 2160, 0);
    /* Wider than 4:3: bars left and right (the handheld cases). */
    fit_case(1280, 800, 106, 0, 1067, 800, 1);    /* 16:10 */
    fit_case(1920, 1080, 240, 0, 1440, 1080, 1);  /* 16:9 */
    fit_case(1280, 720, 160, 0, 960, 720, 1);
    fit_case(2560, 1600, 213, 0, 2133, 1600, 1);
    fit_case(1366, 768, 171, 0, 1024, 768, 1);
    fit_case(1280, 800, 106, 0, 1067, 800, 1);
    /* Taller than 4:3 (a rotated panel): bars top and bottom. */
    fit_case(800, 1280, 0, 340, 800, 600, 1);
    fit_case(1080, 1920, 0, 555, 1080, 810, 1);
    /* Tiny and odd sizes round to the nearest pixel and never leave the drawable. */
    fit_case(1, 1, 0, 0, 1, 1, 0);
    fit_case(3, 1, 1, 0, 1, 1, 1);
    fit_case(7, 5, 0, 0, 7, 5, 0);               /* 7x5 -> h = (7*3+2)/4 = 5 */
    /* Invalid input fills the drawable and reports no bars. */
    CHECK(musashi_host_fit_rect(0, 480, 4, 3, &x, &y, &w, &h) == 0 && w == 0 && h == 480);
    CHECK(musashi_host_fit_rect(640, -1, 4, 3, &x, &y, &w, &h) == 0 && w == 640 && h == -1);
    CHECK(musashi_host_fit_rect(640, 480, 0, 3, &x, &y, &w, &h) == 0 && w == 640 && h == 480);
    CHECK(musashi_host_fit_rect(640, 480, 4, 0, &x, &y, &w, &h) == 0 && w == 640 && h == 480);
    CHECK(musashi_host_fit_rect(640, 480, 4, 3, NULL, NULL, NULL, NULL) == 0);
    /* A drawable far beyond int range of the product still fits (64-bit math). */
    fit_case(32000, 18000, 4000, 0, 24000, 18000, 1);
}

/* Property sweep: the rectangle stays inside the drawable, is centred to
 * within a pixel, keeps the 4:3 shape to within rounding, and fills one full
 * dimension. */
static void sweep(void) {
    int dw, dh;
    for (dw = 1; dw <= 400; ++dw)
        for (dh = 1; dh <= 400; ++dh) {
            int x, y, w, h, r = musashi_host_fit_rect(dw, dh, 4, 3, &x, &y, &w, &h);
            long long err;
            if (x < 0 || y < 0 || w < 1 || h < 1 || x + w > dw || y + h > dh) { CHECK(0); return; }
            if (!(w == dw || h == dh)) { CHECK(0); return; }
            if ((dw - w) - 2 * x < 0 || (dw - w) - 2 * x > 1) { CHECK(0); return; }
            if ((dh - h) - 2 * y < 0 || (dh - h) - 2 * y > 1) { CHECK(0); return; }
            if (r != (w != dw || h != dh)) { CHECK(0); return; }
            /* |w/h - 4/3| within one source pixel of rounding. */
            err = (long long)w * 3 - (long long)h * 4;
            if (err < 0) err = -err;
            if (w > 3 && h > 3 && err > 4) { CHECK(0); return; }
        }
}

int main(void) {
    detection();
    flags();
    window_decision();
    fit_rect();
    sweep();
    if (failures) {
        fprintf(stderr, "host session probe: %d failure(s)\n", failures);
        return 1;
    }
    printf("host session probe ok\n");
    return 0;
}
