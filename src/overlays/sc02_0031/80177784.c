/* Complete SC02 glyph helper; independently matched ordinary C. */
typedef unsigned int u32;
typedef struct { u32 tag, color, xy, uv, unused; } Packet;
Packet *func_80177784(Packet *packet, u32 xy, u32 uv)
{
    packet->tag = (((u32)packet - 20) & 0xFFFFFF) | 0x03000000;
    packet->color = 0x74808080;
    packet->xy = xy;
    packet->uv = uv;
    return packet + 1;
}
