/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801387B8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801387B8(s32 arg0) {
    extern s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2);
    extern s32 func_80139220(s32 a0);
    extern void func_80138948(void *a0);
    extern void func_80139A8C(s32 a0);
    extern void func_80139B18(s32 a0);
    extern s32 D_80127530[];
    u16 *p;
    s32 base;
    s32 cont;
    u8 cmd;
    s32 sub;
    s32 pc;
    for (;;) {
        cont = 0;
        if (*(s32 *)(arg0 + 8) & 0x400) {
            base = D_80127530[*(u16 *)(arg0 + 0x4A)];
            p = (u16 *)(arg0 + 0x44);
        } else {
            p = (u16 *)(arg0 + 0x10);
            base = *(s32 *)(arg0 + 0);
        }
        pc = *p;
        cmd = *(u8 *)(base + pc);
        sub = *(u8 *)(base + pc + 1);
        if (cmd >= 0x20) {
            cont = func_80138DE0(arg0, cmd, sub);
            if (!(*(s32 *)(arg0 + 8) & 0x80220)) {
                cont = 0;
            }
        } else {
            if (cmd != 0) {
                switch (cmd) {
                case 10:
                    func_80139220(arg0);
                    *p += 1;
                    goto loop_end;
                case 1:
                    cont = 1;
                    *(u8 *)(arg0 + 0x23) = sub;
                    *p += 2;
                    goto loop_end;
                case 7:
                    if (!(*(s32 *)(arg0 + 8) & 0x20000)) {
                        *(s32 *)(arg0 + 8) &= ~0x20;
                    }
                    break;
                case 23:
                    *(s32 *)(arg0 + 8) |= 2;
                default:
                    cont = 1;
                    *p += 1;
                    goto loop_end;
                }
            }
            func_80138948((void *)arg0);
        }
    loop_end:
        if (cont == 0) {
            func_80139A8C(arg0);
            func_80139B18(arg0);
            return;
        }
    }
}
