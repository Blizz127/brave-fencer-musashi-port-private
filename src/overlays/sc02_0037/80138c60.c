/* sc02_0037: func_80138C60 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
    } Q_80138C60;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139BE0(s32 a0);
extern void func_80139C7C(u8 *a0);
extern s32 func_8013A8FC(s32 arg0);
extern void func_80139BE0(s32 a0);
void func_80139BE0(s32 a0);
void func_80139C7C(u8 *a0);
s32 func_8013A8FC(s32 arg0);

s32 func_80138C60(s32 arg0)
{
    extern Q_80138C60 D_801841DC[];
    u16 t;
    u8 b;
    s32 f;
    s32 idx;
    if (*(s32 *)(arg0 + 8) & 0x2000) {
        return 1;
    }
    t = *(u8 *)(arg0 + 0x22) & 7;
    *(s16 *)(arg0 + 0x18) = t;
    if (t < 2) {
        *(u8 *)(arg0 + 0x20) = 0;
    }
    f = *(s32 *)(arg0 + 8);
    if (f & 0x40) {
        *(u8 *)(arg0 + 0x22) = (*(u8 *)(arg0 + 0x22) & 0x67) | (f & ~0x67);
    }
    b = *(u8 *)(arg0 + 0x22);
    if (b & 0x80) {
        idx = (b & 0x18) >> 3;
    } else {
        idx = (b & 0x78) >> 3;
        if (b & 0x60) {
            *(s16 *)(arg0 + 0x1C) = 0;
        }
    }
    *(Q_80138C60 *)(arg0 + 0x24) = D_801841DC[idx];
    func_80139BE0(arg0);
    func_80139C7C((u8 *)arg0);
    return func_8013A8FC(arg0);
}
