/* sc01_0077: func_80181F08 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80181F08.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_80019064(void *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);

void func_80181F08(s32 arg0)
{
    typedef struct { u32 w[4]; } St801D9204;
    extern void func_80019064(void *a0);
    extern void func_8012A828(s32 a0, void *a1);
    extern void func_8012B23C(s32 a0);
    extern void func_8012B2CC(s32 a0);
    extern void func_8012E9C0(s32 a0);
    extern s32 func_80143B6C(s32 a0, s32 a1);
    extern void func_80182254(s32 a0);
    extern void func_80182268(s32 a0);
    extern void func_801822E4(s32 a0);
    extern void func_801822FC(s32 a0);
    extern void func_80182338(s32 a0);
    extern void func_801823A0(s32 a0);
    extern void func_80182420(s32 a0);
    extern void func_801827A4(s32 a0);
    extern void func_8018301C(s32 a0);
    extern u8 D_80062BDC;
    extern char D_801B02A8[];
    extern St801D9204 D_801D9204;
    St801D9204 local = D_801D9204;
    if (*(u8 *)(arg0 + 0x5E) == 5) {
        func_80019064(&D_80062BDC);
    }
    if (*(u16 *)(arg0 + 0x5E) == 0x1F) {
        func_8018301C(arg0);
        return;
    }
    *(u8 *)(arg0 + 0xC1) = 0;
    func_8012E9C0(arg0);
    *(u16 *)(arg0 + 0x76) = *(u16 *)(arg0 + 0x76) - *(u16 *)(arg0 + 0x60);
    *(u16 *)(arg0 + 0x5C) &= 0xFFFE;
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) = (*(u16 *)(arg0 + 0x62) + 0x800) & 0xFFF;
    func_8012B2CC(arg0);
    func_8012B23C(arg0);
    *(s16 *)(arg0 + 2) = 3;
    func_80143B6C(arg0, 0);
    switch (*(u8 *)(arg0 + 0x5E)) {
    case 13:
        func_80182254(arg0);
        return;
    case 14:
        func_80182268(arg0);
        return;
    case 10:
        func_801822FC(arg0);
        return;
    case 9:
        func_80182338(arg0);
        return;
    case 17:
        func_801823A0(arg0);
        return;
    case 33:
        func_801822E4(arg0);
        return;
    case 15:
        if (*(s16 *)(arg0 + 0x76) > 0) {
            func_801827A4(arg0);
            return;
        }
        break;
    default:
        if (*(s16 *)(arg0 + 0x76) > 0) {
            *(u16 *)(arg0 + 0x34) = 0;
            *(s32 *)(arg0 + 0x1C) = 0x10;
            func_8012A828(arg0, D_801B02A8);
            return;
        }
        break;
    }
    func_80182420(arg0);
}
