/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB56C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define MulMatrix0 func_8004818C
#define RotMatrixZ func_8004A27C
extern void func_80146C3C(void);

void func_800CB56C(s32 arg0) {

    typedef struct { s32 w[8]; } Blk20;

    extern Blk20 D_800AE620;
    extern void RotMatrixZ(s32 a0, void *a1);
    extern void ApplyMatrixSV();
    extern void MulMatrix0(s32 a0, void *a1, s32 a2);
    extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
    extern s32 func_80128ED8(s32 param_1, s32 *param_2);
    extern void func_80146C3C();

    u16   vec[8];
    Blk20 blk;

    s32 ent;
    s32 obj;
    s32 ang;
    register s32 ang2 __asm__("$4");

    obj = *(s32 *)(arg0 + 0x20);
    __asm__ __volatile__("" : : : "memory");
    ent = *(s32 *)(arg0 + 0x34);
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
    ent += 0x38;
    func_8012F14C(ent, (s32)vec, (s32)vec);
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
    MulMatrix0(ent, &blk, arg0 + 0x38);
    if (func_80128ED8(obj, (s32 *)(arg0 + 0x24)) != 0) {
        ((void (*)(s32))func_80146C3C)(arg0);
    }
}
