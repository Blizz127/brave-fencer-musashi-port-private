/* Known retail hook sites for SLUS-00726 (US Brave Fencer Musashi).
 *
 * Addresses and field offsets only (facts about the program, no retail
 * bytes). Evidence paths are relative to vendor/bfm-decomp (Druthulu's
 * cleaned decomp of the same build, gitignored, fetched separately) or to
 * this repository. tests/test_bfm_plat.py pins each site to its symbol and,
 * when the vendor tree is present, checks that the cited lines still say
 * what the evidence claims. */
#include "bfm_plat_events.h"
#include "bfm_plat_mods.h"

#include <stdlib.h>
#include <string.h>

static int read_u16(uint32_t a, uint32_t *out) {
    uint8_t b[2];
    int r = bfm_plat_guest_read(a, b, 2);
    if (r == BFM_PLAT_OK) *out = (uint32_t)b[0] | ((uint32_t)b[1] << 8);
    return r;
}

static int read_u32(uint32_t a, uint32_t *out) {
    uint8_t b[4];
    int r = bfm_plat_guest_read(a, b, 4);
    if (r == BFM_PLAT_OK)
        *out = (uint32_t)b[0] | ((uint32_t)b[1] << 8) | ((uint32_t)b[2] << 16) |
               ((uint32_t)b[3] << 24);
    return r;
}

/* "SC02_031" / "sc02_0031" -> area 2, room 31. */
static void overlay_room(BfmEventRoom *room) {
    const char *o = bfm_plat_hooks_overlay();
    const char *us;
    room->area = room->room = 0;
    if (!o || (o[0] != 'S' && o[0] != 's') || (o[1] != 'C' && o[1] != 'c')) return;
    room->area = (uint32_t)strtoul(o + 2, NULL, 10);
    us = strchr(o, '_');
    if (us) room->room = (uint32_t)strtoul(us + 1, NULL, 10);
}

/* Edge state, reset by bfm_plat_hooks_register_known. */
static uint32_t last_phase = 0xFFFFFFFFu;
static char last_overlay[32];
static uint32_t last_card_state_save = 0xFFFFFFFFu;
static uint32_t last_card_state_load = 0xFFFFFFFFu;

/* Location-overlay entry stub: fires once when the scene phase is 0 (init)
 * after being non-zero, or when a different overlay reaches phase 0. */
static int fill_room_enter(void *u, BfmEvent e, BfmPlatEventPayload *p) {
    uint32_t phase;
    const char *o = bfm_plat_hooks_overlay();
    int changed;
    (void)u; (void)e;
    if (read_u16(BFM_GUEST_SCENE_PHASE, &phase) != BFM_PLAT_OK) return 1;
    changed = strcmp(last_overlay, o ? o : "") != 0;
    if (phase == 0 && (last_phase != 0 || changed)) {
        last_phase = phase;
        strncpy(last_overlay, o ? o : "", sizeof last_overlay - 1);
        overlay_room(&p->room);
        return 0;
    }
    last_phase = phase;
    strncpy(last_overlay, o ? o : "", sizeof last_overlay - 1);
    return 1;
}

/* func_80011B7C(mode): the scene loop leaves with mode 8. */
static int fill_room_exit(void *u, BfmEvent e, BfmPlatEventPayload *p) {
    uint32_t a0;
    (void)u; (void)e;
    if (bfm_plat_guest_reg(BFM_GUEST_REG_A0, &a0) != BFM_PLAT_OK) return 1;
    if ((a0 & 0xFFFFu) != 8u) return 1;
    if (!bfm_plat_overlay_matches("SC*", bfm_plat_hooks_overlay())) return 1;
    overlay_room(&p->room);
    last_phase = 0xFFFFFFFFu;
    return 0;
}

static int card_edge(uint32_t *last, int (*want)(uint32_t), BfmPlatEventPayload *p) {
    uint32_t st, a1;
    if (read_u32(BFM_GUEST_CARD_STATE, &st) != BFM_PLAT_OK) return 1;
    if (!want(st) || st == *last) {
        *last = st;
        return 1;
    }
    *last = st;
    if (bfm_plat_guest_reg(BFM_GUEST_REG_A1, &a1) != BFM_PLAT_OK) a1 = 0;
    p->save.slot = a1;
    return 0;
}

static int is_save_state(uint32_t s) { return s == 13u; }
static int is_load_state(uint32_t s) { return s == 17u || s == 32u; }

static int fill_save(void *u, BfmEvent e, BfmPlatEventPayload *p) {
    (void)u; (void)e;
    return card_edge(&last_card_state_save, is_save_state, p);
}

static int fill_load(void *u, BfmEvent e, BfmPlatEventPayload *p) {
    (void)u; (void)e;
    return card_edge(&last_card_state_load, is_load_state, p);
}

static const BfmPlatKnownSite known[] = {
    {0x800189A8u, NULL, BFM_EVENT_FRAME_BEGIN, "func_800189A8",
     "src/boot.c:310 first call in main's per-frame inner loop (main @ src/boot.c:277); "
     "src/800.c:6042 body polls both pads (0x4C-byte records at D_80078D98, PadGetState at src/800.c:6094); "
     "also called once per frame by the resident modal loop src/md_MAIN_003/md_MAIN_003_jr_800D1E18.c:236",
     "high: runs exactly once per main-loop frame, before GameModeDispatch; the modal loop "
     "caller also gets FRAME_BEGIN but no FRAME_END", NULL},
    {0x800184F0u, NULL, BFM_EVENT_FRAME_END, "func_800184F0",
     "src/boot.c:372 called right before VSync(*(s32 *)(p + 0xA3E8)) at src/boot.c:374; "
     "definition src/800.c:5761; only caller in vendor/bfm-decomp/src",
     "high: last game call of each main-loop frame before the VSync wait", NULL},
    {0x80128158u, "SC*", BFM_EVENT_ROOM_ENTER, "func_80128158",
     "location-overlay export stub 0 -> func_80128288 (src/overlays/main_0012/80128288.c in this repo: "
     "dispatch D_8017E618[D_800B99F6] for phase < 9); called every scene-loop frame by resident "
     "func_800CF238 at src/resident/resident.c:255; phase 0 reached the SC02/31 init routine "
     "80128420 in docs/MENU-BOOT-CONTINUATION.md (\"SC02 initialization routine\")",
     "medium: phase 0 = scene init is observed for SC02/31 only; fill fires on the edge into "
     "phase 0 or on an overlay change. area/room come from the overlay name the native lane "
     "reports, not from guest RAM", fill_room_enter},
    {0x80011B7Cu, NULL, BFM_EVENT_ROOM_EXIT, "func_80011B7C",
     "src/boot.c:950 sets major mode (base+0xA3C0) and clears the scene phase; the resident "
     "scene loop leaves with func_80011B7C(8) at src/resident/resident.c:261",
     "low: func_80011B7C has ~400 call sites; the fill only fires for mode 8 while a location "
     "overlay is selected, which matches the scene-loop exit but is not proven unique", fill_room_exit},
    {0x8002B0B4u, NULL, BFM_EVENT_SAVE, "func_8002B0B4",
     "memory-card save/load state machine (src/800_b.c:87, 'SaveLoadRoutine' is its case 0); "
     "state 13 writes the slot's 0x300-byte game-state block D_80075CC0 at idx*0x300+0x480 "
     "(src/800_b.c:301, src/800_b.c:318) then advances D_800760AC",
     "medium: fires on entry when D_800760AC becomes 13 (slot = $a1 idx); the state switch sits "
     "under a card-event poll, so a retried write can fire twice", fill_save},
    {0x8002B0B4u, NULL, BFM_EVENT_LOAD, "func_8002B0B4",
     "same state machine; states 17 and 32 read the slot's game-state block with "
     "func_80060404(D_80075CC0, idx*0x300+0x480, 0x300) (src/800_b.c:486-488)",
     "medium: as for save; states 17/32 are the two read paths", fill_load},
};

static const BfmEvent unsited[] = {
    BFM_EVENT_BATTLE_START, BFM_EVENT_BATTLE_END, BFM_EVENT_ITEM_GET
};

size_t bfm_plat_known_sites(const BfmPlatKnownSite **out) {
    if (out) *out = known;
    return sizeof known / sizeof known[0];
}

size_t bfm_plat_unsited_events(const BfmEvent **out) {
    if (out) *out = unsited;
    return sizeof unsited / sizeof unsited[0];
}

int bfm_plat_hooks_register_known(void) {
    BfmPlatHookSite s[sizeof known / sizeof known[0]];
    size_t i;
    last_phase = 0xFFFFFFFFu;
    last_overlay[0] = '\0';
    last_card_state_save = last_card_state_load = 0xFFFFFFFFu;
    memset(s, 0, sizeof s);
    for (i = 0; i < sizeof known / sizeof known[0]; i++) {
        s[i].guest_pc = known[i].guest_pc;
        s[i].event = known[i].event;
        s[i].label = known[i].symbol;
        s[i].fill = known[i].fill;
        s[i].overlay = known[i].overlay;
    }
    return bfm_plat_hooks_register(s, i);
}
