/* SC02.CD member35: func_80176144 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef unsigned int uint;
typedef struct { s32 g0; s32 pad[2]; } S_AF634;
extern u16 D_80078EB2;
extern void func_8012A568(void (*a0)(void));
extern s16 D_8011F7BC;
extern s16 D_8011F7BE;
s32 func_80178004(uint *param_1, uint param_2, int param_3);

void func_80176144(s32 a0)
{
    extern S_AF634 aAF634[] __asm__("D_800AF634");
    extern S_AF634 aAF638[] __asm__("D_800AF638");
    extern u8 D_8011F7A8;
    extern s16 D_8011F7BC;
    extern s16 D_8011F7BE;
    extern s32 func_80178004();
    u32 *slot;
    u32 *p;
    s16 param_1 = (s16)a0;
    p = (u32 *)(aAF638[param_1].g0 + aAF634[param_1].g0 * 4);
    slot = (u32 *)(param_1 * 4 + (s32)&D_8011F7A8);
    slot[14] = (u32)p;
    __asm__("");
    p = (u32 *)func_80178004((s32)p,
                             (s16)((*(u16 *)&D_8011F7BC) - 0x17),
                             (s16)((*(u16 *)&D_8011F7BE) + 0x65));
    slot[16] = (u32)p - 0x14;
    p += 5;
    aAF634[param_1].g0 += ((s32)p - (s32)slot[14]) >> 2;
}
extern u16 D_80078EB2;
