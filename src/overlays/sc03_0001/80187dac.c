/* sc03_0001: func_80187DAC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80188438(s32 a0);
extern void func_801883C4(s32 a0);
extern void func_80188498(s32 a0);
extern void func_8018835C(s32 a0);
void func_8018835C();
void func_801883C4(s32 a0);
void func_80188438(s32 a0);
void func_80188498(s32 a0);

void func_80187DAC(s32 a0) {
    extern void (*D_801C0DF8[])(s32);
    u32 st;
    if (*(s16 *)(a0 + 0x10A) > 0) {
        *(s16 *)(a0 + 0x10A) = *(s16 *)(a0 + 0x10A) - 1;
    }
    if (*(s16 *)(a0 + 0x108) != 0) {
        *(s32 *)(a0 + 0xB0) = *(s16 *)(a0 + 0x108);
        *(s16 *)(a0 + 0x108) = 0;
    }
    st = *(u32 *)(a0 + 0xB0);
    switch (st) {
    case 1:
        if (*(u16 *)(a0 + 0x2) != 2 || *(u16 *)(a0 + 0x34) == 0) {
            if (*(s16 *)(a0 + 0xEA) != st) {
                *(s16 *)(a0 + 0xEA) = st;
                if (*(s16 *)(a0 + 0xE8) != 0) {
                    func_80188438(a0);
                } else {
                    func_801883C4(a0);
                }
                *(s16 *)(a0 + 0xE8) = 1;
            }
        }
        break;
    case 2:
        if (*(u16 *)(a0 + 0x2) != 2 || *(u16 *)(a0 + 0x34) == 0) {
            if (*(s16 *)(a0 + 0xEA) != st) {
                *(s16 *)(a0 + 0xEA) = st;
                if (*(s16 *)(a0 + 0xE8) != 0) {
                    func_80188498(a0);
                } else {
                    func_8018835C(a0);
                }
                *(s16 *)(a0 + 0xE8) = 1;
            }
        }
        break;
    case 3:
        if (*(u16 *)(a0 + 0x2) != 2 || *(u16 *)(a0 + 0x34) == 0) {
            func_801883C4(a0);
        }
        break;
    case 4:
        if (*(u16 *)(a0 + 0x2) != 2 || *(u16 *)(a0 + 0x34) == 0) {
            func_8018835C(a0);
        }
        break;
    }
    D_801C0DF8[*(u16 *)(a0 + 0x2)](a0);
}
