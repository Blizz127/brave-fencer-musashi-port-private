/* SC02.CD member35: func_8016F540 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
struct S;
struct S {
    u8 pad0[0x7E];
    u16 f7E;
};
extern void func_8014708C(void *arg0);
extern s32 func_801472C8(struct S *a0);
extern void func_80171928(void *a0);
extern void func_8014708C(void *a0);
extern s32 func_801472C8(struct S *a0);
extern void func_80171928(void *a0);
void func_80171928(void * a0);

void func_8016F540(void *a0) {
    func_8014708C(a0);
    func_801472C8((struct S *)a0);
    func_80171928(a0);
}
