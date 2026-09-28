/* Overlay range [8012ACE0,8012AD3C) from MAIN.CD member 0012.
 * SHA256(span)=9bd1bffae279deef670db96bc93b00c1d53c79f21d9f781246cd11060c40dec2.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012ACE0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { int a; short cmd; short b; } Elem_8012ACE0;
typedef struct { char pad[0x90]; Elem_8012ACE0 *list; } Owner_8012ACE0;

s32 func_8012ACE0(void *o) {
    int i;
    for (i = 0; ; i++) {
        switch (((Owner_8012ACE0 *)o)->list[i].cmd) {
            case -2:
            case -1:
            case 0:
                return i;
            case -50: case -45: case -40: case -35: case -30:    
            default:
                break;
        }
    }
}
