/* sc03_0098: func_8012DEB8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012DF34(s32 a0, s32 a1, s32 a2);
extern s16 D_80126B9A;
s32 func_8012DF34(s32 a0, s32 a1, s32 a2);
void func_8012F214(s32 a0, s32 a1, s32 a2);

s32 func_8012DEB8(s32 a0, s32 a1, s32 a2) {
    s32 sp10[2];
    s32 sp18[2];
    func_8012F214(a0, a1, (s32)sp10);
    func_8012F214(a0, a2, (s32)sp18);
    if (func_8012DF34(a0, (s32)sp10, (s32)sp18) != 0) {
        D_80126B9A = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
        return 1;
    }
    return 0;
}
