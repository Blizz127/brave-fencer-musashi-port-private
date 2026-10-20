#ifndef MUSASHI_HOST_SESSION_H
#define MUSASHI_HOST_SESSION_H
/* Host session facts for the owner handheld gate (Steam Game Mode / Gamescope).
 *
 * Pure logic: no SDL, no I/O, the environment is an injected lookup, so it
 * compiles on every host lane and is unit-tested without a display
 * (tests/host_session_probe.c). native_boot.c supplies getenv and the SDL
 * calls; see docs/HANDHELD-AUDIT-r49e.md for what each decision rests on.
 *
 * Nothing here changes behaviour by itself: every default is the desktop
 * default (windowed, stretched present). Gamescope is only acted on where
 * native_boot.c asks. */
#include <stdlib.h>
#include <string.h>

#if defined(__linux__)
#define MUSASHI_HOST_IS_LINUX 1
#else
#define MUSASHI_HOST_IS_LINUX 0
#endif

typedef const char *(*MusashiHostEnv)(const char *name);

typedef struct {
    int gamescope;          /* 1: a Gamescope session (Steam Game Mode) */
    const char *because;    /* what decided it, for the log: a variable name or "none" */
    int steam_deck;         /* SteamDeck == "1" */
    int steam_gamepad_ui;   /* SteamGamepadUI == "1" */
} MusashiHostSession;

static inline int musashi_host_blank(const char *s) {
    if (!s) return 1;
    for (; *s; ++s)
        if (*s != ' ' && *s != '\t' && *s != '\n' && *s != '\r') return 0;
    return 1;
}

static inline char musashi_host_lower(char c) {
    return (c >= 'A' && c <= 'Z') ? (char)(c - 'A' + 'a') : c;
}

static inline int musashi_host_eq_nocase(const char *a, const char *b) {
    if (!a || !b) return 0;
    for (; *a && *b; ++a, ++b)
        if (musashi_host_lower(*a) != musashi_host_lower(*b)) return 0;
    return *a == *b;
}

static inline int musashi_host_contains_nocase(const char *hay, const char *needle) {
    size_t n = needle ? strlen(needle) : 0, i, j;
    if (!hay || !n) return 0;
    for (i = 0; hay[i]; ++i) {
        for (j = 0; j < n; ++j) {
            if (!hay[i + j]) return 0;
            if (musashi_host_lower(hay[i + j]) != musashi_host_lower(needle[j])) break;
        }
        if (j == n) return 1;
    }
    return 0;
}

/* 1 for on/1/true/yes, 0 for off/0/false/no, -1 for unset or anything else
 * (so "auto" and typos fall through to the next rule instead of deciding). */
static inline int musashi_host_flag(const char *v) {
    if (!v || !*v) return -1;
    if (musashi_host_eq_nocase(v, "1") || musashi_host_eq_nocase(v, "on") ||
        musashi_host_eq_nocase(v, "true") || musashi_host_eq_nocase(v, "yes")) return 1;
    if (musashi_host_eq_nocase(v, "0") || musashi_host_eq_nocase(v, "off") ||
        musashi_host_eq_nocase(v, "false") || musashi_host_eq_nocase(v, "no")) return 0;
    return -1;
}

/* Gamescope (SteamOS / Bazzite Game Mode). The rule is the owner's launcher's
 * own (SteamGameMode.DetectGamescope in banshee-realm-client, device-exercised
 * there), so the launcher and the game agree on what Game Mode is:
 * GAMESCOPE_WAYLAND_DISPLAY non-blank, or XDG_CURRENT_DESKTOP / XDG_SESSION_DESKTOP
 * naming gamescope, or SteamDeck=1 together with SteamGamepadUI=1. SteamDeck=1
 * alone is NOT enough (a Deck-image desktop session sets it too). Linux only.
 * BFM_GAMESCOPE=0 / =1 force it off / on (device diagnosis). */
static inline void musashi_host_session_detect(MusashiHostEnv env, int is_linux,
                                               MusashiHostSession *out) {
    const char *v;
    if (!out) return;
    memset(out, 0, sizeof *out);
    out->because = "none";
    if (!env) return;
    v = env("SteamDeck");
    out->steam_deck = v && strcmp(v, "1") == 0;
    v = env("SteamGamepadUI");
    out->steam_gamepad_ui = v && strcmp(v, "1") == 0;
    if (!is_linux) { out->because = "not linux"; return; }
    v = env("BFM_GAMESCOPE");
    if (v && strcmp(v, "0") == 0) { out->because = "BFM_GAMESCOPE=0"; return; }
    if (v && strcmp(v, "1") == 0) { out->gamescope = 1; out->because = "BFM_GAMESCOPE=1"; return; }
    if (!musashi_host_blank(env("GAMESCOPE_WAYLAND_DISPLAY"))) {
        out->gamescope = 1; out->because = "GAMESCOPE_WAYLAND_DISPLAY";
    } else if (musashi_host_contains_nocase(env("XDG_CURRENT_DESKTOP"), "gamescope")) {
        out->gamescope = 1; out->because = "XDG_CURRENT_DESKTOP";
    } else if (musashi_host_contains_nocase(env("XDG_SESSION_DESKTOP"), "gamescope")) {
        out->gamescope = 1; out->because = "XDG_SESSION_DESKTOP";
    } else if (out->steam_deck && out->steam_gamepad_ui) {
        out->gamescope = 1; out->because = "SteamDeck+SteamGamepadUI";
    }
}

static inline const char *musashi_host_getenv(const char *name) { return getenv(name); }

static inline void musashi_host_session_detect_env(MusashiHostSession *out) {
    musashi_host_session_detect(musashi_host_getenv, MUSASHI_HOST_IS_LINUX, out);
}

/* Window mode. Precedence, first rule that decides wins:
 *   1. BFM_FULLSCREEN (1/0; --fullscreen and --windowed set it),
 *   2. an explicit config.ini [video] fullscreen = 1 / 0 (config_fullscreen is
 *      -1 when the file does not set it, so the Enhancements DISPLAY row is a
 *      kill switch that works from the pad),
 *   3. Gamescope -> borderless desktop fullscreen,
 *   4. windowed, which is today's behaviour on every other session. */
typedef struct {
    int fullscreen;         /* 1: request borderless desktop fullscreen */
    const char *reason;
} MusashiWindowDecision;

static inline MusashiWindowDecision musashi_host_window_decide(const char *env_fullscreen,
                                                               int config_fullscreen,
                                                               int gamescope) {
    MusashiWindowDecision d;
    int e = musashi_host_flag(env_fullscreen);
    if (e >= 0) {
        d.fullscreen = e;
        d.reason = e ? "BFM_FULLSCREEN=1" : "BFM_FULLSCREEN=0";
    } else if (config_fullscreen == 0 || config_fullscreen == 1) {
        d.fullscreen = config_fullscreen;
        d.reason = config_fullscreen ? "config video.fullscreen=1" : "config video.fullscreen=0";
    } else if (gamescope) {
        d.fullscreen = 1;
        d.reason = "gamescope";
    } else {
        d.fullscreen = 0;
        d.reason = "default";
    }
    return d;
}

/* The largest rectangle of aspect aw:ah centred in a dw x dh drawable, for a
 * fullscreen window whose aspect is not the game's. Returns 1 when bars are
 * needed (the rectangle is smaller than the drawable), 0 when it fills it.
 * Invalid input fills the drawable. Rounds to the nearest pixel; the bars
 * differ by at most one pixel. */
static inline int musashi_host_fit_rect(int dw, int dh, int aw, int ah,
                                        int *x, int *y, int *w, int *h) {
    long long wide, tall;
    int fx = 0, fy = 0, fw = dw, fh = dh;
    if (dw >= 1 && dh >= 1 && aw >= 1 && ah >= 1) {
        wide = (long long)dw * ah;     /* dw/dh against aw/ah, cross-multiplied */
        tall = (long long)dh * aw;
        if (wide > tall) {             /* wider than the game: bars left and right */
            long long n = ((long long)dh * aw + ah / 2) / ah;
            fw = n < 1 ? 1 : n > dw ? dw : (int)n;
            fx = (dw - fw) / 2;
        } else if (wide < tall) {      /* taller than the game: bars top and bottom */
            long long n = ((long long)dw * ah + aw / 2) / aw;
            fh = n < 1 ? 1 : n > dh ? dh : (int)n;
            fy = (dh - fh) / 2;
        }
    }
    if (x) *x = fx;
    if (y) *y = fy;
    if (w) *w = fw;
    if (h) *h = fh;
    return fw != dw || fh != dh;
}
#endif
