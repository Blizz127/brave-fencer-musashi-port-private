/* sc03_0098: func_80145EE8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
extern unsigned char D_80186CE0[];
extern unsigned char D_80186D10[];
extern unsigned char D_80186D60[];
extern unsigned char D_80186D90[];
extern unsigned char D_80186DC0[];
void func_80146014(s32 a0);

void func_80145EE8(s32 param_1)
{
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_80186CE0);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_80186D10);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_80186D60);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_80186D90);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_80186DC0);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_80186CE0);
        ((void (*)(void *))func_80146014)(D_80186D10);
        ((void (*)(void *))func_80146014)(D_80186D60);
        ((void (*)(void *))func_80146014)(D_80186D90);
        ((void (*)(void *))func_80146014)(D_80186DC0);
        break;
    }
}
