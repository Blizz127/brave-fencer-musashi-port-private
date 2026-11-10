/* sc03_0098: func_80183A28 - dispatch through the 0x801A1898 table, then clamp x against actor 0x15E.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern void (*D_801A1898[])(void *);
typedef struct { u16 id; u16 pad; u16 pad2; s16 x; u8 rest[0x104]; } Ent;
extern Ent D_801202A0[];
typedef struct { u16 act; u16 kind; u16 pad; s16 x; u8 pad8[0xF8]; u16 flags; } Obj;
void func_80183A28(Obj *p) {
    s32 i;
    Ent *e;
    D_801A1898[p->kind](p);
    if (p->act != 0 && (p->flags & 0x1000)) {
        e = D_801202A0;
        for (i = 0; i < 0x60; i++, e++) {
            if (e->id == 0x15E) {
                if (p->x < e->x + 0xF0) {
                    p->x = e->x + 0xF0;
                }
                break;
            }
        }
    }
}
