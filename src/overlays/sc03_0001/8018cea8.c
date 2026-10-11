/* sc03_0001: func_8018CEA8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012C218(void *a0);

void func_8018CEA8(s32 arg0) {
    s32 flag;
    s32 r;
    r = func_80029504();
    flag = 0;
    switch (*(s16 *)((s32)arg0 + 0x70)) {
    case 0:
        if ((u32)(r - 0x64) < 0x1E) {
            flag = 1;
        }
        break;
    case 1:
        if ((u32)(r - 0x3B6) < 0x32) {
            flag = 1;
        }
        break;
    }
    if (flag != 0) {
        func_8012C658(0x21, 1 - *(u16 *)((s32)arg0 + 2), arg0);
        func_8012C218((void *)arg0);
    } else if (*(u16 *)((s32)arg0 + 2) == 0) {
        *(u16 *)((s32)arg0 + 2) = *(u16 *)((s32)arg0 + 2) + 1;
    }
}
