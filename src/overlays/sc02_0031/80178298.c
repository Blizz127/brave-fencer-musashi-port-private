/* Complete SC02 glyph parser; independently matched ordinary C. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 tag,color; short x,y; u8 u,v; unsigned short clut,w,h; } Sprite;
Sprite *func_80178298(Sprite *packet, u8 *text, short x, short y)
{
    while (*text < 0x80) {
        switch (*(short *)text) {
        case 0x1850:
        case 0x1858:
            packet->x = x+4;
            packet->y = y-7;
            break;
        case 0x3870: x += 8; text += 2; continue;
        case 0x3871: x += 4; text += 2; continue;
        case 0x3872: x += 2; text += 2; continue;
        default:
            packet->x = x;
            packet->y = y;
            if (*(short *)text >= 0x861) x += 8; else x += 7;
            break;
        }
        packet->tag = (((u32)packet-20)&0xFFFFFF)|0x04000000;
        packet->color = 0x64808080;
        packet->u = *text++;
        packet->v = *text++;
        packet->clut = 0x4056;
        packet->h = packet->w = 8;
        packet++;
    }
    return packet;
}
