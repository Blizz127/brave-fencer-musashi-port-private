/* sc03_0001: func_80186D18 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern s32 func_80178BF8();
extern void func_80172710(void);

s32 func_80186D18(void)
{
    extern u16 D_80126B5E;
    extern u16 D_80126B66;
    extern u16 D_80126B62;
    s16 v1;
    s32 result;
    v1 = *(s16 *)&D_80126B5E;
    if (v1 < 0x400) {
        result = 0;
    } else if (v1 >= 0x501) {
        result = 0;
    } else {
        v1 = *(s16 *)&D_80126B66;
        if (v1 < 0x580) {
            result = 0;
        } else if (v1 >= 0x601) {
            result = 0;
        } else {
            v1 = *(s16 *)&D_80126B62;
            result = (v1 >= -0x200);
        }
    }
    return result;
}
