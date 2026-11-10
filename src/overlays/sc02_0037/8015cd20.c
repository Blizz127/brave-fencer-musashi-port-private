/* sc02_0037: func_8015CD20 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
struct Sub_8015CD20 {
    u8 pad0[0x12];
    u16 unk12;
};
struct Ent_8015CD20 {
    u16 unk0;
    u8 pad2[0x1E];
    struct Sub_8015CD20 *unk20;
    u8 pad24[0x94];
    s16 unkB8;
    u8 pad1BA[0x102];
    s8 unk1BC;
    u8 pad1BD[0x77];
    s32 unk234;
};
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146D90(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern s32 func_8014891C(s32 a0);
extern s32 func_80148980(u8 *a0);
extern s32 func_801489E8(s32 a0);
extern s32 func_80148A48(s32 a0);
extern int func_80148AFC(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149724(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014E434(void);
extern void func_8014FA04(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
void func_80147078(s32 *a0, s16 a1);
extern void func_80147A84(int);
extern void func_80146D90(int);
extern void func_80159B70(void *a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_801496D4(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern int func_80148AFC(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
void func_80154150(s32 a0, s32 a1);
void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014FA04(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_801862A8[])(void *);
extern s32 func_80149FB0(s32 a0);
extern int func_80148AFC(void *a0);
extern void func_80146D90(s32 a0);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_8014E434(void);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern int func_80148AFC(void *a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_801496D4(void*);
extern int func_80148AFC(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32*);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_801496D4(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_80149FB0(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_801496D4(void *a0);
extern void func_801473EC(s32 *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_801725E0(u8 *a0);
extern void func_80146D90(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern s32 func_8014891C(s32 a0);
extern s32 func_80148980(u8 *a0);
extern s32 func_801489E8(s32 a0);
extern s32 func_80148A48(s32 a0);
extern int func_80148AFC(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149724(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014E434(void);
extern void func_8014FA04(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80159B70(void *a0);
extern s32 func_801725E0(u8 *a0);

s32 func_8015CD20(s32 arg0) {
    extern void (*D_801862A8[])(void *);
    extern u8 D_8018625C;
    extern u8 D_8018644C;
    extern u8 D_8018645C;
    s32 temp_v0;
    s32 var_v0;
    struct Sub_8015CD20 *sp;
    ((void(*)())func_80149FB0)();
    if (((s32(*)(struct Ent_8015CD20 *))func_801496D4)(((struct Ent_8015CD20 *)arg0)) != 0) {
        D_801862A8[((struct Ent_8015CD20 *)arg0)->unk0](((struct Ent_8015CD20 *)arg0));
        ((struct Ent_8015CD20 *)arg0)->unk1BC = 0xA;
        ((s32(*)(struct Ent_8015CD20 *))func_80149724)(((struct Ent_8015CD20 *)arg0));
        if (((s32(*)(struct Ent_8015CD20 *))func_80148AFC)(((struct Ent_8015CD20 *)arg0)) & 0xFF) {
            ((void(*)(struct Ent_8015CD20 *, u8 *))func_80146DB8)(((struct Ent_8015CD20 *)arg0), &D_8018625C);
        } else {
            ((void(*)(struct Ent_8015CD20 *))func_80146D90)(((struct Ent_8015CD20 *)arg0));
        }
        return;
    }
    temp_v0 = ((struct Ent_8015CD20 *)arg0)->unk234;
    if (temp_v0 == 0) {
        if (((s32(*)(struct Ent_8015CD20 *))func_80148980)(((struct Ent_8015CD20 *)arg0)) != 0) {
            ((void(*)(struct Ent_8015CD20 *, u8 *))func_80146DB8)(((struct Ent_8015CD20 *)arg0), &D_8018644C);
            ((void(*)(struct Ent_8015CD20 *))func_80147A84)(((struct Ent_8015CD20 *)arg0));
            ((void(*)(struct Ent_8015CD20 *))func_801473EC)(((struct Ent_8015CD20 *)arg0));
            ((void(*)(struct Ent_8015CD20 *, s32))func_80154150)(((struct Ent_8015CD20 *)arg0), 0x15);
            sp = ((struct Ent_8015CD20 *)arg0)->unk20;
            var_v0 = sp->unk12 - 0xAA;
            goto block_13;
        }
        if (((s32(*)(struct Ent_8015CD20 *))func_8014891C)(((struct Ent_8015CD20 *)arg0)) != 0) {
            ((void(*)(struct Ent_8015CD20 *, u8 *))func_80146DB8)(((struct Ent_8015CD20 *)arg0), &D_8018645C);
            ((void(*)(struct Ent_8015CD20 *))func_80147A84)(((struct Ent_8015CD20 *)arg0));
            ((void(*)(struct Ent_8015CD20 *))func_801473EC)(((struct Ent_8015CD20 *)arg0));
            ((void(*)(struct Ent_8015CD20 *, s32))func_80154150)(((struct Ent_8015CD20 *)arg0), 0x14);
            ((struct Ent_8015CD20 *)arg0)->unkB8 = 1;
        }
        if (((s32(*)(struct Ent_8015CD20 *))func_801489E8)(((struct Ent_8015CD20 *)arg0)) != 0) {
            sp = ((struct Ent_8015CD20 *)arg0)->unk20;
            var_v0 = sp->unk12 + 0x71;
            goto block_13;
        }
        if (((s32(*)(struct Ent_8015CD20 *))func_80148A48)(((struct Ent_8015CD20 *)arg0)) != 0) {
            sp = ((struct Ent_8015CD20 *)arg0)->unk20;
            var_v0 = sp->unk12 - 0x71;
block_13:
            sp->unk12 = var_v0 & 0xFFF;
        }
    } else {
        ((struct Ent_8015CD20 *)arg0)->unk234 = temp_v0 - 1;
    }
    ((void(*)(struct Ent_8015CD20 *))func_8014FA04)(((struct Ent_8015CD20 *)arg0));
    if (((s32(*)(struct Ent_8015CD20 *))func_8014E434)(((struct Ent_8015CD20 *)arg0)) == 0) {
        D_801862A8[((struct Ent_8015CD20 *)arg0)->unk0](((struct Ent_8015CD20 *)arg0));
        ((void(*)(struct Ent_8015CD20 *, s32))func_80147078)(((struct Ent_8015CD20 *)arg0), 0);
        ((void(*)(struct Ent_8015CD20 *))func_80159B70)(((struct Ent_8015CD20 *)arg0));
    } else {
        ((void(*)(struct Ent_8015CD20 *))func_801725E0)(((struct Ent_8015CD20 *)arg0));
    }
}
