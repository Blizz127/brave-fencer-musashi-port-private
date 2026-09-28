/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801580B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_801473EC(s32 *a0);
extern void func_80147460(s32 a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern int func_80155FF8(int arg, int a1);
int func_80155FF8(int arg, int a1);
void func_80156648(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80148038(int, int);
extern void func_80147460(int);
extern u8 D_800D524C[];
extern void func_80161418(void *a0);

void func_801580B4(s32 a0) {
    s32 reserved[4];
    (void)reserved;
    *(s32 *)(a0 + 0x44) |= 2;
    if ((*(u16 *)(a0 + 0xB8) & 0x4000) != 0) {
        func_801477E8((s32 *)a0, 0xFFF40000);
        *(s32 *)(a0 + 0x234) += 1;
    }
    if (*(s32 *)(a0 + 0x234) != 0) {
        func_80148038(a0, 0x10000);
        func_80147460(a0);
    }
    func_80147AD4(a0, 0, 0, 0);
    func_801473EC((s32 *)a0);
    {
        register s32 ret __asm__("$2");
        func_80161418((void *)a0);
        __asm__ __volatile__("" : "=r"(ret));
        if (ret != 0) {
            return;
        }
    }
    if (*(u16 *)(a0 + 0xB8) == 0x8000) {
        func_80156648((s32 *)a0);
        *(s8 *)(a0 + 0x1AA) = 0xF;
        func_80154274((s32 *)a0, (s32)D_800D524C);
        func_80147324(0x455);
        func_80146CA0((void *)a0);
    } else {
        func_80155FF8(a0, *(u8 *)(a0 + 0x1AA));
    }
}
