/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801730B4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S801730FC;
struct S801730FC {
    u8 pad[0xB8];
    u16 unkB8;      
};
extern void func_8014706C(void *arg0);
extern void func_801542A4();
extern void func_801542A4(s32 *a0, s32 a1);
extern void func_8014706C(void *a0);
extern void func_80171A1C(u8 *a0);
extern s32 D_80127508;
extern void func_801730FC(struct S801730FC *a0);

void func_801730B4(s32 a0) {
    func_8014706C((void *)a0);
    ((void (*)(s32, s32))func_801542A4)(a0, D_80127508);
    ((void (*)(void *))func_80171A1C)((void *)a0);
    ((void (*)(void *))func_801730FC)((void *)a0);
}
