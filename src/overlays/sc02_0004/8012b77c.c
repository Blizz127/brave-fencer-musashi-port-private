/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B77C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
typedef struct {
    u32 lo : 16;
    u32 hi : 16;
} Ang2_8012B77C_8012B77C;
extern s32 ratan2(s32 a0, s32 a1);
extern int func_80047948(int a0);
extern int func_8004787C(int a0);
extern s32 ratan2(s32 x, s32 y);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);

s32 func_8012B77C(s32 out, s32 from, s32 to) {
    Ang2_8012B77C_8012B77C t;
    s32 dx, dy, dz;
    s32 ang;
    s32 r1, r2;
    dz = *(s16 *)(to + 0xA) - *(s16 *)(from + 0xA);
    dx = *(s16 *)(to + 0x2) - *(s16 *)(from + 0x2);
    dy = *(s16 *)(to + 0x6) - *(s16 *)(from + 0x6);
    ang = (ratan2(-dz, dx) - 0x400) & 0xFFF;
    t.hi = ang;
    r1 = func_80047948(ang);
    r2 = func_8004787C(ang);
    dz = (dz * r1 + dx * r2) >> 12;
    t.lo = ratan2(dy, -dz);
    *(Ang2_8012B77C_8012B77C *)out = t;
    return out;
}
