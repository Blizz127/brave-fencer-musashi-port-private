/* sc03_0098: func_8013895C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127524;
extern s32 D_80127524;
extern s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
extern void func_80138B88(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
void func_80138B88(s32 a0);
s16 func_80138DB8(s32 a0, u8 a1, s32 a2);

void func_8013895C(s32 a0) {
    if ((s32)D_80127524 == a0 || (*(s32 *)(a0 + 8) & 0x2000)) {
        if ((s16)func_80138DB8(a0, 0, 0x40)) {
            *(s8 *)(a0 + 0x1F) = *(u8 *)(a0 + 0x1F) + 1;
            func_80138B88(a0);
            func_8002D4C8(0x630, 0);
        } else if ((s16)func_80138DB8(a0, 0, 0x1000)) {
            *(s8 *)(a0 + 0x1F) = *(u8 *)(a0 + 0x1F) - 1;
            if ((s8)*(s8 *)(a0 + 0x1F) < 0) {
                *(s8 *)(a0 + 0x1F) = *(u8 *)(a0 + 0x21) - 1;
            }
            func_8002D4C8(0x62F, 0);
        } else if ((s16)func_80138DB8(a0, 0, 0x4000)) {
            u8 cur = *(u8 *)(a0 + 0x1F);
            u8 lim = *(u8 *)(a0 + 0x21);
            *(s8 *)(a0 + 0x1F) = cur + 1;
            if (!((s32)(s8)(*(s8 *)(a0 + 0x1F)) < (s32)lim)) {
                *(s8 *)(a0 + 0x1F) = 0;
            }
            func_8002D4C8(0x62F, 0);
        } else if (*(s32 *)(a0 + 8) & 0x2) {
            if ((s16)func_80138DB8(a0, 0, 0x30)) {
                *(s8 *)(a0 + 0x1F) = *(u8 *)(a0 + 0x21) - 1;
                func_8002D4C8(0x62F, 0);
            }
        }
    }
}
