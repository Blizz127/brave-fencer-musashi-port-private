/* sc01_0077: func_8012F68C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
s32 func_8012BEE8(s32 a0);
void func_8012CBCC(s32 a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
struct S80131E00;
extern void func_8012CBCC(s32 a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80131C78(s32 a0);
extern void func_80131CA8(int a0, int a1);
void func_80131C78(s32 a0);
void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_8012F68C(s32 arg0) {
    s32 flag;
    u32 cond;
    flag = 0;
    if (!(*(u32 *)(arg0 + 0xC4) & 2) && (*(u32 *)(arg0 + 0xB4) & 1)) {
        if ((u8)((s32 (*)(s32))func_8012CBCC)(arg0) == 2) {
            func_80131E00((struct S80131E00 *)arg0, 0x12);
            return;
        }
        if (*(u8 *)(arg0 + 0xC2) != 0) {
            cond = func_8012BEE8(arg0);
        } else {
            cond = *(u16 *)(arg0 + 0x72) & 0x4000;
        }
        if (cond != 0) {
            flag = 1;
        }
        if (flag != 0) {
            func_80131C78(arg0);
        }
    }
    func_80131CA8(arg0, 5);
}
