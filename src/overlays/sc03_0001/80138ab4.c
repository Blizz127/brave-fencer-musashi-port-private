/* sc03_0001: func_80138AB4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80127540[4];
extern s32 func_80139D04(s32 a0, s32 a1);
extern s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2);
extern void func_80139B18(s32 a0);
s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2);
void func_80139B18(s32 a0);
s32 func_80139D04(s32 a0, s32 a1);

void func_80138AB4(s32 a0) {
    u8 sp10[8];
    s32 s0 = a0;
    s32 s1;
    s32 a0v;
    s1 = func_80139D04((s32)sp10, (u16)D_80127540[*(u16 *)(s0 + 0x48)]) & 0xFFFF;
    do {
        s32 v1 = *(u16 *)(s0 + 0x44);
        a0v = 0;
        if ((s32)v1 < s1) {
            s32 a1v = (sp10[v1] + 0x30) & 0xFF;
            a0v = func_80138DE0(s0, a1v, 0);
            if (*(s32 *)(s0 + 0x8) & 0x80220) {
            } else {
                a0v = 0;
            }
        } else {
            s32 t = *(u16 *)(s0 + 0x48);
            if ((u32)t < 3) {
                *(s16 *)(s0 + 0x48) = t + 1;
            }
            *(s16 *)(s0 + 0x4) = 2;
        }
    } while (a0v != 0);
    func_80139B18(s0);
}
