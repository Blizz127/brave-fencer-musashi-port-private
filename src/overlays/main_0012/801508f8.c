/* Owner re-derivation from retail assembly (clean input set). */
/* Unless +0x1BF is zero or the type at +0 is 0x1A, calls func_8015094C until it returns zero. */
#include "psx_types.h"

typedef struct {
    /* 0x000 */ u16 type;
    u8 pad002[0x1BD];
    /* 0x1BF */ u8 active;
} Obj801508F8;

extern s32 func_8015094C(Obj801508F8 *obj);

/* Declared s32 but returns no value: retail keeps v0 live at the exit (nop in the
 * first delay slot), which only an int-typed function produces. The one caller
 * (801464FC) ignores v0, so no value is defined or needed. */
s32 func_801508F8(Obj801508F8 *obj)
{
    if (obj->active == 0) {
        return;
    }
    if (obj->type == 0x1A) {
        return;
    }
    while (func_8015094C(obj)) {
    }
}
