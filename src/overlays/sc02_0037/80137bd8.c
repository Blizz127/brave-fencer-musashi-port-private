/* sc02_0037: func_80137BD8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80135EB0.c (preprocessed; only the declarations it uses),
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
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u8 D_800A6518[];
extern void func_80137614(s32 a0, s32 a1, s32 a2);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_801376E8(int a0, int a1);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_80139BE0(s32 a0);
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void * aF801376E8(int a0, int a1) __asm__("func_801376E8");
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
extern s32 D_80127524;
void func_801377B4(s32 a0, s32 a1, s32 a2);
extern s32 D_80127524;
extern s32 D_801269F0;
extern void func_801392FC();
extern void func_801397B0(s32 a0);
extern void func_80137DD4(s32 a0, u8 *a1, u8 *a2);
extern void func_80139680(s32 a0, u8 *a1);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern s32 D_80127524;
extern u16 D_800B99D8;
void func_80137DD4(s32 ent, u8 *arg, u8 *work);

void func_80137BD8(s32 a0) {
    u8 buf[8];
    if ((*(s32 *)(a0 + 8) & 0x1000) != 0) {
        func_801392FC(a0, *(u8 *)(a0 + 0x1E),
                      &D_800A6518[(u16)D_800B9A02 * 20]);
        if (*(u8 *)(a0 + 0x20) != 0) {
            func_801397B0(a0);
        }
    }
    if (D_80127524 == a0) {
        if (*(s16 *)(a0 + 4) == 7) {
            buf[0] = 0x39;
            buf[1] = 0xFF;
            buf[2] = 0x71;
            func_80137DD4(a0, buf, &D_800A6518[(u16)D_800B9A02 * 20]);
        } else if (*(s16 *)(a0 + 4) == 3) {
            if ((D_800B99D8 & 4) != 0) {
                func_80139680(a0, &D_800A6518[(u16)D_800B9A02 * 20]);
            }
        }
    }
}
