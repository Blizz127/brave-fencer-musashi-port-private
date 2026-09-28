/* Overlay range [8015EA3C,8015ED6C) from MAIN.CD member 0012.
 * SHA256(span)=4fa0fc1000317d419ad14098ded6f0919674a442180ffbf24a5235bb7ecdeac4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015EA3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
struct S_80149744 {
    char pad44[0x44];
    s32 w44;       /* 0x44 */
    char pad48[0xAC - 0x48];
    u16 h_AC;      /* 0xAC */
};

extern u16 func_801487F4(s32*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *a0);
extern s32 func_80149D10(s32);
extern void func_80175150(s32*);
extern void func_8016EE40(s32, s32, s32);
extern s32 func_80149744(struct S_80149744*);
extern void func_80149788(void);
extern s32 func_80161B84(void *a0);
extern s32 func_8014A4B4(void *a0);
extern void func_8014A4FC(void);
extern s32 func_80149AA8(s32*);
extern void func_80149AD4(s32*);
extern s32 func_80149B54(s32*);
extern void func_80149BAC(s32*);
extern s32 func_800CF8B4(void);
extern s32 func_801491C4(s32);
extern s32 func_80148E54(void *a0);
extern void func_8001382C(s32 a0, void *a1, void *a2);
extern void func_80146DB8(s32*, s32*);
extern void func_80147A84(s32);
extern void func_801473EC(s32*);
extern void func_80154150(s32, s32);
extern void func_8014D738(void);
extern void func_8015C714(void *a0);
extern s32 func_80161208();  /* canonical no-proto (§17a-1) */
extern void func_801483E8(unsigned char*);


void func_8015EA3C(void *arg0) {

    extern void (*D_80180A1C[])(void *);
    extern s16 D_801152A0;
    s32 invec[4];
    s32 outbuf[4];
    s32 temp;
    s32 r;

    if (!(((s32 (*)(void))func_801487F4)() & 8)) {
        D_80180A1C[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 0);
        func_80159B70(arg0);
        return;
    }
    r = ((s32 (*)(void *))func_80149D10)(arg0);
    if (r == 1) goto Lcase1;
    if (r < 2) goto Ldefault;
    if (r == 2) goto Lcase2;
    goto Ldefault;
Lcase1:
    D_80180A1C[*(u16 *)arg0](arg0);
    ((void (*)(void *))func_80175150)(arg0);
    return;
Lcase2:
    ((void (*)(s32, s32))func_8016EE40)(*(s32 *)((u8 *)arg0 + 0x21C), 0x01000000);
    return;
Ldefault:
    if (((s32 (*)(void *))func_80149744)(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0](arg0);
        ((void (*)(void *))func_80149788)(arg0);
        return;
    }
    if (func_80161B84(arg0) != 0) {
        return;
    }
    if (func_8014A4B4(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0](arg0);
        ((void (*)(void *))func_8014A4FC)(arg0);
        return;
    }
    if (((s32 (*)(void *))func_80149AA8)(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0](arg0);
        ((void (*)(void *))func_80149AD4)(arg0);
        return;
    }
    if (((s32 (*)(void *))func_80149B54)(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0](arg0);
        ((void (*)(void *))func_80149BAC)(arg0);
        return;
    }
    if (func_800CF8B4() != 0) {
        *(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x12) =
            ((*(u16 *)&D_801152A0) + ((s32 (*)(void *))func_801491C4)(arg0)) & 0xFFF;
    }
    temp = func_80148E54(arg0);
    if ((s16)temp >= 0) {
        s32 d = temp - *(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x12);
        invec[0] = 0;
        invec[1] = 0;
        invec[2] = 0xFFFC0000;
        func_8001382C((s16)d, invec, outbuf);
        ((void (*)(void *, void *))func_80146DB8)(arg0, outbuf);
        ((void (*)(void *))func_80147A84)(arg0);
        ((void (*)(void *))func_801473EC)(arg0);
        ((void (*)(void *, s32))func_80154150)(arg0, 0x1E);
    } else {
        ((void (*)(void *, s32))func_80154150)(arg0, 0x1D);
    }
    if (((s32 (*)(void *))func_8014D738)(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 9);
        func_8015C714(arg0);
        return;
    }
    if (((s32 (*)(s32))func_80161208)(arg0) == 0) {  /* §17a-1 */
        ((void (*)(void *))func_801483E8)(arg0);
    }
}
