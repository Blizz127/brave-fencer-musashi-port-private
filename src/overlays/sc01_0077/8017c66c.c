/* sc01_0077: func_8017C66C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_8012A568(void (*a0)(void));
extern void func_800487BC(void *a0);
extern void func_8004867C(void);
extern void func_8004974C(void *a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_8004871C(void);

void func_8017C66C(u16 *a0, void *a1) {
    s32 mat[8];
    s32 buf[8];
    s16 sv[4];
    func_800487BC((void *)mat);
    func_8004867C();
    sv[0] = (s16)(a0[0] - *(s32 *)((u8 *)mat + 0x14));
    sv[1] = (s16)(a0[1] - *(s32 *)((u8 *)mat + 0x18));
    sv[2] = (s16)(a0[2] - *(s32 *)((u8 *)mat + 0x1C));
    func_8004974C((void *)mat, (void *)buf);
    func_80048FBC((void *)buf, (void *)sv, a1);
    func_8004871C();
}
