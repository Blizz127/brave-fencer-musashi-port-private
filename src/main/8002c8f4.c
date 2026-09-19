/* Exact retail word export for [8002C8F4,8002CC4C); EXE-verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (214/214 words at 0x8002C8F4). */
#include "psx_types.h"

extern void func_8003A424(void);
extern void func_8003D518(void);
extern void func_8003C598(s32 *);
extern void func_8003BE24(s32);
extern void func_8002D1F0(s32);
extern void func_8003B280(s32);
extern void func_80037D98(void);

extern void func_8002CC4C(void);
extern void func_8002FAE0(void);
extern void func_80037CC8(void);
extern void func_8003BE74(s32, s32);
extern void func_8003B1EC(s32 *);
extern void func_80034C24(void);
extern void func_80037004(void);

extern void *D_800A4EE8;

extern s32 D_800A4EA4;
extern s16 D_800A4EA8;
extern s16 D_800A4EAA;
extern s16 D_800A4EAC;
extern s16 D_800A4EAE;
extern s16 D_800A4EB4;
extern s16 D_800A4EB6;
extern s32 D_800A4EB8;
extern s32 D_800A4EBC;
extern s32 D_800A4EC8;

extern s32 D_800A4E68;
extern s16 D_800A4E6C;
extern s16 D_800A4E6E;
extern u8  D_800A4E70;
extern u8  D_800A4F18;
extern u8  D_800A4F19;
extern s16 D_800A4EF6;

extern s32 D_800A4638;

extern u8  D_800A4E7A;
extern u8  D_800A46E4;
extern s32 D_800A4654;
extern s32 D_800A466C;
extern s32 D_800A4684;
extern s32 D_800A469C;

extern s32 D_800A64B0;
extern u8  D_800A4650[];
extern s16 D_800A4644[];
extern s16 D_800A4642[];
extern u16 D_800A46E8[];

extern u8  D_800A4988[];
extern s32 D_800A4C68[];
extern u8  D_800A4C6C[];
extern u8  D_800A4C6D[];

extern s16 D_800A4EF8;
extern s16 D_800A4EFA;
extern u8  D_800A4F1B;
extern u8  D_800A46BA;
extern s32 D_800A2B98;
extern s32 D_800A2BA0;
extern s32 D_800C7D20;
extern s32 D_800C7D2C;
extern s8  D_800A4F17;
extern u16 D_800A4E8E;
extern u16 D_800A4EA2;
extern s16 D_800A4EF0;
extern s16 D_800A4EFC;
extern u16 D_800A4F20;
extern u16 D_800A4F22;
extern u8  D_800A4F1D;
extern s32 D_800A4EEC;
extern u8  D_800A4EE6;
extern u16 D_800A4EE0;
extern u16 D_800A4EE4;
extern void (*D_800A4F24)(void);
extern u8  D_800A4F16;
extern u8  D_800A4F1C;
extern u8  D_800A4F1E;

void func_8002C8F4(void)
{
    s32 sp10[2];
    s32 *p;
    u8 *q;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 m;

    func_8003A424();
    func_8003D518();

    p = &D_800A4EA4;
    *p = 0x23CF;
    D_800A4EA8 = 0x3FFF;
    D_800A4EAA = 0x3FFF;
    D_800A4EB4 = 0x3FFF;
    D_800A4EB6 = 0x3FFF;
    D_800A4EAC = 0;
    D_800A4EAE = 0;
    D_800A4EB8 = 0;
    D_800A4EBC = 1;
    D_800A4EC8 = 0;

    func_8003C598(p);
    func_8003BE24(1);
    func_8002D1F0(4);
    func_8003B280(1);
    func_80037D98();

    D_800A4E68 = 0x3C;
    D_800A4E6C = 0x2F;
    D_800A4E6E = 0x2F;
    D_800A4E70 = 1;
    D_800A4F18 = 1;
    D_800A4F19 = 1;
    D_800A4EF6 = 1;
    (&D_800A4638)[1] = 0x1010;
    D_800A4638 = 0;
    D_800A4E7A = 0;
    D_800A46E4 = 0;
    D_800A4654 = 0x10000;
    D_800A466C = 0x14000;
    D_800A4684 = 0x18000;
    D_800A469C = 0x39F00;

    for (j = 0x54; j >= 0; j -= 0xC) {
        *(s32 *)((u8 *)&D_800A64B0 + j) = 0;
    }

    for (i = 0; i < 5; i++) {
        k = i * 0x18;
        D_800A4650[k] = 1;
        *(s16 *)((u8 *)D_800A4644 + k) = 0;
        *(s16 *)((u8 *)D_800A4642 + k) = -1;
    }

    for (n = 0x24C; n >= 0; n -= 0x54) {
        *(u16 *)((u8 *)D_800A46E8 + n) = 0;
    }

    m = 0x10;
    for (i = 0, q = D_800A4988 + 0x4F; i < 8; i++, m++, q += 0x54) {
        k = i * 0x48;
        q[2] = i;
        *(s16 *)(q - 0x45) = m;
        q[-1] = 0;
        *(s32 *)(q - 0x4B) = 0;
        *(s32 *)(q - 0xF) = 0;
        q[1] = 0;
        *(s32 *)((u8 *)D_800A4C68 + k) = m;
        D_800A4C6C[k] = 0;
        D_800A4C6D[k] = 0;
    }

    func_8002CC4C();

    D_800A4EFA = 0x7F;
    D_800A4EF8 = 0x7F;
    D_800A4F1B = 1;
    D_800A46BA = 0;
    D_800A2B98 = 0;
    D_800C7D20 = 0;
    D_800C7D2C = 0;
    D_800A2BA0 = 0;
    D_800A4F17 = 0;
    D_800A4E8E = 0;
    D_800A4EA2 = 0;
    D_800A4EF0 = 0;
    D_800A4EE8 = 0;
    D_800A4EFC = 0;
    D_800A4F20 = 0;
    D_800A4F22 = 0;
    D_800A4F1D = 0;
    D_800A4EEC = 0;
    D_800A4EE6 = 0;
    D_800A4EE0 = 0x4000;
    D_800A4EE4 = 0x4000;
    D_800A4F24 = 0;
    D_800A4F16 = 0;

    func_8002FAE0();
    func_80037CC8();
    func_8003BE74(0, 0xFFFFFF);

    sp10[0] = 1;
    sp10[1] = 0;
    func_8003B1EC(sp10);

    D_800A4F1C = 0;
    D_800A4F1E = 0;
    func_80034C24();
    func_80037004();
}

