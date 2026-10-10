/* sc03_0098: func_801343C4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 D_801C41F8;
extern s32 D_801C41F8;
s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3);

s32 func_801343C4(s32 angle, s32 p1, s32 p2)
{
    extern s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3);
    extern s16 * D_801858B0;
    extern s16 * D_801858B4;
    extern u16 D_801C4208;
    extern u16 D_801C4204;
    s16 *pac;
    s16 *pb0;
    s16 *pacs, *pb0s;
    u16 *pb0u;
    int a1v, a2v, d94, b0;
    int sangle = ((s16)angle);
    pac = D_801858B0;
    d94 = D_801C41F8;
    pb0 = D_801858B4;
    pac[0] = ((u16 *)p1)[0];
    pac[1] = ((u16 *)p1)[1];
    pac[2] = ((u16 *)p1)[2];
    pb0[0] = ((u16 *)p2)[0];
    pb0[1] = ((u16 *)p2)[1];
    pb0[2] = ((u16 *)p2)[2];
    a1v = pac[0]; a2v = pac[2];
    D_801C4208 = 0;
    D_801C4204 = 0;
    if (((int (*)(int, s16, s16, int))func_80133AB0)(sangle, a1v, a2v, d94)) {
    setdst:
        pb0u = (u16 *)D_801858B4;
        ((u16 *)p2)[0] = pb0u[0];
        ((u16 *)p2)[1] = pb0u[1];
        ((u16 *)p2)[2] = pb0u[2];
        ((u16 *)p2)[3] = D_801C4208;
        return 1;
    }
    pacs = D_801858B0;
    pb0s = D_801858B4;
    b0 = pb0s[0];
    if ((pacs[0] & 0xFF80) == (b0 & 0xFF80) &&
        (pacs[2] & 0xFF80) == (pb0s[2] & 0xFF80)) {
        return 0;
    }
    if (((int (*)(int, s16, s16, int))func_80133AB0)(sangle, b0, pb0s[2], D_801C41F8)) {
        goto setdst;
    }
    return 0;
}
