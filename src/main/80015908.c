/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Returns the glyph table entry for printable character ch (codes from 0x20):
 * attribute bit 0x80 selects the second table. */
extern u16 D_80062A78[];
extern u16 D_80062AF8[];

u16 *func_80015908(u8 ch, s32 attr)
{
    s32 first = 0x20;  /* first printable code; a variable rather than folded
                        * into the table address, as in retail */
    s32 index;

    switch (attr & 0x80) {
    case 0:
        return &D_80062A78[ch - first];
    case 0x80:
        index = ch - first;
        return &D_80062AF8[index];
    }
}
