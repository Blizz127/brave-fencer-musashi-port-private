/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80146C3C(void);
typedef struct { s16 vx, vy, vz, pad; } SV_800CB4E4;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_800CB4E4;
typedef struct { s32 vx, vy, vz, vw; } V32_800CB4E4;
extern void func_801465C0(void);
extern void func_8001CC3C(s32 a0, void *a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146C3C();
extern int rand(void);
extern u8 D_800CB8EC[];
extern u8 D_800CB8F8[];
extern SV_800CB4E4 D_800CB954[];
extern V32_800CB4E4 D_800CB984;

void func_800CB4E4(s32 param_1) {
    SV_800CB4E4 rot;
    MTX_800CB4E4 m;
    V32_800CB4E4 vel;
    s32 obj;
    s32 node;

    obj = ((s32 (*)(void))func_801465C0)();
    *(s32 *)(param_1 + 0x20) = obj;

    if (*(s32 *)(param_1 + 0x20) != 0) {
        func_8001CC3C(obj, D_800CB8EC, 0, 0);
        node = obj;
        *(u8 *)(node + 0x27) = 0x90;
        *(u16 *)(node + 0x18) = *(u16 *)(node + 0x1a) = 0x3000;
        *(s32 *)(node + 0x4) |= 0x50000000;
        func_80128EA8(node, param_1 + 0x24, (s32)D_800CB8F8);

        vel = D_800CB984;
        rot = D_800CB954[*(s32 *)(param_1 + 0x2c)];

        if (*(s32 *)(param_1 + 0x30) != 0) {
            rot.vx += ((rand() & 0x3f) << 4) - 0x200;
            rot.vy += ((rand() & 0x3f) << 4) - 0x200;
            rot.vz += ((rand() & 0x3f) << 4) - 0x200;
            vel.vx = ((rand() & 0x1f) - 0x10) * 3 << 15;
            vel.vy = ((rand() & 0x1f) - 0x10) * 3 << 15;
            vel.vz = ((rand() & 0x1f) - 0x10) * 3 << 15;
        }

        func_80049CAC((s32)&rot, (s32)&m);
        func_800484EC((s32)&m, (s32)&vel, (s32)&vel);

        *(s32 *)(param_1 + 0x10) = vel.vx;
        *(s32 *)(param_1 + 0x14) = vel.vy;
        *(s32 *)(param_1 + 0x18) = vel.vz;

        func_80146E90((s32 *)param_1, 4);
        *(s16 *)(param_1 + 0x2) = *(u16 *)(param_1 + 0x2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(param_1);
    }
}
