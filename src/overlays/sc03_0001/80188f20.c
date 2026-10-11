/* sc03_0001: func_80188F20 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
void func_80188F6C(void);

void func_80188F20(s32 a0) {
    extern void func_80188F6C(void);
    extern u8 D_800B9A15;
    extern unsigned char D_800B9A13;
    extern u16 D_80115110;
    extern u16 D_80115112;
    extern s16 D_80115126;
    extern void *D_8011DB24;
    void *func_ptr;
    D_800B9A15 = 1;
    D_800B9A13 = 4;
    D_80115110 = 3;
    func_ptr = func_80188F6C;
    D_80115112 = 0;
    D_80115126 = (s16)a0;
    D_8011DB24 = func_ptr;
}
