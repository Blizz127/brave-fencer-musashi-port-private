/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1E18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s32 unk00; /* +0x00 */
    s32 unk04; /* +0x04 */
    s32 unk08; /* +0x08 */
    s32 unk0C; /* +0x0C */
    s32 unk10; /* +0x10 */
    s32 unk14; /* +0x14 */
    s32 unk18; /* +0x18 */
    s32 unk1C; /* +0x1C */
} D_800D942C_entry;
extern D_800D942C_entry D_800D942C[];
extern u8 D_800EC9FC[];
extern s32 func_8001BFA0(void);
extern s32 func_80045374(void *fp, void *name);

s32 func_800D1E18(void) {
    return func_80045374(D_800EC9FC, (void *) D_800D942C[func_8001BFA0()].unk00) != 0;
}
