/* sc02_0037: func_80136ECC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80135EB0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);

void func_80136ECC(s16 a0, s16 a1, s16 a2, s16 a3, u8 r, u8 g, u8 b) {
    struct {
        u32 tag;
        s16 x0;
        s16 y0;
        s16 x1;
        s16 y1;
        u8 r;
        u8 g;
        u8 b;
    } line;
    line.x0 = a0;
    line.tag = 0;
    line.y0 = a1;
    line.x1 = a2;
    line.y1 = a3;
    line.r = r;
    line.g = g;
    line.b = b;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
}
