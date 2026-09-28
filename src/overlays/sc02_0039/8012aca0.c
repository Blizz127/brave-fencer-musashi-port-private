/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012ACA0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_8012AAAC();
extern void func_8012AAAC(void *arg0);
void func_8012AAAC(void *arg0);
extern M2C_UNK D_8017F428;

void func_8012ACA0(void *arg0) {
    (*(  M2C_UNK ** )((s8 *)( arg0 ) + (  0x90 )))  = &D_8017F428;
    (*(  s32 * )((s8 *)( arg0 ) + (  0x94 )))  = 0;
    (*(  s32 * )((s8 *)( arg0 ) + (  0x9C )))  = 0;
    (*(  s16 * )((s8 *)( arg0 ) + (  0x9A )))  = 0;
    (*(  u16 * )((s8 *)( arg0 ) + (  0x72 )))  = (u16) ((*(  u16 * )((s8 *)( arg0 ) + (  0x72 )))  & 0xF9FF);
    ((void (*)(void))func_8012AAAC)();
}
