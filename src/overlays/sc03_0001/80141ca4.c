/* sc03_0001: func_80141CA4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern s32 func_80029504(void);
extern s32 func_80029178(s32);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern s32 func_800291B4(s32 arg);
extern short D_800B9A02;
extern s32 func_80029178(s32 a0);
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u16 D_80115116;
extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern unsigned char D_80112C04[];
extern unsigned char D_80112C50[];
extern unsigned char D_80112C9C[];
extern unsigned char D_80112CE8[];
extern unsigned char D_80112D38[];
extern unsigned char D_80112D78[];
extern unsigned char D_80112DBC[];
extern unsigned char D_80112DF4[];
extern unsigned char D_80112E14[];
extern unsigned char D_80112E40[];
extern unsigned char D_80112E6C[];
extern unsigned char D_80112EBC[];
extern unsigned char D_80112F0C[];
extern unsigned char D_80112F48[];
extern unsigned char D_80112F9C[];
extern unsigned char D_80112FDC[];
extern unsigned char D_8011302C[];
extern unsigned char D_80113074[];
extern unsigned char D_801130B8[];
extern unsigned char D_801130E8[];
extern unsigned char D_80113138[];
extern unsigned char D_8011317C[];
extern unsigned char D_801131A8[];
extern unsigned char D_801131E8[];
extern unsigned char D_80113214[];
extern unsigned char D_80113254[];
extern unsigned char D_80113278[];
extern unsigned char D_801132B8[];
extern unsigned char D_801132E4[];
extern unsigned char D_80113324[];
extern unsigned char D_80113360[];
extern unsigned char D_801133A4[];
extern unsigned char D_801133F4[];
extern unsigned char D_80113440[];
extern unsigned char D_80113474[];
extern unsigned char D_801134B0[];
extern unsigned char D_801134FC[];
extern unsigned char D_80113530[];
extern unsigned char D_80113554[];
extern unsigned char D_801135A8[];
extern unsigned char D_80113600[];
extern unsigned char D_80113650[];
extern unsigned char D_80113694[];
extern unsigned char D_801136DC[];
extern unsigned char D_80113724[];
extern unsigned char D_80113744[];
extern unsigned char D_80113770[];
extern unsigned char D_80113794[];
extern unsigned char D_801137D8[];
extern unsigned char D_8011381C[];
extern unsigned char D_8011383C[];
extern unsigned char D_8011386C[];
extern unsigned char D_801138A4[];
extern unsigned char D_801138D0[];
extern unsigned char D_80113900[];
extern unsigned char D_80113944[];
extern unsigned char D_80113964[];
extern unsigned char D_8011399C[];
extern unsigned char D_801139E8[];
extern unsigned char D_80113A28[];
extern unsigned char D_80113A50[];
extern unsigned char D_80113A84[];
extern unsigned char D_80113AB0[];
extern unsigned char D_80113AE0[];
extern unsigned char D_80113B34[];
extern unsigned char D_80113B68[];
extern unsigned char D_80113BA4[];
extern unsigned char D_80113BC0[];
extern unsigned char D_80113BF0[];
extern unsigned char D_80113C20[];
extern unsigned char D_80113C3C[];
extern unsigned char D_80113C7C[];

unsigned char *func_80141CA4(void) {
    s32 iVar3;
    s32 cVar1;
    iVar3 = func_80029504();
    if (iVar3 < 10) {
        return D_80112C04;
    }
    if (iVar3 < 0x14) {
        if (func_80029178(0xdf) & 0xff) {
            return D_80112D38;
        }
        if (func_80029178(0xe0) & 0xff) {
            return D_80112CE8;
        }
        cVar1 = func_80029178(0xde) & 0xff;
        if (cVar1) {
            return D_80112C9C;
        }
        return D_80112C50;
    }
    if (iVar3 < 0x1e) {
        return D_80112D78;
    }
    if (iVar3 < 0x28) {
        return D_80112DBC;
    }
    if (iVar3 < 0x32) {
        return D_80113B34;
    }
    if (iVar3 < 0x3c) {
        cVar1 = func_80029178(0xe5) & 0xff;
        if (cVar1 == 0) {
            return D_80112DF4;
        }
        return D_80112E14;
    }
    if (iVar3 < 0x46) {
        return D_80112E40;
    }
    if (iVar3 < 0x50) {
        return D_80112E6C;
    }
    if (iVar3 < 0x5a) {
        return D_80112EBC;
    }
    if (iVar3 < 100) {
        return D_80112F0C;
    }
    if (iVar3 < 0x78) {
        return D_80112F48;
    }
    if (iVar3 < 0x82) {
        return D_80112F9C;
    }
    if (iVar3 < 0x85) {
        if (func_80029178(0x9e) & 0xff) {
            return D_80113074;
        }
        cVar1 = func_80029178(0xef) & 0xff;
        if (cVar1 == 0) {
            return D_80112FDC;
        }
        return D_8011302C;
    }
    if (iVar3 < 0x87) {
        return D_801130B8;
    }
    if (iVar3 < 0x8c) {
        return D_801130E8;
    }
    if (iVar3 < 0x96) {
        return D_80113138;
    }
    if (iVar3 < 200) {
        return D_8011317C;
    }
    if (iVar3 < 0xd2) {
        return D_801131A8;
    }
    if (iVar3 < 0xdc) {
        return D_801131E8;
    }
    if (iVar3 < 0xf0) {
        return D_80113214;
    }
    if (iVar3 < 0x104) {
        return D_80113254;
    }
    if (iVar3 < 0x118) {
        return D_80113278;
    }
    if (iVar3 < 0x136) {
        if (func_80029178(0xf9) & 0xff) {
            return D_801132E4;
        }
        cVar1 = func_80029178(0xfa) & 0xff;
        if (cVar1) {
            return D_80113324;
        }
        return D_801132B8;
    }
    if (iVar3 < 0x140) {
        return D_80113360;
    }
    if (iVar3 < 0x14a) {
        cVar1 = func_80029178(0xff) & 0xff;
        if (cVar1) {
            return D_801133F4;
        }
        return D_801133A4;
    }
    if (iVar3 < 0x17c) {
        return D_80113440;
    }
    if (iVar3 < 0x186) {
        return D_80113474;
    }
    if (iVar3 < 400) {
        return D_801134B0;
    }
    if (iVar3 < 0x19a) {
        return D_801134FC;
    }
    if (iVar3 < 0x1ae) {
        return D_80113530;
    }
    if (iVar3 < 0x1cc) {
        return D_80113554;
    }
    if (iVar3 < 0x1d1) {
        return D_801135A8;
    }
    if (iVar3 < 0x1e0) {
        return D_80113600;
    }
    if (iVar3 < 600) {
        cVar1 = func_80029178(0xb3) & 0xff;
        if (cVar1 == 0) {
            return D_80113650;
        }
        return D_80113694;
    }
    if (iVar3 < 0x276) {
        if (func_80029178(0x10c) & 0xff) {
            return D_80113744;
        }
        cVar1 = func_80029178(0x10d) & 0xff;
        if (cVar1) {
            return D_80113770;
        }
        return D_801136DC;
    }
    if (iVar3 < 0x280) {
        return D_80113724;
    }
    if (iVar3 < 0x28a) {
        return D_80113794;
    }
    if (iVar3 < 0x29e) {
        return D_801137D8;
    }
    if (iVar3 < 0x2a8) {
        return D_8011381C;
    }
    if (iVar3 < 700) {
        return D_8011383C;
    }
    if (iVar3 < 0x2c6) {
        return D_8011386C;
    }
    if (iVar3 < 0x2d0) {
        return D_801138A4;
    }
    if (iVar3 < 0x2da) {
        return D_801138D0;
    }
    if (iVar3 < 0x2e4) {
        return D_80113900;
    }
    if (iVar3 < 0x2f8) {
        return D_80113944;
    }
    if (iVar3 < 900) {
        return D_80113964;
    }
    if (iVar3 < 0x3a2) {
        return D_8011399C;
    }
    if (iVar3 < 0x3ac) {
        cVar1 = func_800291B4(0x3b) & 0xff;
        if ((u32)cVar1 < 10) {
            return D_801139E8;
        }
        return D_80113A28;
    }
    if (iVar3 < 0x3b6) {
        return D_80113A50;
    }
    if (iVar3 < 0x3ca) {
        return D_80113A28;
    }
    if (iVar3 < 0x3d4) {
        return D_80113A84;
    }
    if (iVar3 < 0x3f2) {
        return D_80113AB0;
    }
    if (iVar3 < 0x44c) {
        return D_80113AE0;
    }
    if (iVar3 < 0x47e) {
        return D_80113B68;
    }
    if (iVar3 < 0x492) {
        return D_80113BA4;
    }
    if (iVar3 < 0x4b0) {
        return D_80113BC0;
    }
    if (iVar3 < 0x4ba) {
        cVar1 = func_80029178(0x138) & 0xff;
        if (cVar1 == 0) {
            return D_80113BF0;
        }
        return D_80113C20;
    }
    if (iVar3 < 0x636) {
        cVar1 = func_80029178(0x143) & 0xff;
        if (cVar1 == 0) {
            return D_80113C20;
        }
        return D_80113C3C;
    }
    return D_80113C7C;
}
