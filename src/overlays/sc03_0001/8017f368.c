/* sc03_0001: func_8017F368 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC;
extern void func_8012A568(void (*a0)(void));
extern short D_800B9A02;
extern s16 D_800B9A02;
extern void func_8017E204(void *arg0);
extern void func_8017E1B4(void *a0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern void func_8012E32C(void);
extern void func_8017F750(void *, s32);
extern s32 func_8004969C(s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern s32 func_8004961C(s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern void *func_80010A08(s32);
extern s32 func_80058C6C(s32, void *);
extern void func_8012E28C(s32, s32);
void func_8017F750(void *a0, s32 a1);

void func_8017F368(u16 *a0, s32 a1)
{
    extern s32 D_800A651C[][5];
    extern u16 D_801914BC[];
    extern u16 D_8019153C[];
    extern u16 D_801915DC[][4];
    extern u16 D_801915DE[][4];
    extern u16 D_801915E0[][4];
    extern u16 D_801915E2[][4];
    register s32 zr __asm__("$0");
    u16 pad0[16];
    u16 va[16];
    u16 vb[16];
    s32 sxy[8];
    s16 idx[4];
    s32 p;
    s32 otz;
    s32 flag;
    u16 attr;
    s32 type;
    s32 type2;
    u16 *p1;
    u16 *p2;
    register u16 *dst __asm__("$4");
    s32 i;
    u8 *pk;
    s32 j;
    func_8012E32C();
    attr = a0[3];
    type = attr & 0xFF;
    type2 = type + zr;
    if ((attr & 0xF00) == 0x200) {
        func_8017F750(a0, a1);
        return;
    }
    p1 = (u16 *)((u8 *)D_801914BC + type * 0x20);
    i = 0;
    p2 = p1 + 2;
    dst = va;
    while (i < 4) {
        dst[0] = a0[0] + p1[0];
        dst[1] = a0[1] + p2[-1];
        dst[2] = a0[2] + p2[0];
        i++;
        p1 += 4;
        p2 += 4;
        dst += 4;
    }
    if (func_8004969C((s32)&va[0], (s32)&va[4], (s32)&va[8], (s32)&va[12],
                  &sxy[0], &sxy[1], &sxy[2], &sxy[3], &p, &otz, &flag) <= 0) {
        return;
    }
    otz -= 0x10;
    if (otz < 0) {
        return;
    }
    if (otz >= 0x1000) {
        return;
    }
    p1 = (u16 *)((u8 *)D_8019153C + type2 * 0x20);
    i = 0;
    p2 = p1 + 2;
    dst = vb;
    while (i < 4) {
        dst[0] = a0[0] + p1[0];
        dst[1] = a0[1] + p2[-1];
        dst[2] = a0[2] + p2[0];
        i++;
        p1 += 4;
        p2 += 4;
        dst += 4;
    }
    func_8004961C((s32)&vb[0], (s32)&vb[4], (s32)&vb[8], (s32)&vb[12],
                  &sxy[4], &sxy[5], &sxy[6], &sxy[7], &p, &flag);
    pk = func_80010A08(0xA8);
    for (j = 0; j < 4; j++) {
        idx[0] = D_801915DC[j][0];
        idx[1] = D_801915DE[j][0];
        idx[2] = D_801915E0[j][0];
        idx[3] = D_801915E2[j][0];
        *(s32 *)(pk + 0x4) = a1 & -(idx[0] < 4);
        *(s32 *)(pk + 0xC) = a1 & -(idx[1] < 4);
        *(s32 *)(pk + 0x14) = a1 & -(idx[2] < 4);
        *(s32 *)(pk + 0x1C) = a1 & -(idx[3] < 4);
        pk[7] = 0x3A;
        *(u32 *)(pk + 0x0) = 0x08000000;
        *(s32 *)(pk + 0x8) = sxy[idx[0]];
        *(s32 *)(pk + 0x10) = sxy[idx[1]];
        *(s32 *)(pk + 0x18) = sxy[idx[2]];
        *(s32 *)(pk + 0x20) = sxy[idx[3]];
        func_80058C6C(D_800A651C[(u16)D_800B9A02][0] + (otz * 4), pk);
        pk += 0x24;
    }
    *(s32 *)(pk + 0x4) = a1;
    pk[7] = 0x2A;
    *(u32 *)(pk + 0x0) = 0x05000000;
    *(s32 *)(pk + 0x8) = sxy[0];
    *(s32 *)(pk + 0xC) = sxy[1];
    *(s32 *)(pk + 0x10) = sxy[2];
    *(s32 *)(pk + 0x14) = sxy[3];
    func_80058C6C(D_800A651C[(u16)D_800B9A02][0] + (otz * 4), pk);
    func_8012E28C(otz, 1);
}
