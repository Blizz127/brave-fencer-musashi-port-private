/* Main-exec range [800434F4,80043528) from the SLUS executable.
 * SHA256(span)=5ee39bc9dc45c1507e3dddddbcea3f6c5bf84cfc280c2f88a3063229373073f2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/sys.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_800434F4 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

char *CdIntstr(u_char intr);

extern char D_80073614;

extern char* D_8006CCAC[];

char* func_800434F4(u_char com) {
    if (com >= 0x1c) {
        return &D_80073614;
    }
    return D_8006CCAC[com];
}

char* CdIntstr(u_char intr);
