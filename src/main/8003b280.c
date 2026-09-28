/* Native retail instruction export [8003B280,8003B350).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libspu/SpuSetReverb.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8003B280 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef signed short       s16;

typedef unsigned short     u16;

typedef unsigned int       u32;

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
    SPU_VOICE_REG voice[24 ];

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

extern long D_8006B0EC;

extern long D_8006B0F0;

extern long D_8006B0F4;

extern union SpuUnion* D_8006B54C;

long func_8003B280 (long on_off)
{
    long spuControlRegister;

    switch( on_off ) {
        case 0 :
            D_8006B0EC = 0 ;
            spuControlRegister = D_8006B54C->_rxx.spucnt;
            spuControlRegister &= ~(1 <<  7) ;
            D_8006B54C->_rxx.spucnt = spuControlRegister;
            break;

        case 1 :
            if( D_8006B0F0 != on_off && func_8003B3D0(D_8006B0F4) ) {
                D_8006B0EC = 0 ;
                spuControlRegister = D_8006B54C->_rxx.spucnt;
                spuControlRegister &= ~(1 <<  7) ;
                D_8006B54C->_rxx.spucnt = spuControlRegister;
            } else {
                D_8006B0EC = on_off;
                spuControlRegister = D_8006B54C->_rxx.spucnt;
                spuControlRegister |= (1 <<  7) ;
                D_8006B54C->_rxx.spucnt = spuControlRegister;
            }
            break;
    }

    return D_8006B0EC;
}
