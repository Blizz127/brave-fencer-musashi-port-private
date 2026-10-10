/* sc01_0077: func_8015126C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
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
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
typedef struct { u16 a, b, c, d; } V4U_8014C4AC;
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80126B58;
extern u16 D_801152B8;
extern u16 D_8012693A;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");

unsigned short *func_80146750(unsigned short *a0);
unsigned short *func_8014680C(short *param_1);
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_8011D030;
extern void func_80146AFC(void*);
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");

extern s32 D_8011D030;
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");

void func_80146D80(s32 *a0);
void func_80147084(s32 *a0);
s32 func_801470A0(void *a0);
extern void func_80147364();
extern void func_80147364();
void func_80147324(s32 arg0);
extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_8002D4C8(s32 a0, s32 a1);
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");

void func_801477E8(s32 *a0, s32 a1);
extern void func_80015978(int a0, int *a1);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern u8 D_80078E78[];
extern s32 func_8014CB7C(void);
extern s16 D_800B9A08;
extern u16 *func_80146750(u16 *param_1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80147364();
extern u16 *func_80146750(u16 *param_1);
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_801599A4(void *a0);
extern u8 D_80078E78[];
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
s32 func_8014A454(s32 a0);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern s32 D_8011D030;
void func_8014ACE8(void *a0, s32 a1, s32 a2);
extern void func_80146AFC(void *a0);
extern s32 D_80126B58;
extern u8 D_80078E78[];
extern void func_8014BD24(s32 a0, s32 a1);
extern s32 D_80126B58;
extern u8 D_80078E78[];
extern s32 D_80126B58;
extern s32 D_80126B58;
extern void func_8014B310(void);
void func_8014B310(void);
extern u8 D_80078E78[];
void func_8014B4D4(void *a0);
extern u8 D_80078E78[];
extern void func_8014B944(s32 a0, s32 a1, s32 a2);
extern u8 D_80078E78[];
extern s16 D_800B9A08;
extern u8 D_80078E78[];
void func_8014B944(s32 a0, s32 a1, s32 a2);
extern u8 D_80078E78[];
void func_8014BD24(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80146AFC(void *a0);
extern s32 D_8011D030;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
s32 aF8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) __asm__("func_8014C4AC");
s32 aF8014C4AC() __asm__("func_8014C4AC");

extern void func_80015978(s32 a0, s32 *a1);
extern void func_80147364();
extern void func_80147364();
s32 func_8014CB7C(void);
extern int func_80135888();
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801202A0[];
extern void func_8014E5B4(s32 a0, void *a1, void *a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
s32 aF8014E5B4(s32 a0, void *a1, void *a2) __asm__("func_8014E5B4");
s32 aF8014E5B4(s32 a0, void *a1, void *a2) __asm__("func_8014E5B4");

s32 func_80135888(s32, s32, M2C_UNK, M2C_UNK);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_8014BD24(s32 a0, s32 a1);
extern void func_8014ACE8(void *a0, s32 a1, s32 a2);
extern void func_80147324(s32 arg0);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_801619D0(void *a0);
extern s16 D_800B9A08;
extern void func_8014ACE8(void *a0, s32 a1, s32 a2);
extern void func_8014ACE8(void *a0, s32 a1, s32 a2);
void func_8015173C(s32 *a0);
s32 func_80151880(s32 a0);
s32 func_801518D8(s32 a0);
void func_80153C9C(void);

void func_8015126C(u16 *p)
{
    extern s32 D_80127078;
    extern s32 D_80126AE4;
    extern s32 D_801151FC;
    extern s32 D_80127518;
    extern s32 D_800AE6A8;
    extern u8 D_80078E78[];
    extern s32 func_801470A0(void *a0);
    extern s32 func_8014A454(s32 a0);
    extern void func_80160368(s32 *a0);
    extern s32 func_801619D0(void *a0);
    extern s32 func_80151880(s32 a0);
    extern void func_800CCF68(void *);
    extern s32 func_80161A00(s32 a0);
    extern s32 func_801518D8(s32 a0);
    extern void func_800CCF58(void *);
    extern s32 func_80161A30(s32 a0);
    extern s32 func_80161A60(s32 a0);
    extern void func_801599A4(void *);
    extern void func_801607B8(s32 *a0);
    extern void func_80147084(s32 *a0);
    extern s32 func_80029D3C(void);
    extern s32 func_8014CB7C(void);
    extern void func_80153C9C(void);
    extern void func_8015173C(s32 *a0);
    extern s32 func_801725CC(u8 *a0);
    extern void func_8014B310(void);
    extern void func_8014B4D4(void *a0);
    extern void func_8014B944(s32 a0, s32 a1, s32 a2);
    extern void func_80146D80(s32 *a0);
    extern void func_801477E8(s32 *a0, s32 a1);
    extern void func_80147324(s32 arg0);
    extern void func_8014BD24(s32 a0, s32 a1);
    extern void func_8014ACE8(void *a0, s32 a1, s32 a2);
    u8 *r = D_80078E78;
    s32 *q = &D_800AE6A8;
    register s32 sh16 __asm__("$2");
    u16 uVar3;
    s32 angle;
    s32 v;
    D_80126AE4 = D_80127078;
    D_80127078 = 0;
    D_801151FC = 0;
    if (*(u8 *)(p + 0x54) != 0) {
        if (((p[0x1e] & 1) == 0) || ((p[0x1f] & 0x8000) == 0)) {
            p[0x1e] &= 0xfffe;
            p[0x1f] = 0;
            p[0x20] = 0;
            p[0x21] = 0;
        }
        {
            u8 bVar2 = *(u8 *)(p + 0x54) - 1;
            *(u8 *)(p + 0x54) = bVar2;
            if ((bVar2 & 1) != 0) {
                ((void (*)(void *))func_801470A0)(p);
            }
        }
    }
    uVar3 = p[0x1e];
    if ((uVar3 & 1) == 0) {
        goto L638;
    }
    if (((*(u32 *)(p + 0x1e) & 0x80008000) == 0) || ((q[2] & 0x80ffffff) != 0)) {
        p[0x1e] = uVar3 & 0xfffe;
        p[0x1f] = 0;
        p[0x20] = 0;
        p[0x21] = 0;
        goto L638;
    }
    {
        u16 uVar1 = p[0x1f];
        p[0x1e] = uVar3 & 0xfffe;
        p[0x1f] = uVar1 & 0x7fff;
        if (((uVar1 & 0x4000) == 0) && ((*(u32 *)(p + 0x22) & 1) != 0) &&
            (((s32 (*)(void *))func_8014A454)(p) != 0)) {
            ((void (*)(void *))func_80160368)(p);
            p[0x1f] = 0;
            p[0x20] = 0;
            p[0x21] = 0;
            p[0x1e] &= 0xfffe;
            return;
        }
    }
    if ((func_801619D0(p) != 0) && (((s32 (*)(void *))func_80151880)(p) != 0)) {
        p[0x20] = 0;
        p[0x79] = 0;
        func_800CCF68(p);
    }
    if ((((s32 (*)(void *))func_80161A00)(p) != 0) && (((s32 (*)(void *))func_801518D8)(p) != 0)) {
        func_800CCF58(p);
    }
    if (((s32 (*)(void *))func_80161A30)(p) != 0) {
        p[0xe4] = 0;
    }
    if (((s32 (*)(void *))func_80161A60)(p) != 0) {
        p[0xe4] = 0;
    }
    if (((u32)(p[0] - 0x19) < 2) ||
        ((*(u32 *)(p + 0xfc) != 0) && ((*(u32 *)(p + 0xfc) & 0x2000000) == 0))) {
        goto L620;
    }
    p[0x78] = p[0x1f];
    p[0x79] = p[0x20];
    p[0x7a] = p[0x21];
    func_801599A4(p);
    ((void (*)(void *))func_801607B8)(p);
    ((void (*)(void *))func_80147084)(p);
    {
        u16 t = p[0x1f];
        register s32 cmp79 __asm__("$4");
        *(u8 *)(p + 0x54) = 0;
        ((s8 *)p)[0xdd] = (s8)t;
        if (((t & 0xff) != 0x11) && ((cmp79 = *(s16 *)(p + 0x79)) != 1000)) {
            angle = func_80029D3C();
            p[0x79] = angle;
            if (r[0x49] == 5) {
                sh16 = angle << 16;
            } else {
                if (func_8014CB7C() == 0) {
                    goto LAB_8015152c;
                }
                sh16 = p[0x79] << 16;
            }
            p[0x79] = (u16)(((sh16 >> 16) + (s32)((u32)sh16 >> 31)) >> 1);
        }
    }
LAB_8015152c:
    func_80153C9C();
    func_8015173C(p);
    ((void (*)(void *))func_801725CC)(p);
    if ((p[0x1f] & 0x2000) != 0) {
        ((void (*)(void *))func_8014B310)(p);
    }
    if ((p[0x1f] & 0x1000) != 0) {
        func_8014B4D4(p);
    }
    if ((p[0x1f] & 0x800) != 0) {
        ((void (*)(void *, s32, s32))func_8014B944)(p, 0x50000, 1);
    }
    if ((p[0x1f] & 0x400) != 0) {
        ((void (*)(void *))func_80146D80)(p);
        ((void (*)(void *, s32))func_801477E8)(p, 0);
    }
    if (((s32 (*)(void *))func_80151880)(p) == 2) {
        func_80147324(0x676);
    }
    if (r[0x49] == 0x14) {
        ((void (*)(void *, s32))func_8014BD24)(p, 10);
        func_8014ACE8(p, 4, 10);
    }
    D_80127518 = D_80126AE4;
    v = D_80126AE4;
    goto L640;
L620:
    p[0x1f] = 0;
    p[0x20] = 0;
    p[0x21] = 0;
    p[0x1e] &= 0xfffe;
L638:
    v = D_80127518;
L640:
    D_801151FC = v;
}
