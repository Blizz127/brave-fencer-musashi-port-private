/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Resets the three 16-byte channel records and re-applies each one. */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8  unkC;
    u8  unkD;
    u8  unkE;
    u8  unkF;
} Channel;

extern Channel D_800A5E88[3];

extern void func_80028620(s32 index, Channel *channel);

void func_8002823C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        D_800A5E88[i].unk0 = 0x800;
        D_800A5E88[i].unk4 = 0x800;
        D_800A5E88[i].unk8 = 0;
        D_800A5E88[i].unkC = 0x20;
        D_800A5E88[i].unkD = 0x20;
        D_800A5E88[i].unkE = 0x20;
        func_80028620(i, &D_800A5E88[i]);
    }
}
