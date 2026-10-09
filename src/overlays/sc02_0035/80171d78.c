/* SC02.CD member35: func_80171D78 from Druthulu/BFM-decomp
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
extern void func_80171EC8(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_80146D90(s32 a0);
extern s32 func_8017248C(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_80171EC8(s32 a0);
extern void func_80146D90(s32 a0);
void func_80171EC8(s32 a0);
s32 func_8017248C(s32 arg0, s32 arg1);

s32 func_80171D78(s32 a0, s32 a1)
{
    s32 ret;
    s32 ang;
    s32 p;
    ret = func_8017248C(a0, a1);
    if (ret != 0) {
        func_80146D90(a0);
        return ret;
    }
    ang = func_8004CFEC(*(s16 *)(a1 + 0) - *(s16 *)(a0 + 6),
                 *(s16 *)(a1 + 4) - *(s16 *)(a0 + 0xE));
    ang = (ang + 0x800) & 0xFFF;
    p = *(s32 *)(a0 + 0x20);
    *(s16 *)(p + 0x12) = ang;
    func_80171EC8(a0);
    return 0;
}
