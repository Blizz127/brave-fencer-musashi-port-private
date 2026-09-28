/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5E60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro rtps\n"
    "    cop2op 0x01, 0x01\n"
    ".endm\n"
    ".macro rtpt\n"
    "    cop2op 0x02, 0x30\n"
    ".endm\n"
    ".macro avsz4\n"
    "    cop2op 0x16, 0x2E\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG;
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"( r0 ))
#define gte_ldv3(r0, r1, r2) __asm__ volatile ("lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"( r0 ), "r"( r1 ), "r"( r2 ))
#define gte_rtps() __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt() __asm__ volatile ("nop;nop;rtpt")
#define gte_avsz4() __asm__ volatile ("nop;nop;avsz4")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"( r0 ) : "memory")
#define gte_stsxy3(r0, r1, r2) __asm__ volatile ("swc2 $12, 0( %0 );" "swc2 $13, 0( %1 );" "swc2 $14, 0( %2 )" : : "r"( r0 ), "r"( r1 ), "r"( r2 ) : "memory")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"( r0 ) : "memory")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"( r0 ) : "$12", "memory")

void func_801A5E60(s32 a0, u8 *v)
{
    extern void *func_80010A08(s32);
    extern u8 D_800A6610[];
    extern u16 D_800B9A02;
    extern u8 D_801F8744[];
    extern u8 D_801F8745[];
    extern u8 D_801F8746[];

    u8 *pv;
    u32 *pot;
    s32 pz;
    s32 flag, flag2, otz;
    u8 *pkt;
    u8 *q;
    u32 *otp;

    pv = v;
    {
        register u32 tv __asm__("$2") = *(u16 *)&D_800B9A02;
        register u32 bv __asm__("$3") = (u32)&D_800A6610;
        pot = (u32 *)((tv << 14) + bv);
    }
    pkt = func_80010A08(0x24);
    pkt[3] = 8;
    pkt[7] = 0x38;

    gte_ldv3(pv, pv + 8, pv + 0x10);
    gte_rtpt();
    gte_stflg(&flag);
    gte_stsxy3(pkt + 8, pkt + 0x10, pkt + 0x18);
    gte_ldv0(pv + 0x18);
    gte_rtps();
    gte_stflg(&flag2);
    flag |= flag2;
    gte_stsxy(pkt + 0x20);
    gte_avsz4();
    gte_stotz(&otz);

    if ((flag & ~0x1000) == 0) {
        {
            register s32 ozt __asm__("$2") = otz;
            pz = ozt - 8;
        }
        if ((u32)pz < 0x1000) {
            if (*(u16 *)(pv + 4) & 1) {
                pkt[4] = 0; pkt[5] = 0; pkt[6] = 0;
            } else {
                pkt[4] = D_801F8744[0]; pkt[5] = D_801F8745[0]; pkt[6] = D_801F8746[0];
            }
            if (*(u16 *)(pv + 0xC) & 1) {
                pkt[0xC] = 0; pkt[0xD] = 0; pkt[0xE] = 0;
            } else {
                pkt[0xC] = D_801F8744[0]; pkt[0xD] = D_801F8745[0]; pkt[0xE] = D_801F8746[0];
            }
            if (*(u16 *)(pv + 0x14) & 1) {
                pkt[0x14] = 0; pkt[0x15] = 0; pkt[0x16] = 0;
            } else {
                pkt[0x14] = D_801F8744[0]; pkt[0x15] = D_801F8745[0]; pkt[0x16] = D_801F8746[0];
            }
            if (*(u16 *)(pv + 0x1C) & 1) {
                pkt[0x1C] = 0; pkt[0x1D] = 0; pkt[0x1E] = 0;
            } else {
                pkt[0x1C] = D_801F8744[0]; pkt[0x1D] = D_801F8745[0]; pkt[0x1E] = D_801F8746[0];
            }
            {
                register u32 m24 = 0x00FFFFFF;
                register u32 mFF = 0xFF000000;

                otp = (u32 *)(pz * 4 + (u32)pot);
                pkt[7] |= 2;
                ((P_TAG *)pkt)->addr = ((P_TAG *)otp)->addr;
                ((P_TAG *)otp)->addr = (u32)pkt;
                q = func_80010A08(8);
                q[3] = 1;
                *(u32 *)(q + 4) = 0xE1000020;
                ((P_TAG *)q)->addr = ((P_TAG *)otp)->addr;
                ((P_TAG *)otp)->addr = (u32)q;
            }
        }
    }
}
