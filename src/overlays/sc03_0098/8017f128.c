/* sc03_0098: func_8017F128 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8001D0E8(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8001D0E8(s32 arg0, s32 arg1, s32 arg2);

void func_8017F128(s32 a0) {
    extern u8 D_80199BE4[];
    extern u8 D_8018564C[];
    u16 old_fc;
    if (func_8012C354(a0, (s32)D_80199BE4) != 0) {
        func_8012A828(a0, (s32)D_8018564C);
        *(s16 *)(a0 + 0x2) = 1;
        *(u8 *)(a0 + 0x75) = 8;
        func_8001D0E8(*(s32 *)(a0 + 0x20), 0x104, 0xDC);
        old_fc = *(u16 *)(a0 + 0xFC);
        *(u16 *)(a0 + 0xFC) = 0x60;
        *(u16 *)(a0 + 0xFE) = old_fc;
    }
}
