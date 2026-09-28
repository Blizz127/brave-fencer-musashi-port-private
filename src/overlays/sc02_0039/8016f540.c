/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F540 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S;
struct S {
    u8  pad0[0x7E];  
    u16 f7E;         
};
extern void func_8014708C(void *arg0);
extern s32 func_801472C8(struct S *a0);
extern void func_80171928(void *a0);
extern void func_8014708C(void *a0);

void func_8016F540(void *a0) {
    func_8014708C(a0);
    func_801472C8((struct S *)a0);
    func_80171928(a0);
}
