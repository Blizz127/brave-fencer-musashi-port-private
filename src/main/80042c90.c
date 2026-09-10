#include "psx_types.h"

/* Exact matched stream for the bounded callback-initialization diagnostic. */

/* Byte-exact callback installer [80042C90,80042CE8).
 * Guest callback addresses and MMIO still require native bindings. */
typedef void (*Dispatch)(s32, s32);
extern s32 D_8006CB98[];
extern s32 D_8006CBB8;
extern volatile u32 *D_8006CBBC;
extern void func_80042D8C(void *, s32);
extern void func_80042CE8(void);
extern void func_80042D60(s32, s32);
extern s32 func_800425B0(s32, void (*)(void));

Dispatch func_80042C90(void) {
    s32 *table = D_8006CB98;
    *D_8006CBBC = 0x107;
    D_8006CBB8 = 0;
    func_80042D8C(table, 8);
    func_800425B0(0, func_80042CE8);
    return func_80042D60;
}
