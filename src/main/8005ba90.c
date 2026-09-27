/* Exact retail word export for [8005BA90,8005BD7C); EXE and assembly verified. */
#include "psx_types.h"

/* PS1 queue-record view: field offsets and stride are retail-backed.
 * Volatile declarations reproduce repeated observations, not native atomics.
 * Do not map this pointer-bearing layout directly onto a 64-bit host. */
typedef struct {
    void (*callback)(u32, u32);
    u32 arg0, arg1;
    u8 opaque0C[0x54];
} QueueEntry;

extern s32 func_800426FC(s32);
extern s32 func_800425E0(s32, s32);
extern volatile u32 *D_80072868, *D_8007285C;
extern volatile s32 D_8007288C, D_80072890;
extern s32 D_80072898;
extern volatile s32 D_80072790[];
extern void (*D_80072794)(void);
extern volatile u32 D_8007287C[];
extern volatile u32 func_80072880, D_80072884;
extern volatile QueueEntry D_800C5510[];

s32 func_8005BA90(void) {
    if ((*D_80072868 & 0x01000000) != 0) {
        return 1;
    }
    D_80072898 = func_800426FC(0);
    while (D_8007288C != D_80072890 &&
           (*D_80072868 & 0x01000000) == 0) {
        if (((D_80072890 + 1) & 0x3F) == D_8007288C &&
            D_80072794 == 0) {
            func_800425E0(2, 0);
        }
        while ((*D_8007285C & 0x04000000) == 0) {
        }
        D_800C5510[D_80072890].callback(D_800C5510[D_80072890].arg0,
                                       D_800C5510[D_80072890].arg1);
        D_8007287C[0] = (u32)D_800C5510[D_80072890].callback;
        func_80072880 = D_800C5510[D_80072890].arg0;
        D_80072884 = D_800C5510[D_80072890].arg1;
        D_80072890 = (D_80072890 + 1) & 0x3F;
    }
    func_800426FC(D_80072898);
    if (D_8007288C == D_80072890 &&
        (*D_80072868 & 0x01000000) == 0 &&
        D_80072790[0] != 0 && D_80072794 != 0) {
        D_80072790[0] = 0;
        D_80072794();
    }
    return (D_8007288C - D_80072890) & 0x3F;
}
