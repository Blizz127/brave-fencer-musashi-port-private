/* Exact retail word export for [8001971C,80019930); EXE-verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (133/133 words at 0x8001971C). */
#include "psx_types.h"

typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;

typedef struct {
    CdlLOC pos;
    u32 size;
    char name[16];
} CdlFILE;

extern void func_80019990(void);
extern s32 func_80045374(CdlFILE *fp, char *name);
extern int func_8004239C(int mode);
extern s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern int func_80043B1C(CdlLOC *p);
extern CdlLOC *func_80043A18(int i, CdlLOC *p);

extern CdlFILE D_80063058;
extern u8 D_80062C38;
extern u8 D_80062C68;
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_80063074;
extern s32 D_800747D8;
extern u8 D_800AE830[];
extern u8 D_800AE834;

#define LIST_BUF 0x80180000

void func_8001971C(void) {
    CdlFILE *res;
    register int tries __asm__("$21");
    register u8 *pathBase __asm__("$18");
    register char *nameBase __asm__("$19");
    register int pathOff __asm__("$17");
    int offCopy;
    int dead[4];
    register u32 pathN __asm__("$21");
    int base;
    int n;
    int rdy;
    int fileIdx;
    int bufIdx;
    register int j __asm__("$19");
    register int outer __asm__("$21");
    int locOff;
    u8 *tbl;
    u8 *lbv;
    int dstOff;
    int srcOff;
    s32 *pCount;
    s32 *pOff;
    CdlLOC *p;

    func_80019990();
    tries = 0;
    do {
        res = (CdlFILE *)func_80045374(&D_80063058, (char *)&D_80063058 - 0x14);
        tries++;
        if (res != (CdlFILE *)-1) {
            break;
        }
    } while (tries < 0x10);

    pathN = 0;
    pathBase = &D_80062C38;
    nameBase = (char *)pathBase - 0x14;
    pathOff = 0;
    D_800747D0 = (res != (CdlFILE *)0);
    D_800747D4 = 1;
    D_80063074 = 0;
    D_800747D8 = 0;
    do {
        offCopy = pathOff;
        do {
            res = (CdlFILE *)func_80045374((CdlFILE *)(&D_80062C38 + offCopy), nameBase + offCopy);
        } while ((u32)((int)res + 1) < 2);
        pathN++;
        pathOff += 0x30;
    } while (pathN < 0x15);

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
