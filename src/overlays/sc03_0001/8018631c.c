/* sc03_0001: func_8018631C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern void func_8012A568(void (*a0)(void));
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);

void func_8018631C(s32 a0) {
    extern u8 D_80195268[];
    extern u8 D_80195114[];
    extern s16 D_8019515C;
    extern u8 D_801951A8[];
    extern s32 D_801953B4;
    extern u8 D_80195214[];
    s32 idx;
    u32 t;
    idx = func_801877C0(a0);
    switch (idx) {
    case 0:
        *(s32 *)(a0 + 0xE4) = (s32)&D_80195268[0];
        break;
    case 1:
        if ((func_800291B4(0xDB) & 0xFF) == 0) {
            *(s32 *)(a0 + 0xE4) = (s32)&D_80195114[0];
            func_800291A0(0xDB, 1);
        } else {
            *(s32 *)(a0 + 0xE4) = (s32)&D_8019515C;
        }
        break;
    case 2:
        *(s32 *)(a0 + 0xE4) = (s32)&D_801951A8[0];
        break;
    case 3:
        *(s32 *)(a0 + 0xE4) = (s32)&D_801953B4;
        break;
    case 4:
        t = func_80029504();
        if (t < 0x87) {
            *(s32 *)(a0 + 0xE4) = (s32)&D_801953B4;
        } else {
            *(s32 *)(a0 + 0xE4) = (s32)&D_80195214[0];
        }
        break;
    }
}
