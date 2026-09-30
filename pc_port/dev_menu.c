/* Port Dev Menu model (musashi_dev_menu.h; shared port spec v1). */
#include "musashi_dev_menu.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GUEST_HP_MAX 0x80078eb2u
#define GUEST_HP 0x80078eb4u
#define GUEST_BP_MAX 0x80078eb6u
#define GUEST_BP 0x80078eb8u
#define GUEST_DRANS 0x80078e8cu
#define GUEST_HOUR 0x80078eb1u
#define DRANS_CAP 99999u
#define DRANS_STEP 10000u

enum { PAGE_ROOT, PAGE_WARP, PAGE_FINISH, PAGE_CHEATS, PAGE_OPTIONS };
enum { SCRIPT_MAX = 64, LINES_MAX = 24, LINE_W = 56 };
enum { ACT_NONE, ACT_DRANS, ACT_HOUR };

/* Verified entries only (spec §6/§7): each row is added after the warp or
 * area-finish sweep passes for it. Grouped by chapter. */
typedef struct DevJump { const char *chapter, *label; } DevJump;
static const DevJump kWarps[] = { { NULL, NULL } };
static const DevJump kFinish[] = { { NULL, NULL } };
enum { WARP_COUNT = 0, FINISH_COUNT = 0 };

static const char *const kRoot[] = { "WARP >", "FINISH AREA >", "CHEATS >", "OPTIONS >" };

static struct {
    int inited, enabled, hard_disabled, open, page, selection, help;
    int god, resource, ff_toggle, ff_hold, used, used_reported;
    unsigned ff_speed_index, shot_requests;
    unsigned vblanks, cheat_writes, one_shots, refusals;
    int pending;
    unsigned scene, mode;
    int in_scene, in_field;
    MusashiDevMenuGuest guest;
    struct { unsigned frame, key; } script[SCRIPT_MAX];
    unsigned nscript, iscript;
    char toast[LINE_W];
    char lines[LINES_MAX][LINE_W];
} M;

static const unsigned kFfSpeeds[] = { 2u, 4u, 8u, 0u };

static unsigned parse_key(const char *s, size_t n) {
    static const struct { const char *name; unsigned key; } names[] = {
        {"TOGGLE", MUSASHI_DEV_KEY_TOGGLE}, {"UP", MUSASHI_DEV_KEY_UP},
        {"DOWN", MUSASHI_DEV_KEY_DOWN}, {"OK", MUSASHI_DEV_KEY_OK},
        {"BACK", MUSASHI_DEV_KEY_BACK}, {"HELP", MUSASHI_DEV_KEY_HELP},
        {"GOD", MUSASHI_DEV_KEY_GOD}, {"RESOURCE", MUSASHI_DEV_KEY_RESOURCE},
        {"FF", MUSASHI_DEV_KEY_FF}, {"FFSPEED", MUSASHI_DEV_KEY_FF_SPEED},
        {"SHOT", MUSASHI_DEV_KEY_SHOT}};
    size_t i;
    for (i = 0; i < sizeof names / sizeof names[0]; ++i)
        if (strlen(names[i].name) == n && !strncmp(s, names[i].name, n)) return names[i].key;
    return 0;
}

static void parse_script(const char *s) {
    while (s && *s && M.nscript < SCRIPT_MAX) {
        char *end;
        unsigned long frame = strtoul(s, &end, 10);
        const char *key = end + 1, *next;
        size_t n;
        if (end == s || *end != ':') break;
        next = strchr(key, ',');
        n = next ? (size_t)(next - key) : strlen(key);
        M.script[M.nscript].frame = (unsigned)frame;
        M.script[M.nscript].key = parse_key(key, n);
        if (M.script[M.nscript].key) ++M.nscript;
        s = next ? next + 1 : NULL;
    }
}

int musashi_dev_menu_init(const MusashiDevMenuGuest *guest, int force_on) {
    const char *env = getenv("BFM_DEV_MENU"), *cheats = getenv("BFM_CHEATS");
    if (M.inited) return M.enabled;
    memset(&M, 0, sizeof M);
    M.inited = 1;
    M.hard_disabled = cheats && cheats[0] == '0';
    M.enabled = !M.hard_disabled && guest && (force_on || (env && env[0] == '1'));
    if (guest && !M.hard_disabled) M.guest = *guest;
    if (M.hard_disabled) {
        fprintf(stderr, "[DEV_MENU] hard-disabled (BFM_CHEATS=0)\n");
        return 0;
    }
    if (!M.enabled) return 0;
    parse_script(getenv("BFM_DEV_MENU_KEYS"));
    fprintf(stderr, "[DEV_MENU] enabled scripted_keys=%u (F8 or Back+Start opens, F1 help)\n",
            M.nscript);
    return 1;
}

int musashi_dev_menu_enabled(void) { return M.enabled; }
int musashi_dev_menu_hard_disabled(void) { return M.hard_disabled; }
int musashi_dev_menu_is_open(void) { return M.enabled && M.open; }

void musashi_dev_menu_toast(const char *message) {
    snprintf(M.toast, sizeof M.toast, "%s", message ? message : "");
}

static unsigned page_rows(void) {
    switch (M.page) {
    case PAGE_WARP: return WARP_COUNT + 1u;
    case PAGE_FINISH: return FINISH_COUNT + 1u;
    case PAGE_CHEATS: return 5u;
    case PAGE_OPTIONS: return 4u;
    default: return 4u;
    }
}

static void mark_used(void) { M.used = 1; }

static void set_toggle(int *flag, int on, const char *name) {
    *flag = on;
    if (on) mark_used();
    fprintf(stderr, "[CHEATS] %s %s\n", name, on ? "on" : "off");
    snprintf(M.toast, sizeof M.toast, "%s: %s", name, on ? "ON" : "OFF");
}

static void request(int action, const char *name) {
    M.pending = action;
    fprintf(stderr, "[CHEATS] %s requested\n", name);
}

static void cycle_ff_speed(void) {
    M.ff_speed_index = (M.ff_speed_index + 1u) % (sizeof kFfSpeeds / sizeof kFfSpeeds[0]);
    if (kFfSpeeds[M.ff_speed_index]) fprintf(stderr, "[DEV_MENU] fast-forward speed %ux\n", kFfSpeeds[M.ff_speed_index]);
    else fprintf(stderr, "[DEV_MENU] fast-forward speed max\n");
}

static void select_row(void) {
    unsigned n = page_rows();
    if (M.page != PAGE_ROOT && (unsigned)M.selection + 1u == n) {
        M.selection = M.page - 1;   /* back to the root row it came from */
        M.page = PAGE_ROOT;
        return;
    }
    switch (M.page) {
    case PAGE_ROOT:
        M.page = PAGE_WARP + M.selection;
        M.selection = 0;
        break;
    case PAGE_CHEATS:
        if (M.selection == 0) set_toggle(&M.god, !M.god, "GOD MODE");
        else if (M.selection == 1) set_toggle(&M.resource, !M.resource, "BP MAX");
        else if (M.selection == 2) request(ACT_DRANS, "add drans");
        else request(ACT_HOUR, "time +1 hour");
        break;
    case PAGE_OPTIONS:
        if (M.selection == 0) {
            M.ff_toggle = !M.ff_toggle;
            fprintf(stderr, "[DEV_MENU] fast-forward %s\n", M.ff_toggle ? "on" : "off");
        } else if (M.selection == 1) cycle_ff_speed();
        else ++M.shot_requests;
        break;
    default: break;   /* Warp / Finish Area: no verified entries yet */
    }
}

void musashi_dev_menu_keys(unsigned pressed, int ff_hold) {
    unsigned n;
    if (M.hard_disabled) return;
    M.ff_hold = ff_hold;
    /* Always-on host keys (spec §0): fast-forward and screenshot. */
    if (pressed & MUSASHI_DEV_KEY_FF) {
        M.ff_toggle = !M.ff_toggle;
        fprintf(stderr, "[DEV_MENU] fast-forward %s\n", M.ff_toggle ? "on" : "off");
    }
    if (pressed & MUSASHI_DEV_KEY_SHOT) ++M.shot_requests;
    if (!M.enabled) return;
    if (pressed & MUSASHI_DEV_KEY_TOGGLE) {
        M.open = !M.open;
        M.page = PAGE_ROOT;
        M.selection = 0;
        M.help = 0;
        fprintf(stderr, "[DEV_MENU] %s vblank=%u\n", M.open ? "open" : "closed", M.vblanks);
        return;
    }
    if (pressed & MUSASHI_DEV_KEY_HELP) M.help = !M.help;
    if (pressed & MUSASHI_DEV_KEY_GOD) set_toggle(&M.god, !M.god, "GOD MODE");
    if (pressed & MUSASHI_DEV_KEY_RESOURCE) set_toggle(&M.resource, !M.resource, "BP MAX");
    if (pressed & MUSASHI_DEV_KEY_FF_SPEED) cycle_ff_speed();
    if (!M.open) return;
    n = page_rows();
    if (pressed & MUSASHI_DEV_KEY_UP) M.selection = (M.selection + (int)n - 1) % (int)n;
    if (pressed & MUSASHI_DEV_KEY_DOWN) M.selection = (M.selection + 1) % (int)n;
    if (pressed & MUSASHI_DEV_KEY_OK) select_row();
    else if (pressed & MUSASHI_DEV_KEY_BACK) {
        if (M.help) M.help = 0;
        else if (M.page == PAGE_ROOT) M.open = 0;
        else {
            M.selection = M.page - 1;
            M.page = PAGE_ROOT;
        }
    }
}

/* current = max, the game's own refill of its gauge (func_8014BC44). */
static void refill(uint32_t max_address, uint32_t address) {
    uint16_t max, cur;
    if (!M.guest.read16(M.guest.user, max_address, &max) ||
        !M.guest.read16(M.guest.user, address, &cur) || !max || cur == max) return;
    if (M.guest.write16(M.guest.user, address, max)) ++M.cheat_writes;
}

static void refuse(const char *why) {
    ++M.refusals;
    fprintf(stderr, "[CHEATS] refused: %s\n", why);
    snprintf(M.toast, sizeof M.toast, "%s", why);
}

static void run_pending(void) {
    int action = M.pending;
    M.pending = ACT_NONE;
    if (!M.in_field) { refuse("ONLY IN THE FIELD"); return; }
    if (action == ACT_DRANS) {
        uint32_t drans;
        if (!M.guest.read32(M.guest.user, GUEST_DRANS, &drans) || drans > DRANS_CAP) {
            refuse("DRANS NOT READABLE"); return;
        }
        drans = drans > DRANS_CAP - DRANS_STEP ? DRANS_CAP : drans + DRANS_STEP;
        if (!M.guest.write32(M.guest.user, GUEST_DRANS, drans)) { refuse("DRANS NOT WRITABLE"); return; }
        snprintf(M.toast, sizeof M.toast, "DRANS: %u", (unsigned)drans);
    } else if (action == ACT_HOUR) {
        uint8_t hour;
        if (!M.guest.read8(M.guest.user, GUEST_HOUR, &hour) || hour > 23u) { refuse("CLOCK NOT READABLE"); return; }
        if (hour == 23u) { refuse("NOT PAST MIDNIGHT (LET THE DAY END)"); return; }
        if (!M.guest.write8(M.guest.user, GUEST_HOUR, (uint8_t)(hour + 1u))) { refuse("CLOCK NOT WRITABLE"); return; }
        snprintf(M.toast, sizeof M.toast, "TIME: %02u:XX", (unsigned)hour + 1u);
    }
    ++M.one_shots;
    ++M.cheat_writes;
    mark_used();
    fprintf(stderr, "[CHEATS] %s\n", M.toast);
}

void musashi_dev_menu_vblank(int in_scene, unsigned scene, unsigned mode, int in_field) {
    if (!M.enabled) return;
    ++M.vblanks;
    M.in_scene = in_scene;
    M.in_field = in_field;
    M.scene = scene;
    M.mode = mode;
    while (M.iscript < M.nscript && M.script[M.iscript].frame <= M.vblanks)
        musashi_dev_menu_keys(M.script[M.iscript++].key, 0);
    if (M.pending) run_pending();
    if (!in_field) return;   /* toggles wait for the field */
    if (M.god) refill(GUEST_HP_MAX, GUEST_HP);
    if (M.resource) refill(GUEST_BP_MAX, GUEST_BP);
}

int musashi_dev_menu_fast_forward(void) { return !M.hard_disabled && (M.ff_toggle || M.ff_hold); }
unsigned musashi_dev_menu_ff_speed(void) { return kFfSpeeds[M.ff_speed_index]; }

int musashi_dev_menu_take_screenshot(void) {
    if (!M.shot_requests) return 0;
    M.shot_requests = 0;
    return 1;
}

int musashi_dev_menu_used(void) {
    if (!M.used || M.used_reported) return 0;
    M.used_reported = 1;
    return 1;
}

static void line(size_t *n, const char *fmt, ...) {
    va_list ap;
    if (*n >= LINES_MAX) return;
    va_start(ap, fmt);
    vsnprintf(M.lines[*n], LINE_W, fmt, ap);
    va_end(ap);
    ++*n;
}

static const char *on(int v) { return v ? "ON" : "OFF"; }

size_t musashi_dev_menu_text(const char **lines, size_t max, int *highlight, int *badge_only) {
    size_t n = 0, i, first = 0;
    int any = M.god || M.resource;
    if (highlight) *highlight = -1;
    if (badge_only) *badge_only = 0;
    if (!M.enabled || (!M.open && !any && !M.help)) return 0;
    if (!M.open && !M.help) {
        line(&n, "CHEATS");
        if (badge_only) *badge_only = 1;
    } else if (M.help) {
        line(&n, "PORT DEV MENU - KEYS");
        line(&n, " ");
        line(&n, "F8 / BACK+START   OPEN OR CLOSE THE MENU");
        line(&n, "F1                THIS HELP");
        line(&n, "F2                GOD MODE (HP KEPT AT MAX)");
        line(&n, "F3                BP MAX");
        line(&n, "F6 / L3           FAST-FORWARD ON/OFF");
        line(&n, "BACKSPACE / R3    FAST-FORWARD WHILE HELD");
        line(&n, "F7                FAST-FORWARD SPEED");
        line(&n, "F10               SCREENSHOT");
        line(&n, "UP DOWN ENTER ESC / D-PAD A B   NAVIGATE");
        line(&n, " ");
        line(&n, "THE GAME KEEPS RUNNING WHILE THE MENU IS OPEN.");
    } else {
        line(&n, "PORT DEV MENU");
        line(&n, "SCENE %04X  MODE %04X  %s", M.scene & 0xffffu, M.mode & 0xffffu,
             M.in_field ? "FIELD" : M.in_scene ? "NOT IN FIELD" : "NO SCENE");
        line(&n, " ");
        first = n;
        if (M.page == PAGE_ROOT) {
            for (i = 0; i < 4u; ++i) line(&n, "  %s", kRoot[i]);
        } else if (M.page == PAGE_WARP || M.page == PAGE_FINISH) {
            const DevJump *t = M.page == PAGE_WARP ? kWarps : kFinish;
            unsigned count = M.page == PAGE_WARP ? WARP_COUNT : FINISH_COUNT;
            for (i = 0; i < count; ++i) line(&n, "  %s: %s", t[i].chapter, t[i].label);
            if (!count) {
                line(&n, "  (NONE VERIFIED IN THE PORT YET)");
                ++first;
            }
            line(&n, "  BACK");
        } else if (M.page == PAGE_CHEATS) {
            line(&n, "  GOD MODE: %s", on(M.god));
            line(&n, "  BP MAX: %s", on(M.resource));
            line(&n, "  ADD %u DRANS", DRANS_STEP);
            line(&n, "  TIME +1 HOUR");
            line(&n, "  BACK");
        } else {
            unsigned speed = kFfSpeeds[M.ff_speed_index];
            line(&n, "  FAST-FORWARD: %s", on(M.ff_toggle));
            if (speed) line(&n, "  FAST-FORWARD SPEED: %uX", speed);
            else line(&n, "  FAST-FORWARD SPEED: MAX");
            line(&n, "  SCREENSHOT");
            line(&n, "  BACK");
        }
        if (highlight) *highlight = (int)(first + (size_t)M.selection);
        line(&n, " ");
        line(&n, "%s", M.toast[0] ? M.toast : "F1 HELP");
    }
    for (i = 0; i < n && i < max; ++i) lines[i] = M.lines[i];
    return n < max ? n : max;
}

void musashi_dev_menu_state(MusashiDevMenuState *out) {
    if (!out) return;
    out->enabled = M.enabled;
    out->hard_disabled = M.hard_disabled;
    out->open = M.open;
    out->page = M.page;
    out->selection = M.selection;
    out->help = M.help;
    out->god = M.god;
    out->resource = M.resource;
    out->ff = M.ff_toggle;
    out->ff_speed = (int)kFfSpeeds[M.ff_speed_index];
    out->vblanks = M.vblanks;
    out->cheat_writes = M.cheat_writes;
    out->one_shots = M.one_shots;
    out->refusals = M.refusals;
}

unsigned musashi_dev_menu_warp_count(void) { return WARP_COUNT; }
unsigned musashi_dev_menu_finish_count(void) { return FINISH_COUNT; }

void musashi_dev_menu_reset(void) {
    (void)kWarps;
    (void)kFinish;
    memset(&M, 0, sizeof M);
}
