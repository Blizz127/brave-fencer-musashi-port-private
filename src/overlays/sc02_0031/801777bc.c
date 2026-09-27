/* Complete SC02 retail span [801777BC,801778A8); independently matched ordinary C. */
typedef unsigned int u32;
typedef struct { u32 tag, color, xy, uv, unused; } Packet;
Packet *func_801777BC(Packet *packet, unsigned int digits, short x, short y, short count, short palette, short force)
{
    u32 hidden = 0x01000000;
    u32 clut = (((u32)(palette + 256) << 6) | 0x16) << 16;
    short i;
    for (i = 0; i < count; i++) {
        short digit = (digits << 16) >> 28;
        if (digit || i == count - 1 || i == force) hidden = 0;
        packet->tag = (((u32)packet - 20) & 0xFFFFFF) | 0x03000000;
        packet->xy = ((u32)y << 16) | (unsigned short)x | hidden;
        packet->color = 0x74808080;
        { u32 uv = (digit * 8 + 8) | 0x4000;
        packet->uv = clut | uv; }
        packet++;
        x += 8;
        digits <<= 4;
    }
    return packet;
}
