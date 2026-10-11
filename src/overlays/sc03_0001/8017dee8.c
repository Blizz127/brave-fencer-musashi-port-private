/* sc03_0001: func_8017DEE8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC_8017DEE8;
extern void func_8017E204(void *arg0);
extern s32 func_8012AD50(void *arg0);
void func_8017E204(void *arg0);

void func_8017DEE8(void *arg0) {
    extern u8 D_80078EB1;
    extern Ent_8017D6EC_8017DEE8 D_801EE888[];
    s32 i;
    if (D_80078EB1 == 7) {
        for (i = 0; i < 4; i++) {
            Ent_8017D6EC_8017DEE8 *p = &D_801EE888[i];
            p->unk16 = i;
            func_8017E204(p);
            if (i & 1) {
                p->unk1C = 1;
            }
        }
        func_8012AD50(arg0);
    }
}
