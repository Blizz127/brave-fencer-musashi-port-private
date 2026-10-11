/* sc03_0001: func_80136A94 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern s16 *D_8018DAA4;
extern s16 *D_8018DAA4;
extern u8 D_80126720[];
extern s16 *D_8018DAA4;
extern u8 D_80126720[];
extern s16 *D_8018DAA4;

s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3) {
    extern void func_80048FBC(void *m, void *v0, void *v1);
    extern void func_8004864C(void *v0, void *v1);
    extern u16 D_80126722;
    extern s16 D_80126724;
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    s32 out[4];
    u16 *pb4;
    if (a0) {
        func_80048FBC((void *)a3, *(void **)&D_8018DAA4, *(void **)&D_8018DAA4);
        func_80048FBC((void *)a3, (void *)D_80126720, (void *)D_80126720);
        func_8004864C((void *)D_801152A8, (void *)out);
        *(s16 *)D_801152A8 = out[0];
        D_801152AA = out[1];
        D_801152AC = out[2];
    }
    pb4 = *(u16 **)&D_8018DAA4;
    *(s16 *)(a2) = pb4[0] + *(s32 *)(a1 + 0x48);
    *(s16 *)(a2 + 2) = pb4[1] + *(s32 *)(a1 + 0x4C);
    *(s16 *)(a2 + 4) = pb4[2] + *(s32 *)(a1 + 0x50);
    *(u16 *)D_80126720 = *(u16 *)D_80126720 + *(s32 *)(a1 + 0x48);
    D_80126722 = D_80126722 + *(s32 *)(a1 + 0x4C);
    D_80126724 = D_80126724 + *(s32 *)(a1 + 0x50);
}
