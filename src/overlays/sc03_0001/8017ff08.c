/* sc03_0001: func_8017FF08 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
void func_8017F1F0(s32 a0, s32 a1);
extern s32 D_801EEAE8;
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32 arg0, s32 arg1);
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32 arg0, s32 arg1);
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32 arg0, s32 arg1);
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32 arg0, s32 arg1);
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32 arg0, s32 arg1);
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32, s32);
extern s32 func_80029504(void);
extern s32 D_801EEAE8;
extern void func_8017F1F0(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern void func_8017F1F0(s32 arg0, s32 arg1);

s32 func_8017FF08(void) {
    extern s32 D_8019177C;
    s32 v;
    D_801EEAE8 = (s32)&D_8019177C;
    v = func_80029504();
    if ((u32)(v - 0x64) < 0x1F4) {
        return -1;
    }
    func_8017F1F0(0x96, 0xF0);
}
