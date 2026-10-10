/* sc03_0098: func_8017EF84 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C438(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8001D0E8(s32 arg0, s32 arg1, s32 arg2);

void func_8017EF84(s32 a0) {
    extern u8 D_80199C90[];
    extern u8 D_8018564C[];
    extern u16 D_80199D94[];
    extern u16 D_80199D96[];
    extern u16 D_80199D98[];
    extern u16 D_80199D9A[];
    s32 v0 = *(u16 *)(a0 + 0x70) & 0xF;
    u16 flag;
    if (func_8012C438(a0, (s32)(D_80199C90 + v0 * 52)) != 0) {
        func_8012A828(a0, (s32)D_8018564C);
        *(u8 *)(a0 + 0x75) = 0;
        *(u32 *)(*(s32 *)(a0 + 0x20) + 0x4) |= 0x8040;
        *(u16 *)(a0 + 0xFE) = D_80199D94[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x100) = D_80199D96[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x102) = D_80199D98[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x104) = D_80199D9A[*(s16 *)(a0 + 0xFC) * 4];
        func_8001D0E8(*(s32 *)(a0 + 0x20), 0x104, 0xDC);
        flag = *(u16 *)(a0 + 0x70) & 0xF0;
        switch (flag) {
        case 0:
            *(s16 *)(a0 + 0x2) = 1;
            break;
        case 0x10:
            *(s16 *)(a0 + 0x2) = 2;
            break;
        case 0x20:
            *(s16 *)(a0 + 0x2) = 3;
            break;
        }
        func_8012C588(0x1C4, a0);
    }
}
