/* sc03_0001: func_8018727C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern s32 func_8012E57C(s32 a0, s32 a1);

s32 func_8018727C(void *a0, void *a1) {
    extern u8 D_801C0988;
    s32 v0;
    s16 val;
    if (a1 == 0) {
        a1 = (void *)&D_801C0988;
    }
    *(void **)((char *)a0 + 0xD0) = a1;
    if (*(s32 *)a1 != 0) {
        v0 = ((s32 (*)(void))func_8012C1B8)();
        *(s32 *)((char *)a0 + 0x20) = v0;
        if (v0 == 0) {
            func_8012CAE4(a0);
            return 0;
        }
        func_8001C214(v0, *(s32 *)a1);
    }
    val = *(s16 *)((char *)a1 + 0x12);
    if (val == -1) {
        return 1;
    }
    *(s32 *)((char *)a0 + 0xCC) = func_8012E57C(0x61, val);
    return 1;
}
