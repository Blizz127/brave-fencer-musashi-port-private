/* SC02.CD member35: func_80173648 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_80171CC4(void *a0, void *a1);
extern s32 func_80172664(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80171CC4(void * a0, void * a1);
extern s32 func_80174650(s32);
extern s16 D_80126B3E;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80171CC4(void *a0, void *a1);
extern s32 func_80172664(s32 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B3E;
s32 func_80174650(s32 _arg0);

void func_80173648(u8 *a0) {
    u8 *s0 = a0;
    s16 *p = &D_80126B3E;
    if (*p != 0) {
        func_80171CC4(s0, (u8 *)p - 6);
    }
    if (func_80172664((s32 *)s0) == 0) {
        func_80171A1C(s0);
        func_80174650((s32)s0);
    }
}
