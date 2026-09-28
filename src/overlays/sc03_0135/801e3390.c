/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E3390 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801E3390(void) {
    typedef struct { u32 *ot; u32 pad[4]; } Env_801E46A0;
    extern s32 *func_801E46A0(s32 *);
    extern s32 func_801E3540(s32, u8 *, s16);
    extern s32 func_8005A600(s32, s32, s32, s32, s32);
    extern s32 D_801151D0;
    extern s16 D_8011512C;
    extern s32 D_80115134;
    extern s16 D_800B9A02;
    extern Env_801E46A0 D_800AE7BC[];

    s32 ot;
    u8 *s2;
    s16 n;
    s16 i;

    ot = D_801151D0;
    s2 = D_80115134;

    if (D_8011512C == 1 || D_8011512C == 2) {
        ot = (s32)func_801E46A0((s32 *)ot);
    }

    switch (D_8011512C) {
    case 0:
    case 5:
    case 8:
    case 9:
        n = 1;
        break;
    case 1:
    case 2:
        n = 5;
        break;
    case 3:
    case 4:
    case 10:
    case 11:
        n = 5;
        goto CALL;
    case 6:
    case 7:
    case 12:
        n = 1;
    CALL:
        ot = func_801E3540(ot, s2 + 0xA0, 0);
        break;
    }

    for (i = 0; i < n; i++) {
        ot = func_801E3540(ot, s2, i);
        s2 += 0x20;
    }

    func_8005A600(ot, 0, 0, 0x15, 0);

    *(s32 *)ot = 0x02000000;
    *(s32 *)ot = (D_800AE7BC[*(u16 *)&D_800B9A02].ot[2] & 0xFFFFFF) | 0x02000000;
    D_800AE7BC[*(u16 *)&D_800B9A02].ot[2] =
        (D_800AE7BC[*(u16 *)&D_800B9A02].ot[2] & 0xFF000000) | ((u32)ot & 0xFFFFFF);

    ot += 0x28;
    ((struct { s32 f; } *)&D_801151D0)->f = ot;
}
