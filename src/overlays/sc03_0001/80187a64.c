/* sc03_0001: func_80187A64 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8016F1AC(void);
extern void func_8014B12C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012AD80(s32 a0);
extern s32 func_8012B030(u8 *a0);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012BE98(s32 a0, u16 *a1);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8016F1AC(void);
extern void func_8014B12C(void);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012AD80(s32 a0);
extern s32 func_8012B030(u8 *a0);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012BE98(s32 a0, u16 *a1);

s32 func_80187A64(s32 a0) {
    u16 vals[3];
    s32 sh;
    if (func_8016F1AC() != 0) {
        return 0;
    }
    if (*(u8 *)(a0 + 0x108) == 0) {
        if (*(s16 *)(*(s32 *)(a0 + 0xE8)) < *(s16 *)(a0 + 0x106)) {
            return 1;
        }
    } else if (*(s16 *)(a0 + 0x106) <= 0) {
        return 1;
    }
    vals[0] = *(u16 *)(*(s16 *)(a0 + 0x106) * 4 + *(s32 *)(a0 + 0xE8));
    vals[2] = *(u16 *)(*(s16 *)(a0 + 0x106) * 4 + *(s32 *)(a0 + 0xE8) + 2);
    sh = *(u8 *)(a0 + 0x109);
    sh = sh << 12;
    if (((s32 (*)(void))func_8014B12C)() != 0) {
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
            func_8012B744((void *)(a0 + 4), vals);
        sh = sh << 3;
    } else {
        s32 r = func_8012B608(*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12),
                              func_8012B744((void *)(a0 + 4), vals), 4);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + r;
    }
    func_8012B178(a0, -sh);
    func_8012AD80(a0);
    *(u16 *)(a0 + 0xA) -= 0x10;
    func_8012B030((u8 *)a0);
    if (((s32 (*)(void))func_8014B12C)() != 0) {
        if (func_8012BE98(a0, vals) < 0x1001) {
            if (*(u8 *)(a0 + 0x108) == 0) {
                *(u16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x106) + 1;
            } else {
                *(u16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x106) - 1;
            }
        }
    } else {
        if (func_8012BE98(a0, vals) < 0x101) {
            if (*(u8 *)(a0 + 0x108) == 0) {
                *(u16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x106) + 1;
            } else {
                *(u16 *)(a0 + 0x106) = *(u16 *)(a0 + 0x106) - 1;
            }
        }
    }
    return 0;
}
