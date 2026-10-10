/* sc01_0077: func_8017FAAC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
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
extern u8 D_80078EC1;
extern u8 D_80126B5C;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012AD80(s32 a0);
extern u8 D_80078EC1;
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
s32 func_8005C49C();
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern unsigned char D_80078EC1;
extern s32 func_8012C0EC(s32 a0);
extern s32 func_8005C49C(void);
extern u8 D_80078EC1;
extern u8 D_80126B5C;
extern s32 D_80126B60;
extern s32 D_80126B64;
extern u8 D_8018A9B0[];
extern u8 D_8018A9B2[];
extern u8 D_8018A940[];
extern u8 D_8018A942[];
extern u8 D_8018A944[];
extern void (*D_8018A9D4[])(void);
extern s32 func_8012BC60();
extern s32 func_8012B77C(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012B2CC(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012AD80(s32 a0);
extern s32 func_8012C0EC(s32 a0);
extern void func_8017FD14(void *a0);
void func_8017FD14(void *a0);

void func_8017FAAC(void *arg0)
{
    s32 a0 = (s32)arg0;
    s32 v[4];
    s32 out[4];
    if ((*(u16 *)(a0 + 0xFC) & 1) == 0) {
        *(s16 *)(a0 + 0x50) = (func_8005C49C() & 0xF) - 7;
        *(s16 *)(a0 + 0x52) = (func_8005C49C() & 0xF) - 7;
        *(s16 *)(a0 + 0x54) = (func_8005C49C() & 0xF) - 7;
    }
    if ((D_80078EC1 & 0x7F) == 5) {
        s32 k = *(u8 *)(a0 + 0x70);
        v[0] = *(s32 *)&D_80126B5C;
        v[1] = D_80126B60;
        v[2] = D_80126B64 + *(s16 *)(D_8018A9B0 + k * 4 + 2);
        ((u16 *)v)[1] += *(u16 *)(D_8018A9B0 + k * 4);
        ((u16 *)v)[5] += *(u16 *)(D_8018A9B2 + k * 4);
        ((u16 *)v)[3] -= 0x40;
    } else {
        ((u16 *)v)[1] = *(u16 *)(D_8018A940 + (s8)(*(u16 *)(a0 + 0x70) >> 8) * 16 + *(u8 *)(a0 + 0x100) * 8);
        ((u16 *)v)[3] = *(u16 *)(D_8018A942 + (s8)(*(u16 *)(a0 + 0x70) >> 8) * 16 + *(u8 *)(a0 + 0x100) * 8);
        ((u16 *)v)[5] = *(u16 *)(D_8018A944 + (s8)(*(u16 *)(a0 + 0x70) >> 8) * 16 + *(u8 *)(a0 + 0x100) * 8);
    }
    if (func_8012BC60(a0 + 4, (s32)v) >= 0x401) {
        s32 t;
        func_8012B77C((s32)out, a0 + 4, (s32)v);
        t = out[0];
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) = t;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) +=
            func_8012B608(*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12), t >> 16, 0x17);
        func_8012B2CC(a0);
    } else {
        *(u8 *)(a0 + 0x100) += 1;
        if (*(u8 *)(a0 + 0x100) >= 2) {
            *(u8 *)(a0 + 0x100) = 0;
        }
    }
    func_8012B14C(a0, (s32)D_8018A9D4);
    *(u16 *)(a0 + 0xFC) += 1;
    func_8017FD14((void *)a0);
    func_8012AD80(a0);
    func_8012C0EC(a0);
}
