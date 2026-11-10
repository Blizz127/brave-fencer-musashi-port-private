/* sc02_0037: func_8012B77C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    u32 lo : 16;
    u32 hi : 16;
} Ang2_8012B77C_8012B77C;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern int func_80047948(int a0);
extern int func_8004787C(int a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_8004CFEC(s32 a0, s32 a1);
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
    ang = (func_8004CFEC(-dz, dx) - 0x400) & 0xFFF;
    t.hi = ang;
    r1 = func_80047948(ang);
    r2 = func_8004787C(ang);
    dz = (dz * r1 + dx * r2) >> 12;
    t.lo = func_8004CFEC(dy, -dz);
    *(Ang2_8012B77C_8012B77C *)out = t;
    return out;
}
