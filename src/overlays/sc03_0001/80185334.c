/* sc03_0001: func_80185334 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80184D64(short *param_1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80184D64(short*);

void func_80185334(s32 *a0) {
    *(s32 *)((s32)a0[0x33] + 0xB0) = 2;
    if (func_8018766C(16, 20) != 0) {
        return;
    }
    ((void (*)(s32 *))func_80184D64)(a0);
}
