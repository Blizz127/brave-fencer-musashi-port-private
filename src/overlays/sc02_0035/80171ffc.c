/* SC02.CD member35: func_80171FFC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80146D90(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_80146D90(int);
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
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8017248C(s32, s32);
extern s32 func_8004CFEC(s32, s32);
extern void func_80172170(s32, s32);
extern void func_80146D90(s32);
void func_80172170(s32 a0, s32 a1);
s32 func_8017248C(s32 arg0, s32 arg1);

s32 func_80171FFC(short *a0, short *a1, s32 a2)
{
    s32 r;
    r = func_8017248C((s32)a0, (s32)a1);
    if (r != 0) {
        func_80146D90((s32)a0);
        return r;
    }
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) =
        (func_8004CFEC(a1[0] - a0[3], a1[2] - a0[7]) + 0x800) & 0xFFF;
    func_80172170((s32)a0, a2 & 0xFF);
    return 0;
}
