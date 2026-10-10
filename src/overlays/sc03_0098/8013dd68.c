/* sc03_0098: func_8013DD68 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { u32 w[23]; } DrawEnv_8013DD68;
typedef struct { DrawEnv_8013DD68 env; u8 pad[0x0C]; } Buf_8013DD68;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG_8013DD68;
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
extern u8 D_800AF630[];
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u8 D_800AF630[];
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern int D_800A5E60;
extern s32 D_800A5E60;
extern s16 *D_801C4284;
extern s32 D_801C42B4;
extern s32 D_801C42B8;
extern s32 D_801C42BC;

void func_8013DD68() {
    extern void func_8005A658(void *p, void *env);
    extern u16 D_800AF7B8;
    extern u8 D_800BA0E4[];
    extern u8 D_80185CC4[];
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
    puVar16 = (*(u16 * *)&D_801C4284);
    p = (*(u32 * *)&D_800A5E60);
    uVar1 = *puVar16;
    puVar16 = puVar16 + 1;
    base = pbase + (u32)D_800AF7B8 * 0x5C;
    buf.env = *(DrawEnv_8013DD68 *)(base + 0x38);
    *((u8 *)&buf + 0x18) = 0;
    func_8005A658(p, &buf);
    ((P_TAG_8013DD68 *)p)->addr = ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2)) * 0x10))->addr;
    ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2)) * 0x10))->addr = (u32)p;
    p = p + 0x10;
    iVar14 = 0;
    if (uVar1 != 0) {
        int c5 = 5;
        puVar10 = (u16 *)((int)p + 0x18);
        q = puVar16 + 8;
        do {
            *(u8 *)((int)puVar10 + -0x15) = c5;
            uVar2 = q[-6];
            *(u8 *)((int)puVar10 + -0xd) = 100;
            *(u8 *)((int)puVar10 + -0x10) = (u8)(*(int*)&D_801C42B4);
            *(u8 *)((int)puVar10 + -0xf) = (u8)(*(int*)&D_801C42B8);
            uVar5 = (*(int*)&D_801C42BC);
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
            ((P_TAG_8013DD68 *)p)->addr = ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2)) * 0x10))->addr;
            puVar10 = puVar10 + 0xc;
            ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2)) * 0x10))->addr = (u32)p;
            p = p + 6;
            q = q + 8;
        } while (iVar14 < (int)(u32)uVar1);
    }
    func_8005A658(p, D_80185CC4);
    ((P_TAG_8013DD68 *)p)->addr = ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2)) * 0x10))->addr;
    ((P_TAG_8013DD68 *)(D_800BA0E4 + (*(u16 *)(pbase + 0xA3D2)) * 0x10))->addr = (u32)p;
    p = p + 0x10;
    (*(u32 * *)&D_800A5E60) = p;
    return;
}
