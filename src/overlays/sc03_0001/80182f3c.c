/* sc03_0001: func_80182F3C from Druthulu/BFM-decomp
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
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012E544(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s32 func_8012E544(s32 a0);
extern void func_8017E1B4(void *a0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
extern s32 func_800291B4(s32 arg);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32);
void aF80180B5C(void *arg0) __asm__("func_80180B5C");
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);
extern s32 func_80180B5C(void *a0);
extern s32 func_801877C0(s32);
extern void func_8018166C(void *);
s32 aF8018166C(void *arg0) __asm__("func_8018166C");
extern s32 func_801877C0(s32);
extern s32 func_8012E544(s32 a0);
extern s32 func_801877C0(s32 a0);
extern s32 func_801877C0(s32 a0);
extern s32 func_801877C0(s32 a0);
extern s32 func_801877C0(s32 a0);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern s32 func_801877C0(s32);
extern short D_80191F00;
extern short D_80191F40;
extern short D_80191F80;
extern short D_80191FC0;
extern short D_80192000;
extern short D_80192070;
extern short D_801920C8;
extern short D_80192120;
extern short D_80192190;
extern short D_801921E8;
extern short D_80192278;
extern short D_801922A0;

s32 func_80182F3C(s32 a0) {
    s32 e;
    s32 cond;
    s32 result;
    register s32 v __asm__("$2");
    s32 c;
    if (*(u16 *)(a0 + 0) == 0xA2) {
        e = func_8012E544(0xA4);
        if (e == 0) {
            cond = 0;
        } else {
            cond = (*(u16 *)(e + 2) == 3);
        }
    } else {
        e = func_8012E544(0xA2);
        if (e == 0) {
            cond = 0;
        } else {
            cond = (*(u16 *)(e + 2) == 3);
        }
    }
    if (!cond) {
        v = (s32)&D_801922A0;
        if (*(u16 *)(a0 + 0) == 0xA2) {
            v = (s32)&D_80192278;
        }
        return v;
    }
    result = (s32)&D_80191F00;
    switch (((s32 (*)(void))func_801877C0)()) {
    case 0:
        c = func_800291B4(0xD6) & 0xFF;
        __asm__("" : "=r"(c) : "0"(c));
        if (c != 0) {
            result = (s32)&D_80191F80;
            if ((c & 1) != 0) {
                result = (s32)&D_80191F40;
            }
        }
        c++;
        if ((c & 0xFF) == 0) {
            c = 2;
        }
        func_800291A0(0xD6, c & 0xFF);
        break;
    case 1:
        c = func_800291B4(0xD7) & 0xFF;
        switch (c % 3) {
        case 0:
            result = (s32)&D_80191FC0;
            break;
        case 1:
            result = (s32)&D_80192000;
            break;
        default:
            result = (s32)&D_80192070;
            break;
        }
        c++;
        func_800291A0(0xD7, c & 0xFF);
        break;
    case 2:
        c = func_800291B4(0xD9) & 0xFF;
        __asm__("" : "=r"(c) : "0"(c));
        result = (s32)&D_80192190;
        if ((c & 1) != 0) {
            result = (s32)&D_801921E8;
        }
        c++;
        func_800291A0(0xD9, c & 0xFF);
        break;
    case 3:
        break;
    default:
        c = func_800291B4(0xD8) & 0xFF;
        __asm__("" : "=r"(c) : "0"(c));
        result = (s32)&D_801920C8;
        if ((c & 1) != 0) {
            result = (s32)&D_80192120;
        }
        c++;
        func_800291A0(0xD8, c & 0xFF);
        break;
    }
    return result;
}
