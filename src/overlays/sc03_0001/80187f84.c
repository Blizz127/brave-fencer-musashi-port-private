/* sc03_0001: func_80187F84 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u8 b[12]; } Blk12_801854C4_80187F84;
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 aF801848DC(void *a0) __asm__("func_801848DC");
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8001D0E8(s32 arg0, s32 arg1, s32 arg2);
extern void func_8018835C(s32 a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8001C214(s32, s32);
extern void func_8001C97C(s32 a0);
extern void func_8001D0E8(s32 arg0, s32 arg1, s32 arg2);
extern void func_8018835C(s32 a0);
extern void *func_8018872C(void *a0);
void func_8018835C();
void *func_8018872C(void *a0);

void func_80187F84(s32 a0) {
    extern s32 D_801C0B28[][2];
    extern u32 D_801C0B40;
    extern u32 D_801C0B5C;
    extern s16 D_801C0B68[];
    extern Blk12_801854C4_80187F84 D_801C0B50;
    s32 v0;
    s16 idx;
    s16 *p;
    v0 = ((s32 (*)(s32))func_8012C1B8)(a0);
    *(s32 *)(a0 + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(s32))func_8012CAE4)(a0);
        return;
    }
    idx = *(s16 *)(a0 + 0x70);
    p = &D_801C0B68[idx];
    switch (idx) {
    case 7:
    case 9:
    case 10:
    case 12:
        func_8001C810(v0, D_801C0B28[*p][0]);
        *(s32 *)(v0 + 4) |= 0x8040;
        break;
    default:
        func_8001C214(v0, D_801C0B28[*p][0]);
        break;
    }
    func_8001C97C(D_801C0B28[*p][1]);
    func_8001D0E8(*(s32 *)(a0 + 0x20), 0xC8, 0xB4);
    *(s32 *)(a0 + 0x58) = (u32)&D_801C0B40 | 0x40000000;
    *(s16 *)(a0 + 0x5C) = 0x800;
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x20) = (s32)&D_801C0B5C;
    *(s16 *)(a0 + 0xE8) = 0;
    *(Blk12_801854C4_80187F84 *)(a0 + 0xEC) = D_801C0B50;
    *(s16 *)(a0 + 0x10A) = 6;
    func_8018835C(a0);
    *(s32 *)(a0 + 0xDC) = (s32)func_8018872C;
}
