/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A143C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8005C49C(void);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_80132EF4(s32 a0, s32 a1);
extern s32 func_8012C51C(void *a0, s32 a1);
extern s16 D_801F435C;
typedef struct {
    s32 vx, vy, vz, pad;
} Vec801A143C;
typedef struct {
    s16 f0, f2, f4, f6, f8, fA, fC, fE;
    s32 f10;
} Spawn801A143C;

void func_801A143C(s32 a0) {
    Vec801A143C vin;
    Vec801A143C vout;
    Spawn801A143C stk;
    s32 i;
    s32 pick;
    s32 obj;
    register s32 t __asm__("$16");
    s32 r;

    if (*(s32 *)(a0 + 0x94) == 4) {
        /* This is `x += D * -112` written as explicit shift-arithmetic ON PURPOSE.
           Spelled `D_801F435C * -112`, expmed.c:2192 takes the negate_variant
           (synth_mult on +112 -> `(D<<3) - D`, then a NEG) and combine folds the NEG
           into the `+=`, giving `sll 3 / subu D8,D / sll 4 / SUBU` -- the target has
           `sll 3 / subu D,D8 / sll 4 / ADDU`, i.e. the negative chain built directly. */
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) += (D_801F435C - D_801F435C * 8) * 16;
    }

    if ((u32)(*(s32 *)(a0 + 0x94) - 7) < 0x12) {
        /* 240 == ((x << 4) - x) << 4 */
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) += D_801F435C * 240;
        pick = func_8005C49C() % 8;

        vin.vy = 0;
        vin.vz = 0x400000;
        for (i = 0; i < 8; i++, vin.vz += 0x400000) {
            obj = func_80132EF4(a0, 0x22);
            if (obj == 0) {
                continue;
            }
            /* The $16 pin on `t` is load-bearing (LENGTH-DRIFT +1 without it).
               expand_divmod's internal `t1 = copy_to_mode_reg(op0)` (expmed.c:2986)
               spans basic blocks, so global_alloc owns it and -- crossing 0 calls --
               prefers a call-clobbered reg, taking $v0 and forcing the func_8005C49C() result
               into $v1 via an extra `move`, which also leaves the bgez delay slot a
               nop.  Pinning the result variable to $16 makes t1/quotient/t3/remainder
               all land on $16, op0 stays in the raw return reg $v0, and the surviving
               `t1 = op0` copy fills the delay slot exactly as the target does. */
            t = (func_8005C49C() % 64) << 16;
            if ((func_8005C49C() & 1) == 0) {
                t = -t;
            }
            vin.vx = t;
            func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, (s32)&vin, (s32)&vout);

            *(s32 *)(obj + 0x4) += vout.vx;
            *(s32 *)(obj + 0x8) += vout.vy;
            *(s32 *)(obj + 0xC) += vout.vz;

            r = func_8005C49C();
            *(u16 *)(obj + 0x34) = (((r % 8192) + 0x5000) & ~0xF) | (func_8005C49C() & 1);
            *(u16 *)(*(s32 *)(obj + 0x20) + 0x2C) = 0xC004;

            if (pick != i) {
                continue;
            }

            stk.f0 = (*(s32 *)(a0 + 0x4) + vout.vx) >> 16;
            stk.f2 = (*(s32 *)(a0 + 0x8) + vout.vy) >> 16;
            stk.f4 = (*(s32 *)(a0 + 0xC) + vout.vz) >> 16;
            stk.f6 = 0x376;
            stk.f8 = 0;
            stk.fA = 0;
            stk.f10 = 0;
            stk.fE = 0;
            stk.fC = 0x7FFF;
            func_8012C51C(&stk, a0);
        }
    }

    if (*(s16 *)(a0 + 0x98) == 0) {
        *(s16 *)(a0 + 0x2) = 3;
        *(s32 *)(a0 + 0xE0) &= ~2;
    }
}
