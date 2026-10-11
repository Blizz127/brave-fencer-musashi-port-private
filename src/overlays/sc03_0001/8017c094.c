/* sc03_0001: func_8017C094 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 D_801151D4;
extern void func_800D23D0(void *a0);
extern void func_8012A568(void (*a0)(void));
extern s32 D_801151D4;
extern s32 D_801151D4;
extern s16 D_801EE880;
extern void func_800D23D0(void *a0);

void func_8017C094(void) {
    s16 diffs[3];
    s32 *ptr = (s32 *)D_801151D4;
    diffs[0] = (s16)(*(s32 *)((u8 *)ptr + 0x68) - *(s32 *)((u8 *)ptr + 0x5C));
    diffs[1] = (s16)(*(s32 *)((u8 *)ptr + 0x6C) - *(s32 *)((u8 *)ptr + 0x60));
    diffs[2] = (s16)(*(s32 *)((u8 *)ptr + 0x70) - *(s32 *)((u8 *)ptr + 0x64));
    func_800D23D0(diffs);
    D_801EE880 = (u16)diffs[1];
}
