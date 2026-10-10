/* sc01_0077: func_801788B8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);

s32 func_801788B8(s32 arg0, s32 arg1) {
    s32 iVar1;
    u16 buf[4];
    iVar1 = func_8012C658(0x83, (s32)*(s16 *)((u8 *)arg0 + 0x70), 0);
    if (iVar1 == 0) {
        return 0;
    }
    *(s32 *)((u8 *)iVar1 + 0x64) = arg0;
    buf[0] = *(u16 *)((u8 *)arg0 + 0x6);
    buf[1] = *(u16 *)((u8 *)arg0 + 0xA);
    buf[2] = *(u16 *)((u8 *)arg0 + 0xE);
    if (*(s32 *)((u8 *)arg0 + 0x20) != 0) {
        buf[3] = *(u16 *)((u8 *)(*(s32 *)((u8 *)arg0 + 0x20)) + 0x12);
    } else {
        buf[3] = 0;
    }
    func_8012E8E0(iVar1, (s32)buf);
    func_8012B2CC(iVar1);
    *(s32 *)((u8 *)iVar1 + 0xDC) = arg1;
    return iVar1;
}
