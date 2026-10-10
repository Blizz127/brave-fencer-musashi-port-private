/* sc01_0077: func_8013EA54 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
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
extern s16 D_800B9A08;
extern unsigned short D_80115112;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern u16 D_8011511A;
extern s16 D_800B9A08;
extern unsigned short D_80115112;
void func_8013E958();
extern s32 func_80141C50(void);
extern void func_8013F244(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_80137B80(void);
extern void func_8013E958(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern s32 D_80115130;
extern s16 D_8011514C;
extern s16 D_800B9A08;
void func_8013F244(void);
void func_8013FAF8(s16 arg0, s16 arg1);
s32 func_80141C50(void);

void func_8013EA54(void) {
    s32 sp10[2];
    if ((s16)func_80141C50() == 0) {
        D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
        func_8013F244();
        func_8013FAF8(0, 5);
        func_80137B80();
        if (D_8011511E & 0x40) {
            if (D_8011511A == 0 && D_800B9A08 == 0x308F) {
                func_8002D4C8(0x466, 0);
            } else {
                u16 v = D_8011511A;
                if (v != 4) {
                    D_80115130 = 0;
                }
                if ((u16)(v - 1) <= 1) {
                    D_8011514C = 0;
                }
                func_8002D4C8(0x45D, 0);
                D_80115112 += 1;
            }
        } else if (D_8011511E & 0x810) {
            func_8013E958();
        }
    }
    (void)sp10;
}
