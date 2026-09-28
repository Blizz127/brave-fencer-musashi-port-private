/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F28E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F9F54;
extern s32 D_801F9DD4;

void func_801F28E0(void)
{
    typedef struct { s32 next; u8 pad[0xC]; } Node_801F28E0;
    extern s32 D_801F9DD4;
    extern s32 D_801F9F54;
    Node_801F28E0 *p;
    s32 i;

    p = (Node_801F28E0 *)&D_801F9DD4;
    for (i = 0; i < D_801F9F54 - 1; ) {
        p->next = (s32)(p + 1);
        i++;
        p = p + 1;
    }
}
