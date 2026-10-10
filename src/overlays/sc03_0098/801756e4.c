/* sc03_0098: func_801756E4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern s16 D_800B9A02;
extern short D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern void func_80175DA8(s32 a0);
extern void func_80175AB8(s32 a0);
extern void func_80176144(s32 a0);
extern short D_800B9A02;
void func_80175AB8();
void func_80175DA8();
void func_80176144(s32 a0);

void func_801756E4(s32 arg0) {
    s32 a = arg0;
    short *p;
    s32 f5;
    s32 sum;
    s16 neg;
    s32 b6;
    p = &D_800B9A02;
    f5 = *(u8 *)(a + 5);
    sum = *(u8 *)(a + 6) + f5;
    neg = -(s16)(sum & 0xFF);
    *(u8 *)(a + 6) = sum;
    __asm__ __volatile__("" : : : "memory");
    b6 = *(u8 *)(a + 6);
    *(u8 *)(a + 5) = (u8)f5 + 0xFF;
    *(s16 *)(a + 0x10) = neg;
    *(s16 *)(a + 0xc) = neg;
    *(u16 *)(a + 0x16) = b6;
    *(u16 *)(a + 0x12) = b6;
    *(u16 *)(a + 0xe) = b6;
    *(u16 *)(a + 0x14) = b6;
    func_80175DA8(*p);
    func_80175AB8(*p);
    func_80176144(*p);
    if (*(u8 *)(a + 5) == 0) {
        *(u8 *)(a + 8) = 0;
        *(u8 *)(a + 1) = *(u8 *)(a + 1) + 1;
    }
}
