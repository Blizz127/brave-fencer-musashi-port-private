/* Complete SC02 retail span [801442F8,80144364).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void (*D_8018660C[])(void);
extern void func_8012C218(void *a0);

void func_801442F8(s32 obj) {
    s32 n;

    D_8018660C[*(u16 *)(obj + 2)]();
    n = *(s32 *)(obj + 0x1c) + 1;
    *(s32 *)(obj + 0x1c) = n;
    if (n > 0x1d) {
        func_8012C218((void *)obj);
    }
}
