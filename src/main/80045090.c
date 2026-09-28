/* Exact retail word export for [80045090,80045190); EXE-verified. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libcd/sector_read.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80045090 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef unsigned char u8;

typedef unsigned int u32;

extern volatile u8 *D_8006CF4C;

extern volatile u8 *D_8006CF4C;

extern volatile u8 *D_8006CF58;

extern volatile u32 *D_8006CF5C;

extern volatile u32 *D_8006CF80;

extern volatile u32 *D_8006CF84;

extern void *volatile *D_8006CF88;

extern volatile u32 *D_8006CF8C;

extern volatile u32 *D_8006CF90;

int func_80045090(void *destination, int words) {
    register volatile u8 *status asm("$3");
    register u32 dmaCommand asm("$2");

    *D_8006CF4C = 0;
    *D_8006CF58 = 0x80;
    *D_8006CF80 = 0x20943;
    *D_8006CF5C = 0x1323;
    *D_8006CF84 |= 0x8000;
    *D_8006CF88 = destination;
    *D_8006CF8C = words | 0x10000;

    status = D_8006CF4C;
    do {
        dmaCommand = *status & 0x40;
    } while (!dmaCommand);
    dmaCommand = 0x11000000;

    *D_8006CF90 = dmaCommand;
    {
        volatile u32 *control = D_8006CF90;
        if (*control & 0x1000000) {
            volatile u32 *pending = control;
            u32 mask = 0x1000000;
            do {
            } while (*pending & mask);
        }
    }

    {
        volatile u32 *request = D_8006CF5C;
        register u32 requestValue asm("$2") = 0x1325;

        *request = requestValue;
    }
    return 0;
}

int CD_getsector(void *destination, int words);
