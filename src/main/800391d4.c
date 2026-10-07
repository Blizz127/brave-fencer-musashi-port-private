/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Releases every sequencer voice that plays `key` for the given track:
 * clears its note-on mark in the owning sequence, keys the SPU voice off
 * (mask moved from the key-on set to the key-off set) and marks the voice
 * released. */
typedef struct {
    u8 unk0[35];
    u8 noteOn[16];
    u8 unk33[3];
} SeqTrack;     /* 0x1A bytes, overlapping rows */

typedef struct {
    u8  unk0[4];
    s16 key;
    s16 track;
    u8  unk8[0x48];
    u32 seq;    /* guest u8 *: owning sequence */
    u8  unk54[6];
    u8  owned;
    u8  unk5B[5];
} SeqVoice;     /* 0x60 bytes */

extern SeqVoice D_800C6DD0[16];
extern u32 D_80073140[16];
extern u32 D_800C7D20;
extern u32 D_800A2B98;
extern u8 *D_800762B0;
extern u8  D_800762B4[16];

void func_800391D4(u8 *seq, s16 key, s16 track)
{
    s32 i;
    SeqVoice *voice;
    u32 mask;
    u8 *row;
    u8 *vrow;

    for (i = 0; i < 16; i++) {
        row = seq + track * 26;
        if ((row + i)[35] == 0) {
            continue;
        }
        if (D_800C6DD0[i].key != key) {
            continue;
        }
        voice = &D_800C6DD0[(s16)i];
        if (voice->owned) {
            vrow = (u8 *)voice->seq + voice->track * 26;
            (vrow + (s16)i)[35] = 0;
            voice->owned = 0;
        }
        mask = D_80073140[i];
        D_800C7D20 &= ~mask;
        D_800A2B98 |= mask;
        D_800762B0[i] = 2;
        D_800762B4[i] = 0;
    }
}
