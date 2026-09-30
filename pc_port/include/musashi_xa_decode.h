/* Private XA decode implementation. Source: PSX-SPX CDROM Format,
 * XA-ADPCM and 25-point zigzag coefficient table. Integer filter rounding
 * follows the documented model; physical sample/phase bit parity is unproven.
 * Formats: 4-bit 37800Hz stereo (the opening) and 4-bit 37800Hz mono (room
 * music, e.g. the Spiral Tower top 300B and field 3012), no emphasis. Other
 * formats refuse before changing history or output. Initial interpolation
 * phase is 6.
 */
#ifndef MUSASHI_XA_DECODE_H
#define MUSASHI_XA_DECODE_H
#include <stdint.h>
#include <string.h>
typedef struct MusashiXaDecode {
    int32_t old[2], older[2];
    int16_t ring[2][32];
    unsigned position, phase;
} MusashiXaDecode;
static const int16_t xa_coefficients[29][7] = {
    {0,0,0,0,-1,2,-5},
    {0,0,0,-1,3,-8,17},
    {0,0,-1,3,-8,16,-35},
    {0,-2,3,-8,17,-35,70},
    {0,0,-2,6,-16,43,-23},
    {-2,3,-5,5,10,26,-68},
    {10,-19,31,-27,107,-235,347},
    {-34,60,-74,166,-365,635,-839},
    {65,-75,179,-424,848,-1352,2062},
    {-84,162,-402,882,-1571,2810,-4681},
    {52,-227,689,-1471,3021,-5882,15367},
    {9,306,-926,2488,-6016,21472,21472},
    {-266,-67,1272,-4532,26516,15367,-5882},
    {1024,-615,-1446,29883,9036,-4681,2810},
    {-2680,3229,31033,3229,-2680,2062,-1352},
    {9036,29883,-1446,-615,1024,-839,635},
    {26516,-4532,1272,-67,-266,347,-235},
    {-6016,2488,-926,306,9,-68,26},
    {3021,-1471,689,-227,52,-23,43},
    {-1571,882,-402,162,-84,70,-35},
    {848,-424,179,-75,65,-35,16},
    {-365,166,-74,60,-34,17,-8},
    {107,-27,31,-19,10,-5,2},
    {10,5,-5,3,-1,0,0},
    {-16,6,-2,0,0,0,0},
    {17,-8,3,-2,1,0,0},
    {-8,3,-1,0,0,0,0},
    {3,-1,0,0,0,0,0},
    {-1,0,0,0,0,0,0},
};
static void xa_reset(MusashiXaDecode *d) { memset(d,0,sizeof(*d));d->phase=6; }
static int16_t xa_clamp(int32_t v) { return (int16_t)(v<-32768?-32768:v>32767?32767:v); }
static int32_t xa_floor_shift(int32_t v,unsigned n) {
    return v>=0?v/(1<<n):-(((-v)+(1<<n)-1)/(1<<n));
}
/* Output is interleaved 37800Hz stereo: 2016 frames for a stereo sector,
 * 4032 for a mono one (its sample in both channels); *frames receives the
 * count. Every header is checked before the first decoder-history update.
 * Audio/realtime and Form2 required. */
static int xa_decode_samples(MusashiXaDecode *d,const uint8_t raw[2352],int16_t pcm[8064],
                             unsigned *frames) {
    static const int f0[4]={0,60,115,98},f1[4]={0,0,-52,-55};
    unsigned group,block,ch,j,frame=0;
    if(raw[15]!=2 || (raw[18]&0x64u)!=0x64u || (raw[19]!=0 && raw[19]!=1) ||
       memcmp(raw+16,raw+20,4))return 0;
    for(group=0;group<18;group++)for(block=0;block<8;block++)
        if((raw[24+group*128+4+block]&15u)>12u)return 0;
    if(raw[19]==0) {
        /* Mono: eight sound units per group in time order, one history;
         * unit u's header is p[4+u], its nibbles p[16+u/2+j*4] (u&1: high). */
        for(group=0;group<18;group++) {
            const uint8_t *p=raw+24+group*128;
            for(block=0;block<8;block++) {
                unsigned param=p[4+block],shift=param&15u,filter=(param>>4)&3u;
                for(j=0;j<28;j++) {
                    int32_t nibble=(p[16+(block>>1)+j*4]>>((block&1u)*4))&15;
                    int32_t value;
                    int16_t out;
                    if(nibble&8)nibble-=16;
                    value=nibble*(1<<(12-shift))+
                        xa_floor_shift(d->old[0]*f0[filter]+d->older[0]*f1[filter]+32,6);
                    out=xa_clamp(value);
                    pcm[(frame+j)*2]=pcm[(frame+j)*2+1]=out;
                    d->older[0]=d->old[0];d->old[0]=out;
                }
                frame+=28;
            }
        }
        *frames=frame;
        return 1;
    }
    for(group=0;group<18;group++) {
        const uint8_t *p=raw+24+group*128;
        for(block=0;block<4;block++) {
            for(ch=0;ch<2;ch++) {
                unsigned param=p[4+block*2+ch],shift=param&15u,filter=(param>>4)&3u;
                for(j=0;j<28;j++) {
                    int32_t nibble=(p[16+block+j*4]>>(ch*4))&15;
                    int32_t value;
                    if(nibble&8)nibble-=16;
                    value=nibble*(1<<(12-shift))+
                        xa_floor_shift(d->old[ch]*f0[filter]+d->older[ch]*f1[filter]+32,6);
                    pcm[(frame+j)*2+ch]=xa_clamp(value);
                    d->older[ch]=d->old[ch];d->old[ch]=pcm[(frame+j)*2+ch];
                }
            }
            frame+=28;
        }
    }
    *frames=frame;
    return 1;
}
/* 37800 -> 44100 Hz: 2352 output frames for a stereo sector, 4704 for a mono
 * one; returns that count, 0 when the sector is refused. */
static unsigned xa_decode(MusashiXaDecode *d,const uint8_t raw[2352],int16_t pcm[9408]) {
    int16_t samples[8064];unsigned n,ch,phase,tap,out=0,frames=0;
    if(!xa_decode_samples(d,raw,samples,&frames))return 0;
    for(n=0;n<frames;n++) {
        for(ch=0;ch<2;ch++)d->ring[ch][d->position&31u]=samples[n*2+ch];
        ++d->position;
        if(--d->phase)continue;
        d->phase=6;
        for(phase=0;phase<7;phase++) {
            for(ch=0;ch<2;ch++) {
                int32_t sum=0;
                for(tap=0;tap<29;tap++)
                    sum+=xa_floor_shift(d->ring[ch][(d->position-tap-1u)&31u]*
                                        xa_coefficients[tap][phase],15);
                pcm[out*2+ch]=xa_clamp(sum);
            }
            ++out;
        }
    }
    return out==frames*7u/6u ? out : 0u;
}
#endif
