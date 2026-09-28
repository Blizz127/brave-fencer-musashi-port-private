#ifndef BFM_GL_EXEC_H
#define BFM_GL_EXEC_H

/* GL 3.3 core executor for bfm_gl_core command lists. Context-agnostic: the
 * caller makes a context current and passes its proc loader
 * (SDL_GL_GetProcAddress in renderer_gl.c, OSMesaGetProcAddress in the
 * headless test). No GL loader library, no GL headers beyond the Khronos
 * glcorearb.h at compile time.
 *
 * Objects: the VRAM texture (1024x512 R16UI, fed from the CPU mirror), the
 * VRAM render target (1024S x 512S RGBA8), two scene targets
 * ((disp_w + 2 margin)S x disp_h S), and replacement textures (RGBA8,
 * linear). One shader decodes CLUT/texture pages exactly as bfm_gl_sample,
 * modulates, and dithers at native pixel granularity. */

#include "bfm_gl_core.h"

typedef void *(*BfmGlGetProc)(const char *name);
typedef struct BfmGlExec BfmGlExec;

/* NULL on failure, with a message in err. */
BfmGlExec *bfm_gl_exec_create(BfmGlGetProc getproc, int scale, char *err,
                              size_t err_size);
void bfm_gl_exec_destroy(BfmGlExec *x);
int bfm_gl_exec_scale(const BfmGlExec *x);
/* Reallocates the render targets (their content is lost). */
int bfm_gl_exec_set_scale(BfmGlExec *x, int scale);

/* Uploads the mirror's dirty box to the VRAM texture and clears it. */
void bfm_gl_exec_sync_vram(BfmGlExec *x, BfmGlVram *v);
/* Runs b's command list (call bfm_gl_exec_sync_vram first). dither: global
 * toggle; vertex/batch flags still decide per primitive. */
int bfm_gl_exec_run(BfmGlExec *x, const BfmGlBatch *b, int dither);

/* Reads a target-local 1x rect of a render target back as 15-bit pixels
 * (centre sample of each scaled pixel; STP = 0). */
int bfm_gl_exec_readback(BfmGlExec *x, const BfmGlBatch *b, int target,
                         const BfmPlatRect *local, uint16_t *out);

/* Replacement texture from RGBA8888 rows; 0 on failure. */
uint32_t bfm_gl_exec_texture(BfmGlExec *x, uint32_t w, uint32_t h,
                             const uint8_t *rgba);
void bfm_gl_exec_texture_free(BfmGlExec *x, uint32_t id);

/* Draws the displayed frame into the default framebuffer: the scene slot at
 * the display origin (hor+: the whole wide target) or the display rect of
 * the VRAM target, fitted to image_aspect with black bars, then the overlay
 * batch over the 4:3 display area. Does not swap. */
int bfm_gl_exec_present(BfmGlExec *x, const BfmGlBatch *b,
                        const BfmGlBatch *overlay, int win_w, int win_h,
                        double image_aspect, int dither);

/* Draws a CPU image (RGBA8888, e.g. a 24-bit movie frame) fitted to
 * image_aspect with black bars, then the overlay. Does not swap. */
int bfm_gl_exec_present_image(BfmGlExec *x, int w, int h, const uint8_t *rgba,
                              const BfmGlBatch *overlay, int win_w, int win_h,
                              double image_aspect);

/* The last GL error seen by any call (0 = none), and clears it. */
unsigned bfm_gl_exec_error(BfmGlExec *x);

#endif
