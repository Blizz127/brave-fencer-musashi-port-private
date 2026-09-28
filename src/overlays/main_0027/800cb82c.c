/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB82C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32, s32 *);
extern s32 func_8012EF34(s32, s32);
extern s32 func_80017DC4(void *, void *);
extern void func_800CBA44();
extern void func_800CBBF8();
extern s32 func_80047948(s32);
extern u8 D_800CC290[];
extern u8 D_800CC190[];
extern u8 D_800CC1C0[];
extern u8 D_800CC1B0[];
extern u8 D_800CC1A0[];
typedef struct { u32 a, b; } __attribute__((packed, aligned(1))) Blk8;
struct Mid { u32 gray[4]; u32 code; u8 bmode; };
typedef struct {
    u8 mat[0x14];
    u32 zz[3] __attribute__((aligned(4)));
} __attribute__((packed)) MZ;
typedef struct {
    u16 hB0;
    u16 hB2;
    u32 hpad;
} HB;

void func_800CB82C(s32 a0, s32 a1)
{
    u8 lo[0x30];
    volatile struct Mid mid;
    u8 src[8];
    u8 dstc[8];
    u8 out1[0x20];
    MZ mz;
    HB hb;
    volatile u8 fpad[8];
    register s32 g8 __asm__("$8");
    register s32 c1 __asm__("$3");
    s32 *p;
    s32 *plo;
    s32 *p6;
    s32 s5v;
    s32 chk;
    s32 w;
    s32 bm;
    s32 cn;

    plo = (s32 *)lo;
    p = *(s32 **)((s8 *)a0 + 0x20);
    func_80015978((s32)((s8 *)a0 + 4), (s32 *)src);
    chk = func_8012EF34((s32)src, (s32)D_800CC290);
    if ((chk & ~0x1000) == 0) {
        *(Blk8 *)dstc = *(Blk8 *)D_800CC290;
        s5v = *(u16 *)((s8 *)a1 + 0x16) + 3;
        func_80017DC4((void *)((s8 *)p + 0x18), (void *)mz.mat);
        p = (s32 *)dstc;
        mz.zz[2] = 0;
        mz.zz[1] = 0;
        mz.zz[0] = 0;
        __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  mz.mat  ) : "$12", "$13", "$14", "memory" ) ;
        __asm__ volatile ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"(  mz.mat  ) : "$12", "$13", "$14", "memory" ) ;
        p6 = (s32 *)D_800CC1C0;
        w = *(u16 *)(dstc + 4);
        *(u16 *)(out1 + 0x1C) = w;
        *(u16 *)(out1 + 0x14) = w;
        *(u16 *)(out1 + 0xC) = w;
        *(u16 *)(out1 + 4) = w;
        bm = *(u16 *)((s8 *)a1 + 0x14);
        mid.code = 0x50000000;
        mid.bmode = bm;
        c1 = *(s16 *)((s8 *)a0 + 0x60);
        g8 = 0x808080;
        mid.gray[0] = g8;
        mid.gray[1] = g8;
        mid.gray[2] = g8;
        mid.gray[3] = g8;
        cn = (c1 + 1) & 3;
        c1 <<= 2;
        *(u16 *)((s8 *)a0 + 0x60) = cn;
        cn = (s32)D_800CC1B0;
        c1 += cn;
        if (((s32 (*)(s32, s32, s32, s32, s32 *, s32))func_800CBA44)((s32)out1, (s32)D_800CC190, (s32)a1, (s32)p6,
                          plo, c1) != 0) {
            return;
        }
        *(u16 *)((s8 *)lo + 4) = s5v;
        func_800CBBF8(plo, p);
        a1 = (void *)((s8 *)a1 + 0x18);
        hb.hB0 = func_80047948((*(s16 *)((s8 *)a0 + 0x62)) << 8) / 1024;
        *(u16 *)((s8 *)a0 + 0x62) = (*(u16 *)((s8 *)a0 + 0x62) + 1) & 0xF;
        hb.hB2 = 0;
        if (((s32 (*)(s32, s32, s32, s32, s32 *, s32))func_800CBA44)((s32)out1, (s32)D_800CC1A0, (s32)a1, (s32)&hb.hB0,
                          plo, (s32)p6) != 0) {
            return;
        }
        func_800CBBF8(plo, p);
    }
}
