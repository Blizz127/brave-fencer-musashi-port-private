/* sc03_0001: func_80154F9C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8016F1AC(void);
extern u8 D_80078E78[];
extern s16 D_80078E96;
extern u16 D_80078EA6;
extern s16 D_80078E96;
extern u8 D_800D8D10[];
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern void func_801550FC(s32 a0);
extern u8 D_80078E78[];
extern s16 D_80078E96;
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern u8 D_800D8D10[];
extern s32 func_8016F1AC(void);
extern void func_801550FC(s32 a0);
void func_801550FC(s32 arg0);

void func_80154F9C(s32 a0) {
    u8 *base = D_80078E78;
    if (*(s32 *)(a0 + 0xC8) & 0x1000000) {
        if ((D_80078E96 & 0x8000) || D_80078E9E < 0x10 || (s16)D_80078EA6 < 0x10) {
            if (func_8016F1AC() == 0) {
                return;
            }
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
        func_801550FC(*(s32 *)(a0 + 0xC8));
    } else {
        if ((D_80078E96 & 0x8000) && func_8016F1AC() == 0) {
            *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
            func_801550FC((s32)D_800D8D10);
            return;
        }
        if (!(*(s16 *)(base + 0x26) < 0x10) && !(*(s16 *)(base + 0x2E) < 0x10)) {
            return;
        }
        if (*(s32 *)(a0 + 0x44) & 0xC0) {
            return;
        }
        if (func_8016F1AC() != 0) {
            return;
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
        func_801550FC(0x40000002);
    }
}
