/* sc02_0037: func_801301E8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
s32 func_8012BEE8(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80130D48(s32 a0);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80130D48(s32 a0);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
void func_80130D48(s32 arg0);

void func_801301E8(u8 *a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x2000) {
        if (*(u8 *)(a0 + 0xC3) != 0) {
            if (*(u16 *)(a0 + 0x72) & 0x4000) {
                func_80130D48((s32)a0);
                func_801319E0((s32)a0);
            }
        } else if (func_8012BEE8((s32)a0) != 0) {
            func_80130D48((s32)a0);
            func_801319E0((s32)a0);
        }
    }
    func_80131CA8((int)a0, 0x26);
}
