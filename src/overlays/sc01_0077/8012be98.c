/* sc01_0077: func_8012BE98 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_800132BC(s32 a0, s32 a1);
extern s32 func_800132BC(s32 a0, s32 a1);

void func_8012BE98(s32 arg0, u16 * arg1)
{
    s16 a[3];
    s16 b[3];
    a[0] = *(u16 *)((u8 *)arg0 + 0x6);
    a[1] = 0;
    a[2] = *(u16 *)((u8 *)arg0 + 0xE);
    b[0] = *(u16 *)((u8 *)arg1 + 0x0);
    b[1] = 0;
    b[2] = *(u16 *)((u8 *)arg1 + 0x4);
    func_800132BC((s32)a, (s32)b);
}
