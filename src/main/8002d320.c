/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Shuts the sound voices down: releases pending voices, clears the
 * voice-key bits 16-23 of both channel masks for SPU 0 and 1, and frees
 * every allocated voice. */
typedef struct {
    u32 unk0;
    u32 flags;
    u8  unk8[0x38];
    s32 handle;
    u8  allocated;
    u8  pending;
    u8  unk46[2];
} Voice;        /* 0x48 bytes */

extern Voice D_800A4C28[8];
extern u32 D_800A2B98;
extern u32 D_800A2BA0;
extern u32 D_800C7D20;
extern u32 D_800C7D2C;

extern void func_8003D3B4(s32 handle, s32 mode);
extern void func_8003C23C(s32 spu, u32 mask);
extern void func_8003BE74(s32 spu, u32 mask);
extern void func_8003B250(s32 handle, Voice *voice);

void func_8002D320(void)
{
    Voice *voice;
    s32 i;
    u32 mask;

    voice = D_800A4C28;
    for (i = 0; i < 8; i++, voice++) {
        if (voice->pending) {
            if (!voice->allocated || !(voice->flags & 0x60000)) {
                func_8003D3B4(voice->handle, 1);
            }
            voice->pending = 0;
        }
    }
    mask = D_800A2B98 & 0xFF0000;
    if (mask) {
        func_8003C23C(0, mask);
        D_800A2B98 &= 0xFFFF;
    }
    mask = D_800A2BA0 & 0xFF0000;
    if (mask) {
        func_8003BE74(0, mask);
        D_800A2BA0 &= 0xFFFF;
    }
    voice = D_800A4C28;
    for (i = 0; i < 8; voice++, i++) {
        if (voice->allocated) {
            voice->allocated = 0;
            func_8003B250(voice->handle, voice);
            voice->flags = 0;
        }
    }
    mask = D_800C7D20 & 0xFF0000;
    if (mask) {
        func_8003C23C(1, mask);
        D_800C7D20 &= 0xFFFF;
    }
    mask = D_800C7D2C & 0xFF0000;
    if (mask) {
        func_8003BE74(1, mask);
        D_800C7D2C &= 0xFFFF;
    }
}
