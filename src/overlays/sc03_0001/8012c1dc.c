/* sc03_0001: func_8012C1DC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_800B3DF0[];

s32 func_8012C1DC(s32 a0) {
    u8 *p;
    u8 *end;
    p = (u8 *)(*(s32 *)(a0 + 0x20) + 0x84);
    end = D_800B3DF0;
    if (p != end) {
        do {
            if (*(u16 *)p == 0) {
                return (s32)p;
            }
            p += 0x84;
        } while (p != end);
    }
    return 0;
}
