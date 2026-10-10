/* sc03_0098: func_8012B4B8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
typedef struct { s32 w0, w4, w8, wC; s16 h10, hpad; s32 t0, t1, t2; } Mat32;
extern Mat32 D_800AE620;
extern void func_80049F3C(int r, void *m);
extern void func_8004A0DC(int r, void *m);
extern void func_8004A27C(int r, void *m);

s32 func_8012B4B8(int param_1)
{
    int self;
    register int obj __asm__("$16");
    register int *src __asm__("$5");
    int m[8];
    short sVar1;
    int o2, t0, t1, t2;
    self = param_1;
    obj = *(int *)(self + 0x20);
    if (obj != 0) {
        src = (int *)&D_800AE620;
        __asm__("" : "=r"(src) : "0"(src));
        t0 = src[0]; t1 = src[1]; t2 = src[2]; m[0] = t0; m[1] = t1; m[2] = t2;
        t0 = src[3]; t1 = src[4]; t2 = src[5]; m[3] = t0; m[4] = t1; m[5] = t2;
        t0 = src[6]; t1 = src[7]; m[6] = t0; m[7] = t1;
        func_80049F3C((int)*(short *)(obj + 0x10), (void *)m);
        func_8004A27C((int)*(short *)(obj + 0x14), (void *)m);
        func_8004A0DC((int)*(short *)(obj + 0x12), (void *)m);
        *(Mat32 *)(obj + 0x34) = *(Mat32 *)m;
        o2 = *(int *)(self + 0x20);
        sVar1 = *(unsigned short *)(self + 6) + *(unsigned short *)(self + 0x50);
        *(short *)(o2 + 8) = sVar1;
        *(int *)(o2 + 0x48) = (int)sVar1;
        sVar1 = *(unsigned short *)(self + 0xa) + *(unsigned short *)(self + 0x52);
        *(short *)(o2 + 0xa) = sVar1;
        *(int *)(o2 + 0x4c) = (int)sVar1;
        sVar1 = *(unsigned short *)(self + 0xe) + *(unsigned short *)(self + 0x54);
        *(short *)(o2 + 0xc) = sVar1;
        *(unsigned short *)(o2 + 0x2c) = *(unsigned short *)(o2 + 0x2c) | 1;
        *(int *)(o2 + 0x50) = (int)sVar1;
    }
}
