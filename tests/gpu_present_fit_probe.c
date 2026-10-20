/* Live present geometry for the owner handheld gate (real PsyCross GL context,
 * synthetic all-white VRAM; not game proof). A windowed present stretches the
 * display rect over the whole drawable exactly as before; a fullscreen present
 * keeps 4:3 inside the drawable with black bars, and returning to a window
 * stretches again. Pixels are sampled from inside the present (the host overlay
 * callback runs after the VRAM blit and before the buffer swap), so the result
 * does not depend on what a driver leaves in the back or front buffer.
 *
 * OPT-IN: it puts a fullscreen window over the screen and its size checks assume
 * there is no window manager, so it skips (77) unless MUSASHI_PRESENT_FIT_PROBE=1
 * and is meant for a private Xvfb. Under Xvfb there is no window manager, so SDL
 * takes its legacy fullscreen path (an override-redirect window the size of the
 * screen), not the EWMH path Gamescope uses: this checks the present geometry,
 * not Gamescope. Run it (screens to try: 1280x800 pillarbox, 1280x1024 letterbox,
 * 1920x1080 pillarbox):
 *
 *   MUSASHI_PRESENT_FIT_PROBE=1 xvfb-run -a -s "-screen 0 1280x800x24" \
 *       build/musashi_gpu_present_fit_probe
 */
#include "musashi_gpu_psycross.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tools/third_party/psycross/src/gpu/PsyX_GPU.h"
#include "PsyX/PsyX_render.h"
#include "PsyX/PsyX_public.h"
void musashi_psyx_shutdown(void); /* pc_port/psyx_shutdown.cpp: GL teardown before window */

static int failures;
#define CHECK(cond) do { if (!(cond)) { ++failures; \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); } } while (0)

#define MAX_POINTS 8
static struct {
    int n;
    int x[MAX_POINTS], y[MAX_POINTS];
    unsigned char rgb[MAX_POINTS][3];
} sample;

/* Runs inside musashi_gpu_psycross_present, after the blit and before the swap. */
static void sampler(void *user, int width, int height) {
    int i;
    (void)user; (void)width; (void)height;
    for (i = 0; i < sample.n; ++i) {
        sample.rgb[i][0] = sample.rgb[i][1] = sample.rgb[i][2] = 127;
        (void)musashi_gpu_psycross_overlay_read_rgb(sample.x[i], sample.y[i], 1, 1, sample.rgb[i]);
    }
}

static int white(int i) { return sample.rgb[i][0] > 200 && sample.rgb[i][1] > 200 && sample.rgb[i][2] > 200; }
static int black(int i) { return sample.rgb[i][0] < 20 && sample.rgb[i][1] < 20 && sample.rgb[i][2] < 20; }

/* A present with the given sample points (window coordinates, y up), after one
 * unsampled warm-up present: Mesa resizes the default framebuffer lazily, so the
 * first present after a window size change still draws into the old size. */
static int present_at(MusashiGpuPsyCross *gpu, int n, const int pts[][2]) {
    int i;
    sample.n = 0;
    if (!musashi_gpu_psycross_present(gpu)) return 0;
    sample.n = n;
    for (i = 0; i < n; ++i) { sample.x[i] = pts[i][0]; sample.y[i] = pts[i][1]; }
    return musashi_gpu_psycross_present(gpu);
}

/* Give the X server a moment to answer a fullscreen request. */
static void settle(SDL_Window *w, int want_w, int want_h) {
    int dw = 0, dh = 0;
    Uint32 start = SDL_GetTicks();
    do {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) { }
        SDL_GL_GetDrawableSize(w, &dw, &dh);
        if (dw == want_w && dh == want_h) return;
        SDL_Delay(20);
    } while (SDL_GetTicks() - start < 2000);
}

int main(void) {
    MusashiGpuPsyCross gpu = {0};
    MusashiGpuBackend backend;
    MusashiGpuFill fill = {.command = 0x02ffffffu, .xy = 0, .wh = 0x01ff03ffu};
    MusashiGpuDisplayState display = {
        0, 0x00c60260u, 0x00040010u, 1, 0, 0, 320, 240, 608, 3168, 16, 256, 8
    };
    SDL_Window *window;
    int dw = 0, dh = 0, screen_w, screen_h, start_w, start_h, bars_case = 0;
    SDL_DisplayMode mode;
    const char *opt_in = getenv("MUSASHI_PRESENT_FIT_PROBE");

    if (!opt_in || opt_in[0] != '1') {   /* before any window exists */
        puts("skipped: opt-in probe, see the header comment (MUSASHI_PRESENT_FIT_PROBE=1 under xvfb-run)");
        return 77;
    }
    /* The window starts at least as large as the screen: under Xvfb the GL framebuffer
     * does not grow when a window does, so a smaller start could not be sampled once
     * fullscreen. The only difference between steps 1 and 2 is then the fullscreen flag. */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 || SDL_GetDesktopDisplayMode(0, &mode) != 0) return 77;
    screen_w = mode.w;
    screen_h = mode.h;
    start_w = screen_w > 1280 ? screen_w : 1280;
    start_h = screen_h > 960 ? screen_h : 960;
    PsyX_Initialise("Musashi present fit probe", start_w, start_h, 0);
    window = SDL_GL_GetCurrentWindow();
    if (!SDL_GL_GetCurrentContext() || !window) {
        musashi_psyx_shutdown();
        return 77;
    }
    if (!musashi_gpu_psycross_init(&gpu, &backend)) {
        fprintf(stderr, "gpu init refused\n");
        musashi_psyx_shutdown();
        return 1;
    }
    CHECK(musashi_gpu_fill_derive(&fill));
    CHECK(backend.fill_vram(backend.userdata, &fill));
    CHECK(backend.display(backend.userdata, &display));
    CHECK(backend.display_enable(backend.userdata, 1));
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    musashi_gpu_psycross_set_overlay(sampler, NULL);

    /* 1. Windowed: the stretch fills the whole drawable, corners included. */
    SDL_GL_GetDrawableSize(window, &dw, &dh);
    CHECK(dw == start_w && dh == start_h);
    {
        const int pts[4][2] = {{3, dh / 2}, {dw - 4, dh / 2}, {dw / 2, 3}, {dw / 2, dh - 4}};
        CHECK(present_at(&gpu, 4, pts));
        CHECK(white(0) && white(1) && white(2) && white(3));
    }

    /* 2. Fullscreen on a screen that is not 4:3: black bars on the short sides,
     * the image keeps 4:3 between them and fills the other dimension. */
    if (screen_w * 3 != screen_h * 4) {
        int fx, fy, fw, fh;
        bars_case = 1;
        CHECK(SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP) == 0);
        settle(window, screen_w, screen_h);
        SDL_GL_GetDrawableSize(window, &dw, &dh);
        CHECK(dw == screen_w && dh == screen_h);
        if (screen_w * 3 > screen_h * 4) {           /* wider than 4:3: pillarbox */
            fw = (screen_h * 4 + 1) / 3; fh = screen_h; fx = (screen_w - fw) / 2; fy = 0;
            {
                const int pts[8][2] = {
                    {2, dh / 2}, {fx - 3, dh / 2}, {fx + fw + 2, dh / 2}, {dw - 3, dh / 2},
                    {fx + 3, dh / 2}, {fx + fw - 4, dh / 2}, {dw / 2, 3}, {dw / 2, dh - 4}};
                CHECK(present_at(&gpu, 8, pts));
                CHECK(black(0) && black(1) && black(2) && black(3));
                CHECK(white(4) && white(5) && white(6) && white(7));
            }
        } else {                                      /* taller than 4:3: letterbox */
            fw = screen_w; fh = (screen_w * 3 + 2) / 4; fx = 0; fy = (screen_h - fh) / 2;
            {
                const int pts[8][2] = {
                    {dw / 2, 2}, {dw / 2, fy - 3}, {dw / 2, fy + fh + 2}, {dw / 2, dh - 3},
                    {dw / 2, fy + 3}, {dw / 2, fy + fh - 4}, {3, dh / 2}, {dw - 4, dh / 2}};
                CHECK(present_at(&gpu, 8, pts));
                CHECK(black(0) && black(1) && black(2) && black(3));
                CHECK(white(4) && white(5) && white(6) && white(7));
            }
        }
        printf("fullscreen %dx%d: image %dx%d at %d,%d, bars black\n", dw, dh, fw, fh, fx, fy);

        /* 3. Back to a window: the stretch is back. */
        CHECK(SDL_SetWindowFullscreen(window, 0) == 0);
        SDL_SetWindowSize(window, start_w, start_h);
        settle(window, start_w, start_h);
        SDL_GL_GetDrawableSize(window, &dw, &dh);
        CHECK(dw == start_w && dh == start_h);
        {
            const int pts[4][2] = {{3, dh / 2}, {dw - 4, dh / 2}, {dw / 2, 3}, {dw / 2, dh - 4}};
            CHECK(present_at(&gpu, 4, pts));
            CHECK(white(0) && white(1) && white(2) && white(3));
        }
    } else {
        printf("screen %dx%d is 4:3: the fullscreen bars case does not apply here\n", screen_w, screen_h);
    }
    musashi_gpu_psycross_set_overlay(NULL, NULL);
    CHECK(musashi_gpu_psycross_shutdown(&gpu));
    musashi_psyx_shutdown();
    if (failures) { fprintf(stderr, "present fit probe: %d failure(s)\n", failures); return 1; }
    if (bars_case)
        puts("PRESENT FIT OBSERVED: windowed stretch unchanged, fullscreen keeps 4:3 with black bars, window stretches again");
    else
        puts("PRESENT FIT: 4:3 screen, only the windowed stretch was checked (the bars case needs another aspect)");
    return 0;
}
