/* End-to-end MUSASHI_AUDIO=bfm_plat path without the game: the in-house SPU
 * core (pc_port/spu_cd_audio.c) renders a submitted CD tone through its
 * volume/mix stages into pc_port/plat_audio_sink.c and on to a bfm_plat
 * audio backend ("null" with a deterministic platform clock, or the one
 * named in argv[1]). Checks the sink saw non-silent frames, the backend
 * took them all, and silence stays silent. Prints one OK line; exit 1 on
 * failure. */
#include "bfm_plat_audio.h"
#include "bfm_plat_timing.h"
#include "musashi_plat_audio_sink.h"
#include "musashi_spu_cd_audio.h"

#include <stdio.h>
#include <string.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); return 1; } } while (0)
#define FRAMES 4410u

static uint64_t fake_ns;
static uint64_t fake_now(void *u) { (void)u; return fake_ns; }
static void fake_sleep(void *u, uint64_t ns) { (void)u; fake_ns += ns; }
static uint64_t one_thread(void *u) { (void)u; return 1; }

#ifdef PROBE_OPENAL
int bfm_plat_backend_openal_audio_register(void);
#endif

int main(int argc, char **argv) {
    static int16_t tone[FRAMES * 2];
    const char *want = argc > 1 ? argv[1] : "null", *sel = NULL;
    const BfmPlatClock clock = {fake_now, fake_sleep, NULL};
    MusashiPlatAudioSink sink;
    const MusashiSpuCdAudioBackend *backend;
    MusashiSpuCdAudio *spu;
    BfmPlatAudioStatus st;
    uint64_t silent_frames;
    unsigned i;

    if (!strcmp(want, "null")) bfm_plat_timing_set_clock(&clock);
#ifdef PROBE_OPENAL
    CHECK(bfm_plat_backend_openal_audio_register() == BFM_PLAT_OK);
#endif
    CHECK(bfm_plat_audio_open(want, &sel) == BFM_PLAT_OK && sel);
    if (strcmp(sel, want) != 0) { printf("SKIP %s (unavailable)\n", want); return 0; }
    backend = musashi_plat_audio_sink_init(&sink, one_thread, NULL);
    CHECK(backend != NULL);
    spu = musashi_spu_cd_audio_create();
    CHECK(spu && musashi_spu_cd_audio_init_bios_muted(spu, backend, 0));

    /* Silence first: the settled BIOS mute renders zero frames. */
    CHECK(musashi_spu_cd_audio_advance(spu, 735u * MUSASHI_SPU_CD_AUDIO_SAMPLE_CYCLES));
    CHECK(sink.frames == 735u && sink.nonsilent == 0 && sink.peak == 0);
    silent_frames = sink.frames;

    /* Main volume up, CD gain up, SPU + CD audio enabled; then a 441 Hz
     * square tone arrives as CD PCM and is rendered by the mixer. */
    CHECK(musashi_spu_cd_audio_write16(spu, 0x1f801d80u, 0x3fffu));
    CHECK(musashi_spu_cd_audio_write16(spu, 0x1f801d82u, 0x3fffu));
    CHECK(musashi_spu_cd_audio_write16(spu, 0x1f801db0u, 0x7fffu));
    CHECK(musashi_spu_cd_audio_write16(spu, 0x1f801db2u, 0x7fffu));
    CHECK(musashi_spu_cd_audio_write16(spu, 0x1f801daau, 0x8001u));
    for (i = 0; i < FRAMES; i++) tone[2 * i] = tone[2 * i + 1] = (int16_t)((i % 100u) < 50u ? 8000 : -8000);
    CHECK(musashi_spu_cd_audio_submit_cd_pcm(spu, 735u, tone, FRAMES));
    for (i = 1; i <= 6u; i++) {
        CHECK(musashi_spu_cd_audio_advance(spu, (735u + i * 735u) * MUSASHI_SPU_CD_AUDIO_SAMPLE_CYCLES));
        fake_ns += 1000000000ull / 60u;   /* the null device drains in step */
    }
    CHECK(!sink.faulted);
    CHECK(sink.frames == silent_frames + 6u * 735u);
    CHECK(sink.nonsilent > FRAMES / 2u);
    CHECK(sink.peak > 1000);
    CHECK(bfm_plat_audio_status(&st) == BFM_PLAT_OK);
    CHECK(st.submitted_frames[BFM_AUDIO_STREAM_MAIN] == sink.frames);
    CHECK(musashi_spu_cd_audio_destroy(spu));
    bfm_plat_audio_close();
    printf("OK %s frames=%llu nonsilent=%llu peak=%d\n", sel,
           (unsigned long long)sink.frames, (unsigned long long)sink.nonsilent, sink.peak);
    return 0;
}
