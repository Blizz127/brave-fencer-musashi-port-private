/* Overlay range [8013C0F8,8013C360) from MAIN.CD member 0012.
 * SHA256(span)=17a153c9fd140ff9c317c4d4dfec46aff5a68708915a25c9b3c15e14847bad4e.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013C0F8 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct Bar {
    unsigned char b0;     /* 0x0 */
    unsigned char b1;     /* 0x1 */
    unsigned char b2;     /* 0x2 */
    unsigned char tag;    /* 0x3 */
    unsigned int a;       /* 0x4 */
    unsigned int b;       /* 0x8 */
} Bar;
typedef struct Foo {
    unsigned char pad[0xc];
    unsigned int count;   /* 0xc */
    int field10;          /* 0x10 */
} Foo;

/* func_8013C0F8 — shared body (overlay slot 0x80128158, h_text 95d2c582). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
void func_8013C0F8(int param_1) {
    int iVar1;
    int iVar2;
    unsigned int local_18;
    unsigned int local_14;
    Bar *local_10;
    Foo *local_c;

    iVar1 = param_1 + 0x14;
    if (*(char *)(param_1 + 4) == '\0') {
        iVar2 = iVar1 + *(int *)(param_1 + 0xc);
        *(int *)(param_1 + 0xc) = iVar2;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar1;
        local_c = (Foo *)iVar1;
        for (local_18 = 0; local_18 < *(unsigned int *)(param_1 + 8); local_18++, local_c++) {
            local_c->field10 = local_c->field10 + iVar1;
            local_10 = (Bar *)local_c->field10;
            for (local_14 = 0; local_14 < local_c->count; local_14++, local_10++) {
                switch (local_10->tag) {
                case 0x24:
                case 0x2c:
                case 0x34:
                case 0x3c:
                    *(unsigned int *)local_10 = (*(unsigned int *)local_10 & 0xffffff) + iVar2;
                    break;
                case 0x26:
                case 0x2e:
                case 0x36:
                case 0x3e:
                    *(unsigned int *)local_10 = (*(unsigned int *)local_10 & 0xffffff) + iVar2;
                    break;
                }
            }
        }
        *(unsigned char *)(param_1 + 4) = 1;
    }
}
