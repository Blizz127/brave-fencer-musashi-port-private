/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Requests release of every playing track (status 5) that plays sound
 * id = (s16)key, optionally restricted to variant key >> 16. A type-6 sound
 * definition is first resolved through the lookup table (func_8002F4E4) to
 * pick the definition whose type is checked; nothing happens below id 256.
 * The sound lock is held while scanning. */
typedef struct {
    u8 type;
    u8 unk1[3];
} SoundDef;

typedef struct {
    u16 status;
    u16 unk2;
    u16 sound;
    u16 variant;
    u8  unk8[14];
    u8  release;
    u8  unk17[61];
} SoundTrack;   /* 0x54 bytes */

typedef struct {
    SoundTrack tracks[8];
    u8  unk2A0[0x58F];
    u8  lock;
} SoundState;

extern SoundDef   D_8006451C[];
extern SoundState D_800A46E8;
extern s32 func_8002F4E4(SoundDef *def);  /* returns a u16 entry, 0 = none */

void func_8003491C(s32 key)
{
    s16 id = key;
    s16 variant = (u32)key >> 16;
    s16 sound = key;
    SoundDef *def = &D_8006451C[id];
    SoundTrack *track;
    u8 locked;
    s32 type;
    s32 i;

    if ((def->type & 0x7F) == 6) {
        sound = func_8002F4E4(def);
        if (sound == 0) {
            return;
        }
        def = &D_8006451C[sound];
    }
    if (sound < 256) {
        return;
    }
    locked = D_800A46E8.lock;
    D_800A46E8.lock = 1;
    type = def->type & 0x7F;
    if (type != 1 && type == 5) {
        track = D_800A46E8.tracks;
        for (i = 0; i < 8; i++, track++) {
            if (track->status == 5 && track->sound == id &&
                (variant == 0 || variant == track->variant)) {
                track->release = 1;
            }
        }
    }
    D_800A46E8.lock = locked;
}
