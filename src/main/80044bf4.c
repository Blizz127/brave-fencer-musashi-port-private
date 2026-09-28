/* Native retail instruction export [80044BF4,80044CE8).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/bios.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80044BF4 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef unsigned char u_char;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
 u_char val0;
 u_char val1;
 u_char val2;
 u_char val3;
} CdlATV;

extern volatile u8* D_8006CF4C;

extern volatile u8* D_8006CF50;

extern volatile u8* D_8006CF54;

extern volatile u8* D_8006CF58;

extern volatile u16* D_8006CF60;

int func_80044BF4(void) {
    CdlATV vol;
    if (D_8006CF60[0xDC] == 0 && D_8006CF60[0xDD] == 0) {
        D_8006CF60[0xC0] = 0x3FFF;
        D_8006CF60[0xC1] = 0x3FFF;
    }
    D_8006CF60[0xD8] = 0x3FFF;
    D_8006CF60[0xD9] = 0x3FFF;
    D_8006CF60[0xD5] = (1 << 15) | (1 << 14) | (1 << 0);
    vol.val0 = vol.val2 = 0x80;
    vol.val1 = vol.val3 = 0;
    *D_8006CF4C = 2;
    *D_8006CF54 = vol.val0;
    *D_8006CF58 = vol.val1;
    *D_8006CF4C = 3;
    *D_8006CF50 = vol.val2;
    *D_8006CF54 = vol.val3;
    *D_8006CF58 = 0x20;
    return 0;
}

int CD_initintr();
