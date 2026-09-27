/* Complete SC02 retail span [8017742C,801775E0); mixed C independently matched. */
typedef struct { unsigned int tag; unsigned char r,g,b,code; short x,y,w,h; int pad; } Packet;
extern unsigned char D_8011F837, D_8011F7AB;
extern unsigned char D_8011F7F0[];
Packet *func_8017742C(Packet *input, int xin, int y)
{
    register Packet *next __asm__("$7") = input;
    register Packet *p __asm__("$8") = next;
    register int x __asm__("$9");
    unsigned int selected;
    int height;
    unsigned char *cycle;
    register unsigned char *values __asm__("$10") ;
    unsigned short bottom;
    __asm__ volatile("" : "=r"(p) : "0"(p));
    next->tag = (((unsigned int)next - 20) & 0xFFFFFF) | 0x03000000;
    next->code = 0x60;
    selected = D_8011F837;
    __asm__ volatile("" : "=r"(selected) : "0"(selected));
    values = D_8011F7F0;
    __asm__ volatile("" : "=r"(values) : "0"(values), "r"(next));
    x = xin;
    if (selected < 128) {
        next->r = 255;
        next->g = next->b = 16;
    } else if (selected == 128) {
        switch (D_8011F7AB) {
        default: D_8011F7AB = 0;
        case 0: p->r = 255; p->g = p->b = 48; break;
        case 1: next->g = 255; next->r = next->b = 48; break;
        case 2: next->b = 255; next->r = next->g = 48; break;
        }
        cycle = &D_8011F7AB;
        __asm__ volatile("" : "=r"(cycle) : "0"(cycle));
        (*cycle)++;
    } else {
        next->g = 255;
        next->r = next->b = 16;
    }
    next++;
    p->x = x;
    height = (values[0x47] * 3) >> 3;
    p->w = 8;
    bottom = y + 72;
    p->y = bottom - height;
    p->h = height;
    next->tag = (((unsigned int)next - 20) & 0xFFFFFF) | 0x03000000;
    next->code = 0x60;
    next->r = next->g = 64;
    p = next;
    if (values[0x47]) next->b = 160; else next->b = 64;
    __asm__ volatile("" : "=r"(p) : "0"(p));
    p->w = 8;
    p->h = 72;
    p->x = x;
    p->y = y;
    return next + 1;
}
