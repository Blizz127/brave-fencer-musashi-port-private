/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170B48 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014706C(void *arg0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_8014706C(void *a0);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);

void func_80170B48(int a0)
{
    extern void *D_8011F738;
    extern void func_8014706C(void *a0);
    extern void func_80154274(s32 *a0, s32 a1);
    extern s32 func_80171990(u8 *a0);
    func_8014706C(a0);
    func_80154274((s32 *)a0, (s32)D_8011F738);
    func_80171990((u8 *)a0);
    func_80170B90((u8 *)a0);
}
