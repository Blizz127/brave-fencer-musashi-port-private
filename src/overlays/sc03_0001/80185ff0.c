/* sc03_0001: func_80185FF0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
void func_80185950(void *arg0);
extern s32 func_80187690(u8 a0, u8 a1, u8 a2, u8 a3);
extern void func_80185950(void *arg0);
extern s32 func_80187690(u8 a0, u8 a1, u8 a2, u8 a3);
extern void func_80185950(void *arg0);
extern s32 func_80187690(u8 a0, u8 a1, u8 a2, u8 a3);

void func_80185FF0(void *a0) {
    *(s32 *)(*(s32 *)((s32)a0 + 0xCC) + 0xB0) = 2;
    if (func_80187690(10, 0, 10, 30) == 0 && func_80187690(15, 0, 15, 30) == 0) {
        return;
    }
    *(u8 *)((s32)a0 + 0x105) = *(u16 *)((s32)a0 + 2);
    func_80185950(a0);
}
