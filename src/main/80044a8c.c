/* Exact retail word export for [80044A8C,80044B14); EXE and assembly verified. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libcd/bios_commands.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80044A8C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef unsigned char u8;

typedef unsigned char u_char;

extern volatile u8 *D_8006CF4C;

extern volatile u8 *D_8006CF50;

extern volatile u8 *D_8006CF54;

extern volatile u8 *D_8006CF58;

typedef struct CdlATV {
    u_char val0;
    u_char val1;
    u_char val2;
    u_char val3;
} CdlATV;

void CD_flush(void);

int func_80044A8C(CdlATV *vol) {
    *D_8006CF4C = 2;
    *D_8006CF54 = vol->val0;
    *D_8006CF58 = vol->val1;
    *D_8006CF4C = 3;
    *D_8006CF50 = vol->val2;
    *D_8006CF54 = vol->val3;
    *D_8006CF58 = 0x20;
    return 0;
}

void CD_flush(void);
