/* Complete SC02 retail span [80145A2C,80145B24).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_80029504(void);
extern void func_800D185C(u8 *a0);
extern void func_80145B24(void);

extern u8 D_80187238;
extern u8 D_80187118;
extern u8 D_801870F4;
extern u8 D_801870D0;
extern u8 D_80187214;
extern u8 D_801871F0;
extern u8 D_801870AC;
extern u8 D_801871CC;

void func_80145A2C(void) {
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_80187238;
        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_80187118;
    } else if (v >= 0x578) {
        p = &D_801870F4;
    } else if (v >= 0x514) {
        p = &D_801870D0;
    } else if (v >= 0x384) {
        p = &D_80187238;
    } else if (v >= 0x258) {
        p = &D_80187214;
    } else if (v >= 0xC8) {
        p = &D_801871F0;
    } else {
        p = &D_801870AC;
        if (v >= 0xA) {
            p = &D_801871CC;
        }
    }
    func_800D185C(p);
    func_80145B24();
}
