/* sc03_0001: func_80185528 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
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
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern short D_80192640;
extern void func_80187778(s32*, s32);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_801855CC(void *a0);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern short D_80192640;
extern short D_80192650;
extern void func_80187778(s32 *a0, s32 a1);
s32 func_801855CC(void *a0);

void func_80185528(arg0)
void *arg0;
{
    s32 v;
    void *v1;
    if (func_8018727C(arg0, &D_80192650) != 0) {
        v = func_8018766C(6, 7);
        if (v == 0) {
            v = func_8018766C(7, 0x10);
            if (v == 0) {
                v = func_8018766C(0x10, 0x14);
                if (v == 0) {
                    v = 1;
                } else {
                    v = 0xC;
                }
            } else {
                v = 6;
            }
        } else {
            v = 5;
        }
        *(s16 *)((char *)arg0 + 0x2) = v;
        __asm__ __volatile__("");
        func_80187778((s32 *)arg0, (s32)&D_80192640);
        v1 = *(void **)((char *)arg0 + 0x68);
        *(s16 *)((char *)v1 + 0xC) = 0x7FFF;
        func_801788B8((s32)arg0, (s32)&func_801855CC);
    }
}
