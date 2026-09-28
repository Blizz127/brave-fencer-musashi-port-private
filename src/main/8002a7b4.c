/* Main-exec range [8002A7B4,8002A834) from the SLUS executable.
 * SHA256(span)=590cef177746254b28902f75022efff36ed302c753ee0466c344cebe2e296661.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002A7B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct {
    u16 unk00;
    u8 pad[14];
} Rec16;

extern s32 func_8002A834(s32 arg0);
extern s32 func_8002A998(void);
extern void func_8016E918(s16 a0, s16 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002AAAC(void);
extern Rec16 D_80063906[];

s32 func_8002A7B4(s32 arg0) {
    s32 id;

    if (func_8002A834(arg0) != 0) {
        id = func_8002A998();
        func_8016E918(2, (s16)(D_80063906[id].unk00 - D_80063906[id - 1].unk00));
        func_8002D4C8(0xB2C, 0);
        func_8002AAAC();
        return 1;
    }
    return 0;
}
