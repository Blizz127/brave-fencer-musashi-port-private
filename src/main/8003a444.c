/* Native retail instruction export [8003A444,8003A53C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libspu/_SpuInit.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8003A444 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef	unsigned short	u_short;

typedef	unsigned long	u_long;

typedef signed int         s32;

typedef struct {
    short left;	        
    short right;        
} SpuVolume;

typedef struct {
    unsigned int	mask;	   

    int		mode;	   
    SpuVolume		depth;	   
    int                 delay;	   
    int                 feedback;  
} SpuReverbAttr;

extern void func_8003A53C (void);

extern u_long D_8006B0E4;

extern long D_8006B0E8;

extern long D_8006B0EC;

extern long D_8006B0F0;

extern long D_8006B0F4;

extern SpuReverbAttr D_8006B0F8;

extern long D_8006B10C;

extern volatile long D_8006B110;

extern u_short D_8006B114[24 ];

extern long D_8006B544;

extern long D_8006B568;

extern long D_8006B5A8;

extern long D_8006B5AC;

extern char* D_8006B5B0;

extern long D_8006B5B4[];

void func_8003A444(s32 bHot) {
    s32 i;
    u_short v;

    func_80042580();
    func_8003A5B8(bHot);

    if (bHot == 0)
    {
        v = 0xC000;
        for(i = 24  - 1; i >= 0; i--)
        {
            D_8006B114[i] = v;
        }
    }

    func_8003A53C();
    D_8006B0EC = 0;
    D_8006B0F0 = 0;
    D_8006B0F8.mode = 0;
    D_8006B0F8.depth.left = 0;
    D_8006B0F8.depth.right = 0;
    D_8006B0F8.delay = 0;
    D_8006B0F8.feedback = 0;
    D_8006B0F4 = D_8006B5B4[0];
    func_8003AF04(0xD1 , D_8006B0F4, 0);
    D_8006B5A8 = 0;
    D_8006B5AC = 0;
    D_8006B5B0 = 0;
    D_8006B0E8 = 0;
    D_8006B568 = 0;
    D_8006B0E4 = 0;
    D_8006B110 = 0;
    D_8006B10C = 0;
    D_8006B544 = 0;
}

void func_8003A53C(void);
