/* sc03_0098: func_80175690 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 func_801758FC(void);
extern s32 func_80175820(void);
extern s32 func_801759D8(void);
extern void (*D_80188B24[])(s32 *);
extern s32 func_801758FC(void);
extern s32 func_80175820(void);
extern s32 func_801759D8(void);
s32 func_80175820(void);
s32 func_801758FC(void);
s32 func_801759D8(void);

void func_80175690(s32 *param) {
    D_80188B24[*(u8 *)((s32)param + 1)](param);
    ((void (*)(void))func_801758FC)();
    ((void (*)(void))func_80175820)();
    ((void (*)(void))func_801759D8)();
}
