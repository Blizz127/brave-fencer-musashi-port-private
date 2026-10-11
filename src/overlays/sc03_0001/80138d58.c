/* sc03_0001: func_80138D58 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A9F8(s32 a0, s32 a1);
void func_8013A9F8(s32 a0, s32 a1);

void func_80138D58(s32 a0, u16 a1) {
    if (*(s32 *)(a0 + 0x40) == 0) {
        return;
    }
    if ((u32)(*(u16 *)(a0 + 0x18) - 2) >= 5) {
        return;
    }
    if ((u32)(u16)(a1 - 2) >= 5) {
        return;
    }
    *(s16 *)(a0 + 0x18) = a1;
    func_8013A9F8(*(s32 *)(a0 + 0x40), a1);
}
