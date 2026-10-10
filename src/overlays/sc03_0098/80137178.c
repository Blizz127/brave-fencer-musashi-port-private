/* sc03_0098: func_80137178 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);

void func_80137178(s32 a0, s32 a1)
{
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
    s16 x0;
    s16 white;
    u8 *base = D_800A6518;
    s16 x1;
    s16 y0;
    s16 y1;
    x0 = a0 - 3;
    y0 = a1 - 3;
    x1 = a0 + 3;
    y1 = a1 - 3;
    white = 0xFF;
    line.tag = 0;
    line.r = 0;
    line.g = 0;
    line.b = white;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    func_80051DC8(&line, &base[(u16)D_800B9A02 * 20], 0);
    y0 = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0;
    line.b = white;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    func_80051DC8(&line, &base[(u16)D_800B9A02 * 20], 0);
    y1 = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0;
    line.b = white;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    func_80051DC8(&line, &base[(u16)D_800B9A02 * 20], 0);
}
