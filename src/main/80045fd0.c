/* Main-exec range [80045FD0,800460CC) from the SLUS executable.
 * SHA256(span)=c26d03bf8638b6852079a21c881d02e2b09a8faf91f2866c001225fcbfc19e2e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/cdread.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80045FD0 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef	unsigned long	u_long;

typedef enum { false, true } bool;

typedef void (*CdlCB)(u_char,u_char *);

int func_80043704(u_char com, u_char *param);

void (*func_800439D4(void (*func)()));

CdlCB func_800435B4(CdlCB func);

CdlCB func_8004359C(CdlCB func);

typedef struct {
    int nsectors;       
    u_long* dest_base;  
    u_long* dest_cur;   
    int mode;           
    int payload_words;  
    int status;         
    int vb_attempt;     
    int vb_read;        
    int sector_num;     
    CdlCB cbsync;
    CdlCB cbready;
    CdlCB cbdata;
    int block_mode;  
    u_char* unk34;
    int unk38;
} ReadAttr_t;

extern CdlCB D_8006CF9C;

extern volatile ReadAttr_t D_8006CFA0;

void func_80045FD0(void) {
    D_8006CFA0.dest_cur += D_8006CFA0.payload_words;
    --D_8006CFA0.status;
    ++D_8006CFA0.sector_num;

    if (D_8006CFA0.status != 0) {
        return;
    }

    func_8004359C(D_8006CFA0.cbsync);
    func_800435B4(D_8006CFA0.cbready);

    if (D_8006CFA0.block_mode & 0x1 ) {
        func_800439D4(D_8006CFA0.cbdata);
    }

    func_80043704(0x09 , 0);

    if (D_8006CF9C != 0 ) {
        D_8006CF9C(2, D_8006CFA0.unk34);
    }
}

int cd_read_retry(bool is_retry);
