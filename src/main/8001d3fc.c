/* Main-exec range [8001D3FC,8001D70C) from the SLUS executable.
 * SHA256(span)=105f74153eb2a817bcb9f1c0d7c2de185911d9e989fb7f1cbcf742ca91fc9957.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001D3FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* POLY_FT4 sprite-strip builder: walks a 12-byte record list at arg0+0x20, pulls
 * 0x28-byte prims off the D_800A5E60 bump allocator, builds tpage/clut/UVs with
 * X/Y flip, calls func_8001D8C4, and addPrim's each prim into the OT slot
 * &((PTag *)(D_800A6610 + (D_800B9A02 << 14)))[pri].
 *
 * Five levers were needed (see cookbook notes in the wave report):
 *  1. libgpu addPrim bitfield `struct { u32 addr:24; u32 len:8; }` -> hoists 0x00FFFFFF into $s7.
 *  2. ONE record pointer (not two): gcc's giv combination emits the `addiu $s2,$s3,3`
 *     preheader init and the -1/0/1/3 offsets off it.
 *  3. Chained store `*(u8 *)(cur+0x14) = *(u8 *)(cur+0x24) = u;` -> the SI->QI
 *     `addu $v0,$a0,$zero` before each sb pair, one copy shared across both flip arms.
 *  4. `ut` is a SINGLE-SET temp: birthing-boost (sched.c adjust_priority /
 *     birthing_insn_p, REG_N_SETS(dest)==1) sinks the sllv chain BELOW the
 *     `cur[7] |= abe` block, which is what the target does. Folding ut into ub
 *     (ub = expr; u = ub; ub = ub + w - 1) gives ub 3 sets, kills the boost, and
 *     schedules the whole u-chain before the abe block instead (closeness 31).
 *  5. `u`/`ub` are u16: the mode-changing copy `u = ut` is NOT a plain reg-reg copy,
 *     so cse/coalescing cannot propagate `ut` into u's later uses and delete it.
 *     That single instruction (`addu $a0,$v1,$zero`) is what fixes the whole
 *     $a0<->$v1 allocation of both the U and the V half. Same mechanism keeps the
 *     V-flip diamond's else arm (`addu $a0,$v1,$zero`) alive and shares `(u16)vy`
 *     across both arms.
 *  6. The explicit intermediate `tt` makes the U-half accumulator reuse $v1
 *     (`addu $v1,$v1,$v0`) instead of the dying rec[2] register $v0.
 */

typedef struct { u32 addr : 24; u32 len : 8; } PTag_8001D3FC;

extern u8 D_800A6610[];
extern u16 D_800B9A02;
extern u8 *D_800A5E60;

extern void func_8001D70C(s32 arg0);
extern void func_8001D8C4(s32 arg0, u8 *rec, u8 *prim);

void func_8001D3FC(s32 arg0)
{
    u32 pri;
    u32 attr;
    u8 *rec;
    PTag_8001D3FC *slot;
    u32 sc;
    s32 mode;
    s32 shift;
    u8 *cur;
    u16 id;
    u32 sx, sy;
    s32 xs;
    u16 vx, vy;
    s32 tpage;
    u16 u;
    u16 ub;
    s32 ut, vt;
    s32 tt;
    s32 clut;

    pri = *(u16 *)(arg0 + 0x2C) & 0x3FFF;
    if (pri < 0x1000) {
        attr = *(u32 *)(arg0 + 4);
        rec = *(u8 **)(arg0 + 0x20);
        sc = (u32)(u16)D_800B9A02;
        mode = (attr >> 24) & 3;
        shift = 2 - mode;
        slot = &((PTag_8001D3FC *)(D_800A6610 + (sc << 14)))[pri];
        func_8001D70C(arg0);
        do {
            cur = D_800A5E60;
            id = *(u16 *)rec;
            xs = *(s16 *)(rec + 4);
            sx = *(u16 *)(arg0 + 0x28) + (xs >> shift);
            vx = sx;
            sy = *(u16 *)(arg0 + 0x2A) + *(u16 *)(rec + 6);
            vy = sy;
            D_800A5E60 = cur + 0x28;
            *(u8 *)(cur + 3) = 9;
            *(u8 *)(cur + 7) = 0x2C;
            if (attr & 0x40000000) {
                *(u8 *)(cur + 7) = 0x2E;
                tpage = (mode << 7) | (((attr >> 28) & 3) << 5) |
                        ((sy & 0x100) >> 4) | ((sx & 0x3C0) >> 6) |
                        ((sy & 0x200) << 2);
            } else {
                tpage = (mode << 7) | (1 << 5) |
                        ((sy & 0x100) >> 4) | ((sx & 0x3C0) >> 6) |
                        ((sy & 0x200) << 2);
            }
            *(s16 *)(cur + 0x16) = tpage;
            *(u8 *)(cur + 7) |= (attr & 0x40) >> 6;

            ut = (vx - ((tpage & 0xF) << 6)) << shift;
            u = ut;
            tt = ut + *(u8 *)(rec + 2);
            ub = tt - 1;
            if ((u16)ub >= 0x100) {
                ub = 0xFF;
            }
            if (id & 0x100) {
                *(u8 *)(cur + 0x14) = *(u8 *)(cur + 0x24) = u;
                *(u8 *)(cur + 0x0C) = *(u8 *)(cur + 0x1C) = ub;
            } else {
                *(u8 *)(cur + 0x0C) = *(u8 *)(cur + 0x1C) = u;
                *(u8 *)(cur + 0x14) = *(u8 *)(cur + 0x24) = ub;
            }

            vt = vy;
            if (tpage & 0x10) {
                u = vt - 0x100;
            } else {
                u = vt;
            }
            ub = u + *(u8 *)(rec + 3) - 1;
            if ((u16)ub >= 0x100) {
                ub = 0xFF;
            }
            if (id & 0x200) {
                *(u8 *)(cur + 0x1D) = *(u8 *)(cur + 0x25) = u;
                *(u8 *)(cur + 0x0D) = *(u8 *)(cur + 0x15) = ub;
            } else {
                *(u8 *)(cur + 0x0D) = *(u8 *)(cur + 0x15) = u;
                *(u8 *)(cur + 0x1D) = *(u8 *)(cur + 0x25) = ub;
            }

            clut = ((*(u8 *)(arg0 + 0x27) + 0x100) << 6) |
                   ((*(u8 *)(arg0 + 0x27) < 0xE0) ? 0x16 : 0x10);
            *(s16 *)(cur + 0xE) = clut;
            *(u8 *)(cur + 4) = *(u8 *)(arg0 + 0x24);
            *(u8 *)(cur + 5) = *(u8 *)(arg0 + 0x25);
            *(u8 *)(cur + 6) = *(u8 *)(arg0 + 0x26);
            func_8001D8C4(arg0, rec, cur);

            ((PTag_8001D3FC *)cur)->addr = slot->addr;
            slot->addr = (u32)cur;
            rec += 0xC;
        } while ((id & 0xFF) != 0xFF);
    }
}
