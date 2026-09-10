#include "psx_types.h"

/* Exact matched stream for the bounded native callback-initialization
 * diagnostic. The executable path stops at the first BIOS service below. */

/* Byte-exact C recovery of callback initialization [80042718,800427F4).
 * Guest pointer views and saved CPU context are PS1-width only, not native
 * bindings. Empty tied operands retain the observed base-register lifetime
 * without adding instructions. The guarded path includes nonlocal resume. */

typedef struct {
    u32 opaque00;
    u32 callback04;
    u8 opaque08[0xC];
    u32 callback14;
} CallbackTable;
extern CallbackTable *D_8006CB84;
extern u8 D_8006BAFC[], D_8006BB38[];
extern volatile u16 *D_8006CB88, *D_8006CB8C;
extern volatile u32 *D_8006CB90;
extern void func_80042C64(void *, s32);
extern s32 func_8005CD98(void *);
extern void func_800427F4(void);
extern void func_8005CEF8(void *);
extern u32 func_80042C90(void), func_80042DB8(void);
/* Observed incoming a0 at this BIOS call is the callback-table pointer;
 * this declaration records register flow, not inferred BIOS semantics. */
extern void func_8005CE50(CallbackTable *), func_8005CF18(void);

void *func_80042718(void) {
    u8 *state = D_8006BAFC;
    register u8 *buffer asm("s0");
    if (*(u16 *)state != 0)
        return 0;
    {
        volatile u16 *status = D_8006CB88;
        volatile u16 *mask = D_8006CB8C;
        *mask = 0;
        *status = *mask;
    }
    *D_8006CB90 = 0x33333333;
    func_80042C64(state, 0x41A);
    if (func_8005CD98(state + 0x38))
        func_800427F4();
    buffer = D_8006BB38;
    asm("" : "=r"(buffer) : "0"(buffer));
    *(u32 *)buffer = (u32)(buffer + 0xFDC);
    func_8005CEF8(buffer - 4);
    *(u16 *)(buffer - 0x3C) = 1;
    D_8006CB84->callback14 = func_80042C90();
    D_8006CB84->callback04 = func_80042DB8();
    func_8005CE50(D_8006CB84);
    func_8005CF18();
    buffer -= 0x3C;
    asm("" : "=r"(buffer) : "0"(buffer));
    return buffer;
}
