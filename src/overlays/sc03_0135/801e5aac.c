/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5AAC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801EAC70;
extern s32 D_801EADF0;

void func_801E5AAC(void)
{
    typedef struct { s32 next; u8 pad[0xC]; } Node_801E5AAC;
    extern s32 D_801EAC70;
    extern s32 D_801EADF0;
    Node_801E5AAC *p;
    s32 i;

    p = (Node_801E5AAC *)&D_801EAC70;
    for (i = 0; i < D_801EADF0 - 1; ) {
        p->next = (s32)(p + 1);
        i++;
        p = p + 1;
    }
}
