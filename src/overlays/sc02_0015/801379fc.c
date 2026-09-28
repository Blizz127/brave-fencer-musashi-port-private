/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801379FC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80127524;
extern s32 D_80127548[];
extern s32 D_801269F0;
extern s16 D_801269F4;
extern s32 D_801269F8;
extern void func_80138BE0(s32 a0);
extern void func_80137BD8(s32 a0);
extern void func_8013A380(void);

void func_801379FC(void) {
    s32 i;
    (*(s32 *)D_80127548) = 0x24;
    if ((D_80127524 != 0) && (*(s32 *)D_80127524 != 0)) {
        s32 p;
        s32 idx;
        func_80138BE0(D_80127524);
        i = 0;
        p = (s32)&D_801269F0;
        idx = 0;
        do {
            if ((p != D_80127524) && (*(s32 *)((s32)&D_801269F0 + idx) != 0)) {
                func_80138BE0(p);
            }
            p = p + 0x4c;
            i = i + 1;
            idx = idx + 0x4c;
        } while (i < 3);
    } else {
        s32 p;
        s32 idx;
        i = 0;
        p = (s32)&D_801269F0;
        idx = 0;
        do {
            if (*(s32 *)((s32)&D_801269F0 + idx) != 0) {
                func_80138BE0(p);
            }
            p = p + 0x4c;
            i = i + 1;
            idx = idx + 0x4c;
        } while (i < 3);
    }
    {
        s32 p;
        s32 idx;
        s32 flags;
        i = 0;
        p = (s32)&D_801269F0;
        idx = 0;
        do {
            if (*(s16 *)((s32)&D_801269F4 + idx) != 0) {
                if (*(s32 *)((s32)&D_801269F0 + idx) != 0) {
                    flags = *(s32 *)((s32)&D_801269F8 + idx);
                    if ((flags & 0x1000) != 0) {
                        if ((flags & 0x2000) == 0) {
                            func_80137BD8(p);
                        }
                    }
                }
            }
            p = p + 0x4c;
            i = i + 1;
            idx = idx + 0x4c;
        } while (i < 3);
    }
    func_8013A380();
}
