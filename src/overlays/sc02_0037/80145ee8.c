/* sc02_0037: func_80145EE8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801458E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
void func_80146014(s32 a0);

void func_80145EE8(s32 param_1)
{
    extern unsigned char D_801855CC[];
    extern unsigned char D_801855FC[];
    extern unsigned char D_8018564C[];
    extern unsigned char D_8018567C[];
    extern unsigned char D_801856AC[];
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_801855CC);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_801855FC);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_8018564C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_8018567C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_801856AC);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_801855CC);
        ((void (*)(void *))func_80146014)(D_801855FC);
        ((void (*)(void *))func_80146014)(D_8018564C);
        ((void (*)(void *))func_80146014)(D_8018567C);
        ((void (*)(void *))func_80146014)(D_801856AC);
        break;
    }
}
