/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Stops track index: a playing track (state 1) releases its voices and clears
 * its status, a state-5 track is handed to its own stop routine. */
typedef struct {
    u16 status;
    u8  unk2[12];
    u8  voiceOn[8];
    u8  unk16[62];
} SoundTrack;

typedef struct {
    u8  unk0[0x40];
    s32 unk40;
    u8  unk44[10];
    u8  unk4E;
    u8  unk4F[5];
} SoundVoice;

typedef struct {
    SoundTrack tracks[8];
    SoundVoice voices[8];
} SoundState;

extern SoundState D_800A46E8;

extern void func_80030D80(SoundVoice *voice, s16 mode);
extern void func_80034650(SoundTrack *track, s32 arg1);

void func_8003324C(u16 index)
{
    SoundTrack *track = &D_800A46E8.tracks[index];
    SoundVoice *voice;
    s32 i;

    switch (track->status & 0x3F) {
    case 1:
        for (i = 0; i < 8; i++) {
            voice = &D_800A46E8.voices[i];
            if (track->voiceOn[i]) {
                track->voiceOn[i] = 0;
                voice->unk40 = 0;
                if (voice->unk4E) {
                    func_80030D80(voice, 0);
                }
            }
        }
        track->status = 0;
        break;
    case 5:
        func_80034650(track, 0);
        break;
    }
}
