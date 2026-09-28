/* Overlay range [8013FFD8,8014032C) from MAIN.CD member 0012.
 * SHA256(span)=f2d9b0e4297ecba28273b1d51036de8b8e3118265c56d981dac5d0e0101005e4.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013FFD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_8017F434[];


/* func_8013FFD8 — 213 ins, double jump-table, per-location family (134 members). */

extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);

extern short D_80115128;

s32 func_8013FFD8(s16 arg0, s32 arg1, s32 *arg2) {

    extern u8  D_8017F41C[];
    /* block decl dropped — file-scope array decl covers (§8e) */
    extern u8  D_8017F440[];
    extern u8  D_8017F447[];
    extern u8  D_8017F448[];
    extern s32 D_8017F370;
    extern s32 D_8017F388[];
    extern char *D_8017F344;
    extern unsigned short D_8017F358[];
    extern u8 D_8017F3C8;
    extern u8 D_8017F3CC;
    extern u8 *D_8017F3D8;
    extern s32 D_8010F3C4[];
    extern s32 D_8010EDE8[];
    extern u8  D_80115143;
    extern void * D_801841FC;
    extern void * D_801841F8;
    s32 ret;

    *arg2 = 0x808080;
    ret = 0;

    switch (arg0) {                                   /* jtbl_801D8898 */
    case 0: {
        s16 s0 = (s16) arg1;
        if (s0 < 6) {
            if ((((s32 (*)(u8))func_80029178)(D_8017F41C[s0]) & 0xFF) == 0) {
                return 1;
            }
            ret = ((s32 *)&D_8017F370)[s0];
        }
        break;
    }
    case 1: {
        s16 v1 = (s16) arg1;
        if (v1 < 4) {
            ret = D_8017F388[v1];
        }
        break;
    }
    case 2:
        switch ((*(s16 *)&D_80115128)) {                         /* jtbl_801D88B8 */
        case 0: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_8017F344)[v1];
            }
            break;
        }
        case 1: {
            s16 v1 = (s16) arg1;
            if (v1 < 0xC) {
                s32 v3 = ((s32 (*)(u8, s32))func_800291B4)(((u8 *)&D_8017F434)[v1], arg1) & 0xFF;
                if (v3 == 0) {
                    return 1;
                }
                ret = D_8010EDE8[v3 * 3];
            }
            break;
        }
        case 2: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)((*(u8 * *)&D_801841FC)[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = (*(s32 * *)&D_801841F8)[s0];
            }
            break;
        }
        case 3: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)(D_8017F440[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = ((s32 *)D_8017F358)[s0];
            }
            break;
        }
        case 4: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_8017F3D8)[v1];
            }
            break;
        }
        }
        break;
    case 3: {
        s16 t = (s16) arg1;
        if (t <= 0) {
            s16 s0 = t + D_80115143;
            if (s0 != 0) {
                if ((((s32 (*)(u8, s32))func_800291B4)(D_8017F447[s0], arg1) & 0xFF) == 0) {
                    *arg2 = 0x804040;
                }
                ret = D_8010F3C4[s0];
            } else {
                ret = (*(s32 *)&D_8017F3C8);
            }
        }
        break;
    }
    case 5: {
        s16 v1 = (s16) arg1;
        if (v1 < 3) {
            ret = ((s32 *)&D_8017F3CC)[v1];
        }
        break;
    }
    case 6: {
        s16 s0 = (s16) arg1;
        if (s0 < 0x28) {
            s32 idx;
            if ((((s32 (*)(u8, s32))func_800291B4)(D_8017F448[s0], arg1) & 0xFF) == 0) {
                *arg2 = 0x804040;
            }
            idx = s0 + 1;
            ret = D_8010F3C4[idx];
        }
        break;
    }
    case 7: {
        s16 v1 = (s16) arg1;
        if (v1 < 5) {
            ret = ((s32 *)&D_8017F3D8)[v1];
        }
        break;
    }
    }
    return ret;
}
