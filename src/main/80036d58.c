/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Stops the queued sound requests (func_80034DFC on each recorded handle),
 * then queues a new request for `mode` with its four callbacks and records
 * the returned handle. Does nothing for mode 0 unless D_800C6D28 is set. */
typedef struct {
    u8  active;
    u8  unk1;
    u8  unk2;
    u8  unk3;
    u8  unk4[3];
    u8  unk7;
    u32 start;  /* guest callback */
    s32 mode;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u32 update;
    s32 unk20;
    u32 stop;
    u32 finish;
    s32 slot;
} QueueEntry;   /* 0x30 bytes */

extern s32 D_800C6D28;
extern s32 D_8006AEE8;
extern s32 D_80078F10[];
extern u8  D_800A46BA;
extern u8  D_800A4F1A;
extern s16 D_800A4EF8;

extern void func_80035C4C(void);
extern void func_80036F98(void);
extern void func_8003602C(void);
extern void func_80036FB0(void);
extern void func_80034DFC(s16 handle);
extern s32  func_80034CF0(QueueEntry *req);
extern void func_8003EDE8(s32 channel, u8 left, u8 right);

void func_80036D58(s16 mode)
{
    QueueEntry req;
    s32 handle;
    s32 i;
    u8 volume;

    if (mode == 0 && D_800C6D28 == 0) {
        return;
    }
    D_800A46BA = 0;
    if (D_8006AEE8 != 0) {
        for (i = 0; i < D_8006AEE8; i++) {
            func_80034DFC(D_80078F10[i]);
            D_80078F10[i] = 0;
        }
        D_8006AEE8 = 0;
    }
    req.start = (u32)func_80035C4C;
    req.mode = mode;
    req.update = (u32)func_80036F98;
    req.unk20 = 0;
    req.stop = (u32)func_8003602C;
    req.finish = (u32)func_80036FB0;
    handle = func_80034CF0(&req);
    D_80078F10[D_8006AEE8] = handle;
    if (handle != 0) {
        D_8006AEE8++;
    }
    D_800A4F1A = 0;
    if (mode != 0) {
        D_800C6D28 = 0;
    }
    volume = (u32)(D_800A4EF8 * 97) >> 7;
    func_8003EDE8(0, volume, volume);
}
