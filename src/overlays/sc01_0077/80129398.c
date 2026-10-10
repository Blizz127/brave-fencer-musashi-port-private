/* sc01_0077: func_80129398 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s16 D_800B9AAC[];
extern s16 D_800B9AAE[];
extern s16 D_800B9AB0[];
extern s16 D_800B9AB2[];
extern s16 D_800B9AB4[];
extern s16 D_800B9AB6[];
extern s16 D_800B9AB8[];
extern s16 D_800B9ABA[];

void func_80129398(void)
{
    s32 i;
    s32 off;
    for (i = 0; i < 2; i++) {
        off = i * 0x54;
        *(s16 *)((char *)D_800B9AAC + off) = 0x7FFF;
        *(s16 *)((char *)D_800B9AAE + off) = 0;
        *(u16 *)((char *)D_800B9AB0 + off) = 0xFFFF;
        *(s16 *)((char *)D_800B9AB2 + off) = 0;
        *(s16 *)((char *)D_800B9AB4 + off) = 0x140;
        *(s16 *)((char *)D_800B9AB6 + off) = 0xEE;
        *(s16 *)((char *)D_800B9AB8 + off) = 0;
        *(s16 *)((char *)D_800B9ABA + off) = 0;
        off += 0x54;
    }
}
