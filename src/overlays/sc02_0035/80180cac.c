/* SC02.CD member35: func_80180CAC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 D_80198E4C;

void func_80180CAC(void *a0) {
    s32 p;
    s32 q;
    p = *(u16 *)((char *)a0 + 0x2);
    q = (s32)&D_80198E4C;
    *(s32 *)((char *)a0 + 0xd0) = q;
    *(s32 *)((char *)a0 + 0xcc) = q;
    *(s32 *)((char *)a0 + 0xe0) = *(s32 *)q;
    p += 1;
    *(s16 *)((char *)a0 + 0x2) = p;
}
