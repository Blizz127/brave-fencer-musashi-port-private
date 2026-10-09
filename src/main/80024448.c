/* Main-exec range [80024448,800249F0) from the SLUS executable.
 * SHA256(span)=ff81ac9b9f82924653a5474d03f75218cfb73158612272926d93e719bd569e71.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80024448 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_80024448 (main / src/800.c) -- TMD mesh dispatcher: walks the primitive list at
 * hdr->prims (hdr = *(a0+8): [0]=verts [2]=norms [4]=prims [5]=count) and, per run of
 * primitives, dispatches on (word>>24)&0xFC (0x20..0x3C, jump table jtbl_80072B88) and the
 * gradation bit (word>>16)&4 to the matching emitter, which bumps the D_800A5E60 packet
 * pointer. Each arm then subtracts the run length (u16 at +0) from the remaining count and
 * advances by run_len * stride (16/20/24/28/32/36 bytes). The D_80078D88 tests select the
 * handwritten shaded variants (func_80026514 / func_800268D0) with an 8th argument.
 *   [MATCH 362/362, S72m_1]  Shape facts: every arm carries its OWN `count -= n; p += n*stride`
 * tail (gcc-2.7.2 cross-jumps only the suffix shared with the fall-through predecessor, so the
 * three-way D_80078D88 chains keep three copies); case bodies are in source order
 * 0x20,0x28,0x24,0x2C,0x30,0x38,0x34,0x3C to reproduce the target's body layout while the
 * jump table indexes by value. */
extern u8 *D_800A5E60;
extern s32 D_80078D88[];

/* Callees: every one is DEFINED later in src/800.c. In this split tree each is its own file,
 * so the emitters are prototyped with 32-bit parameters (the same registers and bytes as the
 * old no-proto calls; re-verified byte-identical), as the lane's ABI rule requires. */
extern long *func_800249F0(char *f, s32 verts, s32 norms, long *prim, s32 count, s32 shift, s32 ot);
extern u8 *func_80024DE8(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
extern u8 *func_8002528C(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
extern u8 *func_80025504(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
extern u8 *func_80025A30(u8 *prim, u8 *vtx, u8 *nrm, u8 *pkt, s32 n, s32 shift, u32 *ot);
extern void *func_80025CBC(void *prims, void *scr, void *cols, void *packets, s32 count, s32 otshift, u32 *ot);
extern u8 *func_80025EB8(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
/* Handwritten-asm shaded emitters: they return the packet pointer in $v0 and take an 8th
 * (stack) argument; prototyped, the direct calls give the same bytes as the old no-proto
 * function-pointer casts (re-verified byte-identical). */
extern u8 *func_80026514(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot, s32 shaded);
extern u8 *func_800268D0(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot, s32 shaded);

#define CNT (*(u16 *)s0)
#define OT  (*(u32 **)(param_2 + 4))

void func_80024448(int param_1, int param_2, u32 param_3)
{
    u32 *s0;
    u32 *v0;
    s32 iVar;
    u32 flag;
    u32 vtx;
    u32 nrm;
    /* These five return TU-local untagged struct type names (POLY_F4, PG4, PG3, PktGT3,
     * PktGT4) that src/800.c introduces only AFTER this function, so no file-scope forward
     * decl can spell them (a file-scope `extern u8 *f();` is a hard "conflicting types" error
     * at the later definition). Block-scope externs live in gcc-2.7.2's limbo instead: the
     * later definition draws only a "type mismatch with previous external decl" warning,
     * and the emitted bytes are identical (measured on a synthetic TU, S72m_1). */
    extern u8 *func_80024BC0(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
    extern u8 *func_80025000(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
    extern u8 *func_80025818(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
    extern u8 *func_80026128(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);
    extern u8 *func_800262D8(void *prim, u32 vtx, u32 nrm, u8 *pkt, s32 n, u32 shift, u32 *ot);

    v0 = *(u32 **)(param_1 + 8);
    s0 = (u32 *)v0[4];
    iVar = v0[5];
    vtx = v0[0];
    nrm = v0[2];

    if (iVar == 0) return;

    do {
        flag = (*s0 >> 16) & 4;
        switch ((*s0 >> 24) & 0xFC) {
        case 0x20:
            if (flag) {
                D_800A5E60 = (u8 *)func_80024DE8(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 24);
            } else {
                D_800A5E60 = (u8 *)func_800249F0((char *)s0, vtx, nrm, (long *)D_800A5E60, CNT, param_3, (s32)OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 16);
            }
            break;
        case 0x28:
            if (flag) {
                D_800A5E60 = (u8 *)func_80025000(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 32);
            } else {
                D_800A5E60 = (u8 *)func_80024BC0(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 20);
            }
            break;
        case 0x24:
            D_800A5E60 = (u8 *)func_80025CBC(s0, (void *)vtx, (void *)nrm, D_800A5E60, CNT, param_3, OT);
            iVar -= CNT;
            s0 = (u32 *)((u8 *)s0 + CNT * 24);
            break;
        case 0x2C:
            D_800A5E60 = (u8 *)func_80025EB8(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
            iVar -= CNT;
            s0 = (u32 *)((u8 *)s0 + CNT * 32);
            break;
        case 0x30:
            if (flag) {
                D_800A5E60 = (u8 *)func_80025818(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 28);
            } else {
                if (D_80078D88[0] & 0x10000) {
                    D_800A5E60 = func_80026514(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT, 0);
                    iVar -= CNT;
                    s0 = (u32 *)((u8 *)s0 + CNT * 20);
                } else if (D_80078D88[0] & 0x20000) {
                    D_800A5E60 = func_80026514(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT, 1);
                    iVar -= CNT;
                    s0 = (u32 *)((u8 *)s0 + CNT * 20);
                } else {
                    D_800A5E60 = (u8 *)func_8002528C(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
                    iVar -= CNT;
                    s0 = (u32 *)((u8 *)s0 + CNT * 20);
                }
            }
            break;
        case 0x38:
            if (flag) {
                D_800A5E60 = (u8 *)func_80025A30((u8 *)s0, (u8 *)vtx, (u8 *)nrm, D_800A5E60, CNT, param_3, OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 36);
            } else if (D_80078D88[0] & 0x10000) {
                D_800A5E60 = func_800268D0(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT, 0);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 24);
            } else if (D_80078D88[0] & 0x20000) {
                D_800A5E60 = func_800268D0(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT, 1);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 24);
            } else {
                D_800A5E60 = (u8 *)func_80025504(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
                iVar -= CNT;
                s0 = (u32 *)((u8 *)s0 + CNT * 24);
            }
            break;
        case 0x34:
            D_800A5E60 = (u8 *)func_80026128(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
            iVar -= CNT;
            s0 = (u32 *)((u8 *)s0 + CNT * 28);
            break;
        case 0x3C:
            D_800A5E60 = (u8 *)func_800262D8(s0, vtx, nrm, D_800A5E60, CNT, param_3, OT);
            iVar -= CNT;
            s0 = (u32 *)((u8 *)s0 + CNT * 36);
            break;
        }
    } while (iVar != 0);
}
