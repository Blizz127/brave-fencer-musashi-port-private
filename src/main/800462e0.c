/* Main-exec range [800462E0,8004637C) from the SLUS executable.
 * SHA256(span)=0d298e08ba10c4ceaa17f4f3f1b1a9771ca2d086dd1574023140e6f48bde7cfd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/cdread.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_800462E0 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef	unsigned long	u_long;

typedef void (*CdlCB)(u_char,u_char *);

int func_80043704(u_char com, u_char *param);

int func_800439F8(int mode);

int CdRead(int sectors, u_long *buf, int mode);

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

extern volatile ReadAttr_t D_8006CFA0;

void func_800462E0(void) {
    if (D_8006CFA0.block_mode & 0x1 ) {
        func_800439F8(0);
    }

    D_8006CFA0.status = 0;
    func_8004359C(D_8006CFA0.cbsync);
    func_800435B4(D_8006CFA0.cbready);

    if (D_8006CFA0.block_mode & 0x1 ) {
        func_800439D4(D_8006CFA0.cbdata);
    }

    func_80043704(0x09 , 0);
}

int CdRead(int sectors, u_long* buf, int mode);
