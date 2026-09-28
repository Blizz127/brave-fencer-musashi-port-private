/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3BC - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C
typedef void (*code)(unsigned short *);
extern void func_80149350(s32);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_80017E68(void *a0, void *a1);
extern void func_800D23D0(void *a0);
extern void RotMatrixYXZ(void *a0, void *a1);
extern s32  func_80017758(void *a0, void *a1);
typedef struct { s16 x, y, z, pad; } SVec_800CB3BC;
typedef struct {
      u16 cx, cy, cz;
      u16 _p06;
      u16 a8[4];
      s32 pos[3];
      s32 _p1C;
      SVec_800CB3BC v[4];
      struct { u8 r, g, b, cd; } col[4];
      u32 code;
      s32 _p54;
      u8 m1[0x20];
      u8 m2[0x20];
} Fr_800CB3BC;

void func_800CB3BC(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {

    extern u8  D_800CB820[];
    extern u16 D_800CB7FC[];
    Fr_800CB3BC f;
    register u8  *p   __asm__("$18");    
    register s32  ent __asm__("$20");    
    s16 i;
    s32 node;
    u16 c;
    u8  cv;
    u8  *va;
    u8  *vb;
    u16 *q;

    ent = arg0;
    node = *(s32 *)(ent + 0x34);
    f.v[1].z = 0;
    f.v[1].y = 0;
    f.v[1].x = 0;
    f.v[3].z = 0;
    f.v[2].z = 0;
    f.v[0].z = 0;
    f.col[1].b = 0x70;
    cv = *(u8 *)(ent + 0x12);
    f.cx = arg1;
    __asm__ __volatile__("");
    va = (u8 *)&f.cx;
    __asm__ __volatile__("" : "=r"(va) : "0"(va));
    f.cy = arg2;
    vb = va;
    __asm__ __volatile__("" : "=r"(vb) : "0"(vb));
    p = D_800CB820;
    i = 0;
    f.col[0].b = 0;
    f.col[0].g = 0;
    f.col[0].r = 0;
    f.col[2].b = 0;
    f.col[2].g = 0;
    f.col[2].r = 0;
    f.col[3].b = 0;
    f.col[3].g = 0;
    f.col[3].r = 0;
    f.code = 0x50000000;
    f.cz = arg3;
    f.col[1].r = cv;
    f.col[1].g = cv;
    ((void (*)(s32, void *, void *))func_80149350)(node, va, vb);

    c = f.cx;
    *(s16 *)(ent + 0x06) = c;
    *(s32 *)(ent + 0x4C) = (s16)c;
    c = f.cy;
    *(s16 *)(ent + 0x0A) = c;
    *(s32 *)(ent + 0x50) = (s16)c;
    c = f.cz;
    *(s16 *)(ent + 0x0E) = c;
    *(s32 *)(ent + 0x54) = (s16)c;
    func_800D20C0(&f.cx, f.a8, 8);
    func_80017E68(&f.cx, f.m1);
    func_800D23D0(f.a8);
    RotMatrixYXZ(f.a8, f.m1);

    do {
        f.v[0].x = (s8)*p++;
        f.v[0].y = (s8)*p++;
        f.v[2].x = (s8)*p++;
        f.v[2].y = (s8)*p++;
        f.v[3].x = (s8)*p++;
        f.v[3].y = (s8)*p--;
        func_80017758(f.v, f.m1);
    } while ((i = i + 1) < 4);

    q = D_800CB7FC;
    i = 0;
    f.v[1].z = 0x50;
    f.col[1].b = 0xA0;
    f.v[3].y = 0;
    f.v[2].y = 0;
    f.v[0].y = 0;
    f.col[1].g = 0x10;
    f.col[1].r = 0x10;

    do {
        f.v[0].x = *q++;
        f.v[0].z = *q++;
        f.v[2].x = *q++;
        f.v[2].z = *q++;
        f.v[3].x = *q++;
        f.v[3].z = *q--;
        func_80017758(f.v, (void *)(ent + 0x38));
    } while ((i = i + 1) < 4);
}
