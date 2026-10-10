/* sc01_0077: func_8015BE38 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
struct Obj;
struct Obj {
    short unk0;
    unsigned short idx;
};
typedef struct { char pad[0x12]; s16 field_0x12; } Obj;
struct Obj;
extern void (*D_8018932C[])(void);

void func_8015BE38(struct Obj *a0) {
    D_8018932C[a0->idx]();
}
