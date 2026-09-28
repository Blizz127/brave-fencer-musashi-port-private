/* Overlay range [8017B614,8017B7A8) from MAIN.CD member 0012.
 * SHA256(span)=c6574a19818e972ff3ee5a795b834afbff49930e77c16d42bc7d0cbf96fa5a3a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B614 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { u8 b[8]; } Blk8_8017B614;

extern void func_8012A018(s32 a, s32 b);

// @class: regalloc-order + T1 memcpy-builtin→call re-crack
// @stuck: 0 (iso). Register lever = $16 pin + in-place re-tie on the memcpy-branch src (keeps
// param_2 in $a1 until the branch, then $s0 for the loads). Block-moves are align-1 struct-assigns
// (u8[8]) so they lower via emit_block_move (movstrsi/move_by_pieces) with ZERO memcpy-symbol
// reference — TU-independent, so the sibling TU's `extern memcpy` (which disables the builtin and
// turned the old inlined block-move into a CALL) can no longer drift this.




s32 func_8017B614(s32 param_1, s32 param_2)
{

    extern s32 D_80126990;
    extern s32 D_80126994;
    extern s16 D_8018534C;
    extern s16 D_80185C08;
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern void func_80129CF8(void);
    extern s32 func_8017BE60(void *a0);
    extern u8 D_80181CC0[];
    extern s16 D_801853C4;
    extern s16 D_801853C6;
    extern s16 D_801853C8;
    extern s16 D_801853BC;
    extern s16 D_801853BE;
    extern s16 D_801853C0;
    extern u8 D_8012694C;
    extern s32 D_80126998;
    extern s32 D_80126984;
    extern s32 D_80126988;
    extern s32 D_8012698C;

    u8 buf[16];

    if (((u32)param_2) >= 0xB) {
        register u8 *src __asm__("$16");
        __asm__ __volatile__("" : "=r"(src) : "0"((u8 *)((u32)param_2)));
        *(Blk8_8017B614 *)&buf[0] = *(Blk8_8017B614 *)src;
        *(Blk8_8017B614 *)&buf[8] = *(Blk8_8017B614 *)(src + 8);
    } else {
        s32 a1addr = (s32)&D_80181CC0[((u32)param_2) * 0x10];
        s32 a2addr = (s32)&D_80181CC0[((u32)param_2) * 0x10 + 8];
        func_8012F214(param_1, a1addr, (s32)&buf[0]);
        func_8012F214(param_1, a2addr, (s32)&buf[8]);
    }
    {
        s16 *p794 = &D_801853C4;
        s16 *p78C = &D_801853BC;
        *(Blk8_8017B614 *)p794 = *(Blk8_8017B614 *)&buf[0];
        *(Blk8_8017B614 *)p78C = *(Blk8_8017B614 *)&buf[8];
        func_8012A018((s32)func_8017BE60, 0);
        {
            s32 v794, v796, v798, v78C, v78E, v790;
            D_8012694C = 0;
            v794 = *p794;
            v796 = D_801853C6;
            v798 = D_801853C8;
            v78C = *p78C;
            v78E = D_801853BE;
            v790 = D_801853C0;
            __asm__ __volatile__("");
            D_80185C08 = 1;
            D_8018534C = 0x1E;
            D_80126990 = v794;
            D_80126994 = v796;
            D_80126998 = v798;
            D_80126984 = v78C;
            D_80126988 = v78E;
            D_8012698C = v790;
        }
        func_80129CF8();
    }
}
