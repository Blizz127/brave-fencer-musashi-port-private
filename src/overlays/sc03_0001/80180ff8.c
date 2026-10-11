/* sc03_0001: func_80180FF8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_801788B8(s32 arg0, s32 arg1);
s32 func_80180AC4(s32 a0);
void func_80180B1C(s32 a0);
void func_80180BCC(void *arg0);
extern s32 func_80180AC4(s32 a0);
extern void func_80180BCC(void *a0);
extern s32 func_80180AC4(s32 a0);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_80180AC4(s32 a0);
extern void func_80180BCC(void *a0);
extern void func_80180B1C(s32 a0);
extern s32 func_801788B8(s32 a0, s32 a1);
extern s32 D_801919BC;
extern s32 func_80181078(void *a0);
s32 func_80181078(void *a0);

void func_80180FF8(void *arg0) {
    if (func_8018727C(arg0, &D_801919BC) == 0) {
        return;
    }
    if (((int (*)(void))func_80180AC4)() != 0) {
        func_80180BCC(arg0);
    } else {
        func_80180B1C((s32)arg0);
    }
    *(s16 *)(*(s32 *)((char *)arg0 + 0x68) + 0xC) = 0x7FFF;
    *(s32 *)((char *)arg0 + 0xD4) = func_801788B8((s32)arg0, (s32)func_80181078);
}
