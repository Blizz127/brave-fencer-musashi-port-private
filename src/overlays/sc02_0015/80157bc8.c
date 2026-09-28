/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157BC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146D90(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80148038(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014ED28(s32 _arg0);
extern void func_8014ED28();
extern s32 func_801725A4(u8 *a0);
extern void func_80148038(int, int);
extern void func_80147460(int);
extern void func_80146D90(int);
extern void func_80161D20();
extern void func_8016706C(s32 a0);
extern void func_8016158C(void *a0);
extern void func_8015BE04(s32 *a0);

void func_80157BC8(s32 a0) {
    s32 s1;
    func_80147AD4(a0, 0, 0, 0x10000);
    func_801473EC((s32 *)a0);
    func_80148038(a0, 0x1A000);
    func_80147460(a0);
    {
        register s32 ret __asm__("$2");
        func_8014ED28(a0);
        __asm__ __volatile__("" : "=r"(ret));
        if (ret != 0) {
            func_80146D90(a0);
        }
    }
    {
        register s32 r __asm__("$2");
        func_8016158C((void *)a0);
        __asm__ __volatile__("" : "=r"(r));
        s1 = r;
    }
    if ((s1 & 5) != 0) {
        func_80161D20(a0, *(u16 *)(a0 + 0x16E));
        func_8014C010(a0, 1);
        func_8016706C(4);
        func_8016706C(5);
        func_801599A4((void *)a0);
        func_80159B3C((void *)a0);
    }
    if (s1 != 0) {
        return;
    }
    if (*(s32 *)(a0 + 0x34) > 0) {
        func_801599A4((void *)a0);
        func_80146D90(a0);
        func_8015BE04((s32 *)a0);
    } else {
        func_801725A4((u8 *)a0);
    }
}
