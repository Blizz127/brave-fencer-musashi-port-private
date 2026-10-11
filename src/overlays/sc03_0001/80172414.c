/* sc03_0001: func_80172414 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern void func_8012A568(void (*a0)(void));
extern void func_80161C24(s32, s32);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;

void func_80172414(s32 a0) {
    if (*(u16 *)(a0 + 0xB8) & 0x2000) {
        func_80161C24(a0, *(u16 *)(a0 + 0x16E));
    }
    if (*(s32 *)(a0 + 0x2C) < (s32)0xFFF90000) {
        if ((D_800B99DA & 7) == 0) {
            func_8014C010(a0, 2);
        }
    }
}
