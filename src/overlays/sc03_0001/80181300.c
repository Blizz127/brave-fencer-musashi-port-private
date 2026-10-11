/* sc03_0001: func_80181300 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_80187890(void);

void func_80181300(s32 a0) {
    extern s32 D_80191B58[];
    extern s32 D_80191B6C[];
    s32 v1 = func_80029504();
    if (v1 < 0xC8) {
        s32 v0 = ((s32 (*)(void))func_801877C0)();
        *(s32 *)(a0 + 0xE4) = D_80191B58[v0];
    } else {
        s32 v0 = func_80187890();
        *(s32 *)(a0 + 0xE4) = D_80191B6C[v0];
    }
}
