/* Clean-room re-derivation from the retail disassembly only (B28): intro
 * movie overlay, walk a 16-byte record list ending at type 255. A type-9
 * record fills w halfwords with 0x7FFF, starting w halfwords into its buffer,
 * then uploads the rect {x,y,w,h} from that point (LoadImage 800599B8). */
#include "psx_types.h"

typedef struct {
    s16 x, y, w, h;
} Rect16;

typedef struct {
    u16 type;
    u16 pad;
    s16 x, y, w, h;
    u16 *buf;
} MovieRec;

extern s32 D_800EC69C;
extern void func_800599B8(Rect16 *, u16 *);

void func_800CFB3C(MovieRec *r) {
    Rect16 rc;
    u16 *p;
    s32 i;

    D_800EC69C = 0;
    while (r->type != 255) {
        if (r->type == 9) {
            p = r->buf + r->w;
            for (i = 0; i < r->w; i++) {
                *p++ = 0x7FFF;
            }
            p = r->buf + r->w;
            rc.x = r->x;
            rc.y = r->y;
            rc.w = r->w;
            rc.h = r->h;
            func_800599B8(&rc, p);
        }
        r++;
    }
}
