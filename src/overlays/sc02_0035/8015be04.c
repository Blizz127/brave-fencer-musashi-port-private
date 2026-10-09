/* SC02.CD member35: func_8015BE04 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
struct Obj;
struct Obj {
    short unk0;
    unsigned short idx;
};
typedef struct { char pad[0x12]; s16 field_0x12; } Obj;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32*, s16);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015BE38();
void func_8015BE38(struct Obj *a0);

void func_8015BE04(s32 *a0) {
    func_80147078(a0, 0x3);
    func_8015BE38((struct Obj *)a0);
}
