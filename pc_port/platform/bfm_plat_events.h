#ifndef BFM_PLAT_EVENTS_H
#define BFM_PLAT_EVENTS_H

/* Game-event hook points.
 *
 * The events themselves (BfmEvent, payload structs) are ABI and live in
 * bfm_plugin.h. This header adds:
 *
 *  - a catalog: stable names ("room_enter") and payload descriptions for
 *    every event, for logs, the console `events` command and a future
 *    script runtime;
 *  - hook sites: a table the native lane fills with the guest function
 *    addresses where each game event happens. The dispatcher calls
 *    bfm_plat_hooks_at(pc) on entry to a guest function. If a site is
 *    registered there, its `fill` callback reads guest state (registers /
 *    RAM via bfm_plat_guest_read) into the payload, and the event fires.
 *
 * The retail addresses are not known yet: the catalog lists the hook
 * points with guest_site "TBD" until the native lane identifies them.
 * The direct emitters in bfm_plat.h (bfm_plat_event_room_enter, ...) stay
 * available for hand-ported code. */

#include "bfm_plugin.h"

typedef struct BfmPlatEventInfo {
    BfmEvent event;
    const char *name;          /* "room_enter" */
    const char *payload;       /* "BfmEventRoom" or "" */
    const char *fired_by;      /* who emits it */
    const char *description;
} BfmPlatEventInfo;

const BfmPlatEventInfo *bfm_plat_event_info(BfmEvent event);
const char *bfm_plat_event_name(BfmEvent event);
/* Returns BFM_EVENT_COUNT if unknown. */
BfmEvent bfm_plat_event_from_name(const char *name);

typedef union BfmPlatEventPayload {
    BfmEventRoom room;
    BfmEventBattle battle;
    BfmEventItem item;
    BfmEventSave save;
} BfmPlatEventPayload;

/* Reads guest state for the event at a hook site. Return 0 to fire, nonzero
 * to skip this hit (e.g. the call was not a real room change). */
typedef int (*BfmPlatHookFill)(void *user, BfmEvent event,
                               BfmPlatEventPayload *payload);

typedef struct BfmPlatHookSite {
    uint32_t guest_pc;         /* function entry (KSEG0 address) */
    BfmEvent event;
    const char *label;         /* e.g. "func_80012345 room loader" */
    BfmPlatHookFill fill;      /* NULL: fire with a zeroed payload */
    void *user;
} BfmPlatHookSite;

#define BFM_PLAT_HOOK_SITES_MAX 64

/* Registers sites (copied; label must outlive the registration). A pc may
 * carry several events. */
int bfm_plat_hooks_register(const BfmPlatHookSite *sites, size_t count);
/* Cheap check for the dispatcher's hot path. */
int bfm_plat_hooks_has(uint32_t guest_pc);
/* Fires every event registered at pc; returns how many fired. */
int bfm_plat_hooks_at(uint32_t guest_pc);
size_t bfm_plat_hooks_count(void);
void bfm_plat_hooks_reset(void);

/* Registers the `events` console command (list events + counts + sites). */
void bfm_plat_events_register_console(void);

#endif
