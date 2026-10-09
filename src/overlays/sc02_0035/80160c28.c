/* SC02.CD member35: func_80160C28 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
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
extern void func_80146CA0(void *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80161208(void);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);

void func_80160C28(void *arg0)
{
    s32 p;
    s32 q;
    register void *a __asm__("$4");
    if (func_80161208() == 0) {
        *(s32 *)((u8 *)arg0 + 0x238) += 0x1c000;
        p = *(s32 *)((u8 *)arg0 + 0x20);
        *(u16 *)((u8 *)p + 0x10) =
            (*(u16 *)((u8 *)p + 0x10) - *(u16 *)((u8 *)arg0 + 0x23a)) & 0xfff;
        q = *(s32 *)((u8 *)arg0 + 0x20);
        if (*(s16 *)((u8 *)q + 0x10) < 0xc00) {
            a = arg0;
            __asm__ __volatile__("" : : "r"(a));
            *(u16 *)((u8 *)q + 0x10) = 0xc00;
            *(u16 *)((u8 *)a + 0xb8) = 1;
            func_80146CA0(a);
        }
    }
}
