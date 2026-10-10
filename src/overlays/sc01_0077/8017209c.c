/* sc01_0077: func_8017209C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_80146D90(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
void func_80146D90(s32 a0);
extern void func_80146D90(int);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern void func_80146D90(s32);
extern s32 func_8004CFEC(s32, s32);
extern void func_80146D90(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_80146D90(s32 a0);
extern s32 func_8017248C(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_80146D90(s32 a0);
extern s32 func_8017248C(s32 a0, s32 a1);
extern void func_80146D90(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8017248C(s32, s32);
extern s32 func_8004CFEC(s32, s32);
extern void func_80172170(s32, s32);
extern void func_80146D90(s32);
extern s32 func_8017248C(s32 a0, s32 a1);
extern void func_80146D90(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80172170(s32 a0, s32 a1);
void func_80172170(s32 a0, s32 a1);
s32 func_8017248C(s32 arg0, s32 arg1);

s32 func_8017209C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 ret;
    s32 ang;
    s32 a3p;
    register s32 a2p __asm__("$20");
    a3p = arg3;
    a2p = arg2;
    ret = func_8017248C((s32)arg0, (s32)arg1);
    if (ret != 0) {
        func_80146D90((s32)arg0);
        return ret;
    }
    ang = (func_8004CFEC((s32)*(s16 *)((u8 *)arg1 + 0) - (s32)*(s16 *)((u8 *)arg0 + 6),
                         (s32)*(s16 *)((u8 *)arg1 + 4) - (s32)*(s16 *)((u8 *)arg0 + 0xE))
           + 0x800) & 0xFFF;
    if (a3p != 0) {
        ang = (s16)func_80012DBC((s32)*(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x12),
                                 ang, (s16)a3p, 1);
    }
    *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x12) = ang;
    func_80172170((s32)arg0, a2p & 0xFF);
    return 0;
}
