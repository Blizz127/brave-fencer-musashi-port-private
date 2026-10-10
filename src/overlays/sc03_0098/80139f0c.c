/* sc03_0098: func_80139F0C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127524;
extern s32 D_80127524;
extern s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80139B18(s32 a0);
s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
void func_80139B18(s32 a0);
extern void func_80139B18(s32 a0);
extern s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80139B18(s32 a0);
extern s32 D_80127524;

void func_80139F0C(s32 a0) {
    s32 s0 = a0;
    s32 a2;
    if (D_80127524 != s0 && (*(s32 *)(s0 + 8) & 0x2000) == 0) {
        *(s16 *)(s0 + 4) = 4;
        return;
    }
    if (*(s32 *)(s0 + 8) & 0x4000) {
        a2 = 0x70;
    } else {
        a2 = 0x60;
    }
    if (func_80138DB8(s0, 0, a2) != 0) {
        s32 v1;
        *(s16 *)(s0 + 4) = 2;
        v1 = *(s32 *)(s0 + 8);
        if ((v1 & 0x20000) == 0) {
            *(s32 *)(s0 + 8) = v1 & ~0x20;
        }
        func_8002D4C8(0x88D, 0);
    }
    func_80139B18(s0);
}
