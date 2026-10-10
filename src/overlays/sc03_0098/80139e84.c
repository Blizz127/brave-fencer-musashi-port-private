/* sc03_0098: func_80139E84 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139B18(s32 a0);
void func_80139A8C(s32 a0);
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_80139E84(s32 a0) {
    s32 s0 = a0;
    if (*(u16 *)(s0 + 0xE) == 0) {
        *(s16 *)(s0 + 0x4) = 2;
    } else {
        func_80139A8C(s0);
        if ((*(s32 *)(s0 + 0x8) & 0x80020) != 0) {
            *(s16 *)(s0 + 0x4) = 2;
            *(s16 *)(s0 + 0xE) = 0;
            if ((*(s32 *)(s0 + 0x8) & 0x20000) == 0) {
                *(s32 *)(s0 + 0x8) = *(s32 *)(s0 + 0x8) & -0x21;
            }
        }
    }
    func_80139B18(s0);
}
