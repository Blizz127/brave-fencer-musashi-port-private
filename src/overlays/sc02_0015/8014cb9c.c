/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CB9C - byte-exact against retail at -O2 (tools/register_match.py). */
struct Packed8;
struct Packed8 {
    int a;
    int b;
} __attribute__((packed));
extern struct Packed8 D_80126C98;
extern short D_80126C9E;

void func_8014CB9C(struct Packed8 *a0)
{
    D_80126C98 = *a0;
    D_80126C9E = 1;
}
