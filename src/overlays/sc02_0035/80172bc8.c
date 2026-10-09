/* SC02.CD member35: func_80172BC8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B32;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B32;

void func_80172BC8(void *a0) {
    s32 v0p = *(s32 *)((s32)a0 + 0x20);
    s32 r = func_80012B04(*(s16 *)(v0p + 0x12), D_80126B32, 4);
    s32 v1;
    if (((r << 16) >> 16) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650((s32)a0);
    }
    v1 = *(s32 *)((s32)a0 + 0x20);
    *(s16 *)(v1 + 0x12) = (*(u16 *)(v1 + 0x12) + r) & 0xFFF;
}
