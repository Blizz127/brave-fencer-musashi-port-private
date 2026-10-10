/* sc03_0098: func_80130650 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
s32 func_8012BEE8(s32 a0);
void func_8012CBF4(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80131C78(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8012CBF4(s32 a0);
extern void func_801319E0(int);
extern int func_80131D68(int, int);
extern int func_8012BEE8(int);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_801319E0(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012CBF4(s32);
extern s32 func_80131D68(s32 a0, s32 a1);
extern void func_80131C78(s32 a0);
extern void func_80131CA8(int a0, int a1);
void func_801319E0(s32 arg0);
void func_80131C78(s32 a0);
int func_80131D68(int a0, int a1);

void func_80130650(s32 a0) {
    s32 s1;
    if (*(s32 *)(a0 + 0xB4) & 0x1000) {
        if (*(s16 *)(a0 + 0xA) >= 0x10) {
            func_801319E0(a0);
            return;
        }
        if (func_8012BEE8(a0) != 0) {
            func_801319E0(a0);
            return;
        }
        if (*(s32 *)(a0 + 0xC4) & 0x4) {
            s32 v1 = *(s32 *)(a0 + 0x20);
            *(s16 *)(v1 + 0x10) = *(u16 *)(v1 + 0x10) - 0x100;
        }
        s1 = ((s32 (*)(s32))func_8012CBF4)(a0);
        if (func_80131D68(a0, s1) == 1) {
            return;
        }
        if (s1 & 0x2000) {
            func_80131C78(a0);
        }
    }
    func_80131CA8(a0, 0x23);
}
