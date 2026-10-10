/* sc03_0098: func_80179B74 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80178D40.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u16 D_801C5018[0x200];
extern s16 D_801C541C;

void func_80179B74(u16 *p) {
    s32 pad[10];
    s16 c;
    (void)&pad;
    c = *p++;
    D_801C5018[D_801C541C] = c;
    D_801C541C = (D_801C541C + 1) & 0x1FF;
    switch (c) {
    case 0:
        break;
    case 1:
    case 5:
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        break;
    case 0x13:
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 0x12:
    case 0x14:
    case 0x1F:
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        break;
    case 0x17:
    case 0x1C:
    case 0x1D:
    case 0x20:
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        { s16 t = *p++; D_801C5018[D_801C541C] = t; D_801C541C = (D_801C541C + 1) & 0x1FF; }
        break;
    case 0x22:
        break;
    }
}
