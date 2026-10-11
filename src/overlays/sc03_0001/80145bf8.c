/* sc03_0001: func_80145BF8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80145BF8(void) {
    func_8002D4C8(0x21, func_80028FBC() & 0xFFFF);
    func_8002D4C8(0x22, func_80029000() & 0xFFFF);
    func_8002D4C8(func_80028D9C() == 0 ? 0xC : 0xB, 0);
}
