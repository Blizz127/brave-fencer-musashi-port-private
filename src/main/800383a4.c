/* Clean-room re-derivation from the retail disassembly only (B27): keys off every voice a sequence's tracks hold. */
#include "psx_types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x5D];
    /* 0x5D */ u8 unk5D;
    /* 0x5E */ u8 unk5E;
    /* 0x5F */ u8 unk5F;
} Voice;

extern u8 D_800A4F1D;
extern u8 D_800B9CD8[];
extern Voice D_800C6DD0[];
extern s32 D_80073140[];
extern void func_8003916C(s16 index);
extern void func_8002EFF8(s32 mode, s32 bits);

void func_800383A4(s32 seq) {
    u8 *base = D_800B9CD8 + seq * 508;
    u8 *track = base + 26;
    u8 *used;
    u8 *state;
    s32 i;
    s32 j;

    D_800A4F1D = 1;
    base[506] = 0;
    for (i = 0; i < 16; i++) {
        used = track + 9;
        for (j = 0, state = &D_800C6DD0[0].unk5D; j < 16; j++, state += 0x60) {
            if (*used++ != 0) {
                state[1] = 1;
                state[0] = 0;
                func_8003916C(j);
                func_8002EFF8(0, D_80073140[j]);
            }
        }
        track += 26;
    }
    D_800A4F1D = 0;
}
