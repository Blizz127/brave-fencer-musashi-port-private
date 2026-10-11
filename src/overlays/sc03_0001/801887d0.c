/* sc03_0001: func_801887D0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 aF801848DC(void *a0) __asm__("func_801848DC");
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

s32 func_801887D0(void *a0) {
    extern u16 D_80126B5E;
    extern u16 D_80126B62;
    extern u16 D_80126B66;
    s16 out[3];
    s16 in[3];
    in[0] = D_80126B5E;
    in[1] = D_80126B62;
    in[2] = D_80126B66;
    func_8012F2E8((s32)a0, (s32)in, (s32)out);
    return func_8012CB64((s32)out, -0x80, 0x80, -0x60, 0);
}
