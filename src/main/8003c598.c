/* Native retail instruction export [8003C598,8003C92C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: PsyQ library C derived from xenogears-decomp-ai-archerfish (src/slus_006.64/psyq/libspu/SpuSetCommonAttr.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8003C598 - byte-exact against retail at -O3 (tools/register_match.py). */
typedef signed short       s16;

typedef signed int         s32;

typedef unsigned short     u16;

typedef unsigned int       u32;

typedef struct {
    short left;	        
    short right;        
} SpuVolume;

typedef struct {
    SpuVolume	volume;		   
    int		reverb;		   
    int		mix;		   
} SpuExtAttr;

typedef struct {
    unsigned int	mask;	   

    SpuVolume		mvol;	   
    SpuVolume		mvolmode;  
    SpuVolume		mvolx;	   
    SpuExtAttr		cd;	   
    SpuExtAttr		ext;	   
} SpuCommonAttr;

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

extern union SpuUnion* D_8006B54C;

void func_8003C598(SpuCommonAttr* attr) {
    u16 mvol_mode_left;
    u16 mvol_mode_right;
    u16 vol_total_left;
    u16 vol_total_right;
    u32 mask;
    s32 bSetAll;
    u16 cnt;

    vol_total_left = 0;
    vol_total_right = 0;
    mask = attr->mask;
    bSetAll = attr->mask == 0;

    if (bSetAll || mask & (0x01 <<  0) ) {
        if (bSetAll || mask & (0x01 <<  2) ) {
            switch (attr->mvolmode.left) {

            case 1 :
                mvol_mode_left = 0x8000 ;
                break;
            case 2 :
                mvol_mode_left = 0x9000 ;
                break;
            case 3 :
                mvol_mode_left = 0xA000 ;
                break;
            case 4 :
                mvol_mode_left = 0xB000 ;
                break;
            case 5 :
                mvol_mode_left = 0xC000 ;
                break;
            case 6 :
                mvol_mode_left = 0xD000 ;
                break;
            case 7 :
                mvol_mode_left = 0xE000 ;
                break;
            case 0 :
                vol_total_left = attr->mvol.left;
                mvol_mode_left = 0x0000 ;
                break;
            default:
                vol_total_left = attr->mvol.left;
                mvol_mode_left = 0x0000 ;
                break;
            }
        }
        else {
            vol_total_left = attr->mvol.left;
            mvol_mode_left = 0x0000 ;
        }

        if (mvol_mode_left != 0x0000 ) {
            if (attr->mvol.left > 0x7F ) {
                vol_total_left = 0x7F ;
            } else if (attr->mvol.left < 0) {
                vol_total_left = 0;
            } else {
                vol_total_left = attr->mvol.left;
            }
        }
        vol_total_left &= ~(1 << 15) ;
        D_8006B54C->rxx.main_vol.left = (vol_total_left) | mvol_mode_left;
    }

    if (bSetAll || mask & (0x01 <<  1) ) {
        if (bSetAll || mask & (0x01 <<  3) ) {
            switch (attr->mvolmode.right) {
            case 1 :
                mvol_mode_right = 0x8000 ;
                break;
            case 2 :
                mvol_mode_right = 0x9000 ;
                break;
            case 3 :
                mvol_mode_right = 0xA000 ;
                break;
            case 4 :
                mvol_mode_right = 0xB000 ;
                break;
            case 5 :
                mvol_mode_right = 0xC000 ;
                break;
            case 6 :
                mvol_mode_right = 0xD000 ;
                break;
            case 7 :
                mvol_mode_right = 0xE000 ;
                break;
            case 0 :
                vol_total_right = attr->mvol.right;
                mvol_mode_right = 0x0000 ;
                break;
            default:
                vol_total_right = attr->mvol.right;
                mvol_mode_right = 0x0000 ;
                break;
            }
        } else {
            vol_total_right = attr->mvol.right;
            mvol_mode_right = 0x0000 ;
        }

        if (mvol_mode_right != 0x0000 ) {
            if (attr->mvol.right > 0x7F ) {
                vol_total_right = 0x7F ;
            } else if (attr->mvol.right < 0) {
                vol_total_right = 0;
            } else {
                vol_total_right = attr->mvol.right;
            }
        }
        vol_total_right &= ~(1 << 15) ;
        D_8006B54C->rxx.main_vol.right = vol_total_right | mvol_mode_right;
    }

    if (bSetAll || (mask & (0x01 <<  6) )) {
        D_8006B54C->rxx.cd_vol.left = attr->cd.volume.left;
    }

    if (bSetAll || (mask & (0x01 <<  7) )) {
        D_8006B54C->rxx.cd_vol.right = attr->cd.volume.right;
    }

    if (bSetAll || (mask & (0x01 << 10) )) {
        D_8006B54C->rxx.ex_vol.left = attr->ext.volume.left;
    }

    if (bSetAll || (mask & (0x01 << 11) )) {
        D_8006B54C->rxx.ex_vol.right = attr->ext.volume.right;
    }

    if (bSetAll || (mask & (0x01 <<  8) )) {
        if (attr->cd.reverb == 0) {
            cnt = D_8006B54C->rxx.spucnt;
            cnt &= ~(1 <<  2) ;
            D_8006B54C->rxx.spucnt = cnt;
        } else {
            cnt = D_8006B54C->rxx.spucnt;
            cnt |= (1 <<  2) ;
            D_8006B54C->rxx.spucnt = cnt;
        }
    }

    if (bSetAll || (mask & (0x01 <<  9) )) {
        if (attr->cd.mix == 0) {
            cnt = D_8006B54C->rxx.spucnt;
            cnt &= ~(1 <<  0) ;
            D_8006B54C->rxx.spucnt = cnt;
        } else {
            cnt = D_8006B54C->rxx.spucnt;
            cnt |= (1 <<  0) ;
            D_8006B54C->rxx.spucnt = cnt;
        }
    }

    if (bSetAll || (mask & (0x01 << 12) )) {
        if (attr->ext.reverb == 0) {
            cnt = D_8006B54C->rxx.spucnt;
            cnt &= ~(1 <<  3) ;
            D_8006B54C->rxx.spucnt = cnt;
        } else {
            cnt = D_8006B54C->rxx.spucnt;
            cnt |= (1 <<  3) ;
            D_8006B54C->rxx.spucnt = cnt;
        }
    }

    if (bSetAll || (mask & (0x01 << 13) )) {
        if (attr->ext.mix == 0) {
            cnt = D_8006B54C->rxx.spucnt;
            cnt &= ~(1 <<  1) ;
            D_8006B54C->rxx.spucnt = cnt;
        } else {
            cnt = D_8006B54C->rxx.spucnt;
            cnt |= (1 <<  1) ;
            D_8006B54C->rxx.spucnt = cnt;
        }
    }
}
