/* Overlay range [80140D68,80140E6C) from MAIN.CD member 0012.
 * SHA256(span)=b32357439b00879eb5560f21545e36cb8e7779c2b7a3ee6f4986bb362ab01a1f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80140D68 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s16 x; s16 y; } Hw4;
typedef struct { u16 f0; s16 f2; } Prim4;
typedef struct {
        u32 *ot;             
        u32 pad[4];          
    } Env_800D29F8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_80140D68;
extern s16 D_800B9A02;
extern short D_800B9A02;

s32 *func_80140D68(out, src, idx, dx, ofs)
    s32 *out;
    Prim4 *src;    
    s16  idx;
    s32  dx;
    s16  ofs;
{

    extern Hw4 D_8011516A[];
     




          
    extern Env_800D29F8 D_800AE7BC[];


    register u32 mhi __asm__("$8");
    s16 *q;
    s32  a;

    out[0] = 0x04000000;
    *((u8 *)out + 0xC) = 0x70;
    *((u8 *)out + 0xD) = 0x10;
    mhi = 0x64808080;
    out[1] = mhi;
    *(u16 *)((u8 *)out + 0xE) = 0x4056;

    dx -= 0xD;
    q = (s16 *)(ofs * 2 + (s32)src);
    a = (u16)q[0] + (u16)D_8011516A[idx].x;
    a += dx;
    *(s16 *)((u8 *)out + 0x8) = a;
    *(s16 *)((u8 *)out + 0xA) = q[1] - 4;
    *(s16 *)((u8 *)out + 0x12) = 0x10;
    *(s16 *)((u8 *)out + 0x10) = 0x10;

    ((PTag_80140D68 *)out)->addr = ((PTag_80140D68 *)((D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot) + 2))->addr;
    ((PTag_80140D68 *)((D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot) + 2))->addr = (u32)out;

    return out + 5;
}
