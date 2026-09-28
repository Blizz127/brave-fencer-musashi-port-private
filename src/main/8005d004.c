/* Main-exec range [8005D004,8005D03C) from the SLUS executable.
 * SHA256(span)=3cda1dc138826e3657937c542291a2f60a6cef75ab9f5868bd98b71eafa1b177.
 * Word export for the native seam (m2c produced no draft). */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libapi.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8005D004 - byte-exact against retail at -O3 (tools/register_match.py). */
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

long func_8005D004(long spec) {
    int i = spec & 0xFFFF;
    if (i >= 3)
        return 0;
    return D_80072938[i].rootCounter;
}

long StartRCnt(long spec);
