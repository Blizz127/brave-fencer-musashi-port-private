/* sc03_0001: func_801883C4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801889AC(void);
extern s32 func_801889AC(void);
extern s32 func_801889AC(void);
extern s16 D_801C0B68[];
extern s32 func_801889AC(void);
extern s32 func_801889AC(void);

void func_801883C4(s32 a0) {
    extern s32 D_801C0B28[][2];
    extern s16 D_801C0B68[];
    s32 idx_val, ptr_val, data_val;
    *(s16 *)(a0 + 0x2) = 0x4;
    *(s16 *)(a0 + 0x34) = 0;
    *(s16 *)(a0 + 0xFE) = 0x600;
    *(s16 *)(a0 + 0x100) = 0;
    *(s16 *)(a0 + 0x102) = 0;
    idx_val = D_801C0B68[*(s16 *)(a0 + 0x70)];
    ptr_val = *(s32 *)(a0 + 0x20);
    data_val = D_801C0B28[idx_val][0];
    *(s32 *)(ptr_val + 0x24) = data_val;
    *(s16 *)(a0 + 0x84) = 0;
    *(s16 *)(a0 + 0x5C) = 0;
    *(s32 *)(a0 + 0xB0) = 0;
    func_801889AC();
}
