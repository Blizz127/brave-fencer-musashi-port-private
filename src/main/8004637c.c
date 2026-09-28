/* Exact retail word export for [8004637C,80046480); EXE-verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/cdread.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8004637C - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef	unsigned long	u_long;

typedef enum { false, true } bool;

typedef void (*CdlCB)(u_char,u_char *);

int func_80043830(u_char com, u_char *param, u_char *result);

int CdReadSync(int mode, u_char *result);

void (*func_800439D4(void (*func)()));

CdlCB func_800435B4(CdlCB func);

CdlCB func_8004359C(CdlCB func);

int func_80043410(void);

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

int func_8004637C(int sectors, u_long* buf, int mode) {
    D_8006CFA0.mode = mode;
    switch (D_8006CFA0.mode & (0x10  | 0x20 )) {
    case 0:
        D_8006CFA0.payload_words = 2048 / sizeof(u_long);
        break;
    case 0x20 :
        D_8006CFA0.payload_words = 2340 / sizeof(u_long);
        break;
    default:  
        D_8006CFA0.payload_words = 2328 / sizeof(u_long);
    }
    D_8006CFA0.mode |= 0x20;
    D_8006CFA0.dest_base = buf;
    D_8006CFA0.nsectors = sectors;
    D_8006CFA0.cbsync = func_8004359C(0 );
    D_8006CFA0.cbready = func_800435B4(0 );
    if (D_8006CFA0.block_mode & 0x1 ) {
        D_8006CFA0.cbdata = func_800439D4(0 );
    }
    D_8006CFA0.vb_read = func_8004239C(-1);
    if (func_80043410() & (0x80  | 0x40  | 0x20 )) {
        func_80043830(0x09 , 0, 0);
    }
    return func_800460CC( false) > 0;
}

int CdReadSync(int mode, u_char* result);
