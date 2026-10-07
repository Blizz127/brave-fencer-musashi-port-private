/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Queues a request in the four-entry ring at D_80076118 with the queue lock
 * (D_8006AEF5) held. Returns 0 when the ring is full, otherwise the queued
 * slot index + 1. */
typedef struct {
    u8  active;
    u8  unk1;
    u8  unk2;
    u8  unk3;
    u8  unk4[3];
    u8  unk7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 slot;
} QueueEntry;   /* 0x30 bytes */

extern s32        D_8006AEFC;
extern u8         D_8006AEF5;
extern s32        D_8006AEF8;
extern QueueEntry D_80076118[4];

s32 func_80034CF0(QueueEntry *req)
{
    s32 next = D_8006AEFC;
    u8 locked = D_8006AEF5;
    s32 head = D_8006AEF8;
    QueueEntry *entry;
    s32 slot;

    D_8006AEF5 = 1;
    next++;
    if (next >= 4) {
        next = 0;
    }
    if (next == head) {
        D_8006AEF5 = locked;
        return 0;
    }
    entry = &D_80076118[D_8006AEFC];
    entry->unk8 = req->unk8;
    entry->unkC = req->unkC;
    entry->unk10 = req->unk10;
    entry->unk14 = req->unk14;
    entry->unk18 = req->unk18;
    entry->unk1C = req->unk1C;
    entry->unk20 = req->unk20;
    entry->unk24 = req->unk24;
    entry->unk28 = req->unk28;
    entry->active = 1;
    entry->unk1 = 0;
    entry->unk2 = 0;
    entry->unk3 = 0;
    entry->unk7 = 1;
    slot = D_8006AEFC;
    entry->slot = slot;
    D_8006AEFC = next;
    D_8006AEF5 = locked;
    return slot + 1;
}
