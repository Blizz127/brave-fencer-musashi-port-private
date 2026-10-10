/* sc01_0077: func_8012913C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8001D074(s32 a, s32 b);
extern u8 *func_801291C0(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
u8 *func_801291C0(void);

u8 * func_8012913C(s32 arg0)
{
    s32 iVar1;
    u8 *puVar2;
    iVar1 = ((s32(*)(s32,s32))func_8001D074)(0x7E, 0x100);
    if (iVar1 == 0) {
        return (u8 *)0;
    }
    puVar2 = func_801291C0();
    if (puVar2 == (u8 *)0) {
        return (u8 *)0;
    }
    *(s16 *)puVar2 = arg0;
    *(s32 *)(puVar2 + 0x20) = iVar1;
    func_8001CC3C(iVar1, 0, 0, 0);
    return puVar2;
}
