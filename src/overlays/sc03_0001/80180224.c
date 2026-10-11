/* sc03_0001: func_80180224 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8017E1B4(void *a0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);

void func_80180224(u8 *arg0)
{
    extern u8 D_800D387C[];
    extern u8 D_800D3888[];
    register u8 *param_1 __asm__("$16");
    s32 raw;
    u32 buf[6];
    param_1 = arg0;
    {
        s32 s0;
        s0 = ((s32 (*)(void))func_8012C194)();
        if (s0 == 0) {
            func_8012CAE4(param_1);
            return;
        }
        *(s32 *)(param_1 + 0xCC) = s0;
        func_8001CC3C(s0, 0, 0, 0);
        *(s32 *)(s0 + 0x20) = (s32)D_800D387C;
        *(u8 *)(s0 + 0x27) = 0x9C;
        *(u16 *)(s0 + 0x1A) = 0x3000;
        *(u16 *)(s0 + 0x18) = 0x3000;
        *(u32 *)(s0 + 4) = *(u32 *)(s0 + 4) | 0x50000000;
        func_80128EA8(s0, (s32)(param_1 + 0xD0), (s32)D_800D3888);
    }
    {
        s32 obj = *(s32 *)(param_1 + 0xCC);
        *(u16 *)(obj + 8) = *(u16 *)(param_1 + 6);
        *(u16 *)(obj + 0xA) = *(u16 *)(param_1 + 0xA);
        *(u16 *)(obj + 0xC) = *(u16 *)(param_1 + 0xE);
    }
    raw = *(s16 *)(param_1 + 0x70);
    *(s32 *)(param_1 + 0x1C) = 0x5A;
    *(u16 *)(param_1 + 2) = 1;
    *(s32 *)(param_1 + 0x10) = 0;
    *(s32 *)(param_1 + 0x14) = 0xFFF80000;
    *(s32 *)(param_1 + 0x18) = 0;
    func_8012B0B4((unsigned int *)buf, (raw & 0xFF00) >> 4, (raw & 0xFF) << 6);
    {
        s32 full;
        s32 low;
        full = *(s32 *)buf;
        low = *(s16 *)buf;
        *(s32 *)(param_1 + 0x48) = 0;
        *(s32 *)(param_1 + 0x44) = low;
        *(s32 *)(param_1 + 0x4C) = full >> 16;
    }
}
