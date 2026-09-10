#include "psx_types.h"

/* Byte-exact indirect initialization wrapper [80042580,800425B0).
 * Initial slot +0C points to 80042718, but retain the table indirection.
 * This PS1 layout is not a host callback table. */
typedef struct {
    u8 opaque00[0xC];
    void *(*initialize)(void);
} CallbackDispatch;

/* Exact matched wrapper stream for the native MIPS diagnostic. It preserves
 * the guest table indirection; no host callback table is introduced. */
extern CallbackDispatch *D_8006CB84;

void *func_80042580(void) {
    return D_8006CB84->initialize();
}
