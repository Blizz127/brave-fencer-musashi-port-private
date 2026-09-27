/* SC02.CD FILE_031 / ov_SC02_031 retail span [801787D4,80178840).
 * Offset 0x5067C at overlay base 80128158. SHA256(span)=7ea9953cc0d7c4e0b6ad71ced335096b4b6854a3d882bd09bd8dc7b46feacaa5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801787d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80178840();
extern u8 D_801202A0[];
typedef struct { u16 id; u8 pad2[0xBE]; u8 uC0; u8 padC1[0x4B]; } S;
void func_801787D4(void) {
    S *s;
    s32 i;
    s = (S *)D_801202A0;
    for (i = 0; i < 0x60; i++, s++) {
        if (s->id && s->uC0) {
            func_80178840(s);
        }
    }
}
