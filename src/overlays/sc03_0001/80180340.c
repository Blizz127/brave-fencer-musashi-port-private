/* sc03_0001: func_80180340 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012A568(void (*a0)(void));
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_80016714(void *a0, s32 a1);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);

void func_80180340(s32 param_1) {
    s32 temp_s1;
    s32 temp_v1;
    temp_s1 = *(s32 *)(param_1 + 0xCC);
    func_8012AD80(param_1);
    temp_v1 = *(s32 *)(param_1 + 0xCC);
    *(u16 *)(temp_v1 + 8) = *(u16 *)(param_1 + 6);
    *(u16 *)(temp_v1 + 0xA) = *(u16 *)(param_1 + 0xA);
    *(u16 *)(temp_v1 + 0xC) = *(u16 *)(param_1 + 0xE);
    if ((*(u32 *)(param_1 + 0x1C) & 7) == 0) {
        func_80128ED8(temp_s1, (s32 *)(param_1 + 0xD0));
    }
    if (func_8012BEE8(param_1) != 0) {
        func_80016714((void *)temp_s1, 0x38);
        func_8012C218((void *)param_1);
    }
}
