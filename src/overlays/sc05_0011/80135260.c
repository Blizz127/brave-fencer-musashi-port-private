/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135260 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 func_80135480(void*, s32, s16*, s16*);
extern s32 func_80135EB0(void *arg0, s32 arg1_);
extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
extern int func_80134A74(int, s16, s16, int);

s32 func_80135260(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3)
{
    /* BLOCK scope on purpose: this TU already declares D_8017E2A8/B0/B8 as `extern u8` inside
     * other function bodies (L2461-2463) and as `extern u16 *` inside others (L2587-2589).
     * A FILE-scope pointer decl here would make those inner `extern u8` decls conflicting-types.
     * The same reason keeps D_8019BDAC/D_8019BDCC local (cf. the TU's own L3268-3270). */
    extern u16 *D_8017E2A8;
    extern u16 *D_8017E2AC;
    extern u16 *D_8017E2B4;
    extern s32 D_8019BDAC;
    extern s32 D_8019BDCC;

    u8 dead[56];
    s32 *p;
    s32 flag;
    s32 q;
    u16 *pa;
    u16 *pb;
    u16 *pc;
    u16 *pd;
    u16 *pe;
    u16 t;

    switch (((s32 (*)(void *, s32, s16 *, s16 *))func_80135480)((void *)arg0, arg1, arg2, arg3)) {
    case 0:
        return 0;
    case 1:
        q = arg0 + 0x34;
        p = (s32 *)((arg1 & 0xFFFFFFF) | 0x80000000);
        flag = 0;
        break;
    case 2:
        q = arg0 + 0x34;
        p = (s32 *)((arg1 & 0xFFFFFFF) | 0x80000000);
        flag = 1;
        break;
    case 3:
        q = arg0 + 0x34;
        p = &D_8019BDCC;
        flag = 0;
        break;
    case 4:
        q = (s32)&D_8019BDAC;
        p = &D_8019BDCC;
        flag = 1;
        break;
    }
    if (arg1 >= 0) {
        goto elsepath;
    }
    if (func_80135EB0(p, 0) != 0) {
        goto hit;
    }
    p = (s32 *)*p;
    if (p == 0) {
        return 0;
    }
loop:
    if (func_80135EB0(p, 0) == 0) {
        goto body;
    }
hit:
    func_80136A94(flag, arg0, (s32)arg3, q);
    return 1;
body:
    p = (s32 *)*p;
    if (p != 0) {
        goto loop;
    }
    return 0;
elsepath:
    pa = D_8017E2AC;
    pb = D_8017E2A8;
    pc = D_8017E2B4;
    pc[0] = pa[0] - pb[0];
    pc[1] = pa[1] - pb[1];
    pc[2] = pa[2] - pb[2];
    if (func_80134A74(0, (s16)pb[0], (s16)pb[2], (int)p) != 0) {
        goto hit;
    }
    pd = D_8017E2A8;
    pe = D_8017E2AC;
    t = pe[0];
    if (((pd[0] & 0xFF80) == (t & 0xFF80)) && ((pd[2] & 0xFF80) == (pe[2] & 0xFF80))) {
        return 0;
    }
    if (func_80134A74(0, (s16)t, (s16)pe[2], (int)p) != 0) {
        goto hit;
    }
    return 0;
}
