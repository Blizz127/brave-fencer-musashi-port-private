/* Complete SC02 scene buffer setup; independently matched ordinary C. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { int used; u32 *data; int other; } Buffer;
extern Buffer D_800AF634[];
extern u8 D_8011F7A8[];
extern unsigned short D_8011F7BC, D_8011F7BE;
extern u8 *func_80178004(u8 *,short,short);
#define P(p,o) (*(u8 **)((p)+(o)))
void func_80176144(short buffer)
{
    u8 *slot = D_8011F7A8 + buffer*4;
    u8 *packet = (u8 *)(D_800AF634[buffer].data + D_800AF634[buffer].used);
    P(slot,0x38) = packet;
    packet = func_80178004(packet,D_8011F7BC-23,D_8011F7BE+101);
    P(slot,0x40) = packet-20;
    packet += 20;
    D_800AF634[buffer].used += (packet-P(slot,0x38)) >> 2;
}
