/* sc02_0037: func_8015D1B8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
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
extern void func_80139FBC(struct obj *a0);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_801477E8(s32 *a0, s32 a1);
extern u16 func_80148800(s32 *a0);
extern void func_80149724(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014E6A0(void);
extern void func_8014FA04(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_80149FB0(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014FA04(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_801862A8[])(void *);
extern s32 func_80149FB0(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_8014E6A0(void);
extern void func_80147324(s32 arg0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_80149FB0(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147324(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_80149FB0(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_80149FB0(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80149724(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_80159B70(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80149FB0(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_8014E6A0(void);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_801725F4(u8 *a0);
extern s32 func_80149FB0(s32);
extern void func_80147324(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_80149724(void);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146DB8(s32*, s32*);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_8014FA04(s32);
extern void func_8014E6A0(void);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void*);
extern void func_8015D380(s32);
extern s32 func_801725F4(u8 *a0);
void func_8015D380(s32 a0);

void func_8015D1B8(s32 *a0)
{
    extern void (*D_801862A8[])(void*);
    extern s32 D_80186488;
    extern s32 D_8018648C;
    extern s32 D_801864D0;
    extern s32 D_800D4C14;
    s32 sum;
    s32 keep;
    s32 obj;
    s16 cur;
    s16 prev;
    s16 d;
    s32 off;
    s32 *p;
    s32 dummy[2];
    ((void (*)(void))func_80149FB0)();
    obj = *(s32 *)((u8 *)a0 + 0x20);
    sum = *(u16 *)(obj + 0x10) + *(u16 *)((u8 *)a0 + 0x236);
    *(u16 *)(obj + 0x10) = sum & 0xFFF;
    keep = sum;
    cur = *(s16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x10);
    prev = *(s16 *)((u8 *)a0 + 0x244);
    if (cur - prev >= 0) {
        d = cur - prev;
    } else {
        d = prev - cur;
    }
    if (d > 0x800) {
        func_80147324(0x5E9);
    }
    *(u16 *)((u8 *)a0 + 0x244) = *(u16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x10);
    if (func_80148800(a0) & 0x40) {
        ((void (**)(s32*))D_801862A8)[*(u16 *)a0](a0);
        ((void (*)(s32 *))func_80149724)(a0);
        func_80154274(a0, (s32)&D_800D4C14);
        func_80146E90(a0, 0x10);
        {
            u32 t = keep & 0xFFF;
            if ((s32)t < 0) {
                t += 0x1FF;
            }
            p = &D_801864D0;
            off = (t >> 9) * 8;
        }
        *p = *(s32 *)((u8 *)&D_80186488 + off);
        ((void (*)(s32 *, s32))func_80146DB8)(a0, (s32)(p - 2));
        func_801477E8(a0, *(s32 *)((u8 *)&D_8018648C + off));
        func_80147324(0x5EA);
    } else {
        ((void (*)(s32 *))func_8014FA04)(a0);
        if (((s32 (*)(s32 *))func_8014E6A0)(a0) == 0) {
            ((void (**)(s32*))D_801862A8)[*(u16 *)a0](a0);
            func_80147078(a0, 0);
            ((void (*)(s32 *))func_80159B70)(a0);
        } else {
            ((void (*)(s32 *))func_8015D380)(a0);
            func_801725F4(a0);
        }
    }
}
