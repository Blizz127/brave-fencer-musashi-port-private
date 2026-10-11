/* sc03_0001: func_8017553C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void (*D_80190D04[])();
extern s32 func_801758FC(void);
extern s32 func_80175820(void);
extern s32 func_801759D8(void);
s32 func_80175820(void);
s32 func_801758FC(void);
s32 func_801759D8(void);

void func_8017553C(s32 *param) {
    D_80190D04[*(u8 *)((s32)param + 1)]();
    ((void (*)(void))func_801758FC)();
    ((void (*)(void))func_80175820)();
    ((void (*)(void))func_801759D8)();
}
