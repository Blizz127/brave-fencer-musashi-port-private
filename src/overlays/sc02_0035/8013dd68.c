/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013DD68 - byte-exact against retail at -O2 (tools/register_match.py). */
#define SetDrawEnv func_8005A658
typedef struct { u32 w[23]; } DrawEnv_8013DD68;
typedef struct { DrawEnv_8013DD68 env; u8 pad[0x0C]; } Buf_8013DD68;
typedef void (*code)(unsigned short *);
typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG_8013DD68;
extern u8 D_800AF630[];
extern u8  D_800AF630[];
extern int D_800A5E60;
extern s32 D_800A5E60;
extern s16 *D_801BD694;
extern s32 D_801BD6C4;
extern s32 D_801BD6C8;
extern s32 D_801BD6CC;

void func_8013DD68() {
    extern void SetDrawEnv(void *p, void *env);
    extern u16 D_800AF7B8;
    extern u8 D_800BA0E4[];
    extern u8 D_80184E74[];

    u32 *p;
    u16 uVar1;
    u16 *puVar16;
    u16 *q;
    u16 *puVar10;
    register u16 uVar2 __asm__("$3");
    int uVar5;
    register int iVar14 __asm__("$7");
    Buf_8013DD68 buf;
    u8 *pbase;
    u8 *base;

    pbase = D_800AF630;
    puVar16 = (*(u16 * *)&D_801BD694);
    p = (*(u32 * *)&D_800A5E60);
    uVar1 = *puVar16;
    puVar16 = puVar16 + 1;
    base = pbase + (u32)D_800AF7B8 * 0x5C;
    buf.env = *(DrawEnv_8013DD68 *)(base + 0x38);
    *((u8 *)&buf + 0x18) = 0;
    SetDrawEnv(p, &buf);
    ((P_TAG_8013DD68 *)p)->addr = ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2))  * 0x10)) ->addr;
    ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2))  * 0x10)) ->addr = (u32)p;
    p = p + 0x10;
    iVar14 = 0;
    if (uVar1 != 0) {
        register int c5 __asm__("$11") = 5;
        puVar10 = (u16 *)((int)p + 0x18);
        q = puVar16 + 8;
        do {
            *(u8 *)((int)puVar10 + -0x15) = c5;
            uVar2 = q[-6];
            *(u8 *)((int)puVar10 + -0xd) = 100;
            *(u8 *)((int)puVar10 + -0x10) = (u8)(*(int*)&D_801BD6C4);
            *(u8 *)((int)puVar10 + -0xf) = (u8)(*(int*)&D_801BD6C8);
            uVar5 = (*(int*)&D_801BD6CC);
            *(u32 *)((int)puVar10 + -0x14) = uVar2 & 0x9ff | 0xe1000400;
            *(u8 *)((int)puVar10 + -0xe) = (u8)uVar5;
            *(u16 *)((int)puVar10 + -0xc) = q[-4];
            iVar14 = iVar14 + 1;
            *(u16 *)((int)puVar10 + -0xa) = q[-3];
            *(u8 *)((int)puVar10 + -8) = (u8)*puVar16;
            uVar2 = q[-7];
            *(u16 *)((int)puVar10 + -6) = 0x7800;
            *(u8 *)((int)puVar10 + -7) = (u8)uVar2;
            puVar16 = puVar16 + 8;
            *(u16 *)((int)puVar10 + -4) = q[-2];
            *(u16 *)((int)puVar10 + -2) = q[-1];
            ((P_TAG_8013DD68 *)p)->addr = ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2))  * 0x10)) ->addr;
            puVar10 = puVar10 + 0xc;
            ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2))  * 0x10)) ->addr = (u32)p;
            p = p + 6;
            q = q + 8;
        } while (iVar14 < (int)(u32)uVar1);
    }
    SetDrawEnv(p, D_80184E74);
    ((P_TAG_8013DD68 *)p)->addr = ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2))  * 0x10)) ->addr;
    ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2))  * 0x10)) ->addr = (u32)p;
    p = p + 0x10;
    (*(u32 * *)&D_800A5E60) = p;
    return;
}
