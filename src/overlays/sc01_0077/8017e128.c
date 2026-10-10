/* sc01_0077: func_8017E128 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_80171B44(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80171B44(s32 *a0);
extern void func_80171B44(s32 *a0);
extern void func_8017E170(s32 a0);
void func_8017E170(int param_1);

void func_8017E128(s32 a0)
{
    *(u8 *)(a0 + 0x214) = *(u8 *)(a0 + 0x214) + 1;
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) = 0x800;
    func_80171B44((s32 *)a0);
    func_8017E170(a0);
}
