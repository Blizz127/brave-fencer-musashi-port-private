/* SC02.CD member35: func_80183E68 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8012B77C(s32 out, s32 from, s32 to);
extern s32 func_8012B77C(s32 out, s32 from, s32 to);
extern s16 D_80126CBA;
extern s32 func_8012B77C(s32 out, s32 from, s32 to);

void func_80183E68(s32 *a0, s32 a1, s32 a2) {
    s32 sp10[4];
    s32 sp20;
    s16 *q;
    u16 *p;
    s16 t;
    register s32 rv __asm__("$2");
    q = &D_80126CBA;
    if (*q == 0) {
        p = (u16 *)(q - 3);
        *(s32 *)(a1 + 0xE0) = 0;
    } else {
        p = (u16 *)(a1 + 0x88);
        *(s32 *)(a1 + 0xE0) = 1;
    }
    *(s16 *)((s32)sp10 + 0x2) = p[0] + *(u16 *)a2;
    t = p[1] + *(u16 *)(a2 + 2);
    *(s16 *)((s32)sp10 + 0x6) = t;
    *(s16 *)(a1 + 0x100) = t;
    *(s16 *)((s32)sp10 + 0xA) = p[2] + *(u16 *)(a2 + 4);
    func_8012B77C((s32)&sp20, a1 + 4, (s32)sp10);
    rv = sp20;
    *a0 = rv;
    rv = (s32)a0;
    __asm__ __volatile__("" : : "r" (rv));
}
