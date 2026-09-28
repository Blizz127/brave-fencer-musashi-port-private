/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB860 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146C3C(void);
typedef struct { s16 vx, vy, vz, pad; } SV;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX;
typedef struct { s32 vx, vy, vz, pad; } V32;
extern void func_801465C0();
extern s32 func_8001CC3C(s32, s32, s32, s32);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C();
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern int rand(void);
extern SV D_800CBE50[];
extern u8 D_800CBE5C[];
extern V32 D_800CBEE8;
extern SV D_800CBEB8[];

void func_800CB860(s32 param_1) {
    SV rot;
    MTX m;
    V32 vel;
    s32 p;
    s32 pb;

    p = ((s32 (*)(void))func_801465C0)();
    pb = p;
    *(s32 *)(param_1 + 0x20) = p;

    if (p != 0) {
        ((void (*)(s32, void *, s32, s32))func_8001CC3C)(p, D_800CBE50, 0, 0);
        *(u8 *)(p + 0x27) = 0x90;
        *(s16 *)(p + 0x18) = *(s16 *)(p + 0x1a) = 0x2000;
        *(s32 *)(p + 4) |= 0x50000000;
        func_80128EA8(p, param_1 + 0x24, D_800CBE5C);

        vel = D_800CBEE8;
        rot = D_800CBEB8[*(s32 *)(param_1 + 0x2c)];

        if (*(s32 *)(param_1 + 0x30) != 0) {
            rot.vx += ((rand() & 0x3f) << 4) - 0x200;
            rot.vy += ((rand() & 0x3f) << 4) - 0x200;
            rot.vz += ((rand() & 0x3f) << 4) - 0x200;
            vel.vx = ((rand() & 0x1f) - 0x10) * 0x18000;
            vel.vy = ((rand() & 0x1f) - 0x10) * 0x18000;
            vel.vz = ((rand() & 0x1f) - 0x10) * 0x18000;
        }

        func_80049CAC((s32)&rot, (s32)&m);
        func_800484EC((s32)&m, (s32)&vel, (s32)&vel);

        *(s32 *)(param_1 + 0x10) = vel.vx;
        *(s32 *)(param_1 + 0x14) = vel.vy;
        *(s32 *)(param_1 + 0x18) = vel.vz;

        *(u8 *)(pb + 0x24) = 0xC0;
        *(u8 *)(pb + 0x25) = 0xC0;
        *(u8 *)(pb + 0x26) = 0x40;

        func_80146E90((s32 *)param_1, 4);
        *(s16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(param_1);
    }
}
