/* sc01_0077: func_80182C9C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern int func_8012BEE8(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B178();
extern void func_8012AD80();
extern int func_8012BEE8();
extern void func_8012A828();
extern void func_8012C098();
extern void func_8012C218();
extern unsigned char D_8018AB24[];
extern unsigned char D_801AFFC0[];
extern int D_801270CC;

void func_80182C9C(int p)
{
    switch (*(unsigned short *)(p + 0x34)) {
    case 0:
        func_8012B178(p, 0xfff40000);
        func_8012AD80(p);
        if (func_8012BEE8(p) == 0) return;
        *(unsigned short *)(p + 0x34) = 1;
        func_8012A828(p, D_8018AB24);
        return;
    case 1:
        if (*(short *)(p + 0x98) != 0) return;
        *(unsigned short *)(p + 0x34) = 2;
        func_8012A828(p, D_801AFFC0);
        *(int *)(p + 0x1c) = 4;
        return;
    case 2:
        *(unsigned short *)(*(int *)(p + 0x20) + 0x12) =
            *(unsigned short *)(*(int *)(p + 0x20) + 0x12) - 0x200;
        if (func_8012BEE8(p) == 0) return;
        *(int *)(p + 0x1c) = 0x3c;
        *(unsigned short *)(p + 0x34) = 3;
        return;
    case 3:
        func_8012B178(p, 0xfff40000);
        func_8012AD80(p);
        if (func_8012BEE8(p) == 0) return;
        switch (((int)(*(unsigned short *)(p + 0x70) << 16)) >> 24) {
        case 0:
        case 1:
        case 2:
        case 5:
        case 6:
            func_8012C098(p);
            return;
        case 3:
        case 7:
            func_8012C218(p);
            return;
        case 4:
            D_801270CC = D_801270CC - 1;
            func_8012C218(p);
            return;
        }
        return;
    }
}
