/* sc03_0001: func_801770E0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u32 func_801783D0(s32, s32);
extern void *func_80177784(void *a0, s32 a1, s32 a2, s32 a3);
extern u32 func_801783D0(s32 a0, s32 a1);
extern void *func_801777BC();
extern u32 func_801783D0(s32 a0, s32 a1);
extern void *func_80177784(void *a0, s32 a1, s32 a2, s32 a3);
extern u32 func_801783D0(s32 a0, s32 a1);
extern void *func_801777BC();
extern u16 D_8011F830;
extern u16 D_8011F82E;
void *func_80177784(void *a0, s32 a1, s32 a2, s32 a3);
void *func_801777BC(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
u32 func_801783D0(s32 a0, s32 a1);

u32 *func_801770E0(void *param_1, u32 param_2, s16 param_3_)
{
    s32 c3 = 3;
    s32 cb8 = 0xb8;
    s32 cff = 0xff;
    s32 iVar6 = (s16)param_3_;
    u32 uVar5 = iVar6 << 16;
    void *uVar2;
    void *u4, *u5;
    u32 *puVar3;
    s16 sVar1;
    u32 uVar4;
    u32 dl;
    s32 t;
    uVar2 = ((void * (*)(void *, s32, s32))func_80177784)(param_1, uVar5 | (u16)param_2, 0x6e165010);
    uVar2 = ((void * (*)(void *, s32, s32))func_80177784)(uVar2, uVar5 | ((param_2 + 8) & 0xffff), 0x6e165808);
    uVar2 = ((void * (*)(void *, s32, s32))func_80177784)(uVar2, uVar5 | ((param_2 + 0x10) & 0xffff), 0x6e164060);
    u4 = ((void * (*)(void *, s32, s32))func_80177784)(uVar2, uVar5 | ((param_2 + 0x30) & 0xffff), 0x6e163858);
    sVar1 = (s16)func_801783D0(D_8011F830, 4);
    u5 = func_801777BC(u4, sVar1, (s32)((param_2 + 0x18) << 16) >> 16, iVar6, c3, cb8, cff);
    sVar1 = (s16)func_801783D0(D_8011F82E, 4);
    puVar3 = (u32 *)func_801777BC(u5, sVar1, (s32)((param_2 + 0x38) << 16) >> 16, iVar6, c3, cb8, cff);
    dl = ((struct { u16 h; } *)&D_8011F830)->h;
    { u32 v0m = ((u32)(puVar3 - 5) & 0xffffff) | 0x3000000;
      register u32 c6055 __asm__("$6") = 0x6055ff00;
      puVar3[1] = c6055;
      *puVar3 = v0m; }
    uVar4 = ((iVar6 - 4) << 16) | ((param_2 + 1) & 0xffff);
    puVar3[2] = uVar4;
    puVar3[3] = ((s32)(dl * 0x50e6) >> 16) | 0x20000;
    dl = ((struct { u16 h; } *)&D_8011F82E)->h;
    puVar3[5] = ((u32)puVar3 & 0xffffff) | 0x3000000;
    puVar3[10] = ((u32)(puVar3 + 5) & 0xffffff) | 0x3000000;
    puVar3[6] = 0x60ff3214;
    puVar3[7] = uVar4;
    puVar3[0xb] = 0x60000000;
    puVar3[0xc] = ((iVar6 - 5) << 16) | (param_2 & 0xffff);
    t = (s32)(dl * 0x50e6) >> 16;
    puVar3[8] = t | 0x20000;
    puVar3[0xd] = (t + 2) | 0x40000;
    return puVar3 + 0xf;
}
