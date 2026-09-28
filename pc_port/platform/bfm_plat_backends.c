/* Backends compiled into this build. The default (dependency-free) build has
 * only the built-in null/image/scripted backends. SDL/PsyCross builds define
 * BFM_PLAT_WITH_PSYCROSS / BFM_PLAT_WITH_SDL_AUDIO / BFM_PLAT_WITH_PINNED_DISC
 * and link the matching backends/ file. */
#include "bfm_plat.h"

#ifdef BFM_PLAT_WITH_PSYCROSS
int bfm_plat_backend_psycross_register(void);
#endif
#ifdef BFM_PLAT_WITH_SDL_AUDIO
int bfm_plat_backend_sdl_audio_register(void);
#endif
#ifdef BFM_PLAT_WITH_PINNED_DISC
int bfm_plat_backend_pinned_disc_register(void);
#endif

int bfm_plat_register_builtin_backends(void) {
    static int done;
    int n = 0;
    if (done) return 0;
    done = 1;
#ifdef BFM_PLAT_WITH_PSYCROSS
    n += bfm_plat_backend_psycross_register() == BFM_PLAT_OK;
#endif
#ifdef BFM_PLAT_WITH_SDL_AUDIO
    n += bfm_plat_backend_sdl_audio_register() == BFM_PLAT_OK;
#endif
#ifdef BFM_PLAT_WITH_PINNED_DISC
    n += bfm_plat_backend_pinned_disc_register() == BFM_PLAT_OK;
#endif
    return n;
}
