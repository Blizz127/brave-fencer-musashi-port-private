/* Complete SC02 packet builder; mixed C with empty register constraints. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int used; u32 *data; int other; } Buffer;
extern Buffer D_800AF634[];
extern u8 D_8011F7A8[], D_8011F7F0[], D_80188330[], D_800B9A13;
extern u16 D_80188380[], D_8018838C;
extern u8 D_80188420[], D_8018840C[];
extern void *D_80188438[];
extern u8 D_800D45D4[], D_800D43D4[], D_800D4414[];
extern u8 *func_8017742C(u8 *, short, short);
extern void func_8005A600(u8 *, int, int, int, int);
extern void func_800183E0(void *);
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define W(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
void func_80175DA8(short buffer)
{
    u8 *source = D_80188330;
    short i = 0;
    register u8 *values __asm__("$18") = D_8011F7F0;
    u8 *state = values - 0x48;
    u8 *packet = (u8 *)(D_800AF634[buffer].data + D_800AF634[buffer].used);
    u8 *tail = packet + 16;
    u8 *first;
    void *resource;
    u16 *table;
    register unsigned int amount __asm__("$4");
    register int shifted __asm__("$3");
    register int under __asm__("$3");
    register u8 *field __asm__("$4");
    int mask;
    register int offset __asm__("$2");
    u8 selected;
    P(state, 0x28 + buffer * 4) = packet;
    do {
        __asm__ volatile("" : "=r"(tail) : "0"(tail));
        W(packet,0) = (((u32)packet - 0x14) & 0xFFFFFF) | 0x04000000;
        W(tail,-12) = W(source,0); source += 4;
        if (i < 2) {
            H(tail,-8) = H(source,0) + H(state,12); source += 2;
            H(tail,-6) = H(source,0) + H(state,14); source += 2;
        } else if (i == 2) {
            H(tail,-8) = H(source,0) + H(state,16); source += 2;
            H(tail,-6) = H(source,0) + H(state,18); source += 2;
        } else {
            H(tail,-8) = H(source,0) + H(state,20); source += 2;
            H(tail,-6) = H(source,0) + H(state,22); source += 2;
        }
        W(tail,-4) = W(source,0); source += 4;
        W(tail,0) = W(source,0); source += 4;
        packet += 20; tail += 20;
        i++;
    } while (i < 5);
    state[7] = D_800B9A13;
    packet = func_8017742C(packet, H(state,16) - 152, H(state,18) + 9);
    func_8005A600(packet,0,0,22,0);
    W(packet,0) = (((u32)packet - 20) & 0xFFFFFF) | 0x02000000;
    P(state,0x30 + buffer * 4) = packet;
    packet += 20;
    D_800AF634[buffer].used += (packet - P(state,0x28 + buffer * 4)) >> 2;
    packet = P(state,0x28 + buffer * 4);
    if (values[0x48]) packet[13] = 0; else packet[13] = 160;
    first = P(state,0x28 + buffer * 4);
    H(first,0x22) = 0x6CD6;
    selected = values[0x48];
    if (selected & 0x80) {
        H(first,0x20) = D_8018838C;
        resource = D_800D45D4;
    } else {
        table = D_80188380;
        if (selected) { int index = selected - 1; __asm__ volatile("" : "=r"(index) : "0"(index)); table += index; }
        H(first,0x20) = *table;
        resource = D_80188438[values[0x48]];
    }
    func_800183E0(resource);
    field = P(state,0x28 + buffer * 4);
    shifted = (u32)H(values,0x2E) << 16;
    __asm__ volatile("" : "=r"(field) : "0"(field));
    __asm__ volatile("" : "=r"(shifted) : "0"(shifted));
    if (shifted) { offset = shifted >> 20; __asm__ volatile("" : "=r"(offset) : "0"(offset)); field[0x49] = D_80188420[offset]; }
    else field[0x49] = 160;
    amount = H(values,0x40);
    first = P(state,0x28 + buffer * 4);
    under = amount < 100;
    __asm__ volatile("" : "=r"(under) : "0"(under), "r"(amount));
    if (under) first[0x5D] = D_8018840C[(u16)(amount / 5U)];
    else first[0x5D] = 0;
    mask = *(short *)(values+0x1E) & 0x8000;
    __asm__ volatile("" : "=r"(mask) : "0"(mask));
    resource = D_800D43D4;
    if (mask) resource = D_800D4414;
    func_800183E0(resource);
}
