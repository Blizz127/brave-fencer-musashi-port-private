/* Overlay range [80153978,801539F8) from MAIN.CD member 0012.
 * SHA256(span)=e45b24cb1096642c9f5441bb042f195cf6ed026e7e0612d8de1a42cd190c9b46.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80153978 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} Buf80153978;
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 arg0, void *arg1, s32 arg2);
extern int func_80133784(int a0, void *a1, int a2);
s32 a1;
s32 a2;
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern s32 func_801539F8(s32 a0, void *a1);

s32 func_80153978(s32 a0, u16 *src) {
    Buf80153978 buf;
    buf.unk0 = src[0];
    buf.unk2 = src[1] + 0x1F;
    buf.unk4 = src[2];
    if (func_80133784(0, src, (s32)&buf) == 0x2000 &&
        buf.unk6 == 0 &&
        func_801539F8(a0, &buf) == 0) {
        return 0;
    }
    return 1;
}
