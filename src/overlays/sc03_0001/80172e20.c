/* sc03_0001: func_80172E20 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct Src80172E20;
struct Src80172E20 {
    u8 pad0[6];
    u16 _6;
    u8 pad8[0xA - 8];
    u16 _A;
    u8 padC[0xE - 0xC];
    u16 _E;
};
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 param_1, void * _arg1);
extern s32 func_80174650(s32);
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
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s32 D_80127508;
extern void func_80171A1C(u8 *a0);
extern s32 D_80127508;
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_80172E20(u8 * a0)
{
    struct Src80172E20 *p = (struct Src80172E20 *)D_80127508;
    u16 sp10[3];
    sp10[0] = p->_6;
    sp10[1] = p->_A;
    sp10[2] = p->_E;
    if (func_80171AB0(a0, sp10) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650(a0);
    }
}
