/* sc03_0098: func_8013E370 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012C724(s32 a0, s32 a1);
extern void *D_801274CC;
extern s32 func_8013E410(void);
extern s32 func_8013E448(s32 a0);
extern void func_8012C724(s32 a0, s32 a1);
s32 func_8013E410(void);
s32 func_8013E448(s32 param_1);

void func_8013E370(void) {
    u8 *s0;
    u8 *s2;
    s32 r;
    s0 = (u8 *)D_801274CC;
    if (s0 == 0) return;
    if (*(u16 *)(s0 + 6) == 0) return;
    s2 = s0 + 6;
    do {
        if ((*(u16 *)(s2 + 4) & 0x8000) == 0) {
            r = func_8013E410();
            if (r == 0) return;
            if (func_8013E448((s32)s0) != 0) {
                func_8012C724((s32)s0, r);
            }
        }
        s2 += 0x14;
        s0 += 0x14;
    } while (*(u16 *)s2 != 0);
}
