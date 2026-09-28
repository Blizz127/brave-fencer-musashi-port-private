/* Native retail instruction export [80044B14,80044BF4).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/bios.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80044B14 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    unsigned char sync;
    unsigned char ready;
    unsigned char c;
} Intr_t;

extern volatile Intr_t D_8006CF64;

extern volatile u8* D_8006CF4C;

extern volatile u8* D_8006CF54;

extern volatile u8* D_8006CF58;

extern volatile u32* D_8006CF5C;

int func_80044B14() {
    *D_8006CF4C = 1;
    while (*D_8006CF58 & 7) {
        *D_8006CF4C = 1;
        *D_8006CF58 = 7;
        *D_8006CF54 = 7;
    }
    D_8006CF64.ready = D_8006CF64.c = 0;
    D_8006CF64.sync = 2;
    *D_8006CF4C = 0;
    *D_8006CF58 = 0;
    *D_8006CF5C = 0x1325;
}

int CD_initvol(void);
