/* sc03_0001: func_80180D9C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80029124(s32, s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern void func_80029124(s32 a0, s32 a1);
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 arg);
extern void func_80029124(s32, s32);

s32 func_80180D9C(void) {
        if ((func_80029178(0x110) & 0xFF) == 0) {
            ((void (*)(void *, s32))func_80029124)((void *)0x110, 1);
            return 1;
        }
        return 0;
    }
