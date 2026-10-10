/* sc01_0077: func_80185E68 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80019064(void *a0);
extern u8 D_80062C04[];
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8016B428(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8002D4C8(s32, s32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(int, void *);
extern void func_8002D4C8(s32, s32);
extern void func_8012A828(s32, void *);
extern int func_8005C49C(void);
extern void func_80019064(void *a0);
extern s32 func_8016B428(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B21C(void *a0);
extern s32 func_8005C49C(void);
typedef struct { u8 b[12]; } Blk12_80185E68;

void func_80185E68(s32 arg0) {
    extern u8 D_80062BDC;
    extern s32 D_801D55AC[];
    extern u8 D_801D5588[];
    extern Blk12_80185E68 D_801DA910[];
    extern u8 D_801D5578;
    extern u8 D_801D6F8C[];
    extern s16 D_801DA98A[];
    extern s16 D_801DA98E[];
    extern s16 D_801DA992[];
    s32 idx;
    s32 i;
    s32 v;
    *(s16 *)(arg0 + 2) = 2;
    *(s16 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x1C) = 0x15;
    *(u16 *)(arg0 + 0x5C) = *(u16 *)(arg0 + 0x5C) & 0xFFFE;
    if (*(u8 *)(arg0 + 0x5E) == 5) {
        func_80019064(&D_80062BDC);
    }
    if ((*(u16 *)(arg0 + 0x82) & 1) != 0) {
        func_8016B428(arg0);
        func_80019064(D_80062C04);
    }
    if (--*(s16 *)(arg0 + 0x76) == 0) {
        *(u16 *)(arg0 + 0x5C) = *(u16 *)(arg0 + 0x5C) & 0x7FFF;
        func_8002D4C8(0x4A8, 0);
    } else {
        func_8002D4C8(0x4A9, 0);
    }
    idx = *(s16 *)(arg0 + 0xFC) = D_801D5588[*(s16 *)(arg0 + 0x76)];
    for (i = 0; i < 10; i++) {
        D_801DA910[i] = ((Blk12_80185E68 *)(*(s32 *)D_801D55AC[*(s16 *)(arg0 + 0x76)]))[i];
    }
    func_8012A828(arg0, &D_801D5578);
    {
        u8 *p = &D_801D6F8C[idx * 12];
        *(u16 *)D_801DA98A = *(u16 *)p;
        *(u16 *)D_801DA98E = *(u16 *)(p + 2);
        *(u16 *)D_801DA992 = *(u16 *)(p + 4);
    }
    func_8012B21C((void *)arg0);
    *(s32 *)(arg0 + 0x48) = 0x18000;
    v = func_8005C49C() << 4;
    if ((func_8005C49C() & 1) == 0) {
        v = -v;
    }
    *(s32 *)(arg0 + 0x10) = v;
    v = func_8005C49C() << 4;
    if ((func_8005C49C() & 1) == 0) {
        v = -v;
    }
    *(s32 *)(arg0 + 0x18) = v;
    *(s32 *)(arg0 + 0x14) = -0xC0000;
}
