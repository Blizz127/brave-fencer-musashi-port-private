/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFC1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800599B8();

s32 func_800CFC1C(u16 *param_1)
{
    extern s32 D_800EC69C;

    u8 buf[0x10];
    register u16 *cursor __asm__("$18");
    register s32 uVar13 __asm__("$16");
    register u16 *psVar14 __asm__("$17");
    register s32 uVar16 __asm__("$19");
    register u32 mask __asm__("$20");
    register u16 *puVar9 __asm__("$11");
    register u16 *puVar10 __asm__("$12");
    register s32 iVar11 __asm__("$13");
    u16 tag;
    u32 result;
    u16 stored;
    s32 gate;
    register u32 acc __asm__("$2");
    register u32 uVar5 __asm__("$7");
    register u32 uVar7 __asm__("$6");
    register u32 uVar1 __asm__("$4");
    register u32 uVar6 __asm__("$3");
    register u32 uVar8 __asm__("$8");
    register u32 uVar3 __asm__("$10");

    cursor = param_1;
    uVar16 = 0;
    D_800EC69C = D_800EC69C + 1;
    gate = D_800EC69C < 2;
    if (gate) {
        return (u16 *)gate;
    }
    __asm__ __volatile__("" : "=r"(cursor) : "0"(cursor));
    tag = *(u16 *)cursor;
    D_800EC69C = 0;
    if (tag != 0xff) {
        mask = -0x8000;
        psVar14 = param_1 + 5;
        do {
            iVar11 = 0;
            if (tag == 9) {
                uVar13 = 0;
                puVar10 = *(u16 **)(psVar14 + 1);
                {
                    register s32 boff __asm__("$2") = (s32)((s16 *)psVar14)[-1] * 2;
                    register u16 *pi __asm__("$5");
                    pi = (u16 *)((s32)puVar10 + boff);
                    __asm__ __volatile__("" : "=r"(pi) : "0"(pi));
                    puVar9 = pi;
                }
                if (0 < (s32)((s16 *)psVar14)[-1]) {
                    do {
                        register u32 pix __asm__("$2");
                        register u32 out __asm__("$9");
                        pix = (u32)*puVar9;
                        out = (u32)*puVar10;
                        uVar5 = pix & 0x1f;
                        uVar7 = pix & 0x3e0;
                        uVar1 = pix & 0x7c00;
                        uVar6 = out & 0x1f;
                        uVar8 = out & 0x3e0;
                        uVar3 = out & 0x7c00;
                        if (uVar5 != uVar6) {
                            register s32 c __asm__("$2");
                            uVar13 = 1;
                            if ((s32)uVar5 < (s32)uVar6) uVar5 = uVar5 + 1;
                            c = (s32)uVar6 < (s32)uVar5;
                            if (c) uVar5 = uVar5 - 1;
                        }
                        if (uVar7 != uVar8) {
                            register s32 c __asm__("$2");
                            uVar13 = 1;
                            if ((s32)uVar7 < (s32)uVar8) uVar7 = uVar7 + 0x20;
                            c = (s32)uVar8 < (s32)uVar7;
                            if (c) uVar7 = uVar7 - 0x20;
                        }
                        if (uVar1 != uVar3) {
                            register s32 c __asm__("$2");
                            uVar13 = 1;
                            if ((s32)uVar1 < (s32)uVar3) uVar1 = uVar1 + 0x400;
                            c = (s32)uVar3 < (s32)uVar1;
                            if (c) uVar1 = uVar1 - 0x400;
                        }
                        acc = uVar5 | uVar7;
                        result = acc | uVar1 | (out & mask);
                        stored = result;
                        if ((stored & 0xFFFF) == 0 && out != 0) {
                            stored = result | 0x8000;
                        }
                        *puVar9 = stored;
                        puVar9 = puVar9 + 1;
                        iVar11 = iVar11 + 1;
                        puVar10 = puVar10 + 1;
                    } while (iVar11 < (s32)((s16 *)psVar14)[-1]);
                }
                if (uVar13 != 0) {
                    register u8 *argp __asm__("$4");
                    argp = buf;
                    *(u16 *)(buf + 0) = psVar14[-3];
                    __asm__ __volatile__("" ::: "memory");
                    *(u16 *)(buf + 2) = psVar14[-2];
                    __asm__ __volatile__("" ::: "memory");
                    *(u16 *)(buf + 4) = psVar14[-1];
                    __asm__ __volatile__("" ::: "memory");
                    *(u16 *)(buf + 6) = psVar14[0];
                    func_800599B8(argp);
                }
                uVar16 = uVar16 | uVar13;
            }
            cursor = cursor + 8;
            psVar14 = psVar14 + 8;
            tag = *(u16 *)cursor;
        } while (tag != 0xff);
    }
    return (u16 *)uVar16;
}
