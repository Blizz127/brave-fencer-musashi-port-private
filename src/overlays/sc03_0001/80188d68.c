/* sc03_0001: func_80188D68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern s32 func_801889AC(void);
void aF80185EEC(s32 a0) __asm__("func_801889AC");
extern s32 func_80188E74(s32 a0);
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 func_80188E74(s32 a0);

s32 func_80188D68(void *a0) {
    extern u8 D_801202A0[];
    u8 *p;
    u8 *end;
    s32 t;
    u16 tag;
    s16 out[3];
    s16 in[3];
    p = D_801202A0;
    end = p + 0x6480;
    if (p != end) {
        do {
            tag = *(u16 *)p;
            if (tag != 0 && tag != 0x61 && func_80188E74((s32)p) != 0) {
                t = *(s32 *)(p + 0x20);
                if (t != 0 && *(s32 *)(t + 0x24) != 0 && *(s32 *)(t + 0x4) >= 0) {
                    in[0] = *(u16 *)(p + 0x6);
                    in[1] = *(u16 *)(p + 0xA);
                    in[2] = *(u16 *)(p + 0xE);
                    func_8012F2E8((s32)a0, (s32)in, (s32)out);
                    if (func_8012CB64((s32)out, -0xA0, 0x80, -0xC0, 0x80) != 0) {
                        __asm__("");
                        return 1;
                    }
                }
            }
            p += 0x10C;
        } while (p != end);
    }
    return 0;
}
