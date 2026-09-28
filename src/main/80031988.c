/* Exact retail word export for [80031988,80031A98); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80031988 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct Ent30D80 Ent30D80;
void func_80031988(Ent30D80 *arg0) {
    u16 *rec;
    s32 n;
    s32 base;

    rec = *(u16 **)((u8 *)arg0 + 0x14);
    if (rec != NULL) {
        n = *rec;
        switch (n) {
        case 0:
            n = rec[3];
            rec = (u16 *)rec[4];
            break;
        case 7:
            base = *(s32 *)((u8 *)arg0 + 0x20);
            n = rec[3] + base;
            rec = (u16 *)rec[4];
            break;
        case 5:
            n = rec[4];
            rec = (u16 *)rec[5];
            break;
        case 8:
            base = *(s32 *)((u8 *)arg0 + 0x20);
            n = rec[4] + base;
            rec = (u16 *)rec[5];
            break;
        case 1:
            n = rec[5];
            rec = (u16 *)rec[6];
            break;
        case 9:
            base = *(s32 *)((u8 *)arg0 + 0x20);
            n = rec[5] + base;
            rec = (u16 *)rec[6];
            break;
        case 6:
            n = rec[6];
            rec = (u16 *)rec[7];
            break;
        case 10:
            base = *(s32 *)((u8 *)arg0 + 0x20);
            n = rec[6] + base;
            rec = (u16 *)rec[7];
            break;
        default:
            return;
        }
        if (*(s32 *)((u8 *)arg0 + 0x24) != (n & 0xFFFF)) {
            *(u8 *)((u8 *)arg0 + 0x38) = 0;
            *(s32 *)((u8 *)arg0 + 0x28) = n & 0xFFFF;
            *(u8 *)((u8 *)arg0 + 0x37) |= 1;
            if (*(s32 *)((u8 *)arg0 + 0x24) > (n & 0xFFFF)) {
                *(s32 *)((u8 *)arg0 + 0x2C) = -(s32)rec;
            } else {
                *(s32 *)((u8 *)arg0 + 0x2C) = (s32)rec;
            }
        }
    }
}
