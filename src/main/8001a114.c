/* Exact retail word export for [8001A114,8001A338); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001A114 - byte-exact against retail at -O2 (tools/register_match.py). */
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
typedef struct {
    CdlLOC pos;      /* +0x00  file func_80010000 location */
    u32    size;     /* +0x04  file size in bytes   */
    char   name[16]; /* +0x08  file name            */
} CdlFILE;
extern CdlFILE *func_80045374(CdlFILE *fp, char *name);
extern void func_800434BC(void);
extern int  func_80043830(int com, u8 *param, u8 *result);
extern int  func_80046630(int mode);
extern int  func_8004674C(void);
extern s32     D_800AE6F4;
extern u8      D_800AE738;
extern u8      D_800AE740;
extern int     D_800AE750;
extern CdlFILE D_80063028;

int func_8001A114(void) {
    int ret;
    u8 *p;
    int r;
    int i;
    CdlFILE *fp;
    int *rp;
    s32 *sp;
    int c0;
    int c1;

    ret = 0;
    switch (D_800AE6F4) {
    case 0:
        func_800434BC();
        c0 = 1;
        __asm__ __volatile__("" : "=r"(c0) : "0"(c0));
        c1 = 0;
        __asm__ __volatile__("" : "=r"(c1) : "0"(c1));
        p = &D_800AE738;
        func_80043830(c0, (u8 *)c1, p);
        if ((*p & 0x10) != 0) {
            break;
        }
        D_800AE6F4 = D_800AE6F4 + 1;
        /* fallthrough */
    case 1:
        r = func_80046630(0);
        if (r == 2) {
            goto bump;
        }
        if (r != 0x10) {
            break;
        }
    reset:
        D_800AE6F4 = 0;
        break;
    case 2:
        p = &D_800AE740;
        *p = 0x80;
        if (func_80043830(0xE, p, p - 8) == 0) {
            break;
        }
        if ((p[-8] & 0x10) != 0) {
            goto reset;
        }
        D_800AE750 = 0;
        D_800AE6F4 = D_800AE6F4 + 1;
        break;
    case 3:
        rp = &D_800AE750;
        *rp = *rp + 1;
        if (*rp < 3) {
            break;
        }
        *rp = 0;
        D_800AE6F4 = D_800AE6F4 + 1;
        break;
    case 4:
        r = func_8004674C();
        if ((r == 1) || (r == 0x10) || (r == 0)) {
            D_800AE6F4 = 0;
        }
        if (r != 2) {
            break;
        }
    bump:
        sp = &D_800AE6F4;
        *sp = *sp + 1;
        break;
    case 5:
        i = 0;
        fp = &D_80063028;
        do {
            r = (int)func_80045374(fp, (char *)fp - 0x14);
            if (r != -1) {
                break;
            }
            i = i + 1;
        } while (i < 0x10);
        if ((u32)(r + 1) < 2) {
            goto reset;
        }
        ret = 1;
        break;
    }
    return ret;
}
