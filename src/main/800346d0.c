/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Stops every state-5 track playing sound key: the low half of key selects the
 * sound, a non-zero high half must also match the track's variant. */
typedef struct {
    u16 status;
    u16 unk2;
    u16 sound;
    u16 variant;
    u8  unk8[50];
    u8  voiceHeld[8];   /* 0x3A */
    u8  unk42[18];
} SoundTrack;           /* 0x54 bytes */

typedef struct {
    u8  unk0[0x54];
} SoundVoice;

typedef struct {
    SoundTrack tracks[8];
    SoundVoice voices[8];
} SoundState;

extern SoundState D_800A46E8;

extern void func_80030D80(SoundVoice *voice, s16 mode);

void func_800346D0(s32 key)
{
    SoundTrack *track = D_800A46E8.tracks;
    s32 t = 0;
    s16 sound = key;
    s32 i;

    for (; t < 8; t++, track++) {
        if (track->status == 5 && track->sound == sound &&
            ((key >> 16) == 0 || (key >> 16) == track->variant)) {
            for (i = 0; i < 8; i++) {
                if (track->voiceHeld[i]) {
                    func_80030D80(&D_800A46E8.voices[i], 0);
                }
            }
            track->status = 0;
        }
    }
}
