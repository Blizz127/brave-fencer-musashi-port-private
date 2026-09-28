/* Overlay range [80145EE8,80146014) from MAIN.CD member 0012.
 * SHA256(span)=a95498e1aa71dc94ff5ad139116abfa584d67d12641eae0b00b21cb7c10001f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80145EE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: schedule
// @stuck: branch layout — 3-way dispatch on param_1; trying switch form

extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);


void func_80145EE8(s32 param_1)
{

    extern unsigned char D_8017FD40[];
    extern unsigned char D_8017FD70[];
    extern unsigned char D_8017FDC0[];
    extern unsigned char D_8017FDF0[];
    extern unsigned char D_8017FE20[];
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_8017FD40);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_8017FD70);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_8017FDC0);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_8017FDF0);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_8017FE20);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_8017FD40);
        ((void (*)(void *))func_80146014)(D_8017FD70);
        ((void (*)(void *))func_80146014)(D_8017FDC0);
        ((void (*)(void *))func_80146014)(D_8017FDF0);
        ((void (*)(void *))func_80146014)(D_8017FE20);
        break;
    }
}
