/* sc03_0001: func_80145EE8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
extern unsigned char D_8018EECC[];
extern unsigned char D_8018EEFC[];
extern unsigned char D_8018EF4C[];
extern unsigned char D_8018EF7C[];
extern unsigned char D_8018EFAC[];
void func_80146014(s32 a0);

void func_80145EE8(s32 param_1)
{
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_8018EECC);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_8018EEFC);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_8018EF4C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_8018EF7C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_8018EFAC);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_8018EECC);
        ((void (*)(void *))func_80146014)(D_8018EEFC);
        ((void (*)(void *))func_80146014)(D_8018EF4C);
        ((void (*)(void *))func_80146014)(D_8018EF7C);
        ((void (*)(void *))func_80146014)(D_8018EFAC);
        break;
    }
}
