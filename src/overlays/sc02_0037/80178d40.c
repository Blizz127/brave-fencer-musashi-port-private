/* sc02_0037: func_80178D40 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; } Blk_80178D40;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { u8 pad0[0x12]; u16 unk12; } Obj20_80178D40;
typedef struct Actor_80178D40 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    s16 unk8;
    u16 unkA;
    s16 unkC;
    u16 unkE;
    u8 pad10[0x20 - 0x10];
    Obj20_80178D40 *unk20;
    u8 pad24[0x34 - 0x24];
    s16 unk34;
    u8 pad36[0xD4 - 0x36];
    struct Actor_80178D40 *unkD4;
    s32 unkD8;
    s32 unkDC[7];
    s32 unkF8;
    u8 padFC[0x10A - 0xFC];
    s16 unk10A;
} Actor_80178D40;
typedef struct { s16 vx, vy, vz, pad; } SV3_80178D40;
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012A828(s32 a0, void * a1);
extern s32 D_80126B58;
extern s32 func_8012B8A4(s16 *a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8012E88C(u8 *a0);
extern void func_8012E8A8(u8 *a0);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 * func_8012F40C(s32 *param_1, s32 param_2);
extern void *memcpy(void *, const void *, u32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_80137614(s32 a0, s32 a1, s32 a2);
extern void func_8002D4C8(int, int);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_80175454(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_80175414(s32 _arg0);
extern short D_801C9AE4;
extern s32 D_801C9648;
extern s32 D_801C9234;
extern s32 D_801C9674;
extern s32 D_801C9230;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_80175414(s32 _arg0);
extern void func_80175454(void);
void func_80179B28(s32 a0);
void func_80179D30(u16 *a0);
void func_80179D78(u16 *a0);
void func_80179DCC(short a0);
void func_80179DF8(void);
void func_80179E1C(short a0);
void func_80179E48(s16 a0);
void func_80179E74(s16 a0);
void func_80179EA0(u16 *a0);
void func_80179EE8(short a0);
void func_80179F14(s16 a0, s16 a1);
void func_80179F44(void);
void func_80179F6C(short a0);
void func_80179F98(u16 *a0);
void func_80179FEC(u16 *a0);
void func_8017A040(u16 *a0);
void func_8017A094(s32 arg0);
void func_8017A0C4(s32 arg0);
void func_8017A0F4(void);
void func_8017A11C(void);
void func_8017A144(s32 a0);
void func_8017A180(void);
void func_8017A1A8(void);
void func_8017A1D0(void);
void func_8017A1F8(void);
void func_8017A220(void);
void func_8017A248(void);
void func_8017A270(void);
void func_8017A298(void);
void func_8017A2C0(void);
void func_8017A2E8(void);
void func_8017A310(void);
void func_8017A338(void);
void func_8017A360(void);
void func_8017A388(void);
s32 func_8017A3B0(void);
int func_8017A3D8(void);
s32 func_8017AD0C(s32 arg0);

M2C_UNK func_80178D40(s32 arg0, s32 arg1)
{
    extern void func_80179B28(s32);
    extern void func_80137614(s32, s32, s32);
    extern void func_8012F214(s32, s32, s32);
    extern s32 *func_8012F40C(s32*, s32);
    extern void func_80179D30(u16*);
    extern void func_80179D78(u16*);
    extern void func_80179EA0(u16*);
    extern void func_80179DCC(short);
    extern void func_80179DF8(void);
    extern void func_80179E1C(short);
    extern void func_80179E48(s16);
    extern void func_80179E74(s16);
    extern void func_80179EE8(short);
    extern void func_80179F14(s16, s16);
    extern void func_80179F44(void);
    extern void func_80179F6C(short);
    extern void func_80179F98(u16*);
    extern void func_80179FEC(u16*);
    extern void func_8017A040(u16*);
    extern void func_8017A094(s32);
    extern void func_8017A0C4(s32);
    extern void func_8017A0F4(void);
    extern void func_8017A11C(void);
    extern void func_8017A144(s32);
    extern void func_8017A180(void);
    extern void func_8017A1A8(void);
    extern void func_8017A1D0(void);
    extern void func_8017A1F8(void);
    extern void func_8017A220(void);
    extern void func_8017A248(void);
    extern void func_8017A270(void);
    extern void func_8017A298(void);
    extern void func_8017A2C0(void);
    extern void func_8017A2E8(void);
    extern void func_8017A310(void);
    extern void func_8017A338(void);
    extern void func_8017A360(void);
    extern void func_8017A388(void);
    extern s32 func_8017A3B0(void);
    extern int func_8017A3D8(void);
    extern s32 func_8017AD0C(s32);
    extern void func_8017B238(void *, s32);
    extern void func_8017B614(void *, s32);
    extern void func_8017B7A8(void *);
    extern void func_8017B824(void);
    extern void func_8017B880(void);
    extern void func_8017B940(void *);
    extern void func_8017BA3C(void *, s32);
    extern void func_8017BB34(void *, s32);
    extern void func_8012A828(s32, void*);
    extern s32 func_8012B8A4(s16*);
    extern void func_8012E88C(u8*);
    extern void func_8012E8A8(u8*);
    extern void func_8001AAD0(s32, s32);
    extern s16 D_801C964C;
    extern s16 D_801C9650;
    extern s16 D_801C9654;
    extern s16 D_801C9658;
    extern s32 D_801C9660;
    extern s32 D_801C9664;
    extern s16 D_801C9678;
    extern s16 D_801C967C;
    extern s32 D_801C9680;
    extern s32 D_801C9688;
    extern s32 D_801C968C[10];
    extern s32 D_801C9988;
    extern s16 D_801C9A40;
    extern s32 D_801C9A6C;
    SV3_80178D40 v10, v18, v20, v28, v30, v38, v40, v48;
    s32 out50[2];
    SV3_80178D40 v58, v60;
    Actor_80178D40 *pv = &(*(Actor_80178D40*)&D_80126B58);
    s32 i5b, i5c, fp5b, fp5c;
    s32 *q5b, *q5c, *p5c, *r5c;
    s16 *g = &D_801C9A40;
    switch (((Cmd_80178D40 *)arg1)->op) {
    case 1:
        func_80179B28(D_801C9648);
        D_801C9648 = ((s32 (*)(s32, s32, s32))func_80137614)(((Cmd_80178D40 *)arg1)->a.w, D_801C9654, D_801C9658 ? 0x48 : 0x40);
        (*(s16*)&D_801C9AE4) = 2;
        break;
    case 0:
        func_80179B28(D_801C9648);
        D_801C9648 = ((s32 (*)(s32, s32, s32))func_80137614)(((Cmd_80178D40 *)arg1)->a.w, D_801C964C, D_801C9650 ? 0x48 : 0x40);
        (*(s16*)&D_801C9AE4) = 1;
        break;
    case 0x45:
        ((void (*)(s32))((Cmd_80178D40 *)arg1)->a.w)(((Actor_80178D40 *)arg0));
        if (D_801C9988 != 0) {
            func_80179B28(D_801C9648);
            D_801C9648 = ((s32 (*)(s32, s32, s32))func_80137614)(((Actor_80178D40 *)arg0)->unkDC[1], D_801C964C, D_801C9650 ? 0x48 : 0x40);
            (*(s16*)&D_801C9AE4) = 1;
        } else {
            (*(s16*)&D_801C9AE4) = 3;
        }
        break;
    case 0x32:
        func_80179B28(D_801C9648);
        D_801C9648 = ((s32 (*)(s32, s32, s32))func_80137614)(((Actor_80178D40 *)arg0)->unkDC[((Cmd_80178D40 *)arg1)->a.w], D_801C964C,
                                   D_801C9650 ? 0x48 : 0x40);
        (*(s16*)&D_801C9AE4) = 1;
        break;
    case 2:
        func_80179B28(D_801C9648);
        if (D_801C9660 != 0) {
            D_801C9230 = D_801C9660;
            D_801C9660 = 0;
            (*(s16*)&D_801C9AE4) = 3;
            return;
        }
        (*(s16*)&D_801C9AE4) = 6;
        break;
    case 6:
        func_80179DF8();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 3:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *))func_80179D30)(&v10);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 4:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v10, &v18);
        ((void (*)(void *))func_80179D30)(&v18);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x4C:
        ((void (*)(void *))func_80179D78)((void *)((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x4D:
        v10.vx = ((Blk_80178D40 *)((Cmd_80178D40 *)arg1)->a.p)->f0;
        v10.vy = 0;
        v10.vz = ((Blk_80178D40 *)((Cmd_80178D40 *)arg1)->a.p)->f4;
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v10, &v18);
        v18.pad = ((Blk_80178D40 *)((Cmd_80178D40 *)arg1)->a.p)->f6;
        ((void (*)(void *))func_80179D78)(&v18);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x15:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0)->unkD4, &v10, &v18);
        ((void (*)(void *))func_80179D30)(&v18);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 5:
        ((void (*)(s32))func_80179DCC)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 7:
        ((void (*)(s32))func_80179E1C)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 8:
        ((void (*)(s32))func_80179E74)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 9:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *))func_80179EA0)(&v10);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0xA:
        v10.vx = ((Actor_80178D40 *)arg0)->unk6;
        v10.vy = ((Actor_80178D40 *)arg0)->unkA;
        v10.vz = ((Actor_80178D40 *)arg0)->unkE;
        ((void (*)(void *))func_80179EA0)(&v10);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x16: {
        Actor_80178D40 *p = ((Actor_80178D40 *)arg0)->unkD4;
        v10.vx = p->unk6;
        v10.vy = p->unkA;
        v10.vz = p->unkE;
        ((void (*)(void *))func_80179EA0)(&v10);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    }
    case 0xB:
        func_8017A0F4();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0xC:
        func_8017A11C();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0xD:
        func_8017A180();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0xE:
        func_8017A1A8();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x10:
        func_8017A1D0();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x46:
        func_8017A1F8();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x59:
        func_8017A220();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x5A:
        func_8017A248();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x49:
        func_8017A144(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x47:
        func_8017A270();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x17:
        ((void (*)(s32))func_80179EE8)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x18:
        ((void (*)(s32, s32))func_80179F14)(((Cmd_80178D40 *)arg1)->a.h[0], ((Cmd_80178D40 *)arg1)->a.h[1]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x19:
        ((void (*)(s32))func_80179F6C)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x1A:
        ((void (*)(s32))func_80179F98)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x51:
        ((void (*)(s32))func_8017A040)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x1B:
        D_801C9680 = ((Cmd_80178D40 *)arg1)->a.w;
        func_80179F44();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x1C:
        func_8017A338();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x52:
        func_8017A360();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x1D:
        func_8017A388();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x3B:
        func_8017A094(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x3C:
        func_8017A0C4(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0xF:
    case 0x3F:
        (*(s16*)&D_801C9AE4) = 4;
        D_801C9234 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x3E:
        (*(s16*)&D_801C9AE4) = 5;
        D_801C9674 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x40:
        D_801C9674 = (s32)func_8017A3B0;
        (*(s16*)&D_801C9AE4) = 5;
        break;
    case 0x23:
        ((void (*)(void *, s32))func_8012A828)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x31:
        ((void (*)(void *, s32))func_8012A828)(((Actor_80178D40 *)arg0), ((Actor_80178D40 *)arg0)->unkDC[((Cmd_80178D40 *)arg1)->a.w]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x24:
        (*(s16*)&D_801C9AE4) = 3;
        ((Actor_80178D40 *)arg0)->unk20->unk12 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x25:
        g[0] = 1;
        g[2] = ((Actor_80178D40 *)arg0)->unk20->unk12 + ((Cmd_80178D40 *)arg1)->a.uh[0];
        g[1] = 0x1E;
        (*(s16*)&D_801C9AE4) = 3;
        g[3] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x48:
        g[0] = 1;
        g[2] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        g[1] = 0x1E;
        (*(s16*)&D_801C9AE4) = 3;
        g[3] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x26:
        g[0] = 1;
        g[2] = ((s32 (*)(void *))func_8012B8A4)(((Actor_80178D40 *)arg0));
        g[1] = 0x1E;
        (*(s16*)&D_801C9AE4) = 3;
        g[3] = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x3D:
        ((void(*)(void *, s32))func_8012E8E0)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x27:
        g[0] = 2;
        g[4] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        (*(s16*)&D_801C9AE4) = 3;
        g[1] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x4F:
        g[5] = 1;
        g[0] = 3;
        g[6] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        (*(s16*)&D_801C9AE4) = 3;
        g[7] = ((Actor_80178D40 *)arg0)->unkA;
        g[8] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        g[1] = 0x10;
        g[3] = 4;
    case 0x28:
        g[5] = 0;
        g[0] = 3;
        g[6] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        (*(s16*)&D_801C9AE4) = 3;
        g[7] = ((Actor_80178D40 *)arg0)->unkA;
        g[8] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        g[1] = 0x10;
        g[3] = 4;
        break;
    case 0x29:
        v20.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v20.vy = ((Actor_80178D40 *)arg0)->unkA;
        v20.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v20, &v28);
        g[5] = 0;
        g[0] = 3;
        *(SV3_80178D40 *)(g + 6) = v28;
        g[1] = 0x10;
        g[3] = 4;
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x50:
        v30.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v30.vy = ((Actor_80178D40 *)arg0)->unkA;
        v30.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v30, &v38);
        g[5] = 1;
        g[0] = 3;
        *(SV3_80178D40 *)(g + 6) = v38;
        g[1] = 0x10;
        g[3] = 4;
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x2A:
        g[0] = 4;
        (*(s16*)&D_801C9AE4) = 3;
        g[1] = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x1E:
        func_8017B238(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x21:
        func_8017BA3C(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        func_8017B238(((Actor_80178D40 *)arg0), (s32)&D_801C9664);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x54:
        func_8017BB34(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        func_8017B238(((Actor_80178D40 *)arg0), (s32)&D_801C9664);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x1F:
        func_8017B614(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x22:
        func_8017BA3C(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        func_8017B614(((Actor_80178D40 *)arg0), (s32)&D_801C9664);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x55:
        func_8017BB34(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        func_8017B614(((Actor_80178D40 *)arg0), (s32)&D_801C9664);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x20:
        func_8017B7A8(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x4E:
        D_801C9688 = ((Cmd_80178D40 *)arg1)->a.w;
        func_8017B940(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x57:
        func_8017B824();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x58:
        func_8017B880();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x2B:
        (*(s16*)&D_801C9AE4) = 3;
        ((Actor_80178D40 *)arg0)->unk2 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2C:
        (*(s16*)&D_801C9AE4) = 3;
        ((Actor_80178D40 *)arg0)->unk34 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2D:
        (*(s16*)&D_801C9AE4) = 3;
        ((Actor_80178D40 *)arg0)->unkD8 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2F:
        (*(s16*)&D_801C9AE4) = 3;
        ((Actor_80178D40 *)arg0)->unk10A = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2E:
        (*(s16*)&D_801C9AE4) = 3;
        ((Actor_80178D40 *)arg0)->unkF8 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x11:
        func_8017A298();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x12:
        func_8017A2C0();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x13:
        func_8017A2E8();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x14:
        func_8017A310();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x33: {
        void (*f)(Actor_80178D40 *) = (void (*)(Actor_80178D40 *))((Cmd_80178D40 *)arg1)->a.w;
        D_801C9A6C = (s32)&((Cmd_80178D40 *)arg1)[1];
        f(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801C9AE4) = 3;
        break;
    }
    case 0x30:
        if (((Cmd_80178D40 *)arg1)->a.w == 0) {
            ((void (*)(void *))func_8012E8A8)(((Actor_80178D40 *)arg0));
            (*(s16*)&D_801C9AE4) = 3;
        } else {
            ((void (*)(void *))func_8012E88C)(((Actor_80178D40 *)arg0));
            (*(s16*)&D_801C9AE4) = 3;
        }
        break;
    case 0x4A:
        ((void(*)())func_80175414)();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x4B:
        func_80175454();
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x34:
        (*(s16*)&D_801C9AE4) = 3;
        D_801C9230 = ((Cmd_80178D40 *)arg1)->a.w;
        return;
    case 0x35:
        D_801C9660 = (s32)&((Cmd_80178D40 *)arg1)[1];
        (*(s16*)&D_801C9AE4) = 3;
        D_801C9230 = ((Cmd_80178D40 *)arg1)->a.w;
        return;
    case 0x36:
        (*(s16*)&D_801C9AE4) = 3;
        D_801C9230 += 8;
        if (((s32 (*)(s32))((Cmd_80178D40 *)arg1)->a.w)(((Actor_80178D40 *)arg0)) == 0) {
            break;
        }
        D_801C9230 = *(s32 *)(D_801C9230 + 4);
        return;
    case 0x37:
        (*(s16*)&D_801C9AE4) = 3;
        D_801C964C = ((Cmd_80178D40 *)arg1)->a.uh[0];
        D_801C9650 = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x38:
        (*(s16*)&D_801C9AE4) = 3;
        D_801C9654 = ((Cmd_80178D40 *)arg1)->a.uh[0];
        D_801C9658 = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x39: {
        s32 w1, w2;
        v40.vx = ((Actor_80178D40 *)arg0)->unk6;
        v40.vy = ((Actor_80178D40 *)arg0)->unkA;
        v40.vz = ((Actor_80178D40 *)arg0)->unkE;
        v48.vx = pv->unk6;
        v48.vy = pv->unkA;
        v48.vz = pv->unkE;
        ((void (*)(void *, void *))func_8012F40C)(out50, &v40);
        w1 = out50[0];
        ((void (*)(void *, void *))func_8012F40C)(out50, &v48);
        w2 = out50[0];
        (*(s16*)&D_801C9AE4) = 3;
        D_801C964C = w1;
        D_801C9650 = (s16)w1 >= (s16)w2;
        break;
    }
    case 0x3A: {
        s32 w1, w2;
        v58.vx = ((Actor_80178D40 *)arg0)->unk6;
        v58.vy = ((Actor_80178D40 *)arg0)->unkA;
        v58.vz = ((Actor_80178D40 *)arg0)->unkE;
        v60.vx = pv->unk6;
        v60.vy = pv->unkA;
        v60.vz = pv->unkE;
        ((void (*)(void *, void *))func_8012F40C)(out50, &v58);
        w1 = out50[0];
        ((void (*)(void *, void *))func_8012F40C)(out50, &v60);
        w2 = out50[0];
        (*(s16*)&D_801C9AE4) = 3;
        D_801C9654 = w2;
        D_801C9658 = (s16)w1 < (s16)w2;
        break;
    }
    case 0x41:
        ((void(*)(s32, s32))func_8002D4C8)(((Cmd_80178D40 *)arg1)->a.uh[0], ((Cmd_80178D40 *)arg1)->a.uh[1]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x42:
        ((void (*)(s32))func_8017AD0C)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x43:
        D_801C9674 = (s32)func_8017A3D8;
        D_801C967C = 0;
        (*(s16*)&D_801C9AE4) = 5;
        D_801C9678 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x44:
        func_8001AAD0(((Cmd_80178D40 *)arg1)->a.h[0], ((Cmd_80178D40 *)arg1)->a.h[1]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x53:
        ((void (*)(s32))func_80179E48)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x56:
        ((void (*)(s32))func_80179FEC)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    L5B_found:
        fp5b = ((Cmd_80178D40 *)arg1)->a.w;
        *q5b = fp5b;
        ((void (*)(Actor_80178D40 *))fp5b)(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801C9AE4) = 3;
        break;
    case 0x5B:
        i5b = 0;
        q5b = D_801C968C;
        do {
            i5b++;
            if (*q5b == 0) {
                goto L5B_found;
            }
            q5b++;
        } while (i5b < 10);
        (*(s16*)&D_801C9AE4) = 3;
        break;
    L5C_found1:
        *q5c = 0;
        goto L5C_join;
    case 0x5C:
        i5c = 0;
        if (((Cmd_80178D40 *)arg1)->a.w != 0) {
            fp5c = ((Cmd_80178D40 *)arg1)->a.w;
            q5c = D_801C968C;
            do {
                if (*q5c == fp5c) {
                    goto L5C_found1;
                }
                i5c++;
                q5c++;
            } while (i5c < 10);
        L5C_join:
            if (i5c != 10) {
                (*(s16*)&D_801C9AE4) = 3;
                break;
            }
            i5c = 0;
            do {
                p5c = &D_801C968C[i5c];
                if (*p5c != 0) {
                    goto L5C_found2;
                }
                i5c++;
            } while (i5c < 10);
            (*(s16*)&D_801C9AE4) = 3;
            break;
        L5C_found2:
            *p5c = 0;
            goto L5D;
        }
        r5c = D_801C968C;
        do {
            i5c++;
            if (*r5c != 0) {
                *r5c = 0;
                goto L5D;
            }
            r5c++;
        } while (i5c < 10);
    case 0x5D:
    L5D:
        (*(s16*)&D_801C9AE4) = 3;
        break;
    default:
        break;
    }
Lend:
    D_801C9230 += 8;
}
