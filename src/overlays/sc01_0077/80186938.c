/* sc01_0077: func_80186938 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_801747AC(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 D_801270CC;
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern s32 D_801270C8;
extern void func_8012A828(int, void *);
extern int func_8012BEE8(int a0);
extern void func_8012A828(int a0, void *a1);
extern s32 D_801270CC;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012BEE8(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(int, void *);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
void func_80185BA4(void* p);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void * a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 D_801270C8;
extern s32 D_801270CC;
extern u8 D_801D7A4C;
extern M2C_UNK D_80186E48;
extern void func_80185BA4(void *arg0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_801747AC(s32 a0);

void func_80186938(s32 arg0) {
    s32 temp;
    s32 *p;
    if (*(u16 *)(arg0 + 0x34) == 0) {
        temp = *(s32 *)(arg0 + 0xE4) + *(s32 *)(arg0 + 0xE0);
        *(s32 *)(arg0 + 0xE8) = *(s32 *)(arg0 + 0xE8) + temp;
        *(s32 *)(arg0 + 0xE4) = temp;
        *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12) = *(s16 *)(arg0 + 0xEA);
        func_80185BA4((void *)arg0);
        if (((s32 (*)(void *))func_8012BEE8)((void *)arg0) != 0) {
            *(s16 *)(arg0 + 0x34) = 1;
            ((void (*)(s32, void *))func_8001C214)(*(s32 *)(arg0 + 0x20), &D_801D7A4C);
            ((void (*)(void *, void *))func_8012A828)((void *)arg0, &D_80186E48);
            ((void (*)(void))func_801747AC)();
            p = &D_801270C8;
            *p += 1;
            if (*p >= 4) {
                D_801270CC = 2;
            }
        }
    }
}
