/* sc01_0077: func_80144090 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s32 a; s32 b[4]; } OtBlk;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern u16 D_80115116;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern u16 D_80115116;
extern short D_800B9A02;
extern u16 D_80115116;
extern s32 func_8004787C(s32 a0);
extern void *func_80010A08(s32);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80058C6C(s32, void *);

void func_80144090(s32 param_1) {
    extern OtBlk D_800A651C[];
    extern u8 D_800AF648;
    extern short D_800B9A02;
    void *iVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;
    s32 iVar5;
    s32 iVar6;
    struct {
        s16 v10[4];
        u16 sxy[2];
        s32 p;
        s32 flag;
    } L;
    iVar1 = func_80010A08(0x140);
    if (iVar1 != 0) {
        *(s32 *)(param_1 + 4) = *(s32 *)(param_1 + 4) + *(s32 *)(param_1 + 0x10);
        *(s32 *)(param_1 + 8) = *(s32 *)(param_1 + 8) + *(s32 *)(param_1 + 0x14);
        *(s32 *)(param_1 + 0xc) = *(s32 *)(param_1 + 0xc) + *(s32 *)(param_1 + 0x18);
        L.v10[0] = *(u16 *)(param_1 + 6);
        L.v10[1] = *(u16 *)(param_1 + 0xa);
        L.v10[2] = *(u16 *)(param_1 + 0xe);
        func_8004914C(&D_800AF648);
        func_800491AC(&D_800AF648);
        iVar2 = func_8004955C((s32)L.v10, (s32)L.sxy, &L.p, &L.flag);
        iVar2 = iVar2 + 4;
        if (iVar2 < 0) {
            iVar2 = 0;
        }
        iVar6 = 0;
        do {
            *(s32 *)((u8 *)iVar1 + 4) = 0xffffff;
            *(u8 *)((u8 *)iVar1 + 3) = 4;
            *(u8 *)((u8 *)iVar1 + 7) = 0x20;
            if (*(s32 *)(param_1 + 0x1c) - 6 < 1) {
                *(s16 *)((u8 *)iVar1 + 8) = L.sxy[0];
                *(s16 *)((u8 *)iVar1 + 0xa) = L.sxy[1];
            } else {
                iVar5 = func_8004787C(iVar6);
                *(s16 *)((u8 *)iVar1 + 8) = L.sxy[0] + ((iVar5 * ((*(s32 *)(param_1 + 0x1c) - 6) << 4)) >> 0xc);
                iVar5 = func_80047948(iVar6);
                *(s16 *)((u8 *)iVar1 + 0xa) = L.sxy[1] + ((iVar5 * ((*(s32 *)(param_1 + 0x1c) - 6) << 4)) >> 0xc);
            }
            iVar3 = func_8004787C(iVar6) * (*(s32 *)(param_1 + 0x1c) << 4);
            iVar4 = func_80047948(iVar6) * (*(s32 *)(param_1 + 0x1c) << 4);
            iVar6 = iVar6 + 0x100;
            *(s16 *)((u8 *)iVar1 + 0x10) = L.sxy[0] + ((iVar3 + (iVar4 >> 6)) >> 0xc);
            *(s16 *)((u8 *)iVar1 + 0x12) = L.sxy[1] + ((iVar4 + (iVar3 >> 6)) >> 0xc);
            *(s16 *)((u8 *)iVar1 + 0xc) = L.sxy[0] + ((iVar3 - (iVar4 >> 6)) >> 0xc);
            *(s16 *)((u8 *)iVar1 + 0xe) = L.sxy[1] + ((iVar4 - (iVar3 >> 6)) >> 0xc);
            func_80058C6C(D_800A651C[(u16)D_800B9A02].a + (iVar2 * 4), iVar1);
            iVar1 = (u8 *)iVar1 + 0x14;
        } while (iVar6 < 0x1000);
    }
}
