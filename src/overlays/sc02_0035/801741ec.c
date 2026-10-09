/* SC02.CD member35: func_801741EC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern s16 D_8011F9C8;
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B3C;
extern s16 D_8011F9C8;
s32 func_80174650(s32 _arg0);

void func_801741EC(u8 *a0) {
    s32 v0;
    s32 s1;
    s32 t;
    v0 = *(s32 *)(a0 + 0x20);
    s1 = func_80012B04(*(s16 *)(v0 + 0x12), D_80126B3C, 4);
    if ((s16)s1 == 0) {
        D_8011F9C8 = 1;
        func_80171A1C(a0);
        func_80174650((s32)a0);
    }
    t = *(s32 *)(a0 + 0x20);
    *(u16 *)(t + 0x12) = (*(u16 *)(t + 0x12) + s1) & 0xFFF;
}
