/* sc02_0037: func_8012C820 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_80120194[];
extern u8 D_80120194[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern u8 D_80120194[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern u8 D_80120194[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C820(u8 *a0) {
    u8 *base = D_80120194;
    u8 *p = base + 0x6480;
    if (p != base) {
        do {
            if (*(u16 *)p == 0) goto found;
            p -= 0x10C;
        } while (p != base);
    }
    p = 0;
found:
    if (p != 0) {
        *(u16 *)(a0 + 0xA) = *(u16 *)(a0 + 0xA) | 0x8000;
        func_8012C890((s32)a0, (s32)p, 0);
    } else {
        return 0;
    }
}
