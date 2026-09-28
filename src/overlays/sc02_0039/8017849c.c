/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017849C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];
extern u16 D_801270C0;
extern void func_801787D4(void);
extern void func_8012A908(void);
extern void func_8017869C(s32 a0);
extern void func_80130D0C(s32 a0);
extern void func_8013E370(void);
extern s32 D_8011DB08;

void func_8017849C(void) {
    register u8 *p __asm__("$17");    
    register u8 *q __asm__("$16");    
    register s32 i __asm__("$18");    
    p = (u8 *)D_801202A0;
    func_801787D4();
    i = 0;
    func_8012A908();
    q = p + 0x54;
    do {
        if (*(u16 *)p != 0 &&
            (*(s16 *)&D_801270C0 == 1 || (*(u16 *)(q + 0x1E) & 0x1000) != 0)) {
            register s32 tbl __asm__("$3"); register s32 c6c __asm__("$2");
            func_8017869C((s32)p);
            *(s32 *)(q - 0x1C) = *(s32 *)(q - 0x50);
            c6c = *(u8 *)(q + 0x6C);
            *(s32 *)(q - 0x18) = *(s32 *)(q - 0x4C);
            tbl = D_8011DB08;
            *(s32 *)(q - 0x14) = *(s32 *)(q - 0x48);
            if (c6c != 0 && *(u8 *)(q + 0x6D) != 0) {
                func_80130D0C((s32)p);
            } else {
                (*(void (**)(s32))(tbl + *(u16 *)p * 4))((s32)p);
            }
            if (*(s32 *)(q - 0x34) != 0) {
                *(s16 *)(*(s32 *)(q - 0x34) + 8) =
                    *(u16 *)(q - 0x4E) + *(u16 *)(q - 0x4);
                *(s16 *)(*(s32 *)(q - 0x34) + 10) =
                    *(u16 *)(q - 0x4A) + *(u16 *)(q - 0x2);
                *(s16 *)(*(s32 *)(q - 0x34) + 0xC) =
                    *(u16 *)(q - 0x46) + *(u16 *)q;
            }
        }
        i++;
        q += 0x10C;
        p += 0x10C;
    } while (i < 0x60);
    if (*(s16 *)&D_801270C0 == 1) {
        func_8013E370();
    }
}
