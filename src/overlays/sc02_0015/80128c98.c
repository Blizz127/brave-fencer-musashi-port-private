/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128C98 - byte-exact against retail at -O2 (tools/register_match.py). */
#define cdFileLocTable D_800AE830
typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
typedef CdFileLoc CdFileLoc_80128C98;
extern s32 D_8018DE8C;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern int D_8018DE8C;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);
extern CdFileLoc_80128C98 cdFileLocTable[];

s32 func_80128C98(s32 arg0) {

    extern s16 D_8017E4F4[];
    s16 idx = D_8017E4F4[arg0];

    if (idx >= 0) {
        func_8001ABBC(0, 0, (u8 *)&cdFileLocTable[idx], D_8018DE8C, 0);
    } else {
        return 1;
    }
}
