/* Complete SC02 retail span [80146AFC,80146B9C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 D_8011D030;

s32 func_80146AFC(void *arg0) {
    u8 *p;
    u8 *q;
    u8 *end;

    p = (u8 *)&D_8011D030;
    end = p + 0xA50;
    if ((u32)p < (u32)end) {
        q = p + 0x30;
        do {
            if (*(u16 *)p == 0) {
                *(s32 *)(q + 0x4) = *(s32 *)((u8 *)arg0 + 0x8);
                *(s16 *)p = *(u16 *)((u8 *)arg0 + 0x0);
                *(s16 *)(q - 0x2A) = *(u16 *)((u8 *)arg0 + 0x2);
                *(s16 *)(q - 0x26) = *(u16 *)((u8 *)arg0 + 0x4);
                *(s16 *)(q - 0x22) = *(u16 *)((u8 *)arg0 + 0x6);
                *(s32 *)(q - 0x4) = *(s32 *)((u8 *)arg0 + 0xC);
                *(s32 *)(q + 0x0) = *(s32 *)((u8 *)arg0 + 0x10);
                return (s32)p;
            }
            p += 0x58;
            q += 0x58;
        } while ((u32)p < (u32)end);
    }
    return 0;
}
