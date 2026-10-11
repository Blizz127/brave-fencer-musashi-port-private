/* sc03_0001: func_80136334 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void *memcpy(void *, const void *, unsigned int);
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern u8 D_8018DAA0;
extern u8 D_8018DA9C;
extern s16 *D_8018DAA4;
extern u8 D_8018DAA8;
extern u8 D_8018DA9C;
extern u8 D_8018DAA0;
extern s16 *D_8018DAA4;
extern u8 D_8018DAA8;
extern u8 D_80126720[];

s32 func_80136334(void *arg0, s32 arg1, s32 arg2) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;
    s32 a1v;
    register s32 a2v __asm__("$12");
    s32 n;
    s16 *b4;
    s32 d;
    s32 dx;
    s32 denom;
    s32 result;
    s32 frame_pad[2];
    (void)&frame_pad;
    __asm__("" : "=r"(a1v) : "0"(arg1));
    a2v = arg2;
    if (!(arg1 & 1)) {
        dx = (s16) arg2 - (*(s16 **)&D_8018DA9C)[2];
        d = dx;
        denom = -(*(s16 **)&D_8018DAA8)[2];
    } else {
        denom = (*(s16 **)&D_8018DAA8)[2];
        d = (*(s16 **)&D_8018DA9C)[2] - (s16) arg2;
        dx = -d;
    }
    n = -d;
    {
        s16 *b8 = *(s16 **)&D_8018DAA8;
        u16 *ac = *(u16 **)&D_8018DA9C;
        b4 = D_8018DAA4;
        b4[0] = ac[0] + n * b8[0] / denom;
        b4[1] = ac[1] + n * b8[1] / denom;
        b4[2] = ac[2] + dx;
    }
    if (b4[0] < (*(s16 *)((s8 *)(arg0) + (4)))) return 0;
    if ((*(s16 *)((s8 *)(arg0) + (6))) < b4[0]) return 0;
    if (b4[1] < (*(s16 *)((s8 *)(arg0) + (8)))) return 0;
    if ((*(s16 *)((s8 *)(arg0) + (0xA))) < b4[1]) return 0;
    if (a1v & 0x8000) {
        u16 *b0 = *(u16 **)&D_8018DAA0;
        b4[0] = b0[0];
        b4[1] = b0[1];
    }
    D_801152AA = 0;
    (*(s16 *)D_801152A8) = 0;
    if (a1v & 1) {
        D_8018DAA4[2] = a2v + 2;
        __asm__ __volatile__("");
        D_801152AC = 0xFFF;
    } else {
        D_801152AC = -0xFFF;
        D_8018DAA4[2] = a2v - 2;
    }
    __asm__ __volatile__("" :: "r"(a1v), "r"(a2v));
    (*(s16 *)D_80126720) = ((*(s16 *)((s8 *)(arg0) + (4))) + (*(s16 *)((s8 *)(arg0) + (6)))) >> 1;
    D_80126722 = ((*(s16 *)((s8 *)(arg0) + (8))) + (*(s16 *)((s8 *)(arg0) + (0xA)))) >> 1;
    result = 1;
    D_80126724 = ((*(s16 *)((s8 *)(arg0) + (0xC))) + (*(s16 *)((s8 *)(arg0) + (0xE)))) >> 1;
    return result;
}
