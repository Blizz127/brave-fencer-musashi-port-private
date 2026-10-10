/* sc01_0077: func_8017F780 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern s32 func_8012B4B8();
extern void func_8012A568(void (*a0)(void));
extern void (*D_8018A934[])(s32 *);
extern s32 func_8012B4B8();
extern s32 func_8012C0EC(s32 a0);

void func_8017F780(s32 *arg0) {
    D_8018A934[*(u16 *)((s32)arg0 + 2)](arg0);
    func_8012B4B8((s32)arg0);
    if (*(u16 *)arg0 != 0) {
        ((s32 (*)(s32))func_8012C0EC)((s32)arg0);
    }
}
