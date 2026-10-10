/* sc01_0077: func_801865EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
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
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(int, void *);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern int func_8005C49C(void);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B21C(void *a0);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B21C(void *a0);

void func_801865EC(s32 arg0) {
    extern s32 D_801D5638[];
    s32 ret;
    s32 obj;
    s32 base;
    s32 ang;
    s32 v;
    ret = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(arg0 + 0x20) = ret;
    if (ret == 0) {
        func_8012CAE4((void *)arg0);
    } else {
        func_8001C214(*(s32 *)(arg0 + 0x20), D_801D5638[func_8005C49C() % 3]);
        if (*(s16 *)(arg0 + 0x70) != 0) {
            s32 addr = arg0 + 0x24;
            ang = -*(s16 *)(arg0 + 0xE);
            base = ang + 0x400;
            *(s16 *)(arg0 + 0x2A) = -2;
            *(s16 *)(arg0 + 0x24) = base * 48 / 2048;
            *(s16 *)(arg0 + 0x26) = base * 96 / 2048;
            *(s16 *)(arg0 + 0x28) = base / 64;
            obj = *(s32 *)(arg0 + 0x20);
            *(u16 *)(obj + 0x2C) = *(u16 *)(obj + 0x2C) | 0x80;
            *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x80) = addr;
        }
        obj = *(s32 *)(arg0 + 0x20);
        *(u16 *)(obj + 0x2C) = *(u16 *)(obj + 0x2C) | 0x10;
        obj = *(s32 *)(arg0 + 0x20);
        *(u16 *)(obj + 0x1C) = 0x2000;
        *(u16 *)(obj + 0x1A) = 0x2000;
        *(u16 *)(obj + 0x18) = 0x2000;
        func_8012A828(arg0, &D_80186E48);
        *(s16 *)(arg0 + 2) = 1;
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
        if (*(s16 *)(arg0 + 0x70) == 0) {
            *(s32 *)(arg0 + 0x14) = -(func_8005C49C() << 4);
        } else {
            *(s32 *)(arg0 + 0x14) = -0x80000 - (func_8005C49C() << 5);
        }
        *(s32 *)(arg0 + 0x1C) = 0x32;
    }
}
