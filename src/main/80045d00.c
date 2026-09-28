/* Exact retail word export for [80045D00,80045FD0); EXE-verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libcd/cdread.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80045D00 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned char	u_char;

typedef	unsigned long	u_long;

typedef enum { false, true } bool;

typedef void (*CdlCB)(u_char,u_char *);

typedef struct {
	u_char minute;		 
	u_char second;		 
	u_char sector;		 
	u_char track;		 
} CdlLOC;

int func_80043704(u_char com, u_char *param);

int func_80043994(void *madr, int size);

int func_800439B4( void* madr, int size );

int func_800439F8(int mode);

int func_80043B1C(CdlLOC *p);

void (*func_800439D4(void (*func)()));

CdlCB func_800435B4(CdlCB func);

CdlCB func_8004359C(CdlCB func);

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

extern CdlCB D_8006CF9C;

extern volatile ReadAttr_t D_8006CFA0;

extern char* D_80073A58;

extern int func_8004239C(int mode);

void D_80045FD0(void);

void func_80045D00(u_char status, u_char res[2]) {
    u_long tmp_buf[3];
    D_8006CFA0.unk34 = res;
    if (status == 0x01 ) {
        if (D_8006CFA0.status > 0) {

            if (D_8006CFA0.payload_words == 2048 / 4) {
                if (D_8006CFA0.block_mode & 0x1 ) {

                    func_800439D4(0 );
                    func_800439B4(&tmp_buf,  3);
                    func_800439F8(0x0 );
                    func_800439D4(&D_80045FD0);  
                } else {
                    func_80043994(&tmp_buf,  3);
                }

                if (func_80043B1C(&tmp_buf) != D_8006CFA0.sector_num) {
                    func_8005CD48((char*)&D_80073A58);
                    D_8006CFA0.status = -1;
                }
            }

            if (D_8006CFA0.block_mode & 0x1 ) {
                func_800439B4(D_8006CFA0.dest_cur, D_8006CFA0.payload_words);
            } else {
                func_80043994(D_8006CFA0.dest_cur, D_8006CFA0.payload_words);
                D_8006CFA0.dest_cur += D_8006CFA0.payload_words;
                --D_8006CFA0.status;
                ++D_8006CFA0.sector_num;
            }
        }
    } else {
        D_8006CFA0.status = -1;
    }
    D_8006CFA0.vb_attempt = func_8004239C(-1);

    if (D_8006CFA0.status < 0) {
        func_800460CC( true);
    }

    if (func_8004239C(-1) > D_8006CFA0.vb_read + 0x4B0 ) {
        D_8006CFA0.status = -1;
    }

    if (D_8006CFA0.status != 0 &&
        func_8004239C(-1) <= D_8006CFA0.vb_read + 0x4B0 ) {
        return;
    }

    func_8004359C(D_8006CFA0.cbsync);
    func_800435B4(D_8006CFA0.cbready);

    if (D_8006CFA0.block_mode & 0x1 ) {
        func_800439D4(D_8006CFA0.cbdata);
    }

    func_80043704(0x09 , 0);

    if (D_8006CF9C == 0 ) {
        return;
    }

    D_8006CF9C(D_8006CFA0.status == 0 ? 2 : 5, res);
}

void D_80045FD0(void);

int func_800460CC(bool is_retry);
