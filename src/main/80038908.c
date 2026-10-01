/* Owner re-derivation from retail assembly (clean input set). */
/* Recomputes a sequence's output volume from the master volume, the music fade level and its track scale. */
#include "psx_types.h"

typedef struct {
    u16 scale;
    u8 pad2[6];
} SeqTrack;

typedef struct {
    u8 pad0[0x10];
    s16 volume;
    SeqTrack tracks[1];
} Sequence;

extern u16 D_800A4EE0;
extern s16 D_800A4EF8;

void func_80038908(Sequence *seq) {
    s32 volume;
    s32 i;
    SeqTrack *track;

    volume = D_800A4EF8 << 7;
    volume *= D_800A4EE0;
    volume >>= 14;
    track = seq->tracks;
    for (i = 0; i >= 0; i--, track++) {
        volume *= track->scale;
        volume >>= 14;
    }
    seq->volume = volume;
}
