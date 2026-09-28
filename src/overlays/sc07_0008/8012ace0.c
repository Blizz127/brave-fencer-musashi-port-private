/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012ACE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { int a; short cmd; short b; } Elem_8012ACE0_8012ACE0;
typedef struct { char pad[0x90]; Elem_8012ACE0_8012ACE0 *list; } Owner_8012ACE0_8012ACE0;

s32 func_8012ACE0(void *o) {
    int i;
    for (i = 0; ; i++) {
        switch (((Owner_8012ACE0_8012ACE0 *)o)->list[i].cmd) {
            case -2:
            case -1:
            case 0:
                return i;
            case -50: case -45: case -40: case -35: case -30:   /* scatter -> force jump table (min=-50 sets low bound) */
            default:
                break;
        }
    }
}
