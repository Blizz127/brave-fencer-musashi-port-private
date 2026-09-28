/* Main-exec range [8005CF68,8005D004) from the SLUS executable.
 * SHA256(span)=0a4b6d79b7147a7f722e19a8efddb178c13f9d784ae9562b9afbdcb6ddce3428.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libapi.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8005CF68 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef signed short       s16;

typedef signed int         s32;

typedef unsigned short     u16;

typedef struct {
    u16 rootCounter;
    s16 unk2;
    s16 mode;
    s16 : 16;
    s16 target;
    s32 : 32;
} Counter;

extern volatile Counter* D_80072938;

long func_8005CF68(long spec, short target, long mode) {
    int i = spec & 0xFFFF;
    int final_mode = 0x48;

    if (i >= 3)
        return 0;

    D_80072938[i].mode = 0;
    D_80072938[i].target = target;

    if (i < 2U) {
        if (mode & 0x0010 ) final_mode = 0x49;
        if (!(mode & 0x0001 )) final_mode |= 0x100;
    } else if (i == 2U) {
        if (!(mode & 0x0001 )) final_mode = 0x248;
    }

    if ((mode & 0x1000 ) != 0)
        final_mode |= 0x10;

    D_80072938[i].mode = final_mode;
    return 1;
}

long GetRCnt(long spec);
