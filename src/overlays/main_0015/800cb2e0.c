/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800CB2E0(void *arg0) {
    extern s32 func_80146E98(s32 a0);
    extern void func_80013F3C(void *a0);
    extern void func_800126C4(s32 a0, s32 a1);
    extern void func_800123F0(s32 a0, s32 a1);
    extern void func_80012558(s32 a0, s32 a1);
    extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
    extern void func_80162FC0(s32 *a0);
    extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80163328();
    extern s32 func_801632F0();
    extern void func_80013E94(void *a0, void *a1);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80146CA0(void *a0);
    extern s16 D_80126B18[];
    extern s16 D_80126B1A[];
    extern s16 D_80126B1C;
    extern s32 D_80114EB0;
    extern s32 D_80114EC8;

    register void *a0v __asm__("$17");
    register void *fp __asm__("$18");
    u8 buf[0x40];
    s32 sp60;
    s32 cmd;

    a0v = arg0;
    fp = *(void **)((u8 *)a0v + 0x20);

    if (func_80146E98((s32)a0v)) {
        func_80146A6C(3, a0v, *(s16 *)((u8 *)a0v + 6), *(s16 *)((u8 *)a0v + 0xA), *(s16 *)((u8 *)a0v + 0xE), 0, 0x80001C00);
    } else {
        register u8 *bp __asm__("$16");
        bp = buf + 0x20;
        func_80013F3C(bp);
        func_800126C4((s32)bp, *(s16 *)((u8 *)fp + 0x10));
        func_800123F0((s32)bp, *(s16 *)((u8 *)fp + 0x14));
        func_80012558((s32)bp, *(s16 *)((u8 *)fp + 0x12));
        func_80163194((s32)a0v, 0, 0, 0, (s32)bp);
        func_80162FC0((s32 *)a0v);
        func_80163408((s32)a0v, 0x10, 0x80, 0x200);
        func_80163328(a0v);
        switch ((u32)func_801632F0(a0v)) {
        case 1:
            func_80013E94(&D_80114EB0, &sp60);
            cmd = 0x1F;
            break;
        case 2:
        case 4:
            func_80013E94(&D_80114EC8, &sp60);
            cmd = 7;
            break;
        default:
            return;
        }
        sp60 |= 0x80000000;
        func_80146A6C(cmd, a0v, D_80126B18[0], D_80126B1A[0], D_80126B1C, sp60, 0);
    }
    func_80146CA0(a0v);
}
