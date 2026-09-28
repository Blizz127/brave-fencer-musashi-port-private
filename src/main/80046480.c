/* Exact retail word export for [80046480,8004654C); EXE-verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/cdread.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80046480 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef	unsigned long	u_long;

typedef enum { false, true } bool;

typedef void (*CdlCB)(u_char,u_char *);

int func_8004357C(int mode, u_char *result) ;

void (*CdDataCallback(void (*func)()));

CdlCB CdReadCallback(CdlCB func);

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

extern int func_8004239C(int mode);

int func_800460CC(bool is_retry);

int func_80046480(int mode, u_char* result) {
    int status;
    while (true) {
        status = -1;
        if (func_8004239C(-1) <= D_8006CFA0.vb_read + 0x4B0 ) {
            if (D_8006CFA0.status < 0 ||
                func_8004239C(-1) > D_8006CFA0.vb_attempt + 0x3C ) {
                func_800460CC( true);
                status = D_8006CFA0.nsectors;
            } else {
                status = D_8006CFA0.status;
            }
        }
        if (mode != 0x0  || status <= 0) {
            func_8004357C(1, result);
            return status;
        }
    }
}

CdlCB CdReadCallback(CdlCB func);
