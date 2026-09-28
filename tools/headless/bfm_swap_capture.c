/* LD_PRELOAD capture shim for headless runs of musashi_native_boot (or any
 * SDL2/GL program): hooks SDL_GL_SwapWindow and, per presented frame,
 * counts non-black pixels of the framebuffer about to be shown.
 *
 *   BFM_CAPTURE_DIR          output directory (required; the shim is inert
 *                            without it)
 *   BFM_CAPTURE_EVERY        also write PNGs every N frames (default 600)
 *   BFM_CAPTURE_VRAM_OFFSET  hex offset of PsyCross's `vram` array (1024x512
 *                            16-bit) in the executable (from `nm`); when set,
 *                            the full VRAM is written next to each frame PNG
 *
 * Writes <dir>/frames.log ("frame seconds nonblack width height", one line
 * per frame, flushed), frame_NNNNNN.png at the first frame with non-black
 * pixels, whenever the display turns black/non-black, and every N frames;
 * vram_NNNNNN.png beside them. PNGs use the platform layer's writer
 * (bfm_plat_image.c). Output only goes to BFM_CAPTURE_DIR. It changes no
 * guest state: it reads the back buffer before the real swap. */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <link.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bfm_plat_image.h"

typedef struct SDL_Window SDL_Window;
typedef void (*SwapFn)(SDL_Window *);
typedef void *(*GetProcFn)(const char *);
typedef void (*DrawableFn)(SDL_Window *, int *, int *);
typedef void (*ReadPixelsFn)(int, int, int, int, unsigned, unsigned, void *);
typedef void (*GetIntegervFn)(unsigned, int *);
typedef void (*BindFbFn)(unsigned, unsigned);
typedef void (*PixelStoreFn)(unsigned, int);

#define GL_RGBA 0x1908
#define GL_UNSIGNED_BYTE 0x1401
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_PACK_ALIGNMENT 0x0D05

#define LOADSYM(dst, obj)                                                     \
    do {                                                                      \
        void *o_ = (obj);                                                     \
        memcpy(&(dst), &o_, sizeof o_);                                       \
    } while (0)

static SwapFn real_swap;
static GetProcFn get_proc;
static DrawableFn drawable;
static ReadPixelsFn read_pixels;
static GetIntegervFn get_integerv;
static BindFbFn bind_fb;
static PixelStoreFn pixel_store;
static const char *dir;
static FILE *log_file;
static unsigned long frame, every = 600;
static uintptr_t vram_addr;
static int last_lit = -1, ready;
static struct timespec t0;

static int first_object(struct dl_phdr_info *info, size_t size, void *data) {
    (void)size;
    *(uintptr_t *)data = (uintptr_t)info->dlpi_addr;   /* main program first */
    return 1;
}

static void init(void) {
    const char *e;
    ready = -1;
    if (!(dir = getenv("BFM_CAPTURE_DIR")) || !dir[0]) return;
    if ((e = getenv("BFM_CAPTURE_EVERY")) && atol(e) > 0) every = (unsigned long)atol(e);
    if ((e = getenv("BFM_CAPTURE_VRAM_OFFSET")) && e[0]) {
        uintptr_t base = 0;
        dl_iterate_phdr(first_object, &base);
        vram_addr = base + (uintptr_t)strtoull(e, NULL, 16);
    }
    LOADSYM(real_swap, dlsym(RTLD_NEXT, "SDL_GL_SwapWindow"));
    LOADSYM(get_proc, dlsym(RTLD_NEXT, "SDL_GL_GetProcAddress"));
    LOADSYM(drawable, dlsym(RTLD_NEXT, "SDL_GL_GetDrawableSize"));
    if (!real_swap || !get_proc || !drawable) return;
    {
        char path[1024];
        snprintf(path, sizeof path, "%s/frames.log", dir);
        log_file = fopen(path, "w");
    }
    clock_gettime(CLOCK_MONOTONIC, &t0);
    ready = 1;
}

static void write_vram(unsigned long n) {
    static uint8_t rgb[1024 * 512 * 3];
    char path[1024];
    bfm_plat_vram15_to_rgb((const uint16_t *)vram_addr, 1024u * 512u, rgb);
    snprintf(path, sizeof path, "%s/vram_%06lu.png", dir, n);
    bfm_plat_png_write(path, 1024, 512, 3, rgb);
}

static void capture(SDL_Window *w) {
    int width = 0, height = 0, prev = 0, x, y;
    uint8_t *px, *flip;
    unsigned long lit = 0;
    struct timespec t;
    if (!read_pixels) {
        LOADSYM(read_pixels, get_proc("glReadPixels"));
        LOADSYM(get_integerv, get_proc("glGetIntegerv"));
        LOADSYM(bind_fb, get_proc("glBindFramebuffer"));
        LOADSYM(pixel_store, get_proc("glPixelStorei"));
        if (!read_pixels || !get_integerv || !bind_fb || !pixel_store) { ready = -1; return; }
    }
    drawable(w, &width, &height);
    if (width <= 0 || height <= 0) return;
    if (!(px = (uint8_t *)malloc((size_t)width * height * 4))) return;
    get_integerv(GL_READ_FRAMEBUFFER_BINDING, &prev);
    bind_fb(GL_READ_FRAMEBUFFER, 0);
    pixel_store(GL_PACK_ALIGNMENT, 1);
    read_pixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, px);
    bind_fb(GL_READ_FRAMEBUFFER, (unsigned)prev);
    for (x = 0; x < width * height; x++)
        lit += (px[x * 4] | px[x * 4 + 1] | px[x * 4 + 2]) > 8;
    clock_gettime(CLOCK_MONOTONIC, &t);
    if (log_file) {
        fprintf(log_file, "%lu %.2f %lu %d %d\n", frame,
                (double)(t.tv_sec - t0.tv_sec) + (t.tv_nsec - t0.tv_nsec) / 1e9, lit, width, height);
        fflush(log_file);
    }
    if ((int)(lit > 0) != last_lit || frame % every == 0) {
        char path[1024];
        /* GL rows are bottom-up; PNG wants top-down, RGB */
        if ((flip = (uint8_t *)malloc((size_t)width * height * 3)) != NULL) {
            for (y = 0; y < height; y++)
                for (x = 0; x < width; x++) {
                    const uint8_t *s = &px[((size_t)(height - 1 - y) * width + x) * 4];
                    uint8_t *d = &flip[((size_t)y * width + x) * 3];
                    d[0] = s[0]; d[1] = s[1]; d[2] = s[2];
                }
            snprintf(path, sizeof path, "%s/frame_%06lu.png", dir, frame);
            bfm_plat_png_write(path, (uint32_t)width, (uint32_t)height, 3, flip);
            free(flip);
        }
        if (vram_addr) write_vram(frame);
        last_lit = lit > 0;
    }
    free(px);
}

void SDL_GL_SwapWindow(SDL_Window *w) {
    if (!ready) init();
    if (ready > 0) capture(w);
    frame++;
    if (real_swap) real_swap(w);
    else {
        SwapFn f;
        LOADSYM(f, dlsym(RTLD_NEXT, "SDL_GL_SwapWindow"));
        if (f) f(w);
    }
}
