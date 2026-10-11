/* sc03_0001: func_80171B4C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80146D90(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 D_801151D4;
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_80146D90(int);
extern void func_8012A568(void (*a0)(void));
extern void func_80146D90(s32);
extern s32 func_8004CFEC(s32, s32);
extern s32 D_801151D4;

s32 func_80171B4C(arg0, arg1)
s32 arg0;
u8 arg1;
{
    s32 p, ang, idx;
    u8 c;
    p = D_801151D4;
    *(u8 *)(arg0 + 0xA9) = 0x41;
    ang = func_8004CFEC(*(s32 *)(p + 0x68) - *(s32 *)(p + 0x5C),
                 *(s32 *)(p + 0x70) - *(s32 *)(p + 0x64));
    idx = ((*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12) - ((ang + 0x800) & 0xFFF)) + 0x100) & 0xE00;
    switch (idx / 0x200) {
    case 0: *(u16 *)(arg0 + 0xAA) = 0x1000; break;
    case 1: *(u16 *)(arg0 + 0xAA) = 0x3000; break;
    case 2: *(u16 *)(arg0 + 0xAA) = 0x2000; break;
    case 3: *(u16 *)(arg0 + 0xAA) = 0x6000; break;
    case 4: *(u16 *)(arg0 + 0xAA) = 0x4000; break;
    case 5: *(u16 *)(arg0 + 0xAA) = 0xC000; break;
    case 6: *(u16 *)(arg0 + 0xAA) = 0x8000; break;
    case 7: *(u16 *)(arg0 + 0xAA) = 0x9000; break;
    }
    c = *(u8 *)(arg0 + 0x20C);
    *(u8 *)(arg0 + 0x20C) = c + 1;
    if (c != arg1) {
        return 0;
    }
    func_80146D90(arg0);
    return 1;
}
