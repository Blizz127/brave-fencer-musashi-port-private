/* Owner re-derivation from retail assembly (clean input set). */
/* Sound system start-up: library init, common attributes, channel and voice
 * tables, sequencer state, then the remaining sound subsystems. */
#include "psx_types.h"

typedef struct {
    s32 mask;
    s16 mvol_left;
    s16 mvol_right;
    s16 mode_left;
    s16 mode_right;
    s16 x_left;
    s16 x_right;
    s16 cd_left;
    s16 cd_right;
    s32 cd_reverb;
    s32 cd_mix;
    s16 ext_left;
    s16 ext_right;
    s32 ext_reverb;
    s32 ext_mix;
} SoundAttr;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[8];
    u8 unk10;
    u8 pad11[3];
    s32 unk14;
} SoundChannel;

typedef struct {
    s16 unk0;
    s16 pad2;
    s32 unk4;
    s16 pad8;
    s16 unkA;
    u8 padC[52];
    s32 unk40;
    u8 pad44[10];
    u8 unk4E;
    u8 pad4F;
    u8 unk50;
    u8 unk51;
    u8 pad52[2];
} SoundVoice;

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 pad6[66];
} SoundTrack;

typedef struct {
    s32 unk0;
    s32 unk4;
} SoundMode;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} SoundSlot;

extern SoundAttr D_800A4EA4;
extern s32 D_800A4E68;
extern s16 D_800A4E6C;
extern s16 D_800A4E6E;
extern u8 D_800A4E70;
extern u8 D_800A4F18;
extern u8 D_800A4F19;
extern s16 D_800A4EF6;
extern s32 D_800A463C;
extern s32 D_800A4638;
extern u8 D_800A4E7A;
extern u8 D_800A46E4;
extern SoundChannel D_800A4640[];
extern SoundSlot D_800A64B0[];
extern SoundVoice D_800A46E8[];
extern SoundVoice D_800A4988[];
extern SoundTrack D_800A4C68[];
extern s16 D_800A4EFA;
extern s16 D_800A4EF8;
extern u8 D_800A4F1B;
extern u8 D_800A46BA;
extern s32 D_800A2B98;
extern s32 D_800C7D20;
extern s32 D_800C7D2C;
extern s32 D_800A2BA0;
extern u8 D_800A4F17;
extern s16 D_800A4E8E;
extern s16 D_800A4EA2;
extern s16 D_800A4EF0;
extern s32 D_800A4EE8;
extern s16 D_800A4EFC;
extern s16 D_800A4F20;
extern s16 D_800A4F22;
extern u8 D_800A4F1D;
extern s32 D_800A4EEC;
extern u8 D_800A4EE6;
extern s16 D_800A4EE0;
extern s16 D_800A4EE4;
extern s32 D_800A4F24;
extern u8 D_800A4F16;
extern u8 D_800A4F1C;
extern u8 D_800A4F1E;

extern void func_8003A424(void);
extern void func_8003D518(void);
extern void func_8003C598(SoundAttr *attr);
extern void func_8003BE24(s32 on);
extern void func_8002D1F0(s32 n);
extern void func_8003B280(s32 on);
extern void func_80037D98(void);
extern void func_8002CC4C(void);
extern void func_8002FAE0(void);
extern void func_80037CC8(void);
extern void func_8003BE74(s32 on, s32 bits);
extern void func_8003B1EC(SoundMode *mode);
extern void func_80034C24(void);
extern void func_80037004(void);

void func_8002C8F4(void)
{
    SoundMode mode;
    s32 i;
    s32 n;
    SoundVoice *voice;

    func_8003A424();
    func_8003D518();
    D_800A4EA4.mask = 0x23CF;
    D_800A4EA4.mvol_left = 0x3FFF;
    D_800A4EA4.mvol_right = 0x3FFF;
    D_800A4EA4.cd_left = 0x3FFF;
    D_800A4EA4.cd_right = 0x3FFF;
    D_800A4EA4.mode_left = 0;
    D_800A4EA4.mode_right = 0;
    D_800A4EA4.cd_reverb = 0;
    D_800A4EA4.cd_mix = 1;
    D_800A4EA4.ext_mix = 0;
    func_8003C598(&D_800A4EA4);
    func_8003BE24(1);
    func_8002D1F0(4);
    func_8003B280(1);
    func_80037D98();
    D_800A4E68 = 60;
    D_800A4E6C = 47;
    D_800A4E6E = 47;
    D_800A4E70 = 1;
    D_800A4F18 = 1;
    D_800A4F19 = 1;
    D_800A4EF6 = 1;
    D_800A463C = 0x1010;
    D_800A4638 = 0;
    D_800A4E7A = 0;
    D_800A46E4 = 0;
    D_800A4640[0].unk14 = 0x10000;
    D_800A4640[1].unk14 = 0x14000;
    D_800A4640[2].unk14 = 0x18000;
    D_800A4640[3].unk14 = 0x39F00;
    for (i = 0; i < 8; i++) {
        D_800A64B0[i].unk0 = 0;
    }
    for (i = 0; i < 5; i++) {
        D_800A4640[i].unk10 = 1;
        D_800A4640[i].unk4 = 0;
        D_800A4640[i].unk2 = -1;
    }
    for (i = 0; i < 8; i++) {
        D_800A46E8[i].unk0 = 0;
    }
    voice = D_800A4988;
    for (n = 16, i = 0; i < 8; i++, n++, voice++) {
        voice->unk51 = i;
        voice->unkA = n;
        voice->unk4E = 0;
        voice->unk4 = 0;
        voice->unk40 = 0;
        voice->unk50 = 0;
        D_800A4C68[i].unk0 = n;
        D_800A4C68[i].unk4 = 0;
        D_800A4C68[i].unk5 = 0;
    }
    func_8002CC4C();
    D_800A4EFA = 127;
    D_800A4EF8 = 127;
    D_800A4F1B = 1;
    D_800A46BA = 0;
    D_800A2B98 = 0;
    D_800C7D20 = 0;
    D_800C7D2C = 0;
    D_800A2BA0 = 0;
    D_800A4F17 = 0;
    D_800A4E8E = 0;
    D_800A4EA2 = 0;
    D_800A4EF0 = 0;
    D_800A4EE8 = 0;
    D_800A4EFC = 0;
    D_800A4F20 = 0;
    D_800A4F22 = 0;
    D_800A4F1D = 0;
    D_800A4EEC = 0;
    D_800A4EE6 = 0;
    D_800A4EE0 = 0x4000;
    D_800A4EE4 = 0x4000;
    D_800A4F24 = 0;
    D_800A4F16 = 0;
    func_8002FAE0();
    func_80037CC8();
    func_8003BE74(0, 0xFFFFFF);
    mode.unk0 = 1;
    mode.unk4 = 0;
    func_8003B1EC(&mode);
    D_800A4F1C = 0;
    D_800A4F1E = 0;
    func_80034C24();
    func_80037004();
}
