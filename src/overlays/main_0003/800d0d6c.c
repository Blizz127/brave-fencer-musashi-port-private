/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0D6C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern u8 D_800AA60C[];
extern u32 D_800EC8B4;
extern u8  D_800EC8B7;
extern u32 D_800EC8B8;
extern u8  D_800EC8BC;
extern u8  D_800EC8BD;
extern u8  D_800EC8BE;
extern u8  D_800EC8BF;
extern s16 D_800EC8C0;
extern s16 D_800EC8C2;
extern u8  D_800EC8C4;
extern u8  D_800EC8C5;
extern s16 D_800EC8C6;
extern s16 D_800EC8C8;
extern s16 D_800EC8CA;
extern u32 D_800EC8CC;
extern u8  D_800EC8CF;
extern u32 D_800EC8D0;
extern u8  D_800EC8D4;
extern u8  D_800EC8D5;
extern u8  D_800EC8D6;
extern u8  D_800EC8D7;
extern s16 D_800EC8D8;
extern s16 D_800EC8DA;
extern u8  D_800EC8DC;
extern u8  D_800EC8DD;
extern s16 D_800EC8DE;
extern s16 D_800EC8E0;
extern s16 D_800EC8E2;
extern s16 D_800EC894;
extern u32 D_800EC944;
extern u8  D_800EC947;
extern u32 D_800EC948;
extern u8  D_800EC94C;
extern u8  D_800EC94D;
extern u8  D_800EC94E;
extern u8  D_800EC94F;
extern s16 D_800EC950;
extern s16 D_800EC952;
extern u8  D_800EC954;
extern u8  D_800EC955;
extern s16 D_800EC956;
extern s16 D_800EC958;
extern s16 D_800EC95A;
extern u32 D_800EC98C;
extern u8  D_800EC98F;
extern u32 D_800EC990;
extern u8  D_800EC994;
extern u8  D_800EC995;
extern u8  D_800EC996;
extern u8  D_800EC997;
extern s16 D_800EC998;
extern s16 D_800EC99A;
extern u8  D_800EC99C;
extern u8  D_800EC99D;
extern s16 D_800EC99E;
extern s16 D_800EC9A0;
extern s16 D_800EC9A2;

void func_800D0D6C(void) {
    typedef struct {
        unsigned int addr : 24;
        unsigned int len : 8;
    } PrimTag;

    register u8 *base = D_800AF630;

    D_800EC8B7 = 5;
    D_800EC8B8 = 0xE100010A;
    D_800EC8BF = 0x64;
    D_800EC8BE = 0x80;
    D_800EC8BD = 0x80;
    D_800EC8BC = 0x80;
    D_800EC8C0 = -0xA0;
    D_800EC8C2 = -0x78;
    D_800EC8C4 = 0;
    D_800EC8C5 = 0;
    D_800EC8C6 = 0x7800;
    D_800EC8C8 = 0x100;
    D_800EC8CA = 0xF0;

    D_800EC8CF = 5;
    D_800EC8D0 = 0xE100010E;
    D_800EC8D7 = 0x64;
    D_800EC8D6 = 0x80;
    D_800EC8D5 = 0x80;
    D_800EC8D4 = 0x80;
    D_800EC8D8 = 0x60;
    D_800EC8DA = -0x78;
    D_800EC8DC = 0;
    D_800EC8DD = 0;
    D_800EC8DE = 0x7800;
    D_800EC8E0 = 0x40;
    D_800EC8E2 = 0xF0;

    D_800EC947 = 5;
    D_800EC948 = 0xE100000F;
    D_800EC94F = 0x64;
    D_800EC94E = 0x80;
    D_800EC94D = 0x80;
    D_800EC94C = 0x80;
    D_800EC950 = -0x50;
    D_800EC952 = 0x20;
    D_800EC954 = 0;
    D_800EC955 = 0;
    D_800EC956 = 0x7800;
    D_800EC958 = 0x78;
    D_800EC95A = 0x3C;
    D_800EC956 = 0x7A00;

    ((PrimTag *)&D_800EC944)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC944;

    D_800EC98F = 5;
    D_800EC990 = 0xE100000F;
    D_800EC997 = 0x64;
    D_800EC996 = 0x80;
    D_800EC995 = 0x80;
    D_800EC994 = 0x80;
    D_800EC998 = -0x6E;
    D_800EC99A = D_800EC894 * 20 + 0x20;
    D_800EC99C = 0;
    D_800EC99D = 0x3C;
    D_800EC99E = 0x7800;
    D_800EC9A0 = 0x1E;
    D_800EC9A2 = 0x14;
    D_800EC99E = 0x7A00;

    ((PrimTag *)&D_800EC98C)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC98C;

    ((PrimTag *)&D_800EC8CC)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC8CC;

    ((PrimTag *)&D_800EC8B4)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC8B4;
}
