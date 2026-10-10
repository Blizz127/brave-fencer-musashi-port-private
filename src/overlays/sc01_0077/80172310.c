/* sc01_0077: func_80172310 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 D_80126B58;
extern s32 *D_80126B78;
extern void func_80172358(u8 *a0, u8 *a1);
extern void func_8012A568(void (*a0)(void));
extern s32 D_80126B58;
extern s32 *D_80126B78;
extern void func_80172358(u8 *a0, u8 *a1);
void func_80172358(u8 *a0, u8 *a1);

void func_80172310(u8 *a0) {
    func_80172358((u8 *)&D_80126B58, a0);
    *(u16 *)((u8 *)D_80126B78 + 0x12) = *(u16 *)(a0 + 6);
}
