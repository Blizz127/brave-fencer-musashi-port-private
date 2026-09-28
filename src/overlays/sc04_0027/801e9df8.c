/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E9DF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u32 w[38]; } Blk152_8017DF40_801E9DF8;
typedef struct { u8 b[4]; } Blk4_8017DF40_801E9DF8;

void func_801E9DF8(s32 arg0) {

    extern u8  D_80078E78[];   /* live: 152-byte block            (host TU declares this identically) */
    extern u16 D_800A6588[];   /* live: u16[64]                                                      */
    extern u8  D_800AE648[];   /* live: u8[64]                                                       */
    extern u8  D_800BA1B8[];   /* live: u8[256]                                                      */
    extern u8  D_800BA2B8[];   /* live: 4-byte struct[24], align 1                                   */
    extern u8  D_801F21B8[];   /* shadow: +0x000 */
    extern u16 D_801F2250[];   /* shadow: +0x098 */
    extern u8  D_801F22D0[];   /* shadow: +0x118 */
    extern u8  D_801F2310[];   /* shadow: +0x158 */
    extern u8  D_801F2410[];   /* shadow: +0x258 */
    s16 i;

    if ((s16)arg0 == 0) {
        *(Blk152_8017DF40_801E9DF8 *)D_80078E78 = *(Blk152_8017DF40_801E9DF8 *)D_801F21B8;
        for (i = 0; i < 64; i++) {
            D_800A6588[i] = D_801F2250[i];
        }
        for (i = 0; i < 64; i++) {
            D_800AE648[i] = D_801F22D0[i];
        }
        for (i = 0; i < 256; i++) {
            D_800BA1B8[i] = D_801F2310[i];
        }
        for (i = 0; i < 24; i++) {
            ((Blk4_8017DF40_801E9DF8 *)D_800BA2B8)[i] = ((Blk4_8017DF40_801E9DF8 *)D_801F2410)[i];
        }
    } else {
        *(Blk152_8017DF40_801E9DF8 *)D_801F21B8 = *(Blk152_8017DF40_801E9DF8 *)D_80078E78;
        for (i = 0; i < 64; i++) {
            D_801F2250[i] = D_800A6588[i];
        }
        for (i = 0; i < 64; i++) {
            D_801F22D0[i] = D_800AE648[i];
        }
        for (i = 0; i < 256; i++) {
            D_801F2310[i] = D_800BA1B8[i];
        }
        for (i = 0; i < 24; i++) {
            ((Blk4_8017DF40_801E9DF8 *)D_801F2410)[i] = ((Blk4_8017DF40_801E9DF8 *)D_800BA2B8)[i];
        }
    }
}
