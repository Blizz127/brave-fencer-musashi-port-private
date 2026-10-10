/* sc01_0077: func_8016E9EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8016EC0C(s32 a0, s32 a1);
extern u8 *D_80189EB8[];
extern u8 D_80189ED0[];
extern u16 D_80189ED4[];
extern s32 func_800D2CA8(s32 a0, s32 a1);
extern void func_800D2D10(s32 a0, s32 a1, void *a2, s32 a3);
extern s32 func_80024054(void *a0, void *a1);
extern void func_8016EC0C(s32 a0, s32 a1);
void func_8016EC0C(s32 a0, s32 a1);

void func_8016E9EC(u8 *p)
{
    register u32 zr __asm__("$0");
    int i;
    int c;
    u8 *buf;
    u8 off;
    u16 h;
    s32 r;
    i = p[0] - 1;
    off = D_80189ED0[i];
    buf = D_80189EB8[i];
    c = i + zr;
    r = func_800D2CA8(p[3], 0x1C);
    func_800D2D10(r, 1, buf + off, 0);
    func_80024054(buf, p + 8);
    p[3] = c;
    *(s16 *)(p + 4) = -0xD7;
    h = D_80189ED4[i];
    p[2] = 0;
    *(u16 *)(p + 6) = h;
    p[1] = p[1] + 1;
    ((void (*)(u8 *, s32))func_8016EC0C)(p, 0x80);
}
