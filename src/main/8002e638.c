/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Starts sound cue id: through the sequencer when it is active, otherwise by
 * programming the fallback value registers. */
typedef struct {
    u16 channel;
    u16 unk2;
} CueVoice;

extern u16      D_800A4E8E;
extern s16      D_800A4E86;
extern s32      D_80078F10;
extern CueVoice D_8006A99C[];
extern u16      D_800A46B8;
extern s32      D_800A46B4;
extern u8       D_800A46BA;
extern u8       D_8006AEEC;
extern u16      D_800A4EF4;

extern s16  func_8003836C(s32 handle);
extern void func_8002E700(u16 id);

void func_8002E638(u16 id)
{
    u16 value;

    if ((D_800A4E8E & 4) && func_8003836C(D_800A4E86) != 0) {
        func_8002E700(id);
        return;
    }
    if (D_80078F10 != 0) {
        if (id < 5) {
            value = D_8006A99C[id].channel;
        } else {
            value = 31;
        }
        D_800A46B8 = value;
        value = D_8006AEEC;
        D_800A46B4 = 0xFFFF;
        D_800A46BA = 1;
        D_800A4EF4 = value;
    }
}
