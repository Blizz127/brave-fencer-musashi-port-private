#ifndef BFM_PLUGIN_H
#define BFM_PLUGIN_H

/* Brave Fencer Musashi port: C plugin ABI.
 *
 * A plugin is a shared object (.so / .dll / .dylib) in a mod folder, named by
 * the manifest's `plugin =` key. It exports:
 *
 *   int  bfm_plugin_init(const BfmPluginHost *host, BfmPluginInfo *info);
 *   void bfm_plugin_shutdown(void);            (optional)
 *
 * init returns 0 to stay loaded. `host` stays valid until shutdown. Plugins
 * talk to the game only through the host table: event hooks, guest memory
 * accessors, cheats, console commands and config. The same table is the
 * seam a Lua (or other) script runtime binds to.
 *
 * ABI rules: fields are only ever appended to BfmPluginHost; check
 * host->abi_version >= the version that added a field, and host->size.
 * Plugin SDK = this header + bfm_plat_types.h + bfm_plat_input.h. */

#include "bfm_plat_types.h"
#include "bfm_plat_input.h"

#define BFM_PLUGIN_ABI_VERSION 1u

#if defined(_WIN32)
#define BFM_PLUGIN_EXPORT __declspec(dllexport)
#else
#define BFM_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

/* Named game events. Payload type in brackets (NULL if none). New events are
 * appended; numbering is part of the ABI. */
typedef enum BfmEvent {
    BFM_EVENT_BOOT = 0,           /* after all mods loaded */
    BFM_EVENT_SHUTDOWN = 1,
    BFM_EVENT_FRAME_BEGIN = 2,    /* start of a game frame */
    BFM_EVENT_FRAME_END = 3,      /* end of a game frame ("frame tick") */
    BFM_EVENT_VSYNC = 4,          /* each NTSC field waited */
    BFM_EVENT_INPUT = 5,          /* [BfmEventInput] pads may be edited */
    BFM_EVENT_BEFORE_PRESENT = 6,
    BFM_EVENT_AFTER_PRESENT = 7,
    BFM_EVENT_ROOM_ENTER = 8,     /* [BfmEventRoom] */
    BFM_EVENT_ROOM_EXIT = 9,      /* [BfmEventRoom] */
    BFM_EVENT_BATTLE_START = 10,  /* [BfmEventBattle] boss / scripted fight */
    BFM_EVENT_BATTLE_END = 11,    /* [BfmEventBattle] */
    BFM_EVENT_ITEM_GET = 12,      /* [BfmEventItem] */
    BFM_EVENT_SAVE = 13,          /* [BfmEventSave] */
    BFM_EVENT_LOAD = 14,          /* [BfmEventSave] */
    BFM_EVENT_COUNT
} BfmEvent;

typedef struct BfmEventInput {
    BfmPlatPad *pads;             /* BFM_PLAT_PAD_PORTS entries, editable */
    uint32_t *hotkeys;            /* editable */
} BfmEventInput;

typedef struct BfmEventRoom {
    uint32_t area;
    uint32_t room;
} BfmEventRoom;

typedef struct BfmEventBattle {
    uint32_t encounter;
    int32_t result;               /* END: 1 won, 0 lost/fled; START: 0 */
} BfmEventBattle;

typedef struct BfmEventItem {
    uint32_t item;
    int32_t count;
} BfmEventItem;

typedef struct BfmEventSave {
    uint32_t slot;
} BfmEventSave;

typedef void (*BfmEventFn)(void *user, BfmEvent event, void *payload);

/* A cheat. With apply == NULL it is a "poke" cheat: every frame while
 * enabled, `value` (width 1, 2 or 4 bytes, little endian) is written to
 * guest `address`. Otherwise apply() runs every frame while enabled. */
typedef struct BfmCheat {
    const char *name;             /* unique, no spaces */
    const char *description;
    uint32_t address;
    uint32_t value;
    uint8_t width;
    void (*apply)(void *user);
    void (*on_toggle)(void *user, int enabled);
    void *user;
} BfmCheat;

/* Console command. Writes its reply into out (NUL-terminated). Returns 0 on
 * success, nonzero on usage error. */
typedef int (*BfmCommandFn)(void *user, int argc, const char *const *argv,
                            char *out, size_t out_size);

typedef struct BfmPluginHost {
    uint32_t abi_version;
    uint32_t size;                /* sizeof(BfmPluginHost) of the host */
    const char *mod_name;         /* the calling plugin's mod */
    const char *mod_dir;          /* its folder (for its own files) */

    void (*log)(const char *mod, int level, const char *message);
    /* Returns a subscription id (> 0) or a negative BfmPlatResult. */
    int (*subscribe)(BfmEvent event, BfmEventFn fn, void *user);
    int (*unsubscribe)(int subscription);

    /* Guest RAM by guest address (0x80000000-based or physical). Return
     * BFM_PLAT_OK, or BFM_PLAT_NOT_READY before the runtime binds memory. */
    int (*guest_read)(uint32_t address, void *out, uint32_t size);
    int (*guest_write)(uint32_t address, const void *data, uint32_t size);

    /* The cheat struct and its strings must outlive the plugin's load. */
    int (*register_cheat)(const BfmCheat *cheat);
    int (*set_cheat)(const char *name, int enabled);
    int (*register_command)(const char *name, const char *help,
                            BfmCommandFn fn, void *user);

    /* "section.key" from the user config; plugins use "[mod.<name>]". */
    const char *(*config_get)(const char *key);
} BfmPluginHost;

typedef struct BfmPluginInfo {
    uint32_t abi_version;         /* set to BFM_PLUGIN_ABI_VERSION */
    const char *name;
    const char *version;
} BfmPluginInfo;

typedef int (*BfmPluginInitFn)(const BfmPluginHost *host, BfmPluginInfo *info);
typedef void (*BfmPluginShutdownFn)(void);

#endif
