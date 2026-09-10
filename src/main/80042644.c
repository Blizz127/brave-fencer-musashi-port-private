#include "psx_types.h"

/* Exact callback-table dispatch [80042644,80042674). */

typedef void (*CallbackDispatch)(s32, void *);
typedef struct {
    u8 opaque00[0x14];
    CallbackDispatch callback14;
} CallbackTable;

extern CallbackTable *D_8006CB84;

void func_80042644(s32 index, void *value) {
    D_8006CB84->callback14(index, value);
}
