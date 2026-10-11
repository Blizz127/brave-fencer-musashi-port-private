/* sc03_0001: func_8018541C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern short D_80192640;
extern void func_80187778(s32*, s32);

void func_8018541C(s32 *a0) {
        *(s32 *)((s32)a0[0x33] + 0xB0) = 2;
        if (func_8018766C(0x6, 0x7) != 0) {
            return;
        }
        *(short *)((char *)a0 + 0x2) = 6;
        ((void (*)(s32 *, void *))func_80187778)(a0, (void *)&(*(s32 *)&D_80192640));
    }
