/* libgs HLE: the packet-building parts of libgs over guest RAM.
 *
 * libgs's 2D sort calls build GPU packets in the packet area whose pointer
 * lives at GsOUT_PACKET_P (0x800A5E60) and link them into a guest GsOT. The
 * HLE does the same, so the packets render in OT order through DrawOTag (the
 * HLE decoder or the interpreter's GPU path), exactly like the retail code.
 * Layouts and field arithmetic follow the game's decompiled C for each entry
 * (repo src/main/<addr>.c); no Psy-Q code is used.
 *
 *   GsOT         +0 u16 length, +4 GsOT_TAG *org, +8 u16 offset, +10 u16 point
 *                (the retail code reads offset and point as one 32-bit word)
 *   GsLINE       +0 attribute, +4 x0 y0 x1 y1 (s16), +12 r g b
 *   GsSPRITE     +0 attribute, +4 x y, +8 w h, +0xC tpage, +0xE u v, +0x10 cx cy,
 *                +0x14 r g b
 *   GsCOORDINATE2 +0 flag, +4 MATRIX coord, +0x24 MATRIX workm, +0x44 param,
 *                +0x48 super, +0x4C sub */
#include "bfm_psyq_compat.h"
#include "../bfm_plat.h"

#include <stdio.h>
#include <string.h>

#define GS_OUT_PACKET_P 0x800A5E60u   /* u32: next free packet address */
#define GS_DRAW_OFS_X   0x800A6548u   /* s16: current buffer's draw offset */
#define GS_DRAW_OFS_Y   0x800A654Au
#define GS_IDMATRIX     0x800AE620u   /* MATRIX GsIDMATRIX */
#define GS_LIGHT_MODE   0x800C6DC8u   /* s32 */

#define A(n) bfm_psyq_arg(r, n)

static uint8_t *g(uint32_t addr, uint32_t len) { return (uint8_t *)bfm_psyq_ptr(addr, len); }

static int get32(uint32_t a, uint32_t *v) {
    uint8_t *p = g(a, 4);
    if (!p) return 0;
    *v = (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    return 1;
}

static int put32(uint32_t a, uint32_t v) {
    uint8_t *p = g(a, 4);
    if (!p) return 0;
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
    return 1;
}

static uint16_t u16at(const uint8_t *p) { return (uint16_t)(p[0] | (p[1] << 8)); }

/* The libgs OT link (func_80051EA0): slot = org + (pri - offset)*4;
 * packet tag = old slot word with byte 3 = len; slot = packet, byte 3 = 0.
 * Returns the address after the packet (header + len words). */
int bfm_psyq_gs_link(uint32_t pkt, uint32_t ot, uint32_t pri, uint8_t len, uint32_t *next) {
    uint32_t org, ofs, slot, old;
    int32_t idx;
    if (!get32(ot + 4, &org) || !get32(ot + 8, &ofs)) return 0;
    idx = (int32_t)(pri & 0xFFFFu) - (int32_t)ofs;
    slot = org + (uint32_t)idx * 4u;
    if (!get32(slot, &old)) return 0;
    if (idx < 0) bfm_plat_mods_log("libgs", 1, "GsOT priority below the OT offset");
    put32(pkt, (old & 0x00FFFFFFu) | ((uint32_t)len << 24));
    put32(slot, pkt & 0x00FFFFFFu);
    *next = pkt + (uint32_t)len * 4u + 4u;
    return 1;
}

static int draw_offset(int16_t *x, int16_t *y) {
    uint8_t *px = g(GS_DRAW_OFS_X, 4);
    if (!px) return 0;
    *x = (int16_t)u16at(px);
    *y = (int16_t)u16at(px + 2);
    return 1;
}

/* GsSortLine(GsLINE *lp, GsOT *ot, u16 pri): E1 + LINE_F2, 4 words after the tag */
int bfm_psyq_GsSortLine(uint32_t *r) {
    uint8_t *lp = g(A(0), 15);
    uint32_t pkt, next, attr;
    int16_t ox, oy;
    if (!lp || !get32(GS_OUT_PACKET_P, &pkt) || !g(pkt, 20) || !draw_offset(&ox, &oy)) return 0;
    attr = (uint32_t)lp[0] | ((uint32_t)lp[1] << 8) | ((uint32_t)lp[2] << 16) | ((uint32_t)lp[3] << 24);
    if ((int32_t)attr < 0) return 1;                     /* display-off bit: nothing drawn */
    put32(pkt + 4, ((attr >> 23) & 0x60u) | 0xE1000200u);
    put32(pkt + 8, (uint32_t)lp[12] | ((uint32_t)lp[13] << 8) | ((uint32_t)lp[14] << 16) |
                   ((((attr >> 29) & 2u) | 0x40u) << 24));
    put32(pkt + 12, (uint16_t)(u16at(lp + 4) + (uint16_t)ox) | ((uint32_t)(uint16_t)(u16at(lp + 6) + (uint16_t)oy) << 16));
    put32(pkt + 16, (uint16_t)(u16at(lp + 8) + (uint16_t)ox) | ((uint32_t)(uint16_t)(u16at(lp + 10) + (uint16_t)oy) << 16));
    if (!bfm_psyq_gs_link(pkt, A(1), A(2), 4, &next)) return 0;
    put32(GS_OUT_PACKET_P, next);
    return 1;
}

/* GsSortFastSprite(GsSPRITE *sp, GsOT *ot, u16 pri): E1 + SPRT, 5 words after the tag */
int bfm_psyq_GsSortFastSprite(uint32_t *r) {
    uint8_t *sp = g(A(0), 0x17);
    uint32_t pkt, attr, org, ofs, slot, old;
    int16_t ox, oy;
    if (!sp || !get32(GS_OUT_PACKET_P, &pkt) || !g(pkt, 24) || !draw_offset(&ox, &oy)) return 0;
    attr = (uint32_t)sp[0] | ((uint32_t)sp[1] << 8) | ((uint32_t)sp[2] << 16) | ((uint32_t)sp[3] << 24);
    if ((int32_t)attr < 0 || u16at(sp + 8) == 0 || u16at(sp + 10) == 0) return 1;
    if (!get32(A(1) + 4, &org) || !get32(A(1) + 8, &ofs)) return 0;
    slot = org + (A(2) & 0xFFFFu) * 4u - ofs * 4u;
    if (!get32(slot, &old)) return 0;
    put32(pkt + 4, (u16at(sp + 12) & 0x1Fu) | ((attr >> 17) & 0x180u) | 0xE1000200u | ((attr >> 23) & 0x60u));
    put32(pkt + 12, ((uint32_t)(uint16_t)(u16at(sp + 4) + (uint16_t)ox)) |
                    ((uint32_t)(uint16_t)(u16at(sp + 6) + (uint16_t)oy) << 16));
    put32(pkt + 8, ((attr >> 5) & 0x02000000u) | ((attr << 18) & 0x01000000u) | 0x64000000u |
                   ((uint32_t)sp[0x16] << 16) | ((uint32_t)sp[0x15] << 8) | sp[0x14]);
    put32(pkt + 16, sp[0x0E] | ((uint32_t)sp[0x0F] << 8) |
                    ((uint32_t)(int32_t)(int16_t)u16at(sp + 0x12) << 22) |
                    (((uint32_t)(int32_t)(int16_t)u16at(sp + 0x10) << 12) & 0x3F0000u));
    put32(pkt + 20, u16at(sp + 8) | ((uint32_t)u16at(sp + 10) << 16));
    put32(pkt, old + 0x05000000u);
    put32(slot, pkt & 0x00FFFFFFu);
    put32(GS_OUT_PACKET_P, pkt + 0x18u);
    return 1;
}

/* GsInitCoordinate2(GsCOORDINATE2 *super, GsCOORDINATE2 *base) */
int bfm_psyq_GsInitCoordinate2(uint32_t *r) {
    uint32_t super = A(0), base = A(1);
    uint8_t *c = g(base, 0x50), *id = g(GS_IDMATRIX, 32);
    if (!c || !id) return 0;
    if (super != 0 && super != 1 && !g(super + 0x4C, 4)) return 0;
    memcpy(c + 4, id, 32);
    put32(base + 0x48, super);
    put32(base, 0);
    if (super != 0 && super != 1) put32(super + 0x4C, base);
    return 1;
}

/* GsMapModelingData(u_long *p): p = &tmd.flags; relocates the object table
 * (vert_top, normal_top, primitive_top of each 28-byte object) once. */
int bfm_psyq_GsMapModelingData(uint32_t *r) {
    uint32_t p = A(0), flags, count, table, i;
    if (!get32(p, &flags) || !get32(p + 4, &count)) return 0;
    if (flags & 1u) return 1;
    table = p + 8;
    if ((int32_t)count > 0 && !g(table, count * 28u)) return 0;
    put32(p, flags | 1u);
    for (i = 0; (int32_t)i < (int32_t)count; i++) {
        uint32_t e = table + i * 28u, v = 0, k;
        for (k = 0; k < 24u; k += 8u)   /* vert_top, normal_top, primitive_top */
            if (get32(e + k, &v)) put32(e + k, v + table);
    }
    return 1;
}

/* GsSetLightMode(mode): 0..3 stored; others logged (and ignored) */
int bfm_psyq_GsSetLightMode(uint32_t *r) {
    uint32_t mode = A(0);
    if (mode <= 3u) return put32(GS_LIGHT_MODE, mode);
    bfm_plat_mods_log("libgs", 1, "GsSetLightMode: unknown mode");
    return 1;
}

/* ---- GsSortObject5 (libgs PRESET2.o, 0x80055D40) -------------------------
 *
 * GsSortObject5(GsDOBJ5 *obj, GsOT *ot, int shift, u_long *scratch) walks the
 * preset packet blocks of a GsDOBJ5 and hands each block to the per-type
 * libgs sort routine named by libgs's GsFCALL5-style function-pointer tables
 * in guest RAM (0x800A2CF0..0x800A2E04). Those routines are guest code
 * (entered through the lane; a routine that is not a lane entry is the strict
 * lane_guest_call stop), so this wrapper only re-does the dispatcher.
 * Reconstructed from the retail control flow (not from Psy-Q source):
 *
 *   obj  +0 attribute, +8 TMD object (+0 vert_top, +8 normal_top,
 *        +0x10 primitive_top), +0xC first preset block
 *   block +0 next (low 24 bits; 0 ends), +4 count n, +8.. packet area
 *   attribute: bit 31 skip; 3-4 -> 0x80079580, 5 -> 0x800A2B74,
 *        6 -> 0x8007957C, 9-11 (division) -> 0x800C7D28, 30 -> 0x800C6D24
 *   light = bit6 ? 2 : ((!bit5 && GsLIGHT_MODE == 1) || (bit5 && bits3-4 == 1)) ? 1 : 0
 *
 * Three loops: division (packets appended at GsOUT_PACKET_P, the routine's
 * return value becomes the new GsOUT_PACKET_P), preset buffer 0 (block + 8)
 * and preset buffer 1 when the game's buffer index D_800C7C74 == 1 (a
 * per-type offset into the block). The primitive pointer advances by a
 * per-type size times n. Codes are the TMD mode byte with bit 1 masked. */
#define GS5_FN(off) (0x800A2C00u + (off))
typedef struct Gs5Type {
    uint16_t fn;        /* table offset from 0x800A2C00 */
    uint8_t lit;        /* lit (normals; light-indexed table) */
    uint8_t size;       /* TMD primitive bytes */
    uint8_t buf1;       /* preset buffer 1 offset into the block */
    uint16_t grd_fn;    /* 0: none; buffers 0/1 use this light-indexed table when flag bit 2 is set */
    uint8_t grd_size;
    uint8_t grd_buf1;
} Gs5Type;
static const Gs5Type kGs5Types[30] = {
    [0x00] = {0x0F0, 1, 16, 0x1C, 0x1F0, 24, 0x24},
    [0x01] = {0x108, 0, 16, 0x1C, 0, 0, 0},
    [0x04] = {0x130, 1, 24, 0x28, 0, 0, 0},
    [0x05] = {0x148, 0, 28, 0x28, 0, 0, 0},
    [0x08] = {0x170, 1, 20, 0x20, 0, 0, 0},
    [0x09] = {0x188, 0, 16, 0x20, 0, 0, 0},
    [0x0C] = {0x1B0, 1, 32, 0x30, 0, 0, 0},
    [0x0D] = {0x1C8, 0, 32, 0x30, 0, 0, 0},
    [0x10] = {0x110, 1, 20, 0x24, 0x1FC, 28, 0x24},
    [0x11] = {0x128, 0, 24, 0x24, 0, 0, 0},
    [0x14] = {0x150, 1, 28, 0x30, 0, 0, 0},
    [0x15] = {0x168, 0, 36, 0x30, 0, 0, 0},
    [0x18] = {0x190, 1, 24, 0x2C, 0, 0, 0},
    [0x19] = {0x1A8, 0, 28, 0x2C, 0, 0, 0},
    [0x1C] = {0x1D0, 1, 36, 0x3C, 0, 0, 0},
    [0x1D] = {0x1E8, 0, 44, 0x3C, 0, 0, 0},
};

uint32_t musashi_native_guest_call(uint32_t target, unsigned argc,
                                   const uint32_t *args, uint32_t *v1);

int bfm_psyq_GsSortObject5(uint32_t *r) {
    const uint32_t obj = A(0), ot = A(1), shift = A(2), scratch = A(3);
    uint32_t attr, tmd, blk, prim, vert, norm, lmode, b5, b6, div, lightmode = 0, w;
    uint32_t light, loop, tmp;
    uint16_t bufidx = 0;
    uint8_t *p;
    if (!get32(obj, &attr)) return 0;
    if ((int32_t)attr < 0) return 1;
    lmode = (attr >> 3) & 3u;
    b5 = (attr >> 5) & 1u;
    b6 = (attr >> 6) & 1u;
    div = (attr >> 9) & 7u;
    if (!put32(0x80079580u, lmode) || !put32(0x800A2B74u, b5) || !put32(0x8007957Cu, b6) ||
        !put32(0x800C7D28u, div) || !put32(0x800C6D24u, (attr >> 30) & 1u)) return 0;
    if (div) {
        uint32_t s1v, s2v;
        if (!get32(0x800AE618u, &s1v) || !get32(0x800AE61Cu, &s2v)) return 0;
        if (!put32(scratch, div) || !put32(scratch + 4u, s1v) || !put32(scratch + 8u, s2v)) return 0;
    }
    if (b6 == 1u) light = 2u;
    else {
        if (!b5 && !get32(GS_LIGHT_MODE, &lightmode)) return 0;
        light = ((!b5 && lightmode == 1u) || (b5 == 1u && lmode == 1u)) ? 1u : 0u;
    }
    if (!get32(obj + 8u, &tmd) || !get32(obj + 12u, &blk)) return 0;
    if (!get32(tmd + 16u, &prim) || !get32(tmd, &vert) || !get32(tmd + 8u, &norm)) return 0;
    if (div) loop = 0u;
    else {
        if (!(p = g(0x800C7C74u, 2))) return 0;
        bufidx = u16at(p);
        loop = bufidx == 1u ? 2u : 1u;
    }
    for (;;) {
        uint32_t n, code, fn = 0, args[8], argc, ret;
        uint16_t flag;
        const Gs5Type *t;
        int grd;
        if (!(p = g(prim, 4))) return 0;
        code = p[3] & 0xFDu;
        flag = u16at(p + 2);
        if (!get32(blk + 4u, &n)) return 0;
        t = (code >= 0x20u && code < 0x3Eu) ? &kGs5Types[code - 0x20u] : NULL;
        if (!t || !t->fn) {
            fprintf(stderr, loop ? "non suppported code %x %x\n" : "non supported code %x %x\n",
                    (unsigned)code, (unsigned)blk);
        } else {
            grd = t->grd_fn && (flag & 4u);
            if (loop == 0u) {                       /* division: append at GsOUT_PACKET_P */
                uint32_t pk;
                if (grd) {
                    fprintf(stderr, "Notsupported yet!!\n");
                    prim += t->grd_size * n;
                    goto next;
                }
                if (!get32(GS_OUT_PACKET_P, &pk)) return 0;
                if (t->lit) {
                    if (!get32(GS5_FN(t->fn) + 12u + light * 4u, &fn)) return 0;
                    args[0] = prim; args[1] = vert; args[2] = norm; args[3] = pk;
                    args[4] = n; args[5] = shift; args[6] = ot; args[7] = scratch; argc = 8u;
                } else {
                    if (!get32(GS5_FN(t->fn) + 4u, &fn)) return 0;
                    args[0] = prim; args[1] = vert; args[2] = pk; args[3] = n;
                    args[4] = shift; args[5] = ot; args[6] = scratch; argc = 7u;
                }
                ret = musashi_native_guest_call(fn, argc, args, NULL);
                if (!put32(GS_OUT_PACKET_P, ret)) return 0;
            } else {                                /* preset buffer 0 / 1 */
                uint32_t pkt;
                if (grd) {
                    pkt = blk + (loop == 2u ? t->grd_buf1 : 8u);
                    if (!get32(GS5_FN(t->grd_fn) + light * 4u, &fn)) return 0;
                } else {
                    pkt = blk + (loop == 2u ? t->buf1 : 8u);
                    if (!get32(GS5_FN(t->fn) + (t->lit ? light * 4u : 0u), &fn)) return 0;
                }
                if (t->lit) {
                    args[0] = prim; args[1] = vert; args[2] = norm; args[3] = pkt;
                    args[4] = n; args[5] = shift; args[6] = ot; argc = 7u;
                } else {
                    args[0] = prim; args[1] = vert; args[2] = pkt; args[3] = n;
                    args[4] = shift; args[5] = ot; argc = 6u;
                }
                (void)musashi_native_guest_call(fn, argc, args, NULL);
            }
            prim += (grd ? t->grd_size : t->size) * n;
        }
    next:
        if (!get32(blk, &w)) return 0;
        tmp = w & 0x00FFFFFFu;
        if (!tmp) break;
        blk = tmp;
    }
    (void)bufidx;
    return 1;
}
