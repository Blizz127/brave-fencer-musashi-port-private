/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Releases every voice keyed by track index (passing mode to the voice stop
 * routine) and clears the track's status. */
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

void func_8003350C(s32 index, s16 mode)
{
    SoundTrack *track = &D_800A46E8.tracks[index];
    SoundVoice *voice;
    s32 i;

    for (i = 0; i < 8; i++) {
        voice = &D_800A46E8.voices[i];
        if (track->voiceOn[i]) {
            track->voiceOn[i] = 0;
            voice->unk40 = 0;
            if (voice->unk4E) {
                func_80030D80(voice, mode);
            }
        }
    }
    track->status = 0;
}
