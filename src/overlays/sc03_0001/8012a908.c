/* sc03_0001: func_8012A908 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u8 D_801202A0[];
extern u16 D_801270C0;
extern void func_8012A988(u8 *a0);
void func_8012A988(u8 *a0);

void func_8012A908(void) {
    u8 *p = D_801202A0;
    s32 i;
    for (i = 0; i < 0x60; i++) {
        if (((s16)D_801270C0 == 1) || (*(u16 *)(p + 0x72) & 0x1000)) {
            func_8012A988(p);
        }
        p += 0x10C;
    }
}
