/* Main-exec range [80045190,80045280) from the SLUS executable.
 * SHA256(span)=77e526dc5a872043abece5e9e352f9dad763783516e64d981969950d3bf0eb77.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/bios.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80045190 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef unsigned int size_t;

typedef unsigned char u8;

typedef unsigned int u32;

extern volatile u8* D_8006CF4C;

extern volatile u8* D_8006CF58;

extern volatile u32* D_8006CF5C;

extern volatile u32* D_8006CF80;

extern volatile u32* D_8006CF84;

extern volatile u32* D_8006CF88;

extern volatile u32* D_8006CF8C;

extern volatile u32* D_8006CF90;

int func_80045190(void* madr, size_t size) {
    volatile u32 sp0;
    *D_8006CF4C = 0;
    *D_8006CF58 = 0x80;
    *D_8006CF80 = 0x21020843;
    *D_8006CF5C = 0x1325;
    *D_8006CF84 |= 0x8000;
    *D_8006CF88 = (u32)madr;
    *D_8006CF8C = size | 0x10000;
    while (!(*D_8006CF4C & 0x40))
        ;
    *D_8006CF90 = ((0 << (0)) | (0 << (1)) | (1 << (8)) | (0 << (9)) | (0x4 << (20)) | (1 << (24)) | (1 << (28)) | (0 << (29)));
    sp0 = *D_8006CF90;
    return 0;
}

void CD_set_test_parmnum(int arg0);
