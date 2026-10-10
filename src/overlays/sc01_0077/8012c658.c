/* sc01_0077: func_8012C658 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct S8012C658 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
};
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80126720[];
extern u8 D_80126720[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern u8 D_80126720[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2) {
    struct S8012C658 sp;
    s32 var_v0;
    u16 *var_a1;
    u16 *end;
    u16 *param;
    if ((arg2 != 0) && (*(u16 *)(arg2 + 0x0) != 0)) {
        sp.unk0 = *(u16 *)(arg2 + 0x6);
        sp.unk2 = *(u16 *)(arg2 + 0xA);
        sp.unk4 = *(u16 *)(arg2 + 0xE);
    } else {
        sp.unk4 = 0;
        sp.unk2 = 0;
        sp.unk0 = 0;
    }
    sp.unk6 = (s16)arg0;
    sp.unk8 = (s16)arg1;
    sp.unkA = 0;
    sp.unk10 = 0;
    sp.unkE = 0;
    sp.unkC = 0x7FFF;
    param = &sp.unk0;
    end = (u16 *)D_80126720;
    if (arg2 == 0) {
        var_a1 = (u16 *)((u8 *)end - 0x6480);
    } else {
        var_a1 = (u16 *)(arg2 + 0x10C);
    }
    while (var_a1 != end) {
        if (*var_a1 == 0) {
            goto found;
        }
        var_a1 = (u16 *)((u8 *)var_a1 + 0x10C);
    }
    var_a1 = 0;
found:
    var_v0 = 0;
    if (var_a1 != 0) {
        var_v0 = ((s32 (*)(u16 *, u16 *))func_8012C890)(param, var_a1);
    }
    return var_v0;
}
