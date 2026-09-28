/* Exact overlay word export for [800D21C4,800D222C) from MAIN.CD member0010
 * (extracted/overlays/main/0010.bin offset 0x233CC, load base 800AEDF8).
 * SHA256(span)=cea980ece7c8be65b92ff15b99d08ce725273d5bd43c7631820441ad4e93685d.
 * Word export only: the native seam executes the member's own words. */
#include "psx_types.h"

extern void *func_801465C0(s32);
extern void func_8001CC3C(void *, s32, s32, s32);

u8 *func_800D21C4(s32 arg0, s32 arg1, u8 arg2) {
    u8 *entity;

    entity = (u8 *)func_801465C0(arg0);
    if (entity != 0) {
        func_8001CC3C(entity, arg1, 0, 0);
        entity[0x27] = arg2;
        return entity;
    }
    return 0;
}
