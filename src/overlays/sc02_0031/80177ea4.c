/* Complete SC02 retail span [80177EA4,80177F84); independently matched ordinary C. */
typedef unsigned int u32;
typedef struct { u32 tag, color, xy, uv, unused; } Packet;
Packet *func_80177EA4(Packet *packet, int digits, short x, short y)
{
    short i;
    u32 hidden = 0x01000000;
    for (i = 0; i < 7; i++) {
        short glyph;
        packet->tag = (((u32)packet - 20) & 0xFFFFFF) | 0x03000000;
        packet->color = 0x74808080;
        if (i != 0) {
            if (i == 6) {
                glyph = 1;
                hidden = 0;
            } else {
                glyph = ((digits >> 16) & 15) + 1;
                digits = (u32)digits << 4;
            }
            if (glyph != 1) hidden = 0;
            packet->xy = ((u32)y << 16) | (unsigned short)x | hidden;
        } else {
            glyph = 0;
            packet->xy = ((u32)y << 16) | (unsigned short)x;
        }
        packet->uv = (glyph << 3) | 0x6B564000;
        packet++;
        x += 8;
    }
    return packet;
}
