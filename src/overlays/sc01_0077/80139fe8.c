/* sc01_0077: func_80139FE8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139B18(s32 a0);
extern void func_8001931C(void);
void func_80139788(void);
extern void func_8001931C(void);
void func_80139A8C(s32 a0);
extern void func_8001931C(void);
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80139B18(s32 a0);
extern s32 func_8001B22C(void *a0);
extern void func_8001931C(void);
extern void func_80139788(void);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_80139FE8(void *a0) {
    s32 v1;
    s32 a0v;
    v1 = func_8001B22C(a0);
    if (v1 == 2 || v1 == 4) {
        *(s16 *)((u8 *)a0 + 4) = 2;
    } else if (v1 == 0) {
        a0v = *(s32 *)((u8 *)a0 + 8);
        if (a0v & 1) {
            func_8001931C();
        } else {
            *(s32 *)((u8 *)a0 + 8) = (a0v & 0xFFFEFFFF) | 0x20020;
            func_80139788();
        }
        *(s16 *)((u8 *)a0 + 4) = 2;
    } else {
        func_80139A8C((s32)a0);
        if (*(s32 *)((u8 *)a0 + 8) & 0x20) {
            *(s16 *)((u8 *)a0 + 4) = 2;
        }
    }
    func_80139B18((s32)a0);
}
