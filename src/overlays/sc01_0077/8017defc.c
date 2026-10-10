/* sc01_0077: func_8017DEFC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_80171B44(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126980;
M2C_UNK func_8017D98C(void);
extern void func_80171B44(s32 *a0);
M2C_UNK func_8017D98C();
extern u16 D_80126980;

void func_8017DEFC(void *arg0) {
    u16 temp_v0;
    temp_v0 = D_80126980 | 0x8000;
    D_80126980 = temp_v0;
    if (temp_v0 & 0x8000) {
        func_8017D98C();
        func_80171B44(arg0);
        (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
    }
}
