/* Exact retail word export for [80043A18,80043B1C); EXE-verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/sys.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80043A18 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef struct {
	u_char minute;		 
	u_char second;		 
	u_char sector;		 
	u_char track;		 
} CdlLOC;

int CdPosToInt(CdlLOC *p);

CdlLOC* func_80043A18(int i, CdlLOC* p) {
    inline int ENCODE_BCD(n) { return ((n / 10) << 4) + (n % 10); }

    i += 150;
    p->sector = ENCODE_BCD(i % 75);
    p->second = ENCODE_BCD(i / 75 % 60);
    p->minute = ENCODE_BCD(i / 75 / 60);
    return p;
}

int CdPosToInt(CdlLOC* p);
