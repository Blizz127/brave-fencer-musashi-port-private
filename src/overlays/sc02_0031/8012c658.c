/* Complete SC02 retail span [8012C658,8012C750).
 * Matched C: Druthulu shared ov/func_8012C658.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

typedef struct {
    u16 pos_x;   /* +0x0 from parent +0x6 when parent present */
    u16 pos_y;   /* +0x2 from parent +0xA */
    u16 pos_z;   /* +0x4 from parent +0xE */
    s16 type_id; /* arg0 */
    s16 subtype; /* arg1 */
    s16 pad_a;
    s16 life;    /* 0x7FFF */
    s16 pad_e;
    s32 pad_10;
} ObjectSpawnParams;

extern u8 D_80126720[];
extern s32 func_8012C890(u16 *params, u16 *slot);

s32 func_8012C658(s32 type_id, s32 subtype, s32 parent) {
    ObjectSpawnParams sp;
    s32 result;
    u16 *slot;
    u16 *pool_end;
    u16 *params;

    if (parent != 0 && *(u16 *)(parent + 0x0) != 0) {
        sp.pos_x = *(u16 *)(parent + 0x6);
        sp.pos_y = *(u16 *)(parent + 0xA);
        sp.pos_z = *(u16 *)(parent + 0xE);
    } else {
        sp.pos_z = 0;
        sp.pos_y = 0;
        sp.pos_x = 0;
    }
    sp.type_id = (s16)type_id;
    sp.subtype = (s16)subtype;
    sp.pad_a = 0;
    sp.pad_10 = 0;
    sp.pad_e = 0;
    sp.life = 0x7FFF;

    params = &sp.pos_x;
    pool_end = (u16 *)D_80126720;
    if (parent == 0) {
        slot = (u16 *)((u8 *)pool_end - 0x6480);
    } else {
        slot = (u16 *)(parent + 0x10C);
    }
    while (slot != pool_end) {
        if (*slot == 0) {
            goto found;
        }
        slot = (u16 *)((u8 *)slot + 0x10C);
    }
    slot = 0;
found:
    result = 0;
    if (slot != 0) {
        result = func_8012C890(params, slot);
    }
    return result;
}
