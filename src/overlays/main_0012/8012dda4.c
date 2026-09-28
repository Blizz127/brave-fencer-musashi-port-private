/* Overlay range [8012DDA4,8012DE2C) from MAIN.CD member 0012.
 * SHA256(span)=8e0d36f684ae0058590ef139652bdd4047a1878eae9b012e07e92f16eac65cd9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012DDA4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct Entry_8012DDA4 {
    u16 active;
    unsigned char pad[0x10C - 2];
} Entry_8012DDA4;
extern u8 D_80126720[];

s32 func_8012DDA4()
{

    extern u8 D_80126720[];
    extern Entry_8012DDA4 * D_801840D4;
    extern Entry_8012DDA4 * D_801840D0;

    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);

    while (D_801840D4 != end) {
        p = D_801840D4;
        if (p->active != 0 && p != D_801840D0) {
            D_801840D4 = p + 1;
            return p;
        }
        D_801840D4++;
    }
    D_801840D4 = 0;
    return 0;
}
