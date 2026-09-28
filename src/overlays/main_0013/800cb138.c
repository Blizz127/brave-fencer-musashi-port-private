/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB138 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define MulMatrix0 func_8004818C
#define RotMatrixYXZ func_80049A1C
#define RotMatrixZ func_8004A27C
#define rand func_8005C49C


void func_800CB138(s32 arg0) {

    typedef struct { s32 w[8]; } Blk20;

    extern Blk20 D_800AE620;
    extern u8 D_800CB8FC[];
    extern u8 D_800CB88C[];
    extern s32 rand(void);
    extern u8 *func_800D222C(s32 a0, s32 a1, s32 a2);
    extern void func_800D20C0(void *a0, void *a1, s32 a2);
    extern void func_800D23D0(void *a0);
    extern void RotMatrixYXZ();
    extern void RotMatrixZ(s32 a0, void *a1);
    extern void ApplyMatrixSV();
    extern void MulMatrix0(s32 a0, void *a1, s32 a2);
    extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
    extern void func_80128EA8();
    extern void func_80146C3C();

    s16   sp10[4];
    s16   sp18[4];
    s16   mtx[16];
    u16   vec[4];
    s16   sv2[4];
    Blk20 blk;

    s32 ent;
    u8 *p;
    s32 m;
    s32 ang;
    register s32 ang2 __asm__("$4");

    ent = *(s32 *)(arg0 + 0x34);
    if ((*(s32 *)(arg0 + 0x2C) & 0x8000) == 0) {
        sp10[0] = *(u16 *)(ent + 6);
        sp10[1] = *(u16 *)(ent + 0xA);
        sp10[2] = *(u16 *)(ent + 0xE);
        func_800D20C0(sp10, sp18, 0);
        func_800D23D0(sp18);
        RotMatrixYXZ(sp18, arg0 + 0x38);
        *(s16 *)(arg0 + 2) = 2;
    } else {
        p = func_800D222C(arg0, (s32)D_800CB8FC, 0x1A);
        if (p != 0) {
            *(s16 *)(arg0 + 0x10) = rand() & 0xFFF;
            m = *(s32 *)(arg0 + 0x34);
            __asm__ __volatile__("" : : : "memory");
            { register Blk20 *s __asm__("$5") = &D_800AE620; s32 t0, t1, t2;
              __asm__ __volatile__("" : "=r"(s) : "0"(s));
              t0 = s->w[0]; t1 = s->w[1]; t2 = s->w[2];
              blk.w[0] = t0; blk.w[1] = t1; blk.w[2] = t2;
              t0 = s->w[3]; t1 = s->w[4]; t2 = s->w[5];
              blk.w[3] = t0; blk.w[4] = t1; blk.w[5] = t2;
              t0 = s->w[6]; t1 = s->w[7];
              blk.w[6] = t0; blk.w[7] = t1; }
            ang = *(s16 *)(arg0 + 0x10);
            { void *q = &blk; RotMatrixZ(ang, q); __asm__ __volatile__("" : "=r"(q)); }
            vec[0] = *(s32 *)(arg0 + 0x30) << 2;
            vec[1] = 0;
            vec[2] = 0x30;
            { void *q = &blk; ApplyMatrixSV(q, vec, vec); __asm__ __volatile__("" : "=r"(q)); }
            m += 0x38;
            func_8012F14C(m, (s32)vec, (s32)vec);
            *(s16 *)(arg0 + 6)   = vec[0];
            *(s16 *)(arg0 + 0xA) = vec[1];
            ang2 = ang + 0x200;
            __asm__ __volatile__("" : : : "memory");
            *(s16 *)(arg0 + 0xE) = vec[2];
            __asm__ __volatile__("" : : : "memory");
            { register Blk20 *s __asm__("$7") = &D_800AE620;
              s32 t0, t1; register s32 t2 __asm__("$6");
              __asm__ __volatile__("" : "=r"(s) : "0"(s));
              t0 = s->w[0]; t1 = s->w[1]; t2 = s->w[2];
              blk.w[0] = t0; blk.w[1] = t1; blk.w[2] = t2;
              t0 = s->w[3]; t1 = s->w[4]; t2 = s->w[5];
              blk.w[3] = t0; blk.w[4] = t1; blk.w[5] = t2;
              t0 = s->w[6]; t1 = s->w[7];
              blk.w[6] = t0; blk.w[7] = t1; }
            { void *q; __asm__ __volatile__("" : : : "memory"); q = &blk;
              RotMatrixZ(ang2, q); __asm__ __volatile__("" : "=r"(q)); }
            MulMatrix0(m, &blk, arg0 + 0x38);
            *(s32 *)(arg0 + 0x20) = (s32)p;
            *(s32 *)(p + 0x34) = arg0 + 0x38;
            *(u16 *)(p + 0x1A) = 0x2000;
            *(u16 *)(p + 0x18) = 0x2000;
            func_80128EA8(p, arg0 + 0x24, D_800CB88C);
            *(s16 *)(arg0 + 2) = *(u16 *)(arg0 + 2) + 1;
        } else {
            func_80146C3C(arg0);
        }
    }
}
