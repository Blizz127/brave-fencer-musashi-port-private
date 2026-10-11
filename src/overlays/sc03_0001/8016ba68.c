/* sc03_0001: func_8016BA68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s32 D_80126B58;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_8014C050(s32 a0, s32 a1);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_8014C050(s32 a0, s32 a1);
extern s32 D_80126B58;
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_8014C050(s32 a0, s32 a1);
extern void func_80146C3C();

s32 func_8016BA68(s32 arg0, s32 arg1) {
    extern s32 D_80126B58;
    s32 temp_v0;
    temp_v0 = func_8014C050(&D_80126B58, 0x56);
    if (temp_v0 != 0) {
        ((void (*)(void *))func_80146C3C)(temp_v0);
    }
    func_80146A6C(0x56, arg0, (*(s16 *)((s8 *)(arg0) + (0x7C))), (*(s16 *)((s8 *)(arg0) + (0x7E))), (s32) (*(s16 *)((s8 *)(arg0) + (0x80))), arg1, 0);
}
