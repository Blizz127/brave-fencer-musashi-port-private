/* sc01_0077: func_80129CF8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct BigCopy;
struct BigCopy { s32 words[41]; };
typedef struct { s32 vpx, vpy, vpz, vrx, vry, vrz, rz, super; } RView;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern struct BigCopy D_80126DB8;
extern u8 D_80126948[];
extern struct BigCopy D_80114EE8;
extern s32 D_80126E60[];
extern s8 D_801150D6;
extern u8 D_80127504;
extern void func_8012A328(void);
extern void func_80053308(s32);
extern s32 func_80012F74(s32, s32, s32, s32);
extern void func_80054DCC(void *);
extern s8 D_801150D6;
extern u8 D_80127504;
extern s32 D_80126E60[];
extern s32 D_80126F04[];
extern u8 D_80126948[];
extern s32 D_80126FA8[];
extern struct BigCopy D_80126DB8;
extern u8 D_800AF630[];
extern s32 D_800AE688[];
extern s32 D_801151D4;
void func_8012A328(void);

void func_80129CF8(void)
{
    RView view;
    s32 *cam;
    s32 *p1;
    s32 *p2;
    s32 a;
    s32 b;
    s32 iVar2;
    func_8012A328();
    p2 = (s32 *)D_800AF630;
    p1 = (s32 *)&D_80126DB8;
    if (*(u8 *)&D_801150D6 == 1) {
        cam = D_80126E60;
    } else if (*(u8 *)&D_801150D6 == 2) {
        cam = D_80126F04;
    } else {
        cam = (s32 *)D_80126948;
        if (*(u8 *)&D_801150D6 == 3) {
            cam = D_80126FA8;
        }
    }
    if (cam[0] != 0) {
        (*(void (*)(s32 *))cam[0])(cam);
    }
    func_80053308(cam[2]);
    if (D_80127504 != 0) {
        p1[0xf] = (s16)func_80012F74((s16)p1[0xf], (s16)cam[0xf], 2, 1);
        p1[0x10] = (s16)func_80012F74((s16)p1[0x10], (s16)cam[0x10], 2, 1);
        p1[0x11] = (s16)func_80012F74((s16)p1[0x11], (s16)cam[0x11], 2, 1);
        p1[0x12] = (s16)func_80012F74((s16)p1[0x12], (s16)cam[0x12], 2, 1);
        p1[0x13] = (s16)func_80012F74((s16)p1[0x13], (s16)cam[0x13], 2, 1);
        p1[0x14] = (s16)func_80012F74((s16)p1[0x14], (s16)cam[0x14], 2, 1);
        p1[0x15] = (s16)func_80012F74((s16)p1[0x15], (s16)cam[0x15], 2, 1);
        D_80127504 = D_80127504 - 1;
    } else {
        p1[0xf] = cam[0xf];
        p1[0x10] = cam[0x10];
        p1[0x11] = cam[0x11];
        p1[0x12] = cam[0x12];
        p1[0x13] = cam[0x13];
        p1[0x14] = cam[0x14];
        p1[0x15] = cam[0x15];
    }
    a = p1[0xf];
    b = cam[0x1f];
    cam[0x17] = a + b;
    a = p1[0x10];
    b = cam[0x20];
    cam[0x18] = a + b;
    a = p1[0x11];
    b = cam[0x21];
    cam[0x19] = a + b;
    a = p1[0x12];
    b = cam[0x22];
    cam[0x1a] = a + b;
    a = p1[0x13];
    b = cam[0x23];
    cam[0x1b] = a + b;
    a = p1[0x14];
    b = cam[0x24];
    cam[0x1c] = a + b;
    iVar2 = p1[0x15] + cam[0x25];
    cam[0x1e] = cam[0x16];
    cam[0x1d] = iVar2;
    func_80054DCC(&cam[0x17]);
    *(RView *)(p2 + 6) = *(RView *)D_800AE688;
    D_801151D4 = (s32)cam;
}
