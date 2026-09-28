/* Exact retail word export for [800373D0,800374CC); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800373D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct { u16 f0; } H2;

typedef struct {
    s32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u8  unk0A;
    u8  unk0B;
    s32 unk0C;
} Rsc16;

typedef struct {
    s16 unk00;
    u8  pad02[4];
    u16 unk06;
} StructA4E88;

extern StructA4E88 D_800A4E88;
extern u8           D_800BA320[];
extern Rsc16        D_80076248[];    
extern u8           D_80076251;      
extern u8           D_80076250[];
extern u8           D_80076298;
extern H2           D_80065438[];

extern void func_8002D7FC(s32 arg0);
extern void func_8002FDE8(s32 arg0, void *arg1);

void func_800373D0(void) {
    register StructA4E88 *sp2 __asm__("$18");
    register u8          *sp3 __asm__("$19");
    register Rsc16 *p __asm__("$16");
    register s32 i __asm__("$17");

    sp2 = &D_800A4E88;
    sp3 = D_800BA320;

    p = D_80076248;
    i = 0;
    do {
        if ((&D_80076251)[i] != 0) {
            if (D_80076250[i] != 0) {
                if (p->unk00 & 0x3000) {
                    sp2->unk00 = p->unk00 & 0xFFF;
                    sp2->unk06 |= 0x20;
                    func_8002D7FC((s32) sp3);
                    if (!(p->unk00 & 0x1000)) {
                        func_8002FDE8(D_80065438[sp2->unk00].f0, sp3 + 0x7000);
                    }
                }
            }
        }
        p++;
        i += 0x10;
    } while ((s32) p < (s32) &D_80076298);
}
