/* sc03_0001: func_8017DA48 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32, s32);
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern void func_8012B2CC(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 D_801BE2F0;
extern s32 D_801BE5E0;
extern s32 D_80191038;
extern void *D_80191044[];

void func_8017DA48(s32 a0) {
    if (*(s16 *)(a0 + 0xFC) != *(s16 *)(a0 + 0xFE)) {
        *(s16 *)(a0 + 0xFE) = *(s16 *)(a0 + 0xFC);
        switch (*(s16 *)(a0 + 0xFC)) {
        case 0:
            *(s32 *)(a0 + 0x1C) = 1;
            *(s16 *)(a0 + 0x2) = 1;
            break;
        case 1:
            func_8012A828(a0, (s32)&D_801BE2F0);
            *(s16 *)(a0 + 0x2) = 2;
            break;
        case 2:
            func_8012A828(a0, (s32)&D_801BE5E0);
            *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = 0xC00;
            func_8012B2CC(a0);
            func_8012B1B4(a0, (s32)&D_80191038);
            *(s16 *)(a0 + 0x2) = 4;
            *(s32 *)(a0 + 0x1C) = 0x78;
            break;
        case 3:
            func_8012A828(a0, (s32)&D_801BE2F0);
            *(s16 *)(a0 + 0x2) = 5;
            break;
        }
    }
    ((void (*)(s32))D_80191044[*(u16 *)(a0 + 0x2)])(a0);
}
