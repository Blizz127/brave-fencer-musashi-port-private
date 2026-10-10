/* sc01_0077: func_801820DC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801820DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012CBCC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B14C(s32 a0, s32 a1);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);
extern void func_80182968(void);
extern char D_8018AA8C[];
extern char D_801AFF18[];
extern void func_8012CBCC(int);
extern int func_8012BEE8(int);
extern int func_8005C49C(void);
extern void func_80182968(void);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(int, void *);
extern void func_8012CBF4(int);
extern s32 func_80143B6C(s32 arg0, s32 arg1);
extern void func_8018294C(void *a0);
extern char D_8018AA8C[];
extern char D_801AFF18[];

void func_801820DC(int arg0)
{
    int idx;
    s32 frame_pad[2];
    (void)&frame_pad;
    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        func_8012CBCC(arg0);
        if (func_8012BEE8(arg0) != 0) {
            *(u16 *)(arg0 + 0x5e) = 0;
            *(u8 *)(arg0 + 0xc1) = 0;
            *(u16 *)(arg0 + 0x2) = 1;
            *(u16 *)(arg0 + 0x34) = 0;
            *(int *)(arg0 + 0x1c) = (func_8005C49C() & 0x1f) + 0x46;
            *(u16 *)(arg0 + 0xe0) = 0;
            *(u16 *)(arg0 + 0xe2) = *(u16 *)(*(int *)(arg0 + 0x20) + 0x12);
            idx = (int)((u32)*(u16 *)(arg0 + 0x70) << 16) >> 24;
            switch (idx) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 7:
                if ((*(u16 *)(arg0 + 0xfe) & 2) != 0) {
                    *(u16 *)(arg0 + 0xe2) = 0;
                }
                break;
            case 5:
                ((void (*)(int))func_80182968)(arg0);
                return;
            case 4:
            case 6:
            default:
                break;
            }
            *(u16 *)(arg0 + 0xe4) = 0x1e;
            *(u16 *)(arg0 + 0x5e) = 0;
            *(u16 *)(arg0 + 0x5c) = 0xaa10;
            func_8012B2CC(arg0);
            func_8012B23C(arg0);
            ((void (*)(int, void *))func_8012B14C)(arg0, &(*(char *)D_8018AA8C));
            func_8012A828(arg0, &(*(char *)D_801AFF18));
        }
        break;
    case 1:
        func_8012CBF4(arg0);
        if (*(int *)(arg0 + 0x1c) == 0x1e || *(int *)(arg0 + 0x1c) == 0xd) {
            ((void (*)(int, int))func_80143B6C)(arg0, 0);
        }
        if (func_8012BEE8(arg0) != 0) {
            ((void (*)(int))func_8018294C)(arg0);
        }
        break;
    }
}
