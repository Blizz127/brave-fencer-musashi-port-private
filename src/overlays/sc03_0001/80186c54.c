/* sc03_0001: func_80186C54 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8012BD14(s32 a0);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);

s32 func_80186C54(void *a0)
{
    s32 ptr;
    u16 st;
    ptr = *(s32 *)((s32)a0 + 0x64);
    st = *(u16 *)((s32)ptr + 0x2);
    if (st != 1 && st != 4) {
        return 0;
    }
    if (func_8012BD14(ptr) >= 0x4001) {
        return 0;
    }
    {
        s32 p;
        u16 st2;
        p = *(s32 *)((s32)a0 + 0x64);
        st2 = *(u16 *)((s32)p + 0x2);
        st2++;
        *(u16 *)((s32)p + 0x2) = st2;
    }
    func_80178BF8();
    return (s32)func_80172710;
}
