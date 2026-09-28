#include "bfm_plat_input.h"
#include "bfm_plat_mods.h"

#include <string.h>

#define MAX_BACKENDS 8

static BfmPlatPad scripted_pads[BFM_PLAT_PAD_PORTS];
static uint32_t scripted_hotkeys;

static int scripted_open(void *self) {
    unsigned i;
    (void)self;
    for (i = 0; i < BFM_PLAT_PAD_PORTS; i++) {
        memset(&scripted_pads[i], 0, sizeof scripted_pads[i]);
        scripted_pads[i].lx = scripted_pads[i].ly = 0x80;
        scripted_pads[i].rx = scripted_pads[i].ry = 0x80;
    }
    scripted_pads[0].connected = 1;
    scripted_hotkeys = 0;
    return BFM_PLAT_OK;
}

static int scripted_poll(void *self, BfmPlatPad pads[BFM_PLAT_PAD_PORTS],
                         uint32_t *hk) {
    (void)self;
    memcpy(pads, scripted_pads, sizeof scripted_pads);
    *hk = scripted_hotkeys;
    return BFM_PLAT_OK;
}

static const BfmPlatInputBackend null_backend = {
    "null", scripted_open, NULL, scripted_poll, NULL, NULL
};

static const BfmPlatInputBackend *backends[MAX_BACKENDS] = {&null_backend};
static unsigned backend_count = 1;
static const BfmPlatInputBackend *active;
static BfmPlatPad latched[BFM_PLAT_PAD_PORTS];
static uint32_t hotkeys_now, hotkeys_prev;

void bfm_plat_input_scripted_set(unsigned port, const BfmPlatPad *pad) {
    if (port < BFM_PLAT_PAD_PORTS && pad) scripted_pads[port] = *pad;
}

void bfm_plat_input_scripted_hotkeys(uint32_t hk) { scripted_hotkeys = hk; }

int bfm_plat_input_register(const BfmPlatInputBackend *b) {
    unsigned i;
    if (!b || !b->name || !*b->name || !b->poll) return BFM_PLAT_INVALID;
    for (i = 0; i < backend_count; i++)
        if (strcmp(backends[i]->name, b->name) == 0) return BFM_PLAT_INVALID;
    if (backend_count >= MAX_BACKENDS) return BFM_PLAT_NO_SPACE;
    backends[backend_count++] = b;
    return BFM_PLAT_OK;
}

int bfm_plat_input_open(const char *name, const char **selected) {
    const BfmPlatInputBackend *b = &null_backend;
    unsigned i;
    int r;
    bfm_plat_input_close();
    for (i = 0; name && i < backend_count; i++)
        if (strcmp(backends[i]->name, name) == 0) b = backends[i];
    r = b->open ? b->open(b->self) : BFM_PLAT_OK;
    if (r != BFM_PLAT_OK && b != &null_backend) {
        b = &null_backend;
        r = b->open(b->self);
    }
    active = b;
    memset(latched, 0, sizeof latched);
    hotkeys_now = hotkeys_prev = 0;
    if (selected) *selected = b->name;
    return r;
}

void bfm_plat_input_close(void) {
    if (active && active->close) active->close(active->self);
    active = NULL;
}

const char *bfm_plat_input_active(void) { return active ? active->name : NULL; }

int bfm_plat_input_poll(void) {
    BfmPlatPad pads[BFM_PLAT_PAD_PORTS];
    uint32_t hk = 0;
    int r;
    if (!active) return BFM_PLAT_NOT_READY;
    memset(pads, 0, sizeof pads);
    r = active->poll(active->self, pads, &hk);
    if (r != BFM_PLAT_OK) return r;
    {
        BfmEventInput ev;
        ev.pads = pads;
        ev.hotkeys = &hk;
        bfm_plat_mods_emit(BFM_EVENT_INPUT, &ev);
    }
    memcpy(latched, pads, sizeof pads);
    hotkeys_prev = hotkeys_now;
    hotkeys_now = hk;
    return BFM_PLAT_OK;
}

int bfm_plat_input_pad(unsigned port, BfmPlatPad *out) {
    if (!active) return BFM_PLAT_NOT_READY;
    if (port >= BFM_PLAT_PAD_PORTS || !out) return BFM_PLAT_INVALID;
    *out = latched[port];
    return BFM_PLAT_OK;
}

uint32_t bfm_plat_input_hotkeys(void) { return hotkeys_now; }
uint32_t bfm_plat_input_hotkeys_pressed(void) {
    return hotkeys_now & ~hotkeys_prev;
}

int bfm_plat_input_set_bindings(const BfmPlatBinding *b, size_t n) {
    if (!active) return BFM_PLAT_NOT_READY;
    if (n && !b) return BFM_PLAT_INVALID;
    return active->set_bindings ? active->set_bindings(active->self, b, n)
                                : BFM_PLAT_UNSUPPORTED;
}

size_t bfm_plat_pad_to_wire(const BfmPlatPad *pad, uint8_t out[8]) {
    uint16_t low;
    if (!pad || !out || !pad->connected) return 0;
    low = (uint16_t)~pad->buttons;
    out[0] = pad->analog ? 0x73 : 0x41;
    out[1] = 0x5A;
    out[2] = (uint8_t)(low & 0xFFu);
    out[3] = (uint8_t)(low >> 8);
    if (!pad->analog) return 4;
    out[4] = pad->rx;
    out[5] = pad->ry;
    out[6] = pad->lx;
    out[7] = pad->ly;
    return 8;
}

void bfm_plat_input_reset(void) {
    bfm_plat_input_close();
    backend_count = 1;
    memset(scripted_pads, 0, sizeof scripted_pads);
    scripted_hotkeys = 0;
    memset(latched, 0, sizeof latched);
    hotkeys_now = hotkeys_prev = 0;
}
