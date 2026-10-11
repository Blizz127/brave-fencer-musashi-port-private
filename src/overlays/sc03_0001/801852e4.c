/* sc03_0001: func_801852E4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80187778(s32*, s32);

void func_801852E4(void * arg0) {
    extern short D_80192640;
    if (func_80178970() != 0) {
        ((void (*)(s32))func_80178D18)((s32)arg0);
        *(short *)((char *)arg0 + 0x2) = 6;
        ((void (*)(s32, s32))func_80187778)((int)arg0, (int)&D_80192640);
    }
}
