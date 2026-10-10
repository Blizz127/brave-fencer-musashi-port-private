/* sc01_0077: func_8017C908 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_800491CC(s32 *a0, s32 *a1);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8004921C(s32 a0, s32 a1);

void func_8017C908(s32 a0, s32 a1) {
    s32 ofx;
    s32 ofy;
    s32 sxy;
    s32 p;
    func_800491CC(&ofx, &ofy);
    func_8004921C(0, 0);
    func_8004955C(a0, a1, &sxy, &p);
    func_8004921C(ofx, ofy);
}
