/* SC02.CD member35: func_80175590 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s16 D_800B9A02;
extern void func_801757A0(s32);
extern void func_801757A0(s32 a0);
extern short D_800B9A02;
void func_801757A0(s32 a0);

void func_80175590(void *arg0) {
    u8 temp_a0;
    register s16 temp_v1 __asm__("$3");
    s32 temp_v0;
    temp_a0 = *(u8 *)((u8 *)arg0 + 5);
    temp_v0 = *(u8 *)((u8 *)arg0 + 6) - temp_a0;
    temp_v1 = -(temp_v0 & 0xFF);
    *(u8 *)((u8 *)arg0 + 6) = (u8)temp_v0;
    __asm__ __volatile__("" : : : "memory");
    temp_v0 = *(u8 *)((u8 *)arg0 + 6);
    *(u8 *)((u8 *)arg0 + 5) = (u8)(temp_a0 + 0xFF);
    *(s16 *)((u8 *)arg0 + 0x10) = temp_v1;
    *(s16 *)((u8 *)arg0 + 0xC) = temp_v1;
    *(s16 *)((u8 *)arg0 + 0x16) = (s16)temp_v0;
    *(s16 *)((u8 *)arg0 + 0x12) = (s16)temp_v0;
    *(s16 *)((u8 *)arg0 + 0xE) = (s16)temp_v0;
    *(s16 *)((u8 *)arg0 + 0x14) = (s16)temp_v0;
    func_801757A0((s32)D_800B9A02);
    if (*(u8 *)((u8 *)arg0 + 5) == 0) {
        *(u8 *)((u8 *)arg0 + 8) = 0;
        *(u8 *)((u8 *)arg0 + 1) = (u8)(*(u8 *)((u8 *)arg0 + 1) + 1);
    }
}
extern s16 D_800B9A02;
