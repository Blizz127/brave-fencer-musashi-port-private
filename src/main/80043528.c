/* Main-exec range [80043528,8004355C) from the SLUS executable.
 * SHA256(span)=a3e99ba544ede2d2c25b31770bf36d76ef8f0d95aa7003fda50e53f0177d70c5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/sys.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80043528 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

int CdSync(int mode, u_char *result) ;

extern char D_80073614;

extern char* D_8006CD2C[];

char* func_80043528(u_char intr) {
    if (intr >= 7) {
        return &D_80073614;
    }
    return D_8006CD2C[intr];
}

int CdSync(int mode, u_char* result);
