/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A94A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
extern s16 D_80126B5E;
extern s16 D_80126B66;
extern Mtx32_801A90D8 D_800AE620;
typedef struct { s16 vx, vy, vz, pad; } SV_801A90D8;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8012B21C(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8004CFEC(s32 a0, s32 a1);

void func_801A94A0(s32 *s1)
{
    s16 angle;
    s32 vz;
    s32 t;
    s32 flag;
    Mtx32_801A90D8 mtx;
    SV_801A90D8 vin;
    SV_801A90D8 vout;

    func_8012B21C(s1);
    if (*(s16 *)((s8 *)s1 + 0xFE) != 0) {
        *(s16 *)((s8 *)s1 + 0xA) = -0x500;
        if (*(s16 *)((s8 *)s1 + 0x70) == 0) {
            angle = func_8005C49C() & 0xFF8;
            t = func_8005C49C();
            vz = -(t % 704);
            flag = 1;
        } else {
            s16 dx = D_80126B5E;
            s16 dz = D_80126B66;
            if (dx * dx + dz * dz <= 0x78FFF) {
                *(s16 *)((s8 *)s1 + 6) = dx;
                *(u16 *)((s8 *)s1 + 0xE) = *(u16 *)&D_80126B66;
                flag = 0;
            } else {
                angle = (func_8004CFEC(-dz, dx) - 0x400) & 0xFFF;
                vz = -0x2C0;
                flag = 1;
            }
        }
        {
            register s32 doMatrix __asm__("$2");
            doMatrix = flag;
        if (doMatrix != 0) {
            mtx = D_800AE620;
            func_8004A0DC(angle, &mtx);
            vin.vy = 0;
            vin.vx = 0;
            vin.vz = vz;
            func_80048FBC(&mtx, &vin, &vout);
            *(u16 *)((s8 *)s1 + 6) = vout.vx;
            *(u16 *)((s8 *)s1 + 0xE) = vout.vz;
        }
        }
        *(s32 *)((s8 *)s1 + 0x14) = 0x80000;
    } else {
        *(s32 *)((s8 *)s1 + 0x48) = 0x12000;
    }
    func_8012AD44((s32 *)s1, 1);
}
