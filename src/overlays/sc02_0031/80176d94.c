/* Complete SC02 retail span [80176D94,80176FF4); independently matched mixed C. */
typedef unsigned char u8;
typedef unsigned int u32;
extern unsigned short D_8011F82C, D_8011F82A;
extern u8 *func_80177784(u8 *,u32,u32);
extern int func_801783D0(int,int);
extern u8 *func_801777BC(u8 *,short,short,short,int,int,int);
#define W(p,o) (*(u32 *)((p)+(o)))
#define XY(x,y) (((u32)(y)<<16)|(unsigned short)(x))
u8 *func_80176D94(u8 *packet, int x, short y)
{
    int digits, width, maximum;
    u32 position;
    register u8 *end __asm__("$2");
    packet = func_80177784(packet,XY(x,y),0x6B565040);
    packet = func_80177784(packet,XY(x+8,y),0x6B565808);
    packet = func_80177784(packet,XY(x+16,y),0x6B564060);
    packet = func_80177784(packet,XY(x+48,y),0x6B563858);
    digits = func_801783D0(D_8011F82C,4);
    packet = func_801777BC(packet,digits,x+24,y,3,173,255);
    digits = func_801783D0(D_8011F82A,4);
    __asm__ volatile("" : "=r"(x) : "0"(x));
    packet = func_801777BC(packet,digits,x+56,y,3,173,255);
    width = D_8011F82C;
    W(packet,0) = (((u32)packet-20)&0xFFFFFF)|0x03000000;
    W(packet,4) = 0x6000DCFF;
    position = XY(x+1,y+10);
    W(packet,8) = position;
    W(packet,12) = ((int)(width * 20710U) >> 16) | 0x20000;
    maximum = D_8011F82A;
    W(packet,20) = ((u32)packet&0xFFFFFF)|0x03000000;
    W(packet,40) = (((u32)packet+20)&0xFFFFFF)|0x03000000;
    W(packet,24) = 0x600000FF;
    end = packet+60;
    W(packet,28) = position;
    W(packet,44) = 0x60000000;
    W(packet,48) = XY(x,y+9);
    { int scaled = (int)(maximum * 20710U) >> 16;
    W(packet,32) = scaled | 0x20000;
    W(packet,52) = (scaled+2) | 0x40000;
    }
    __asm__ volatile("" : "=r"(end) : "0"(end));
    return end;
}
