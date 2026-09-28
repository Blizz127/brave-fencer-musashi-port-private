/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015C32C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_80146E98(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern int func_80148AFC(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 * arg0);
extern void func_80149BAC(s32 *a0);
extern s32 func_80149FB0(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014CC28(s32 a0);
extern void func_8014D738(void);
extern u16 D_800B99DA;
extern s32 func_8014F3E8(s32 a0);
extern void func_80147324(s32 a0);
extern void func_8001382C(s32 a0, void *a1, void *a2);
extern void func_80147A84(int);
extern void func_80159BE4(s32);
extern void func_80159BE4(s32 arg0);
extern s32 func_801619A4(s32 *a0);
extern void func_800CCCC0(s32 a0);
extern void func_80147A84(s32 a0);
extern s32 func_8015BE94();
extern s32 func_8015BE94(s32 *a0);
extern void func_8015C0C4(s32 a0);
extern void func_8015C0C4(s32);
extern s32 func_801496D4(void*);
extern s32 func_801619A4(s32*);
extern s32 func_80149AA8(s32*);
extern void func_80149AD4(s32*);
extern s32 func_80149B54(s32*);
extern void func_80149BAC(s32*);
extern s32 func_801498E0(s32*);
extern s32 func_80149954(s32);
extern s32 func_80149A64(s32*);
extern void func_801473EC(s32*);
extern void func_8014CC28(s32);
extern s32 func_8014F3E8(s32);
extern void func_80159BE4(s32 a0);
extern void func_8015C6E0(s32*);

void func_8015C32C(s32 arg0) {

    extern void (*D_80180378[])(void *);
    s32 iVar2;
    u32 uVar4;
    s32 vin[4];
    s32 vout[4];

    func_80149FB0(arg0);
    if (((s32 (*)(s32))func_801496D4)(arg0) != 0) {
        D_80180378[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_80149704)(arg0);
        return;
    }
    switch (((s32 (*)(s32))func_801619A4)(arg0)) {
    case 0:
    case 1:
    case 6:
        if (((s32 (*)(s32))func_80149AA8)(arg0) != 0) {
            D_80180378[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149AD4)(arg0);
            return;
        }
        if (((s32 (*)(s32))func_80149B54)(arg0) != 0) {
            D_80180378[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149BAC)(arg0);
            return;
        }
        break;
    case 3:
        ((void (*)(s32))func_801498E0)(arg0);
        break;
    case 4:
        ((void (*)(s32))func_80149954)(arg0);
        break;
    case 5:
        if (((s32 (*)(s32))func_80149A64)(arg0) != 0) {
            D_80180378[*(u16 *)arg0]((void *)arg0);
            func_800CCCC0(arg0);
            return;
        }
    }
    if ((func_80148AFC((void *)arg0) & 0xff) != 0) {
        vin[0] = 0;
        vin[1] = 0;
        vin[2] = -0x4000;
        func_8001382C((s32)*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12), vin, vout);
        *(s32 *)(arg0 + 0x234) += vout[0];
        *(s32 *)(arg0 + 0x238) += vout[1];
        *(s32 *)(arg0 + 0x23c) += vout[2];
    }
    func_8001382C((s16)-*(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12), (void *)(arg0 + 0x234), vout);
    func_80146DB8((s32 *)arg0, vout);
    func_80147A84(arg0);
    ((void (*)(s32))func_801473EC)(arg0);
    if ((D_800B99DA & 3) == 0) {
        func_8014C010(arg0, 1);
        func_80147324(0x65f);
    }
    if (((s32 (*)(s32))func_8014D738)(arg0) != 0) {
        D_80180378[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_8015C6E0)(arg0);
        return;
    }
    iVar2 = ((s32 (*)(s32))func_8014CC28)(arg0);
    uVar4 = ((u32 (*)(s32))func_8014F3E8)(arg0);
    if (uVar4 != 0) {
        if ((uVar4 & 0x4000) == 0) {
            if (func_80146E98(arg0) != 0) {
                D_80180378[*(u16 *)arg0]((void *)arg0);
                func_80147078((s32 *)arg0, 0);
                func_80159BE4(arg0);
            }
        } else {
            func_80147078((s32 *)arg0, 4);
            func_8015C0C4(arg0);
        }
    } else {
        if (iVar2 == 0) {
            D_80180378[*(u16 *)arg0]((void *)arg0);
            func_80147078((s32 *)arg0, 3);
            ((void (*)(s32))func_8015BE94)(arg0);
        }
    }
}
