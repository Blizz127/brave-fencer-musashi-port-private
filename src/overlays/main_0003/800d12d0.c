/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D12D0 - byte-exact against retail at -O0 (tools/register_match.py). */
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
extern u8  D_800EC890;
extern s16 D_800EC894;
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
extern u32 D_800EC8E4;
extern u8  D_800EC8E7;
extern u32 D_800EC8E8;
extern u8  D_800EC8EC;
extern u8  D_800EC8ED;
extern u8  D_800EC8EE;
extern u8  D_800EC8EF;
extern s16 D_800EC8F0;
extern s16 D_800EC8F2;
extern u8  D_800EC8F4;
extern u8  D_800EC8F5;
extern s16 D_800EC8F6;
extern s16 D_800EC8F8;
extern s16 D_800EC8FA;
extern u32 D_800EC8FC;
extern u8  D_800EC8FF;
extern u32 D_800EC900;
extern u8  D_800EC904;
extern u8  D_800EC905;
extern u8  D_800EC906;
extern u8  D_800EC907;
extern s16 D_800EC908;
extern s16 D_800EC90A;
extern u8  D_800EC90C;
extern u8  D_800EC90D;
extern s16 D_800EC90E;
extern s16 D_800EC910;
extern s16 D_800EC912;
extern u32 D_800EC914;
extern u8  D_800EC917;
extern u32 D_800EC918;
extern u8  D_800EC91C;
extern u8  D_800EC91D;
extern u8  D_800EC91E;
extern u8  D_800EC91F;
extern s16 D_800EC920;
extern s16 D_800EC922;
extern u8  D_800EC924;
extern u8  D_800EC925;
extern s16 D_800EC926;
extern s16 D_800EC928;
extern s16 D_800EC92A;
extern u32 D_800EC92C;
extern u8  D_800EC92F;
extern u32 D_800EC930;
extern u8  D_800EC934;
extern u8  D_800EC935;
extern u8  D_800EC936;
extern u8  D_800EC937;
extern s16 D_800EC938;
extern s16 D_800EC93A;
extern u8  D_800EC93C;
extern u8  D_800EC93D;
extern s16 D_800EC93E;
extern s16 D_800EC940;
extern s16 D_800EC942;
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

void func_800D12D0(void) {
    typedef struct {
        unsigned int addr : 24;
        unsigned int len : 8;
    } PrimTag;

    register u8 *base = D_800AF630;

    D_800EC8B7 = 5;
    D_800EC8B8 = 0xE100008A;
    D_800EC8BF = 0x64;
    D_800EC8BC = D_800EC8BD = D_800EC8BE = D_800EC890;
    D_800EC8C0 = -0x140;
    D_800EC8C2 = -0xF0;
    D_800EC8C4 = 0;
    D_800EC8C5 = 0x10;
    D_800EC8C6 = 0x7800;
    D_800EC8C8 = 0x100;
    D_800EC8CA = 0xF0;

    D_800EC8CF = 5;
    D_800EC8D0 = 0xE100008C;
    D_800EC8D7 = 0x64;
    D_800EC8D4 = D_800EC8D5 = D_800EC8D6 = D_800EC890;
    D_800EC8D8 = -0x40;
    D_800EC8DA = -0xF0;
    D_800EC8DC = 0;
    D_800EC8DD = 0x10;
    D_800EC8DE = 0x7800;
    D_800EC8E0 = 0x100;
    D_800EC8E2 = 0xF0;

    D_800EC8E7 = 5;
    D_800EC8E8 = 0xE100008E;
    D_800EC8EF = 0x64;
    D_800EC8EC = D_800EC8ED = D_800EC8EE = D_800EC890;
    D_800EC8F0 = 0xC0;
    D_800EC8F2 = -0xF0;
    D_800EC8F4 = 0;
    D_800EC8F5 = 0x10;
    D_800EC8F6 = 0x7800;
    D_800EC8F8 = 0x80;
    D_800EC8FA = 0xF0;

    D_800EC8FF = 5;
    D_800EC900 = 0xE100009A;
    D_800EC907 = 0x64;
    D_800EC904 = D_800EC905 = D_800EC906 = D_800EC890;
    D_800EC908 = -0x140;
    D_800EC90A = 0;
    D_800EC90C = 0;
    D_800EC90D = 0;
    D_800EC90E = 0x7800;
    D_800EC910 = 0x100;
    D_800EC912 = 0xF0;

    D_800EC917 = 5;
    D_800EC918 = 0xE100009C;
    D_800EC91F = 0x64;
    D_800EC91C = D_800EC91D = D_800EC91E = D_800EC890;
    D_800EC920 = -0x40;
    D_800EC922 = 0;
    D_800EC924 = 0;
    D_800EC925 = 0;
    D_800EC926 = 0x7800;
    D_800EC928 = 0x100;
    D_800EC92A = 0xF0;

    D_800EC92F = 5;
    D_800EC930 = 0xE100009E;
    D_800EC937 = 0x64;
    D_800EC934 = D_800EC935 = D_800EC936 = D_800EC890;
    D_800EC938 = 0xC0;
    D_800EC93A = 0;
    D_800EC93C = 0;
    D_800EC93D = 0;
    D_800EC93E = 0x7800;
    D_800EC940 = 0x80;
    D_800EC942 = 0xF0;

    D_800EC947 = 5;
    D_800EC948 = 0xE100000F;
    D_800EC94F = 0x64;
    D_800EC94C = D_800EC94D = D_800EC94E = D_800EC890;
    D_800EC950 = -0xA0;
    D_800EC952 = 0x64;
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
    D_800EC994 = D_800EC995 = D_800EC996 = D_800EC890;
    D_800EC998 = -0xBE;
    D_800EC99A = D_800EC894 * 20 + 0x64;
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

    ((PrimTag *)&D_800EC92C)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC92C;

    ((PrimTag *)&D_800EC914)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC914;

    ((PrimTag *)&D_800EC8FC)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC8FC;

    ((PrimTag *)&D_800EC8E4)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC8E4;

    ((PrimTag *)&D_800EC8CC)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC8CC;

    ((PrimTag *)&D_800EC8B4)->addr =
        ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr;
    ((PrimTag *)(*(u16 *)(base + 0xA3D2) * 0x4000 + (u32)D_800AA60C))->addr =
        (u32)&D_800EC8B4;
}
