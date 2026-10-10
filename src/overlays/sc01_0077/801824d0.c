/* sc01_0077: func_801824D0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012DBD0(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8012CC64(s32 a0, void *a1);
extern void func_8012CBF4(s32);
extern s32 func_8012CBA4(s32 a0);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_80182FD0(s32 a0);
extern void func_80182E30(short*);
extern void func_8018294C(void*);
extern u8 D_8018AB10[];
void func_8018294C(void *a0);
void func_80182E30(short *param_1);

void func_801824D0(int param_1)
{
    u8 bVar1;
    s32 uVar3;
    s32 uVar4;
    func_8012DBD0(param_1, 0x50, *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12) + 0x800, 0x1D);
    bVar1 = *(u8 *)(param_1 + 0xC2);
    switch (bVar1) {
    case 0:
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x10) -= 0x100;
        *(s32 *)(param_1 + 0x1C) += 1;
        if (*(s32 *)(param_1 + 0x1C) < 0x29) {
            if (*(s32 *)(param_1 + 0x14) < 1)
                uVar3 = ((s32 (*)(s32))func_8012CBF4)(param_1);
            else
                uVar3 = func_8012CC64(param_1, &D_8018AB10);
            if ((uVar3 & 0x2000) == 0)
                return;
            if ((uVar3 & 0xFF) != 2) {
                *(u8 *)(param_1 + 0xC2) = 1;
                func_80143B6C(param_1, 1);
                *(s32 *)(param_1 + 0x14) = 0xFFF30000;
                *(s32 *)(param_1 + 0x1C) = 0;
                return;
            }
            goto LAB_80182750;
        }
        goto LAB_80182780;
    case 1:
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x10) -= 0x100;
        *(s32 *)(param_1 + 0x1C) += 1;
        if (*(s32 *)(param_1 + 0x1C) < 0x29) {
            uVar4 = *(s32 *)(param_1 + 0x14);
            uVar3 = func_8012CC64(param_1, &D_8018AB10);
            if ((uVar3 & 0x2000) == 0)
                return;
            if ((uVar3 & 0xFF) != 2) {
                func_80143B6C(param_1, 1);
                *(s32 *)(param_1 + 0x14) = uVar4;
                *(u8 *)(param_1 + 0xC2) = 2;
                *(s32 *)(param_1 + 0x1C) = 0;
                *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x10) = 0;
                return;
            }
            goto LAB_80182750;
        }
        goto LAB_80182780;
    case 2:
        *(s32 *)(param_1 + 0x10) = *(s32 *)(param_1 + 0x10) * 15 / 16;
        *(s32 *)(param_1 + 0x18) = *(s32 *)(param_1 + 0x18) * 15 / 16;
        if ((*(u8 *)(param_1 + 0xC3) & 1) != 0) {
            uVar3 = func_8012CBA4(param_1);
            if ((uVar3 & 0x2000) == 0)
                goto LAB_80182780;
            if ((uVar3 & 0xFF) == 2)
                goto LAB_80182750;
        } else {
            uVar3 = ((s32 (*)(s32))func_8012CBF4)(param_1);
            if ((uVar3 & 0x2000) != 0)
                *(u8 *)(param_1 + 0xC3) |= 1;
        }
        if ((*(s32 *)(param_1 + 0x1C) & 3) == 3)
            func_80143B6C(param_1, 1);
        *(s32 *)(param_1 + 0x1C) += 1;
        if (*(s32 *)(param_1 + 0x1C) < 0x11)
            return;
        if ((uVar3 & 0x2000) == 0)
            goto LAB_80182780;
        if ((uVar3 & 0xFF) != 2)
            goto LAB_80182760;
    LAB_80182750:
        func_80182FD0(param_1);
        return;
    LAB_80182760:
        if (*(s16 *)(param_1 + 0x76) <= 0)
            goto LAB_80182780;
        ((void (*)(s32))func_80182E30)(param_1);
        return;
    LAB_80182780:
        ((void (*)(s32))func_8018294C)(param_1);
        return;
    default:
        return;
    }
}
