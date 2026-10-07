/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Draws the queued on-screen text (type 1) and number (type 2) requests of
 * the game state into the current frame's ordering table, then adds a
 * draw-mode primitive for the 320x256 texture page. Does nothing while state
 * byte 0xA3E1 is 1. */
typedef struct {
    s16 type;
    u8  unk2[14];
} TextReq;      /* 0x10 bytes */

typedef struct {
    u32 addr : 24;
    u32 len : 8;
} PrimTag;

typedef struct {
    PrimTag tag;
    u32 code;
} DrawModePrim;

typedef struct {
    u32 ot;     /* guest PrimTag * */
    u8 unk4[16];
} FrameBuffer;  /* 0x14 bytes */

extern u8 D_800AF630[];
extern FrameBuffer D_800A651C[];
extern u32 D_800A5E60; /* guest pointer: next free primitive */

extern void func_80015608(TextReq *req, PrimTag *ot);
extern void func_80015760(TextReq *req, PrimTag *ot);
extern u16  func_80058B40(s32 tp, s32 abr, s32 x, s32 y);

void func_80015498(void)
{
    u8 *state = D_800AF630;
    PrimTag *ot = (PrimTag *)D_800A651C[*(u16 *)(state + 0xA3D2)].ot;
    TextReq *req;
    DrawModePrim *prim;

    if (*(u8 *)(state + 0xA3E1) == 1) {
        return;
    }
    for (req = (TextReq *)(state + 0x9DA8); req < (TextReq *)(state + 0xA1A8); req++) {
        switch (req->type) {
        case 1:
            func_80015608(req, ot);
            break;
        case 2:
            func_80015760(req, ot);
            break;
        case 0:
            break;
        }
    }
    prim = (DrawModePrim *)D_800A5E60;
    prim->tag.len = 1;
    prim->code = 0xE1000000 | (func_80058B40(0, 0, 320, 256) & 0x9FF);
    prim->tag.addr = ot->addr;
    ot->addr = (u32)prim;
    D_800A5E60 += 8;
}
