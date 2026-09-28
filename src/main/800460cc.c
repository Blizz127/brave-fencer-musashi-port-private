/* Exact retail word export for [800460CC,800462E0); EXE-verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/cdread.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_800460CC - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef	unsigned long	u_long;

typedef unsigned char      u8;

typedef enum { false, true } bool;

typedef void (*CdlCB)(u_char,u_char *);

typedef struct {
	u_char minute;		 
	u_char second;		 
	u_char sector;		 
	u_char track;		 
} CdlLOC;

void func_800434BC(void);

int func_800435CC(u_char com, u_char *param, u_char *result);

int func_80043704(u_char com, u_char *param);

int func_80043B1C(CdlLOC *p);

void (*func_800439D4(void (*func)()));

CdlCB func_800435B4(CdlCB func);

CdlCB func_8004359C(CdlCB func);

int func_80043410(void);

CdlLOC *func_80043440(void);

int func_80043420(void);

void CdReadBreak( void );

extern void func_8005CD48(char *);

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

extern char* D_80073A70;

extern char* D_80073A88;

extern int func_8004239C(int mode);

void D_80045D00(u_char, u_char*);

void D_80045FD0(void);

void D_80045D00(u_char status, u_char res[2]);

void D_80045FD0(void);

int func_800460CC(bool is_retry) {
    u8 mode;

    func_8004359C(0 );
    func_800435B4(0 );
    if (D_8006CFA0.block_mode & 0x1 ) {
        func_800439D4(0 );
    }

    if (func_80043410() & 0x10 ) {
        if ((func_8004239C(-1) & 0x3F) == 0) {
            func_8005CD48((char*)&D_80073A70);
        }
        func_80043704(0x01 , 0);
        D_8006CFA0.vb_read = func_8004239C(-1);
        D_8006CFA0.status = -1;
        return D_8006CFA0.status;
    }

    if (is_retry) {
        func_8005CD48((char*)&D_80073A88);
        func_800435CC(0x09 , 0, 0);
        if (!func_800435CC(0x02 , func_80043440(), 0)) {
            D_8006CFA0.status = -1;
            return D_8006CFA0.status;
        }
    }

    func_800434BC();

    mode = D_8006CFA0.mode;

    if (mode != func_80043420() || is_retry) {
        if (!func_800435CC(0x0e , &mode, 0)) {
            D_8006CFA0.status = -1;
            return D_8006CFA0.status;
        }
    }

    D_8006CFA0.sector_num = func_80043B1C(func_80043440());

    func_800435B4(&D_80045D00);

    if (D_8006CFA0.block_mode & 0x1 ) {
        func_800439D4(&D_80045FD0);
    }

    D_8006CFA0.dest_cur = D_8006CFA0.dest_base;

    func_80043704(0x06 , 0);

    D_8006CFA0.status = D_8006CFA0.nsectors;
    D_8006CFA0.vb_attempt = func_8004239C(-1);

    return D_8006CFA0.status;
}

void CdReadBreak(void);
