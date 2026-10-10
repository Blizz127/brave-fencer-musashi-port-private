/* sc01_0077: func_8012B744 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);

s32 func_8012B744(void *a0, void *a1) {
    s32 ang;
    ang = func_8004CFEC(*(s16 *)((s32)a0 + 0xA) - *(s16 *)((s32)a1 + 0x4),
                 *(s16 *)((s32)a1 + 0x0) - *(s16 *)((s32)a0 + 0x2));
    return (ang - 0x400) & 0xFFF;
}
