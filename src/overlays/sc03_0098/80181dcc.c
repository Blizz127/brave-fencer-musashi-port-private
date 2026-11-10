/* sc03_0098: func_80181DCC - snap an object next to the nearest actor 0x17F, or free it.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
typedef struct { u16 id; u8 p2[2]; s32 v[3]; u8 rest[0xFC]; } E;
extern E D_801202A0[];
extern s32 func_8012BC60();
extern s32 func_8012B6D4();
extern void func_8012B0B4();
extern s32 func_8012CEB0();
extern void func_8012ADE4();
typedef struct {
    u8 pad0[4]; u8 a4[2]; u16 x; u8 p8[2]; u16 y; u8 pc[2]; u16 z; u8 pad10[0x2A];
    u16 f3a; u8 p3c[2]; u16 f3e; u8 p40[2]; u16 f42;
} Obj;
void func_80181DCC(Obj *p) {
    s32 i;
    E *e;
    s16 q[4];
    s16 r[4];
    s32 d;
    s32 *dp;
    u8 *p4;
    e = D_801202A0;
    i = 0;
    p4 = p->a4;
    dp = &d;
    for (; i < 0x60; i++, e++) {
        if (e->id == 0x17F && (E *)p != e) {
            if (func_8012BC60(p4, e->v) < 0x1000) {
                func_8012B0B4(dp, func_8012B6D4(p4, e->v), 0x41);
                {
                    u16 *hp = (u16 *)&e->v[2] + 1;
                    r[0] = hp[-4];
                    r[1] = hp[-2];
                    r[2] = hp[0];
                    r[0] = r[0] + d;
                    r[2] = r[2] + (d >> 16);
                }
                q[0] = p->f3a;
                q[1] = p->f3e;
                q[2] = p->f42;
                if ((func_8012CEB0(q, r, 0) & 0x2000) == 0) {
                    func_8012ADE4(p);
                } else {
                    p->x = r[0];
                    p->y = r[1];
                    p->z = r[2];
                }
                return;
            }
        }
    }
}
