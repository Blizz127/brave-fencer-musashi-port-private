/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB910 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80146E90(s32 *, s32);
extern int rand(void);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146C3C(void);
typedef struct { s16 vx, vy, vz, pad; } SV_800CB910;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_800CB910;
typedef struct { s32 vx, vy, vz, pad; } V32_800CB910;
extern void func_8001CF00(s32 a0);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800CBF24(void);
extern SV_800CB910 D_800CC028[];
extern V32_800CB910 D_800CC058;
extern u16     D_800CC068[];

void func_800CB910(s32 param_1) {
    s16 buf[4];
    SV_800CB910 rot;
    MTX_800CB910 m;
    V32_800CB910 vel;
    s32 obj;
    s32 p;
    s32 p2;
    s16 *q;
    s32 i;
    u16 sc;

    obj = *(s32 *)(param_1 + 0x34);
    p = ((s32 (*)(void))func_801465C0)();
    p2 = p;
    *(s32 *)(param_1 + 0x20) = p;

    if (p != 0) {
        func_8001CF00(p);
        *(s32 *)(p + 0x4) |= 0x80000000;
        func_80015978(obj + 4, (s32 *)buf);
        buf[1] -= 0x40;
        func_80015954((s32)buf, param_1 + 4);

        if (*(s32 *)(param_1 + 0x2c) == 0) {
            func_800CBF24();
        }

        sc = D_800CC068[*(s32 *)(param_1 + 0x30)];
        *(u16 *)(p2 + 0x18) = *(u16 *)(p2 + 0x1a) = *(u16 *)(p2 + 0x1c) = sc;

        vel = D_800CC058;
        rot = D_800CC028[*(s32 *)(param_1 + 0x2c)];

        if (*(s32 *)(param_1 + 0x30) != 0) {
            rot.vx += ((rand() & 0x3f) << 4) - 0x200;
            rot.vy += ((rand() & 0x3f) << 4) - 0x200;
            rot.vz += ((rand() & 0x3f) << 4) - 0x200;
            vel.vx = ((rand() & 0x1f) - 0x10) << 18;
            vel.vy = ((rand() & 0x1f) - 0x10) << 18;
            vel.vz = ((rand() & 0x1f) - 0x10) << 18;
        }

        func_80049CAC((s32)&rot, (s32)&m);
        func_800484EC((s32)&m, (s32)&vel, (s32)&vel);

        *(s32 *)(param_1 + 0x10) = vel.vx;
        *(s32 *)(param_1 + 0x14) = vel.vy;
        *(s32 *)(param_1 + 0x18) = vel.vz;

        q = (s16 *)(param_1 + 0x38);
        i = 0;
        *(s32 *)(param_1 + 0x4c) = ((rand() & 0x1f) - 0x10) * 11;
        *(s32 *)(param_1 + 0x50) = ((rand() & 0x1f) - 0x10) * 11;
        *(s32 *)(param_1 + 0x54) = ((rand() & 0x1f) - 0x10) * 11;

        do {
            i++;
            *q++ = (rand() & 0x7f) - 0x40;
            *q++ = (rand() & 0x7f) - 0x40;
            *q++ = (rand() & 0x7f) - 0x40;
        } while (i < 3);

        func_80146E90((s32 *)param_1, 2);
        *(s16 *)(param_1 + 0x2) = *(u16 *)(param_1 + 0x2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(param_1);
    }
}
