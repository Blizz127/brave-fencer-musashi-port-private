/* sc02_0037: func_8012F7B4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
s32 func_8012BEE8(s32 a0);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);

void func_8012F7B4(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 4) {
        func_8012BEE8(a0);
        if (*(s32 *)(a0 + 0x1C) == 1) {
            if (func_80131A34(a0, 8) == 0) {
                func_80131A34(a0, 0x20);
            }
        }
    }
    func_80131CA8(a0, 7);
}
