/* sc02_0037: func_8016AB6C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AB6C.c (preprocessed; only the declarations it uses),
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
typedef struct Obj_8016AB6C {
    s32 unk0;
    s32 unk4;
    u8 pad8[0xE - 0x8];
    s16 unkE;
    u8 pad10[0x24 - 0x10];
    u8 unk24, unk25, unk26, unk27;
    u8 pad28[0x2E - 0x28];
    s16 unk2E;
    s16 unk30;
} Obj_8016AB6C;
typedef struct Ent_8016AB6C {
    u16 unk0, unk2, unk4, unk6, unk8, unkA, unkC, unkE;
    s32 unk10, unk14, unk18, unk1C;
    Obj_8016AB6C *unk20;
    s16 unk24, unk26, unk28, unk2A;
    s32 unk2C;
    s32 unk30;
} Ent_8016AB6C;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef struct SVec_8016AB6C {
    s16 vx, vy, vz, pad;
} SVec_8016AB6C;
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
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_80139FBC(struct obj *a0);
extern s32 func_8005C49C(void);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801465C0(void);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146C3C(u8 *a0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern int func_8005C49C(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
void func_80146C3C(u8 *a0);
extern void func_80146C3C();
extern void func_80146C3C(u8*);
extern void func_800D20C0(void *a0, void *a1, s32 a2);

s32 func_8016AB6C(s32 arg0) {
    typedef struct Obj_8016AB6C {
        s32 unk0;
        s32 unk4;
        u8 pad8[0xE - 0x8];
        s16 unkE;
        u8 pad10[0x24 - 0x10];
        u8 unk24, unk25, unk26, unk27;
        u8 pad28[0x2E - 0x28];
        s16 unk2E;
        s16 unk30;
    } Obj_8016AB6C;
    typedef struct Ent_8016AB6C {
        u16 unk0, unk2, unk4, unk6, unk8, unkA, unkC, unkE;
        s32 unk10, unk14, unk18, unk1C;
        Obj_8016AB6C *unk20;
        s16 unk24, unk26, unk28, unk2A;
        s32 unk2C;
        s32 unk30;
    } Ent_8016AB6C;
    typedef struct SVec_8016AB6C {
        s16 vx, vy, vz, pad;
    } SVec_8016AB6C;
    extern s32 func_801783D0(s32 a0, s32 a1);
    extern s32 func_80024054(u8 *a0, u8 *a1);
    extern void func_8001CE28(Obj_8016AB6C *a0, u8 *a1);
    extern s32 func_8005C49C(void);
    extern void func_801465C0(void);
    extern void func_80146C3C(u8 *a0);
    extern void func_800D20C0(void *a0, void *a1, s32 a2);
    extern u8 D_80186D38[];
    extern u8 D_801C8960[];
    extern u8 D_80186D48[];
    extern u8 D_801C8988[];
    SVec_8016AB6C sp10;
    SVec_8016AB6C sp18;
    s16 var_s0;
    s16 var_v1;
    s16 var_s3;
    s16 tmp;
    s32 temp_v0;
    u32 r;
    u8 var_c2;
    Obj_8016AB6C *obj;
    temp_v0 = func_801783D0(((Ent_8016AB6C *)arg0)->unk30, 0);
    var_s0 = 3;
    var_v1 = -0x1000;
    ((Ent_8016AB6C *)arg0)->unk30 = temp_v0;
    do {
        if (temp_v0 & var_v1) {
            goto lout;
        }
        var_s0--;
        var_v1 >>= 4;
    } while (var_s0 >= 0);
lout:
    switch (((Ent_8016AB6C *)arg0)->unk2C) {
    case 0:
        ((Ent_8016AB6C *)arg0)->unk26 = 1;
        ((Ent_8016AB6C *)arg0)->unk24 = 0x60;
        ((Ent_8016AB6C *)arg0)->unkA -= 0x20;
        break;
    case 1:
    case 5:
        ((Ent_8016AB6C *)arg0)->unk14 = 0xFFF60000;
        r = ((u32(*)())func_8005C49C)();
        tmp = var_s0 + 1;
        var_s0 = tmp;
        ((Ent_8016AB6C *)arg0)->unk10 = (r & 0xF) - 8 << 0xF;
        ((Ent_8016AB6C *)arg0)->unk18 = ((r >> 4) & 0xF) - 8 << 0xF;
        ((Ent_8016AB6C *)arg0)->unk26 = 4;
        ((Ent_8016AB6C *)arg0)->unk24 = 0x80;
        ((Ent_8016AB6C *)arg0)->unk30 |= 0xA << (tmp * 4);
        break;
    case 2:
    case 4:
        ((Ent_8016AB6C *)arg0)->unk26 = 4;
        ((Ent_8016AB6C *)arg0)->unk24 = 0x80;
        ((Ent_8016AB6C *)arg0)->unkA -= 0x18;
        break;
    case 3:
        tmp = var_s0 + 1;
        var_s0 = tmp;
        var_s0++;
        ((Ent_8016AB6C *)arg0)->unk26 = 4;
        ((Ent_8016AB6C *)arg0)->unk24 = 0x80;
        ((Ent_8016AB6C *)arg0)->unkA -= 0x18;
        ((Ent_8016AB6C *)arg0)->unk30 = (((Ent_8016AB6C *)arg0)->unk30 | (0xF << (tmp * 4))) * 0x10;
        break;
    case 6:
    case 7:
        obj = ((Obj_8016AB6C *(*)(s32))func_801465C0)(temp_v0);
        if (obj == 0) {
            ((void(*)(Ent_8016AB6C *))func_80146C3C)(((Ent_8016AB6C *)arg0));
            return;
        }
        sp10.vx = ((Ent_8016AB6C *)arg0)->unk6;
        sp10.vy = ((Ent_8016AB6C *)arg0)->unkA - 0x18;
        sp10.vz = ((Ent_8016AB6C *)arg0)->unkE;
        ((void(*)(SVec_8016AB6C *, SVec_8016AB6C *, s32))func_800D20C0)(&sp10, &sp18, 6);
        ((Ent_8016AB6C *)arg0)->unk6 = sp10.vx;
        ((Ent_8016AB6C *)arg0)->unkA = sp10.vy;
        ((Ent_8016AB6C *)arg0)->unkE = sp10.vz;
        if (((Ent_8016AB6C *)arg0)->unk2C == 6) {
            var_s3 = func_80024054(D_80186D38, D_801C8960) + 3;
            func_8001CE28(obj, D_801C8960);
        } else {
            var_s3 = func_80024054(D_80186D48, D_801C8988) + 9;
            func_8001CE28(obj, D_801C8988);
        }
        obj->unkE = var_s3;
        obj->unk4 |= 0x04000000;
        if (((Ent_8016AB6C *)arg0)->unk2C == 6) {
            obj->unk27 = 0xB5;
            var_s0 = 0x70;
        } else {
            obj->unk27 = 0xAE;
            var_s0 = 0xB0;
        }
        var_c2 = var_s0;
        var_s0 = var_s3 >> 2;
        obj->unk2E = -8;
        obj->unk30 = 0;
        obj->unk26 = var_c2;
        obj->unk25 = var_c2;
        obj->unk24 = var_c2;
        ((Ent_8016AB6C *)arg0)->unk20 = obj;
        break;
    }
    ((Ent_8016AB6C *)arg0)->unk2A = 4 - (var_s0 * 4);
    ((Ent_8016AB6C *)arg0)->unk28 = var_s0;
    ((Ent_8016AB6C *)arg0)->unk1C = 0xB;
    ((Ent_8016AB6C *)arg0)->unk2++;
}
