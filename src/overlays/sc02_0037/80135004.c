/* sc02_0037: func_80135004 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *memcpy(void *, const void *, u32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void *memcpy(void *, const void *, u32);
int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4);

s32 func_80135004(s32 arg0, s32 p1, s32 p2)
{
    extern s32 D_801C8418;
    extern int func_80134A74(int, s16, s16, int);
    extern s16 * aD801841A0_80135004 __asm__("D_801841A0");
    extern s16 * aD8018419C_80135004 __asm__("D_8018419C");
    extern u8 D_801841A8;
    extern s16 *D_801841A4;
    extern u16 D_801C8428;
    register s16 *pb0 __asm__("$9");
    register s16 *pac __asm__("$6");
    register s16 *pb8 __asm__("$8");
    u16 *pb4;
    u16 a, b;
    int id;
    int a1v, a2v, d94;
    pb0 = aD801841A0_80135004;
    __asm__ __volatile__("" : : "r"(pb0));
    a = ((u16 *)p2)[0]; pac = aD8018419C_80135004; pb0[0] = a; b = ((u16 *)p1)[0]; pb8 = (*(s16 * *)&D_801841A8); pac[0] = b; pb8[0] = a - b;
    a = ((u16 *)p2)[1]; pb0[1] = a; b = ((u16 *)p1)[1]; pac[1] = b; pb8[1] = a - b;
    a = ((u16 *)p2)[2]; pb0[2] = a; b = ((u16 *)p1)[2]; pac[2] = b; pb8[2] = a - b;
    id = ((int)arg0) & 0xFFFF;
    a1v = pac[0]; a2v = pac[2]; d94 = D_801C8418;
    D_801C8428 = 0;
    if (func_80134A74(id, a1v, a2v, d94)) {
    found:
        pb4 = (*(u16 * *)&D_801841A4);
        ((u16 *)p2)[0] = pb4[0];
        ((u16 *)p2)[1] = pb4[1];
        ((u16 *)p2)[2] = pb4[2];
        ((u16 *)p2)[3] = D_801C8428;
        return 1;
    }
    {
        u16 *qb;
        int qa0;
        u16 *qa;
        qb = (u16 *)aD8018419C_80135004;
        qa = (u16 *)aD801841A0_80135004;
        qa0 = qa[0];
        if (((qb[0] & 0xFF80) == (qa0 & 0xFF80)) &&
            ((qb[2] & 0xFF80) == (qa[2] & 0xFF80)))
            return 0;
        if (func_80134A74(id, (s16)qa0, (s16)qa[2], D_801C8418))
            goto found;
        return 0;
    }
}
