/* Exact retail word export for [80036D58,80036EB4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80036D58 - byte-exact against retail at -O2 (tools/register_match.py). */
#define CdIntToPos func_80043A18
#define CdPosToInt func_80043B1C
#define CdSearchFile func_80045374
typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;
typedef struct {
    CdlLOC pos;
    u32    size;
    char   name[16];
} CdlFILE;
extern CdlFILE *CdSearchFile(CdlFILE *fp, char *name);
extern int      CdPosToInt(CdlLOC *p);
extern CdlLOC  *CdIntToPos(int i, CdlLOC *p);
typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
} CdReq;











extern s32 D_8006AEE8;
extern s32 D_80078F10;
extern s32 D_800C6D28;
extern u8 D_800A46BA;
extern u8 D_800A4F1A;
extern s16 D_800A4EF8;

extern s32 func_80034CF0(u8 *);
extern void func_80034DFC(s16);
extern s32 func_8003EDE8(s32, s32, s32);
extern s32 func_80035C4C();    /* §376: def returns s32 and takes (s32) */
extern void func_80036F98(void);
extern void func_8003602C(s32);   /* §376: the definition takes s32 (the use is address-taken and already cast) */
extern void func_80036FB0(s32, s32);

void func_80036D58(s16 arg0)
{
    CdReq req;
    s32 pad[2];
    s32 i;
    s16 *p;
    s32 r;
    s32 n;
    s32 cnt;

    if (arg0 != 0 || D_800C6D28 != 0) {
        D_800A46BA = 0;
        if (D_8006AEE8 != 0) {
            i = 0;
            if (D_8006AEE8 > 0) {
                p = (s16 *)&D_80078F10;
                do {
                    func_80034DFC(*p);
                    i++;
                    cnt = D_8006AEE8;
                    *(s32 *)p = 0;
                    p += 2;
                } while (i < cnt);
            }
            D_8006AEE8 = 0;
        }
        req.f08 = (s32)func_80035C4C;
        req.f0c = arg0;
        req.f1c = (s32)func_80036F98;
        req.f20 = 0;
        req.f24 = (s32)func_8003602C;
        req.f28 = (s32)func_80036FB0;
        r = func_80034CF0((u8 *)&req);
        n = D_8006AEE8;
        (&D_80078F10)[n] = r;
        if (r != 0) {
            D_8006AEE8 = n + 1;
        }
        D_800A4F1A = 0;
        if (arg0 != 0) {
            D_800C6D28 = 0;
        }
        func_8003EDE8(0, ((u32)D_800A4EF8 * 97) >> 7 & 0xFF, ((u32)D_800A4EF8 * 97) >> 7 & 0xFF);
    }
}
