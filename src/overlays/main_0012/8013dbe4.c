/* Overlay range [8013DBE4,8013DD68) from MAIN.CD member 0012.
 * SHA256(span)=c29b13b8bcdf065392b31b6550c8820ee0bfee8190e7795147796a25bb5a5aad.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013DBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: struct
// @stuck: none — MATCH (match_one 97/97). Two levers: (1) offset-first pointer arith
//   `(int*)(param_1*12 + (int)D_801841A8)` makes the addu `offset+base` (dest=v0) so x/y/z
//   load into a0/a1/a2 and each global loads LATE into v1 (base-first gave addu dest=v1 →
//   global hoisted into a0, shifting x/y/z to a1/a2/a3). (2) the clamp must be NESTED
//   if/else (slti dup'd inside each <,>= branch), NOT a merged `if(diff<5)` after the
//   branch — gcc cross-jumps the identical `G=x` and `G=t` store tails into the two shared
//   sites; the merged form emits one slti + unconditional store and diverges.


extern void func_8013DD68(void);

void func_8013DBE4(int param_1)
{

    extern void *D_801841A8;
    extern s16 *D_801841AC;
    extern s32 D_801841BC;
    extern s32 D_801841DC;
    extern s32 D_801841E0;
    extern s32 D_801841E4;
    int *p;
    int x, y, z;
    int flag;

    if (D_801841AC != 0) {
        D_801841BC = 0;
        p = (int *)(param_1 * 12 + (int)D_801841A8);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801841DC != x) {
            flag = 1;
            if (D_801841DC < x) {
                if (x - D_801841DC < 5) {
                    D_801841DC = x;
                } else {
                    D_801841DC = D_801841DC + 4;
                }
            } else {
                if (D_801841DC - x < 5) {
                    D_801841DC = x;
                } else {
                    D_801841DC = D_801841DC - 4;
                }
            }
        }
        if (D_801841E0 != y) {
            flag = 1;
            if (D_801841E0 < y) {
                if (y - D_801841E0 < 5) {
                    D_801841E0 = y;
                } else {
                    D_801841E0 = D_801841E0 + 4;
                }
            } else {
                if (D_801841E0 - y < 5) {
                    D_801841E0 = y;
                } else {
                    D_801841E0 = D_801841E0 - 4;
                }
            }
        }
        if (D_801841E4 != z) {
            flag = 1;
            if (D_801841E4 < z) {
                if (z - D_801841E4 < 5) {
                    D_801841E4 = z;
                } else {
                    D_801841E4 = D_801841E4 + 4;
                }
            } else {
                if (D_801841E4 - z < 5) {
                    D_801841E4 = z;
                } else {
                    D_801841E4 = D_801841E4 - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801841BC = flag;
    }
}
