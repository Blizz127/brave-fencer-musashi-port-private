/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F1738 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u32 w[38]; } Blk152_8017DF40_801F1738;
typedef struct { u8 b[4]; } Blk4_8017DF40_801F1738;

void func_801F1738(s32 arg0) {

    extern u8  D_80078E78[];    
    extern u16 D_800A6588[];    
    extern u8  D_800AE648[];    
    extern u8  D_800BA1B8[];    
    extern u8  D_800BA2B8[];    
    extern u8  D_801F9AE8[];    
    extern u16 D_801F9B80[];    
    extern u8  D_801F9C00[];    
    extern u8  D_801F9C40[];    
    extern u8  D_801F9D40[];    
    s16 i;

    if ((s16)arg0 == 0) {
        *(Blk152_8017DF40_801F1738 *)D_80078E78 = *(Blk152_8017DF40_801F1738 *)D_801F9AE8;
        for (i = 0; i < 64; i++) {
            D_800A6588[i] = D_801F9B80[i];
        }
        for (i = 0; i < 64; i++) {
            D_800AE648[i] = D_801F9C00[i];
        }
        for (i = 0; i < 256; i++) {
            D_800BA1B8[i] = D_801F9C40[i];
        }
        for (i = 0; i < 24; i++) {
            ((Blk4_8017DF40_801F1738 *)D_800BA2B8)[i] = ((Blk4_8017DF40_801F1738 *)D_801F9D40)[i];
        }
    } else {
        *(Blk152_8017DF40_801F1738 *)D_801F9AE8 = *(Blk152_8017DF40_801F1738 *)D_80078E78;
        for (i = 0; i < 64; i++) {
            D_801F9B80[i] = D_800A6588[i];
        }
        for (i = 0; i < 64; i++) {
            D_801F9C00[i] = D_800AE648[i];
        }
        for (i = 0; i < 256; i++) {
            D_801F9C40[i] = D_800BA1B8[i];
        }
        for (i = 0; i < 24; i++) {
            ((Blk4_8017DF40_801F1738 *)D_801F9D40)[i] = ((Blk4_8017DF40_801F1738 *)D_800BA2B8)[i];
        }
    }
}
