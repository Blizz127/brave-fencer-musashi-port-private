/* sc03_0001: func_8018D0E4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_80029124(s32, s32);
extern s32 func_800291B4(s32 arg);
extern void func_80029124(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern int func_800D0FE0(int a0);
extern void func_800D0F0C(s32, s32);
extern void func_80029124(s32, s32);
extern s32 func_800291B4(s32 arg);
extern void func_800D0F0C(s32, s32);
extern int func_800D0FE0(int a0);
extern void func_80029124(s32, s32);
extern s32 func_800291B4(s32 arg);
extern s32 func_800D0FE0(s32);
extern void func_800D0F0C(s32, s32);
extern s16 D_8010EDEC;
extern u8 D_8010EDF1;
extern s32 D_801EB594;
extern u32 D_801EB5A8;
extern s32 D_801EB6D8;
typedef struct {
    s16 field_0;
    s16 field_2;
    s32 field_4;
    s32 field_8;
    s32 field_C;
} Struct801EF318;
extern Struct801EF318 D_801EF318;

void func_8018D0E4(void) {
    s16 i;
    D_801EF318.field_0 = 0;
    for (i = 0; i < 0xC; i++) {
        s32 slot = i + 0x2F;
        s32 id = func_800291B4(slot) & 0xFF;
        if (id != 0) {
            register s32 tmp __asm__("$2");
            s32 t;
            register s32 rb __asm__("$6");
            s16 flags;
            s32 m;
            tmp = (id << 1) + id;
            t = tmp << 2;
            flags = *(s16 *)((u8 *)&D_8010EDEC + t);
            if (flags < 0) {
                rb = *(u8 *)((u8 *)&D_8010EDF1 + t);
                m = rb & 0xFF;
                if (flags & 0x4000) {
                    D_801EF318.field_8 = (&D_801EB594)[id];
                    D_801EF318.field_C = (&D_801EB5A8)[id];
                    func_80029124(m, 1);
                    func_800D0FE0(slot);
                    D_801EF318.field_0 = 2;
                    return;
                } else {
                    register s32 sc __asm__("$4");
                    register s32 d __asm__("$2");
                    sc = slot;
                    __asm__("" : "=r"(sc) : "0"(sc));
                    d = rb - 0x14;
                    D_801EF318.field_4 = (&D_801EB6D8)[d >> 1];
                    ((void (*)(s32))func_800D0F0C)(sc);
                    D_801EF318.field_0 = 1;
                    return;
                }
            }
        }
    }
}
