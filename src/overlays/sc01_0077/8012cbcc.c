/* sc01_0077: func_8012CBCC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012CC88(s32 a, s32 b, s32 c);
extern u8 D_800D3918[];
extern s32 func_8012CC88();
extern u8 D_800D3918[];
extern s32 func_8012CC88(s32 a, s32 b, s32 c);
extern u8 D_800D3918[];
extern s32 func_8012CC88();
extern u8 D_800D3918[];
s32 func_8012CC88(s32 a0, s32 a1, s32 a2);

void func_8012CBCC(s32 a0) {
    func_8012CC88(a0, 1, (s32)D_800D3918);
}
