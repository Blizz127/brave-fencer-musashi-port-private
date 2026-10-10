/* sc03_0098: func_8015773C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_801553A8(s32 *a0);
void func_801553A8(s32 *a0);
void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_801553A8(s32 *a0);

s32 func_8015773C(u8 * arg0)
{
    *(s32 *)((u8 *)arg0 + 0x44) = *(s32 *)((u8 *)arg0 + 0x44) & ~2;
    func_80154A74((s32)arg0, 0x11);
    func_801553C0((s32)arg0);
    func_801553A8(arg0);
}
