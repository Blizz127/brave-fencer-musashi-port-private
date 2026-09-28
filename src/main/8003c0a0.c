/* Exact retail word export for [8003C0A0,8003C23C); EXE and assembly verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libspu/SpuClearReverbWorkArea.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8003C0A0 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned long	u_long;

typedef signed int         s32;

typedef unsigned int       u32;

typedef void (*SpuTransferCallbackProc)(void);

extern long D_8006B0E0;

extern char D_8006B144[1024];

extern long D_8006B568;

extern long D_8006B574;

extern volatile SpuTransferCallbackProc D_8006B584;

extern long D_8006B5B4[];

long func_8003C0A0 (long mode) {
    volatile s32 callback;
    s32 oldTransmode;
    s32 addr;
    s32 bTransferring;
    s32 bTansmodeCleared;
    u32 size;
    u32 remaining;

    callback = 0;
    bTansmodeCleared = 0;

    if ((mode >= (u_long)10 ) ||
        (func_8003B3D0(D_8006B5B4[mode]))) {
        return (-1) ;
        }

    if (mode == 0 ) {
        remaining = 0x10 << D_8006B574;
        addr = 0xFFF0 << D_8006B574;
    } else {
        remaining = ((512 * 1024  >> 3)  - D_8006B5B4[mode]) << D_8006B574;
        addr = D_8006B5B4[mode] << D_8006B574;
    }

    oldTransmode = D_8006B568;
    if (D_8006B568 == 1) {
        D_8006B568 = 0;
        bTansmodeCleared = 1;
    }

    bTransferring = 1;
    if (D_8006B584 != 0) {
        callback = D_8006B584;
        D_8006B584 = 0;
    }

    while (bTransferring) {
        size = remaining;
        if (!(remaining < (0x400U + 1))) {
            size = 0x400;
        } else {
            bTransferring = 0;
        }
        func_8003AB84(2 , addr);
        func_8003AB84(1 );
        func_8003AB84(3 , &D_8006B144, size);
        func_8005CE98(D_8006B0E0);
        remaining -= 0x400;
        addr += 0x400;
    };

    if (bTansmodeCleared) {
        D_8006B568 = oldTransmode;
    }

    if (callback) {
        D_8006B584 = callback;
    }

    return 0 ;
}
