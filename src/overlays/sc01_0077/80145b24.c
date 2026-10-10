/* sc01_0077: func_80145B24 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);
extern void func_80162120(void);
extern void func_80029124(s32, s32);
extern s32 func_80165A50(s32);
extern void func_80029514(s32);
extern u8 D_800AF630[];
extern u8 D_80078EC0;
extern s32 D_80126B58;

void func_80145B24(void)
{
    s32 iVar1;
    s32 uVar2;
    u8 *p;
    p = &D_800AF630;
    iVar1 = func_80029504();
    uVar2 = func_800291DC(8);
    if ((uVar2 & 0x8000) != 0) {
        func_800291C8(8, 0);
        func_80162120();
    }
    if (iVar1 >= 0x6A4) {
        func_80029124(0x1A, 0);
        func_80029124(0x8E, 0);
        func_80029124(0x143, 0);
        if ((D_80078EC0 & 0x7F) != 0) {
            D_80078EC0 = 1;
        }
        func_80165A50((s32)&D_80126B58);
        func_80029514(0x4B0);
    }
    *(s16 *)(p + 0xA3DA) = 0x3000;
}
