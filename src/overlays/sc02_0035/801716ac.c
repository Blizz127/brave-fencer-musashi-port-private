/* SC02.CD member35: func_801716AC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
extern void func_801511A8(u8 *a0);
extern u8 D_800B9A17;
extern u8 D_800B9A17;
extern void func_8017196C(s32 *a0, s8 a1);
extern void func_80147060(u8 *a0);
extern void func_801511A8(u8 *a0);
extern void func_80148634(void *a0);
void aF8016F0E4(u8 *p) {
    extern s16 D_80078EB4;
    extern u8 D_800B9A17;
    *(s32 *)(p + 0x1F8) = 0;
    *(s32 *)(p + 0x1FC) = 0;
    func_8017196C((s32 *)p, 0);
    func_80147060(p);
    func_801511A8(p);
    if (*(u16 *)&D_80078EB4 != 0) {
        D_800B9A17 = 1;
    }
    func_80148634(p);
}
extern void func_80148634(void *a0);
extern void func_80147060(u8 *a0);
extern void func_80148634(void *a0);
extern void func_80148634(void *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80147060(u8 *a0);
extern s32 func_80012FC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;
void func_8017196C(s32 *a0, s8 a1);

s32 func_801716AC(s32 a0, void * a1, s32 * a2)
{
    s32 d;
    s32 p;
    a0 = a0 * 0x10;
    p = a0 + (s32)a1;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xC), (&D_800A5E94)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xC) = *(u8 *)(p + 0xC) + d;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xD), (&D_800A5E95)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xD) = *(u8 *)(p + 0xD) + d;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xE), (&D_800A5E96)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xE) = *(u8 *)(p + 0xE) + d;
}
