/* Native retail instruction export [8003A5B8,8003A84C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libspu/spu_init.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8003A5B8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef signed int s32;

typedef unsigned int u32;

typedef unsigned short u16;

typedef void (*SpuCallback)(void);

typedef struct SpuVoiceRegs {
    volatile u16 volume_left;
    volatile u16 volume_right;
    volatile u16 pitch;
    volatile u16 start_address;
    volatile u16 adsr_low;
    volatile u16 adsr_high;
    volatile u16 envelope;
    volatile u16 repeat_address;
} SpuVoiceRegs;

typedef struct SpuRegs {
      SpuVoiceRegs voice[24];
      volatile u16 master_volume_left;
      volatile u16 master_volume_right;
      volatile u16 reverb_volume_left;
      volatile u16 reverb_volume_right;
      volatile u16 key_on[2];
      volatile u16 key_off[2];
      volatile u16 pitch_modulation[2];
      volatile u16 noise_enable[2];
      volatile u16 reverb_enable[2];
      unsigned char pad_19C[0xA];
      volatile u16 trans_addr;
      volatile u16 transfer_fifo;
      volatile u16 spucnt;
      volatile u16 transfer_control;
      volatile u16 transfer_status;
      volatile u16 cd_volume_left;
      volatile u16 cd_volume_right;
      volatile u16 external_volume_left;
      volatile u16 external_volume_right;
      volatile u16 current_master_volume_left;
      volatile u16 current_master_volume_right;
      unsigned char pad_1BC[4];
      volatile u16 reverb[32];
} SpuRegs;

extern s32 D_8006B574;

extern s32 D_8006B570;

extern s32 D_8006B578;

extern s32 D_8006B57C;

extern SpuRegs *D_8006B54C;

extern u32 *D_8006B55C;

extern u16 D_8006B564;

extern SpuCallback volatile D_8006B584;

extern SpuCallback volatile D_8006B588;

extern int D_8006B568, D_8006B56C, D_8006B580;

extern u16 D_800A6410[10], D_8006B58C[];

extern char D_8007344C[], D_8007345C[];

void func_8003B0E4(void);

void func_8003A84C(void *address, u32 size);

int func_8005C604(const char *format, ...);

int func_8003A5B8(int hot) {
    unsigned int timeout;
    int channel;
    volatile u16 *clear;
    *D_8006B55C |= 0xB0000;
    D_8006B568 = 0;
    D_8006B56C = 0;
    D_8006B564 = 0;
    D_8006B54C->master_volume_left = 0;
    D_8006B54C->master_volume_right = 0;
    D_8006B54C->spucnt = 0;
    func_8003B0E4();
    D_8006B54C->master_volume_left = 0;
    D_8006B54C->master_volume_right = 0;
    timeout = 0;
    while (D_8006B54C->transfer_status & 0x7FF) {
        if (++timeout > 0xF00) {
            func_8005C604(D_8007344C, D_8007345C);
            break;
        }
    }
    channel = 0;
    D_8006B570 = 2;
    D_8006B574 = 3;
    D_8006B578 = 8;
    D_8006B57C = 7;
    D_8006B54C->transfer_control = 4;
    D_8006B54C->reverb_volume_left = 0;
    D_8006B54C->reverb_volume_right = 0;
    D_8006B54C->key_off[0] = 0xFFFF;
    D_8006B54C->key_off[1] = 0xFFFF;
    D_8006B54C->reverb_enable[0] = 0;
    D_8006B54C->reverb_enable[1] = 0;
    clear = D_800A6410;

    for (; channel < 10; channel++) {
        *clear++ = 0;
    }
    if (!hot) {
        D_8006B564 = 0x200;
        D_8006B54C->pitch_modulation[0] = 0;
        D_8006B54C->pitch_modulation[1] = 0;
        D_8006B54C->noise_enable[0] = 0;
        D_8006B54C->noise_enable[1] = 0;
        D_8006B54C->cd_volume_left = 0;
        D_8006B54C->cd_volume_right = 0;
        D_8006B54C->external_volume_left = 0;
        D_8006B54C->external_volume_right = 0;
        func_8003A84C(D_8006B58C, 0x10);
        for (channel = 0; channel < 24; channel++) {
            D_8006B54C->voice[channel].volume_left = 0;
            D_8006B54C->voice[channel].volume_right = 0;
            D_8006B54C->voice[channel].pitch = 0x3FFF;
            D_8006B54C->voice[channel].start_address = 0x200;
            D_8006B54C->voice[channel].adsr_low = 0;
            D_8006B54C->voice[channel].adsr_high = 0;
        }
        D_8006B54C->key_on[0] = 0xFFFF;
        D_8006B54C->key_on[1] = 0xFF;
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
        D_8006B54C->key_off[0] = 0xFFFF;
        D_8006B54C->key_off[1] = 0xFF;
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
    }
    D_8006B580 = 1;
    D_8006B54C->spucnt = 0xC000;
    D_8006B584 = 0;
    D_8006B588 = 0;
    return 0;
}
