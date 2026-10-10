/* sc01_0077: func_801563EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { s32 a, b, c; } S801563EC;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern S801563EC D_80188B80[];

S801563EC *func_801563EC(u16 idx) {
    return &D_80188B80[idx];
}
