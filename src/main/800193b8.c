/* Main-exec range [800193B8,8001971C) from the SLUS executable.
 * SHA256(span)=35d47bb97eea16e04ae585d91cb7756e36278a95e49388a48a8ffddf1d5560a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800193B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 minute; /* +0x00 */
    u8 second; /* +0x01 */
    u8 sector; /* +0x02 */
    u8 track;  /* +0x03 */
} CdlLOC;
extern int      func_80043B1C(CdlLOC *p);
extern CdlLOC  *func_80043A18(int i, CdlLOC *p);
extern void func_80019990(void);
extern int func_8004239C(int mode);
extern s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern u8 D_80062C38;
extern u8 D_80062C68;
extern u8 D_80062DE8;
extern s32 D_800747D0;
extern s32 D_80063074;
extern s32 D_800747D8;
extern u8 D_800AE830[];
extern u8 D_800AE834;
#define LIST_BUF 0x80180000

void func_800193B8(s32 arg0) {
    CdlLOC loc;
    u8 hdr[0x90];
    register s32 sector __asm__("$18");
    s32 rdy;
    register s32 tmp __asm__("$3");
    register u8 *q __asm__("$16");
    register u8 *r __asm__("$17");
    register int i __asm__("$23");
    int base;
    int n;
    int fileIdx;
    int bufIdx;
    register int j __asm__("$19");
    register int outer __asm__("$23");
    int locOff;
    u8 *tbl;
    u8 *lbv;
    int dstOff;
    int srcOff;
    s32 *pCount;
    s32 *pOff;
    CdlLOC *p;
    register CdlLOC *pp __asm__("$5");

    func_80019990();
    sector = arg0 + 1;
    D_800747D0 = 0;
    D_80063074 = 0;
    D_800747D8 = 0;
    func_80043A18(sector, &loc);
    do {
        rdy = func_80019A24((int *)&loc, (void *)LIST_BUF, 0x800, 0);
        if (rdy != 0) {
            break;
        }
        func_8004239C(0);
    } while (1);

    memcpy(hdr, (void *)LIST_BUF, 0x88);
    tmp = sector + 1;
    sector = tmp + ((*(u32 *)(hdr + 0x1C) + 0x7FF) >> 11);
    func_80043A18(sector, &loc);
    do {
        rdy = func_80019A24((int *)&loc, (void *)LIST_BUF, 0x800, 0);
        if (rdy != 0) {
            break;
        }
        func_8004239C(0);
    } while (1);
    i = 2;

    sector += 1;
    q = &D_80062C38;
    pp = (CdlLOC *)q;
    /* sched fence: forces the `a1 = q` copy to be scheduled before the loop-pointer
     * init; without it gcc's list scheduler emits `addiu s1,s0,0x60` first. */
    __asm__ ("" : "=r"(q) : "0"(q));
    r = q + 0x60;
    func_80043A18(sector + *(s32 *)(LIST_BUF + 0x00), pp);
    func_80043A18(sector + *(s32 *)(LIST_BUF + 0x08), (CdlLOC *)(q + 0x30));
    do {
        pp = (CdlLOC *)r;
        r += 0x30;
        i++;
        func_80043A18(sector + *(s32 *)(LIST_BUF + 0x10), pp);
    } while (i < 9);

    q = &D_80062DE8;
    func_80043A18(sector + *(s32 *)(LIST_BUF + 0x18), (CdlLOC *)q);
    func_80043A18(sector + *(s32 *)(LIST_BUF + 0x20), (CdlLOC *)(q + 0x210));

    do {
        rdy = func_80019A24((int *)&D_80062C38, (void *)LIST_BUF, 0xE40, 0);
        if (rdy != 0) {
            break;
        }
        func_8004239C(0);
    } while (1);

    tbl = D_800AE830;
    lbv = (u8 *)LIST_BUF;
    fileIdx = 0;
    bufIdx = 0;
    outer = 0;
    locOff = 0;
    pCount = (s32 *)LIST_BUF;
    do {
        base = func_80043B1C((CdlLOC *)(&D_80062C68 + locOff));
        n = *pCount;
        pCount += 2;
        bufIdx++;
        j = 0;
        if (n > 0) {
            p = (CdlLOC *)((u32)(fileIdx * 8) + (u32)tbl);
            dstOff = fileIdx * 8;
            pOff = (s32 *)((u32)(bufIdx * 8) + (u32)lbv);
            srcOff = bufIdx * 8;
            do {
                if (*pOff != 0) {
                    func_80043A18(*pOff + base, p);
                    *(s32 *)(&D_800AE834 + dstOff) = *(s32 *)(0x80180004 + srcOff);
                }
                pOff += 2;
                srcOff += 8;
                pCount += 2;
                bufIdx++;
                p += 2;
                dstOff += 8;
                j++;
                fileIdx++;
            } while (j < n);
        }
        outer++;
        locOff += 0x30;
    } while (outer < 8);
}
