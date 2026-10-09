/* SC02.CD member35: func_8016B91C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct {
    u8 pad6[0x6];
    u16 h6;
    u16 h8;
    u16 hA;
} SrcB964;
typedef struct {
    u8 pad8[0x8];
    u16 h8;
    u16 hA;
    u16 hC;
} DstB964;
extern void func_8016B964(SrcB964 *a0, DstB964 *a1);
void func_8016B964(SrcB964 *a0, DstB964 *a1);

void func_8016B91C(s32 arg0) {
    ((void (*)(s32, s32))func_8016B964)(arg0, *(s32*)((u8*)arg0 + 0x10));
    ((void (*)(s32, s32))func_8016B964)(arg0, *(s32*)((u8*)arg0 + 0x14));
    ((void (*)(s32, s32))func_8016B964)(arg0, *(s32*)((u8*)arg0 + 0x18));
}
