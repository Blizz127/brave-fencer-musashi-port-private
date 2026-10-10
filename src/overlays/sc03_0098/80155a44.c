/* sc03_0098: func_80155A44 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 func_80029178(s32 arg);
extern u16 func_80148800(s32 *a0);
extern u8 func_8014BEF8(void);
extern s32 func_80029178(s32 a0);
extern void func_80149CB4(void);
extern u8 func_8014BEF8(void);
extern s32 func_80029178(s32);
extern u16 func_80148800(s32 *a0);
extern s32 func_80029178(s32 arg);
extern u8 func_8014BEF8(void);
extern u16 func_80148800(s32 *a0);
extern void func_80149CB4(void);

int func_80155A44(int param_1)
{
    int x = *(unsigned char *)(param_1 + 0x1AA);
    switch (x) {
    case 0:
    case 1:
        if ((((unsigned char (*)(int))func_80029178)(0x85) & 0xFF) &&
            ((int (*)(int))func_8014BEF8)(param_1) &&
            *(unsigned char *)(param_1 + 0x1C0) &&
            (((int (*)(int))func_80148800)(param_1) & 0x10)) {
            ((void (*)(int, int))func_80149CB4)(param_1, 2);
            return 1;
        }
        break;
    case 2:
        if ((((unsigned char (*)(int))func_80029178)(0x86) & 0xFF) &&
            (((int (*)(int))func_80148800)(param_1) & 0x10)) {
            ((void (*)(int, int))func_80149CB4)(param_1, 3);
            return 1;
        }
        break;
    }
}
