/* Overlay range [80139BE0,80139C7C) from MAIN.CD member 0012.
 * SHA256(span)=7b8a9866ce4a7b5531597372b73283e05bc955ebd4a8c580af1ec71695472958.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned char D_8017E94C[];

void func_80139BE0(int param_1)
{
        extern unsigned char D_8017E94C[];
        int v;
        if ((*(unsigned int *)(param_1 + 8) & 0x2000) == 0) {
            int t = *(unsigned char *)(param_1 + 0x22) & 0x60;
            int h = *(unsigned short *)(param_1 + 0x18);
            unsigned int idx;
            __asm__("" : "=r"(t) : "0"(t));
            idx = (unsigned char)t;
            if (h < 7) {
                if (h >= 2) {
                    v = D_8017E94C[idx >> 5];
                } else {
                    v = D_8017E94C[0];
                }
            } else {
                v = D_8017E94C[0];
            }
            *(short *)(param_1 + 0x2e) = 3;
            *(short *)(param_1 + 0x2c) = v;
        }
        *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x2c) * 6;
        {
            int x = *(short *)(param_1 + 0x2e);
            *(short *)(param_1 + 0x36) = x * 12 + (x - 1) * 2;
        }
    }
