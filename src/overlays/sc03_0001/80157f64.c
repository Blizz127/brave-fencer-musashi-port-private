/* sc03_0001: func_80157F64 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern s32 func_80029178(s32 arg);
extern u16 func_80148800(s32 *a0);
extern s32 func_80029178(s32 a0);
extern void func_80149CB4(void);
extern s32 func_80029178(s32);
extern u16 func_80148800(s32 *a0);
extern s32 func_80029178(s32 arg);
extern u16 func_80148800(s32 *a0);
extern void func_80149CB4(void);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_80149CB4(void);

s32 func_80157F64(s32 *a0) {
    if ((func_80029178(0x87) & 0xFF) != 0) {
        if ((func_80148800(a0) & 0x80) != 0) {
            ((void (*)(s32 *, s32))func_80149CB4)(a0, 5);
            return 1;
        }
    }
    return 0;
}
