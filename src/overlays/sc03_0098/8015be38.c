/* sc03_0098: func_8015BE38 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct Obj;
struct Obj {
    short unk0;
    unsigned short idx;
};
typedef struct { char pad[0x12]; s16 field_0x12; } Obj;

void func_8015BE38(struct Obj *a0) {
    extern void (*D_80187B30[])(void);
    D_80187B30[*(u16 *)((s32)a0 + 0x2)]();
}
