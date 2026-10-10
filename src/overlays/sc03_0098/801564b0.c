/* sc03_0098: func_801564B0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern u8 D_80078E78[];
extern u8 D_80078E78[];
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8002A1B4(void);
extern s32 func_8002A400(void);
extern s32 func_8002A670(void);
extern s32 func_8002A8E0(void);
extern u8 D_80078E78[];

s32 func_801564B0(s32 a0) {
    s32 s0 = (s32)D_80078E78;
    s32 v1;
    if (*(s32 *)(a0 + 0x44) & 0x200) {
        if (func_8005C49C() & 0x1) {
            return 0x8000;
        }
    }
    if (func_8002A1B4() || func_8002A400() || func_8002A670() || func_8002A8E0()) {
        if ((func_8005C49C() & 0x3) == 0) {
            return 0x8000;
        }
    }
    if ((func_8005C49C() & 0x3) != 0) {
        return 0;
    }
    v1 = func_8005C49C() % 160 & 0xFFFF;
    if ((u32)v1 < 0x51) {
        return 0;
    }
    if (v1 >= *(s16 *)(s0 + 0x2E)) {
        __asm__ __volatile__("");
        return 0;
    }
    return 0x8000;
}
