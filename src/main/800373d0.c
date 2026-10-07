/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Applies the pending requests in the five-entry request table: each armed
 * request with a 0x3000 bit set updates the shared state and, unless bit
 * 0x1000 is set, starts its stream. */
typedef struct {
    u32 flags;
    u32 unk4;
    u8  ready;
    u8  armed;
    u8  unkA[6];
} Request;              /* 0x10 bytes */

typedef struct {
    s16 id;
    u16 unk2;
    u16 unk4;
    u16 state;
} ReqState;

typedef struct {
    u8 unk0[0x7000];
    u8 buffer[1];
} StreamWork;

extern Request    D_80076248[5];
extern ReqState   D_800A4E88;
extern StreamWork D_800BA320;
extern u16        D_80065438[];

extern void func_8002D7FC(StreamWork *work, u32 flags);
extern void func_8002FDE8(u16 file, u8 *dest);

void func_800373D0(void)
{
    s32 i;
    u32 flags;

    for (i = 0; i < 5; i++) {
        if (D_80076248[i].armed && D_80076248[i].ready) {
            flags = D_80076248[i].flags;
            if (!(flags & 0x3000)) {
                continue;
            }
            /* Same result as id = flags & 0xFFF. The extra stores fold away, but
             * they keep gcc from hoisting the D_80065438 base into a saved
             * register, which is what the retail code does (found by permuter). */
            D_800A4E88.id = 0xFFF;
            D_800A4E88.id = D_800A4E88.id;
            D_800A4E88.id &= flags;
            D_800A4E88.state |= 0x20;
            func_8002D7FC(&D_800BA320, flags);
            if (!(D_80076248[i].flags & 0x1000)) {
                func_8002FDE8(D_80065438[D_800A4E88.id], D_800BA320.buffer);
            }
        }
    }
}
