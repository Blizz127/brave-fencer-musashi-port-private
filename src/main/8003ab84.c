/* Exact retail word export for [8003AB84,8003AE14); EXE and assembly verified. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libspu/Spu.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8003AB84 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef unsigned short u_short;

typedef signed short s16;

typedef signed int s32;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    short left;
    short right;
} SpuVolume;

typedef struct {
    SpuVolume volume;
    u16 pitch;
    u16 addr;
    u16 adsr[2];
    u16 volumex;
    u16 loop_addr;
} SPU_VOICE_REG;

typedef struct {
    u16 m_dAPF1;
    u16 m_dAPF2;
    s16 m_vIIR;
    s16 m_vCOMB1;
    s16 m_vCOMB2;
    s16 m_vCOMB3;
    s16 m_vCOMB4;
    s16 m_vWALL;
    s16 m_vAPF1;
    s16 m_vAPF2;
    u16 m_mLSAME;
    u16 m_mRSAME;
    u16 m_mLCOMB1;
    u16 m_mRCOMB1;
    u16 m_mLCOMB2;
    u16 m_mRCOMB2;
    u16 m_dLSAME;
    u16 m_dRSAME;
    u16 m_mLDIFF;
    u16 m_mRDIFF;
    u16 m_mLCOMB3;
    u16 m_mRCOMB3;
    u16 m_mLCOMB4;
    u16 m_mRCOMB4;
    u16 m_dLDIFF;
    u16 m_dRDIFF;
    u16 m_mLAPF1;
    u16 m_mRAPF1;
    u16 m_mLAPF2;
    u16 m_mRAPF2;
    s16 m_vLIN;
    s16 m_vRIN;
} ReverbRegisters;

typedef struct {
    SPU_VOICE_REG voice[24];
    SpuVolume main_vol;
    SpuVolume rev_vol;
    u16 key_on[2];
    u16 key_off[2];
    u16 chan_fm[2];
    u16 noise_mode[2];
    u16 rev_mode[2];
    u32 m_EndxFlags;
    u16 unk;
    u16 rev_work_addr;
    u16 irq_addr;
    u16 trans_addr;
    u16 trans_fifo;
    u16 spucnt;
    u16 data_trans;
    u16 spustat;
    SpuVolume cd_vol;
    SpuVolume ex_vol;
    SpuVolume main_volx;
    u32 unk2;
    ReverbRegisters m_Reverb;
} SPU_RXX;

union SpuUnion {
    SPU_RXX _rxx;
    volatile SPU_RXX rxx;
    u16 _raw[0x100];
    volatile u16 raw[0x100];
};

extern union SpuUnion* D_8006B54C;

extern volatile long* D_8006B550;

extern volatile long* D_8006B554;

extern volatile long* D_8006B558;

extern u_short D_8006B564;

extern long D_8006B574;

extern long D_8006B59C;

extern long D_8006B5A0;

extern long D_8006B5A4;

typedef void *va_list;

s32 func_8003AB84(s32 operation, ...) {
    u16 spuTransferMode;
    s32 chcr;
    u32 dmaTimer;
    u32 addr;
    va_list args;
    u32 arg;
    u16 controlRegister;
    (args = ((char *)&(operation) + (((sizeof (operation) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))));
    switch (operation) {
        case 2:
            arg = (args = ((char *) (args)) += (((sizeof (u32) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)), *((u32 *) ((char *) (args) - (((sizeof (u32) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)))));
            D_8006B54C->rxx.trans_addr = D_8006B564 = arg >> D_8006B574;
            break;
        case 1:
            D_8006B59C = 0;
            dmaTimer = 0;
            while (D_8006B54C->rxx.trans_addr != D_8006B564) {
                if (++dmaTimer > (0xF00U)) {
                    return (-2);
                }
            }
            controlRegister = D_8006B54C->rxx.spucnt;
            controlRegister &= ~( 3 << 4 );
            controlRegister |= ( 2 << 4 );
            D_8006B54C->rxx.spucnt = controlRegister;
            break;
        case 0:
            D_8006B59C = 1;
            dmaTimer = 0;
            while (D_8006B54C->rxx.trans_addr != D_8006B564) {
                if (++dmaTimer > (0xF00U)) {
                    return (-2);
                }
            }
            controlRegister = D_8006B54C->rxx.spucnt;
            controlRegister &= ~( 3 << 4 );
            controlRegister |= ( 3 << 4 );
            D_8006B54C->rxx.spucnt = controlRegister;
            break;
        case 3:
            if (D_8006B59C == 1) {
                spuTransferMode = ( 3 << 4 );
            } else {
                spuTransferMode = ( 2 << 4 );
            }
            dmaTimer = 0;
            while ((D_8006B54C->rxx.spucnt & ( 3 << 4 )) != spuTransferMode) {
                if (++dmaTimer > (0xF00U)) {
                    return (-2);
                }
            }
            if (D_8006B59C == 1) {
                func_8003B0B8();
            } else {
                func_8003B08C();
            }
            arg = (args = ((char *) (args)) += (((sizeof (u32) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)), *((u32 *) ((char *) (args) - (((sizeof (u32) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)))));
            D_8006B5A0 = arg;
            arg = (args = ((char *) (args)) += (((sizeof (u32) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)), *((u32 *) ((char *) (args) - (((sizeof (u32) + sizeof (int) - 1) / sizeof (int)) * sizeof (int)))));
            D_8006B5A4 = (arg / 64);
            D_8006B5A4 += ((arg % 64) ? 1 : 0);
            *D_8006B550 = D_8006B5A0;
            *D_8006B554 = (D_8006B5A4 << 16) | 16;
            if (D_8006B59C == 1) {
                chcr = ((0 << (0)) | (0 << (1)) | (0 << (8)) | (1 << (9)) | (1 << (24)) | (0 << (28)) | (0 << (29)));
            } else {
                chcr = ((1 << (0)) | (0 << (1)) | (0 << (8)) | (1 << (9)) | (1 << (24)) | (0 << (28)) | (0 << (29)));
            }
            *D_8006B558 = chcr;
            break;
    }
    return 0;
}

s32 _spu_Fw(s32 addr, s32 size);

void func_8003B08C(void);

void func_8003B0B8(void);
