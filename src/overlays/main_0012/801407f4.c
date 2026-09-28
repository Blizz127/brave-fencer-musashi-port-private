/* Overlay range [801407F4,80140958) from MAIN.CD member 0012.
 * SHA256(span)=90beba0ea7bad140bcb48f3caa2d749d6bb55a2ae72ff24e0f388fae4af6ee7a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801407F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: iv-combine
// @stuck: none — MATCH (89 ins). Sequential struct fields fed from a running source
//         pointer compile to fixed offsets when written base[0..n]; the target advances
//         the pointer, so use post-increment `*p++` for EVERY field (gcc drops the dead
//         final increment, yielding the "increment N-2 then offset 0/2" tail).


extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);

void func_801407F4(void)
{

    extern u8 *D_8017F3D8;
    extern u8 *D_8017F3DC;
    extern u8 *D_8017F3E0;
    extern u8 *D_8017F3E4;
    extern u8 *D_8017F3E8;
    extern u16 *D_8017F3EC[];
    extern u16 *D_8017F3F4[];
    extern u16 *D_8017F414[];
    u8 *puVar1;
    s32 iVar2;
    u16 *puVar3;

    puVar1 = D_8017F3D8;
    iVar2 = func_80028D58();
    puVar3 = D_8017F3EC[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;

    puVar1 = D_8017F3DC;
    iVar2 = func_80028DE0();
    puVar3 = D_8017F3EC[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;

    iVar2 = func_80028FBC();
    *(s16 *)(D_8017F3E0 + 0x18) = *D_8017F3F4[iVar2];
    iVar2 = func_80029000();
    *(s16 *)(D_8017F3E4 + 0x18) = *D_8017F3F4[iVar2];

    puVar1 = D_8017F3E8;
    iVar2 = func_80028D9C();
    puVar3 = D_8017F414[iVar2];
    *(s16 *)(puVar1 + 0x12) = *puVar3++;
    *(s16 *)(puVar1 + 0x14) = *puVar3++;
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    *(s16 *)(puVar1 + 0x1c) = *puVar3++;
}
