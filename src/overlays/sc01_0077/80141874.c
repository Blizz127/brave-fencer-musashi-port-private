/* sc01_0077: func_80141874 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern unsigned short D_80115112;
extern void func_801754A8(void);
extern s32 func_80014ED4(s32);
extern s32 func_80015018(s32);
extern void func_80141C04(void);
extern u16 D_8011511E;
extern u16 D_8011511C;
extern unsigned short D_80115112;
extern u16 D_80115116;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern u16 D_8011511E;
extern u16 D_80115112;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern u16 D_8011511E;
extern u16 D_8011511C;
extern u16 D_8011511E;
extern short D_800B9A02;
extern u16 D_8011511E;
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern unsigned short D_80115112;
extern u16 D_80115112;
extern short D_800B9A02;
extern u16 D_80115112;
extern void func_801754A8(void);
extern s32 func_80014ED4(s32);
extern s32 func_80015018(s32);
extern void func_80141C04(void);
extern u16 D_8011511E;
extern u16 D_8011511C;
extern unsigned short D_80115112;
extern u16 D_80115116;
extern void (*D_80187F1C[])(void);
void func_80141C04(void);

void func_80141874(void) {
    register void (*fp)(void) __asm__("$2");
    func_801754A8();
    D_8011511E = func_80014ED4(0);
    D_8011511C = func_80015018(0);
    fp = D_80187F1C[D_80115112];
    fp();
    func_80141C04();
    D_80115116 += 1;
}
