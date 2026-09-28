/* GL 3.3 core executor. See bfm_gl_exec.h. */

#include "bfm_gl_exec.h"

#include <GL/glcorearb.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BFM_GL_FUNCS(X)                                                    \
    X(PFNGLGETSTRINGPROC, GetString)                                       \
    X(PFNGLGETERRORPROC, GetError)                                         \
    X(PFNGLGETINTEGERVPROC, GetIntegerv)                                   \
    X(PFNGLVIEWPORTPROC, Viewport)                                         \
    X(PFNGLSCISSORPROC, Scissor)                                           \
    X(PFNGLENABLEPROC, Enable)                                             \
    X(PFNGLDISABLEPROC, Disable)                                           \
    X(PFNGLCLEARCOLORPROC, ClearColor)                                     \
    X(PFNGLCLEARPROC, Clear)                                               \
    X(PFNGLBLENDEQUATIONPROC, BlendEquation)                               \
    X(PFNGLBLENDFUNCPROC, BlendFunc)                                       \
    X(PFNGLBLENDCOLORPROC, BlendColor)                                     \
    X(PFNGLGENTEXTURESPROC, GenTextures)                                   \
    X(PFNGLDELETETEXTURESPROC, DeleteTextures)                             \
    X(PFNGLBINDTEXTUREPROC, BindTexture)                                   \
    X(PFNGLTEXIMAGE2DPROC, TexImage2D)                                     \
    X(PFNGLTEXSUBIMAGE2DPROC, TexSubImage2D)                               \
    X(PFNGLTEXPARAMETERIPROC, TexParameteri)                               \
    X(PFNGLACTIVETEXTUREPROC, ActiveTexture)                               \
    X(PFNGLPIXELSTOREIPROC, PixelStorei)                                   \
    X(PFNGLREADPIXELSPROC, ReadPixels)                                     \
    X(PFNGLGENFRAMEBUFFERSPROC, GenFramebuffers)                           \
    X(PFNGLDELETEFRAMEBUFFERSPROC, DeleteFramebuffers)                     \
    X(PFNGLBINDFRAMEBUFFERPROC, BindFramebuffer)                           \
    X(PFNGLFRAMEBUFFERTEXTURE2DPROC, FramebufferTexture2D)                 \
    X(PFNGLCHECKFRAMEBUFFERSTATUSPROC, CheckFramebufferStatus)             \
    X(PFNGLGENVERTEXARRAYSPROC, GenVertexArrays)                           \
    X(PFNGLDELETEVERTEXARRAYSPROC, DeleteVertexArrays)                     \
    X(PFNGLBINDVERTEXARRAYPROC, BindVertexArray)                           \
    X(PFNGLGENBUFFERSPROC, GenBuffers)                                     \
    X(PFNGLDELETEBUFFERSPROC, DeleteBuffers)                               \
    X(PFNGLBINDBUFFERPROC, BindBuffer)                                     \
    X(PFNGLBUFFERDATAPROC, BufferData)                                     \
    X(PFNGLVERTEXATTRIBPOINTERPROC, VertexAttribPointer)                   \
    X(PFNGLVERTEXATTRIBIPOINTERPROC, VertexAttribIPointer)                 \
    X(PFNGLENABLEVERTEXATTRIBARRAYPROC, EnableVertexAttribArray)           \
    X(PFNGLCREATESHADERPROC, CreateShader)                                 \
    X(PFNGLSHADERSOURCEPROC, ShaderSource)                                 \
    X(PFNGLCOMPILESHADERPROC, CompileShader)                               \
    X(PFNGLGETSHADERIVPROC, GetShaderiv)                                   \
    X(PFNGLGETSHADERINFOLOGPROC, GetShaderInfoLog)                         \
    X(PFNGLDELETESHADERPROC, DeleteShader)                                 \
    X(PFNGLCREATEPROGRAMPROC, CreateProgram)                               \
    X(PFNGLATTACHSHADERPROC, AttachShader)                                 \
    X(PFNGLBINDATTRIBLOCATIONPROC, BindAttribLocation)                     \
    X(PFNGLLINKPROGRAMPROC, LinkProgram)                                   \
    X(PFNGLGETPROGRAMIVPROC, GetProgramiv)                                 \
    X(PFNGLGETPROGRAMINFOLOGPROC, GetProgramInfoLog)                       \
    X(PFNGLDELETEPROGRAMPROC, DeleteProgram)                               \
    X(PFNGLUSEPROGRAMPROC, UseProgram)                                     \
    X(PFNGLGETUNIFORMLOCATIONPROC, GetUniformLocation)                     \
    X(PFNGLUNIFORM1IPROC, Uniform1i)                                       \
    X(PFNGLUNIFORM2FPROC, Uniform2f)                                       \
    X(PFNGLUNIFORM4FPROC, Uniform4f)                                       \
    X(PFNGLUNIFORM4IPROC, Uniform4i)                                       \
    X(PFNGLDRAWARRAYSPROC, DrawArrays)

typedef struct Target {
    GLuint tex, fbo;
    int w, h;                    /* 1x size */
} Target;

struct BfmGlExec {
#define X(type, name) type name;
    BFM_GL_FUNCS(X)
#undef X
    GLuint prog, blit, vao, vbo, empty_vao, vram_tex, white_tex, image_tex;
    Target tgt[3];               /* VRAM, scene 0, scene 1 */
    int scale;
    GLint u_size, u_flip, u_pass, u_dither, u_scale, u_win, u_vram, u_repl;
    GLint b_src, b_tex;
    unsigned err;
};

static const char *vs_src =
    "#version 330 core\n"
    "layout(location = 0) in vec2 a_pos;\n"
    "layout(location = 1) in vec4 a_color;\n"
    "layout(location = 2) in vec2 a_uv;\n"
    "layout(location = 3) in uvec4 a_info;\n"
    "layout(location = 4) in vec2 a_st;\n"
    "uniform vec2 u_size;\n"
    "uniform int u_flip;\n"
    "out vec4 v_color;\n"
    "noperspective out vec2 v_uv;\n"
    "flat out uvec4 v_info;\n"
    "noperspective out vec2 v_st;\n"
    "void main() {\n"
    "    vec2 n = a_pos / u_size * 2.0 - 1.0;\n"
    "    if (u_flip != 0) n.y = -n.y;\n"
    "    gl_Position = vec4(n, 0.0, 1.0);\n"
    "    v_color = a_color; v_uv = a_uv; v_info = a_info; v_st = a_st;\n"
    "}\n";

/* Mirrors bfm_gl_sample / bfm_gl_modulate / bfm_gl_dither5. */
static const char *fs_src =
    "#version 330 core\n"
    "in vec4 v_color;\n"
    "noperspective in vec2 v_uv;\n"
    "flat in uvec4 v_info;\n"
    "noperspective in vec2 v_st;\n"
    "uniform usampler2D u_vram;\n"
    "uniform sampler2D u_repl;\n"
    "uniform int u_pass;\n"
    "uniform int u_dither;\n"
    "uniform int u_scale;\n"
    "uniform ivec4 u_win;\n"
    "out vec4 o_color;\n"
    "const int dm[16] = int[16](-4, 0, -3, 1, 2, -2, 3, -1, -3, 1, -4, 0, 3, -1, 2, -2);\n"
    "uint vr(int x, int y) { return texelFetch(u_vram, ivec2(x & 1023, y & 511), 0).r; }\n"
    "int wnd(int u, int off, int size) {\n"
    "    if (size <= 0) return u;\n"
    "    return (u & (size - 1)) | (off & ~(size - 1) & 255);\n"
    "}\n"
    "void main() {\n"
    "    uint flags = v_info.z;\n"
    "    vec3 rgb = v_color.rgb;\n"
    "    if ((flags & 1u) != 0u) {\n"
    "        vec3 t;\n"
    "        bool stp = false;\n"
    "        if (v_info.w != 0u) {\n"
    "            vec4 r = texture(u_repl, v_st);\n"
    "            if (r.a < 0.5) discard;\n"
    "            t = r.rgb;\n"
    "        } else {\n"
    "            uint p;\n"
    "            if ((flags & 8u) != 0u) {\n"
    "                p = vr(int(floor(v_uv.x)), int(floor(v_uv.y)));\n"
    "            } else {\n"
    "                int u = int(floor(v_uv.x)) & 255, v = int(floor(v_uv.y)) & 255;\n"
    "                uint tp = v_info.y, cl = v_info.x, d = (tp >> 7) & 3u;\n"
    "                int bx = int(tp & 15u) * 64, by = int((tp >> 4) & 1u) * 256;\n"
    "                int cx = int(cl & 63u) * 16, cy = int((cl >> 6) & 511u);\n"
    "                u = wnd(u, u_win.x, u_win.z);\n"
    "                v = wnd(v, u_win.y, u_win.w);\n"
    "                if (d == 0u) {\n"
    "                    uint w = vr(bx + u / 4, by + v);\n"
    "                    p = vr(cx + int((w >> uint((u & 3) * 4)) & 15u), cy);\n"
    "                } else if (d == 1u) {\n"
    "                    uint w = vr(bx + u / 2, by + v);\n"
    "                    p = vr(cx + int((w >> uint((u & 1) * 8)) & 255u), cy);\n"
    "                } else {\n"
    "                    p = vr(bx + u, by + v);\n"
    "                }\n"
    "                if (p == 0u) discard;\n"
    "            }\n"
    "            stp = (p & 0x8000u) != 0u;\n"
    "            t = vec3(float(p & 31u), float((p >> 5) & 31u), float((p >> 10) & 31u)) / 31.0;\n"
    "        }\n"
    "        if (u_pass == 1 && stp) discard;\n"
    "        if (u_pass == 2 && !stp) discard;\n"
    "        rgb = (flags & 2u) != 0u ? t : min(t * v_color.rgb * (255.0 / 128.0), vec3(1.0));\n"
    "    }\n"
    "    if (u_dither != 0 && (flags & 4u) != 0u) {\n"
    "        ivec2 q = ivec2(gl_FragCoord.xy) / u_scale;\n"
    "        float d = float(dm[(q.y & 3) * 4 + (q.x & 3)]);\n"
    "        vec3 c8 = clamp(floor(rgb * 255.0 + 0.5) + d, 0.0, 255.0);\n"
    "        rgb = floor(c8 / 8.0) / 31.0;\n"
    "    }\n"
    "    o_color = vec4(rgb, 1.0);\n"
    "}\n";

static const char *blit_vs =
    "#version 330 core\n"
    "uniform vec4 u_src;\n"
    "out vec2 v_uv;\n"
    "void main() {\n"
    "    vec2 c = vec2(float(gl_VertexID & 1), float(gl_VertexID >> 1));\n"
    "    gl_Position = vec4(c.x * 2.0 - 1.0, 1.0 - c.y * 2.0, 0.0, 1.0);\n"
    "    v_uv = vec2(mix(u_src.x, u_src.z, c.x), mix(u_src.y, u_src.w, c.y));\n"
    "}\n";

static const char *blit_fs =
    "#version 330 core\n"
    "in vec2 v_uv;\n"
    "uniform sampler2D u_tex;\n"
    "out vec4 o_color;\n"
    "void main() { o_color = vec4(texture(u_tex, v_uv).rgb, 1.0); }\n";

static void note_err(BfmGlExec *x) {
    GLenum e;
    while ((e = x->GetError()) != GL_NO_ERROR)
        if (!x->err) x->err = e;
}

unsigned bfm_gl_exec_error(BfmGlExec *x) {
    unsigned e;
    note_err(x);
    e = x->err;
    x->err = 0;
    return e;
}

static GLuint compile(BfmGlExec *x, GLenum kind, const char *src, char *err,
                      size_t n) {
    GLuint s = x->CreateShader(kind);
    GLint ok = 0;
    x->ShaderSource(s, 1, &src, NULL);
    x->CompileShader(s);
    x->GetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        if (err && n) x->GetShaderInfoLog(s, (GLsizei)n, NULL, err);
        x->DeleteShader(s);
        return 0;
    }
    return s;
}

static GLuint link(BfmGlExec *x, const char *vs, const char *fs, char *err,
                   size_t n) {
    GLuint v = compile(x, GL_VERTEX_SHADER, vs, err, n), f, p;
    GLint ok = 0;
    if (!v) return 0;
    if (!(f = compile(x, GL_FRAGMENT_SHADER, fs, err, n))) {
        x->DeleteShader(v);
        return 0;
    }
    p = x->CreateProgram();
    x->AttachShader(p, v);
    x->AttachShader(p, f);
    x->LinkProgram(p);
    x->DeleteShader(v);
    x->DeleteShader(f);
    x->GetProgramiv(p, GL_LINK_STATUS, &ok);
    if (!ok) {
        if (err && n) x->GetProgramInfoLog(p, (GLsizei)n, NULL, err);
        x->DeleteProgram(p);
        return 0;
    }
    return p;
}

static void target_free(BfmGlExec *x, Target *t) {
    if (t->fbo) x->DeleteFramebuffers(1, &t->fbo);
    if (t->tex) x->DeleteTextures(1, &t->tex);
    memset(t, 0, sizeof *t);
}

static int target_alloc(BfmGlExec *x, Target *t, int w, int h) {
    target_free(x, t);
    x->GenTextures(1, &t->tex);
    x->BindTexture(GL_TEXTURE_2D, t->tex);
    x->TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w * x->scale, h * x->scale, 0,
                  GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    x->GenFramebuffers(1, &t->fbo);
    x->BindFramebuffer(GL_FRAMEBUFFER, t->fbo);
    x->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                            t->tex, 0);
    if (x->CheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        x->BindFramebuffer(GL_FRAMEBUFFER, 0);
        target_free(x, t);
        return BFM_PLAT_ERROR;
    }
    x->Disable(GL_SCISSOR_TEST);
    x->ClearColor(0, 0, 0, 1);
    x->Clear(GL_COLOR_BUFFER_BIT);
    x->BindFramebuffer(GL_FRAMEBUFFER, 0);
    t->w = w;
    t->h = h;
    return BFM_PLAT_OK;
}

BfmGlExec *bfm_gl_exec_create(BfmGlGetProc gp, int scale, char *err, size_t n) {
    BfmGlExec *x;
    static const uint8_t white[4] = {255, 255, 255, 255};
    const char *missing = NULL;
    if (err && n) err[0] = '\0';
    if (!gp) return NULL;
    if (scale < 1) scale = 1;
    if (scale > 8) scale = 8;
    if (!(x = (BfmGlExec *)calloc(1, sizeof *x))) return NULL;
    /* object -> function pointer via memcpy (POSIX representation;
     * ISO C has no cast for it) */
#define X(type, name)                                                      \
    {                                                                      \
        void *p_ = gp("gl" #name);                                         \
        memcpy(&x->name, &p_, sizeof p_);                                  \
        if (!p_ && !missing) missing = "gl" #name;                         \
    }
    BFM_GL_FUNCS(X)
#undef X
    if (missing) {
        if (err && n) snprintf(err, n, "GL function %s not available", missing);
        free(x);
        return NULL;
    }
    x->scale = scale;
    if (!(x->prog = link(x, vs_src, fs_src, err, n)) ||
        !(x->blit = link(x, blit_vs, blit_fs, err, n))) {
        bfm_gl_exec_destroy(x);
        return NULL;
    }
    x->u_size = x->GetUniformLocation(x->prog, "u_size");
    x->u_flip = x->GetUniformLocation(x->prog, "u_flip");
    x->u_pass = x->GetUniformLocation(x->prog, "u_pass");
    x->u_dither = x->GetUniformLocation(x->prog, "u_dither");
    x->u_scale = x->GetUniformLocation(x->prog, "u_scale");
    x->u_win = x->GetUniformLocation(x->prog, "u_win");
    x->u_vram = x->GetUniformLocation(x->prog, "u_vram");
    x->u_repl = x->GetUniformLocation(x->prog, "u_repl");
    x->b_src = x->GetUniformLocation(x->blit, "u_src");
    x->b_tex = x->GetUniformLocation(x->blit, "u_tex");

    x->GenVertexArrays(1, &x->vao);
    x->GenVertexArrays(1, &x->empty_vao);
    x->GenBuffers(1, &x->vbo);
    x->BindVertexArray(x->vao);
    x->BindBuffer(GL_ARRAY_BUFFER, x->vbo);
    x->VertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(BfmGlVertex),
                           (const void *)offsetof(BfmGlVertex, x));
    x->VertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(BfmGlVertex),
                           (const void *)offsetof(BfmGlVertex, r));
    x->VertexAttribPointer(2, 2, GL_UNSIGNED_SHORT, GL_FALSE, sizeof(BfmGlVertex),
                           (const void *)offsetof(BfmGlVertex, u));
    x->VertexAttribIPointer(3, 4, GL_UNSIGNED_SHORT, sizeof(BfmGlVertex),
                            (const void *)offsetof(BfmGlVertex, clut));
    x->VertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, sizeof(BfmGlVertex),
                           (const void *)offsetof(BfmGlVertex, s));
    x->EnableVertexAttribArray(0);
    x->EnableVertexAttribArray(1);
    x->EnableVertexAttribArray(2);
    x->EnableVertexAttribArray(3);
    x->EnableVertexAttribArray(4);
    x->BindVertexArray(0);

    x->PixelStorei(GL_UNPACK_ALIGNMENT, 1);
    x->PixelStorei(GL_PACK_ALIGNMENT, 1);
    x->GenTextures(1, &x->vram_tex);
    x->BindTexture(GL_TEXTURE_2D, x->vram_tex);
    x->TexImage2D(GL_TEXTURE_2D, 0, GL_R16UI, BFM_GL_VRAM_W, BFM_GL_VRAM_H, 0,
                  GL_RED_INTEGER, GL_UNSIGNED_SHORT, NULL);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    x->white_tex = bfm_gl_exec_texture(x, 1, 1, white);

    if (target_alloc(x, &x->tgt[0], BFM_GL_VRAM_W, BFM_GL_VRAM_H) != BFM_PLAT_OK) {
        if (err && n) snprintf(err, n, "VRAM render target incomplete at %dx", scale);
        bfm_gl_exec_destroy(x);
        return NULL;
    }
    note_err(x);
    if (x->err) {
        if (err && n) snprintf(err, n, "GL error 0x%x during setup", x->err);
        bfm_gl_exec_destroy(x);
        return NULL;
    }
    return x;
}

void bfm_gl_exec_destroy(BfmGlExec *x) {
    int i;
    if (!x) return;
    for (i = 0; i < 3; i++) target_free(x, &x->tgt[i]);
    if (x->vram_tex) x->DeleteTextures(1, &x->vram_tex);
    if (x->white_tex) x->DeleteTextures(1, &x->white_tex);
    if (x->image_tex) x->DeleteTextures(1, &x->image_tex);
    if (x->vbo) x->DeleteBuffers(1, &x->vbo);
    if (x->vao) x->DeleteVertexArrays(1, &x->vao);
    if (x->empty_vao) x->DeleteVertexArrays(1, &x->empty_vao);
    if (x->prog) x->DeleteProgram(x->prog);
    if (x->blit) x->DeleteProgram(x->blit);
    free(x);
}

int bfm_gl_exec_scale(const BfmGlExec *x) { return x ? x->scale : 1; }

int bfm_gl_exec_set_scale(BfmGlExec *x, int scale) {
    int i;
    if (!x || scale < 1 || scale > 8) return BFM_PLAT_INVALID;
    if (scale == x->scale) return BFM_PLAT_OK;
    x->scale = scale;
    for (i = 1; i < 3; i++) target_free(x, &x->tgt[i]);
    return target_alloc(x, &x->tgt[0], BFM_GL_VRAM_W, BFM_GL_VRAM_H);
}

void bfm_gl_exec_sync_vram(BfmGlExec *x, BfmGlVram *v) {
    int y;
    if (!x || !v || !v->dirty) return;
    x->BindTexture(GL_TEXTURE_2D, x->vram_tex);
    x->PixelStorei(GL_UNPACK_ALIGNMENT, 2);
    for (y = v->dy0; y < v->dy1; y++)
        x->TexSubImage2D(GL_TEXTURE_2D, 0, v->dx0, y, v->dx1 - v->dx0, 1,
                         GL_RED_INTEGER, GL_UNSIGNED_SHORT,
                         &v->px[(size_t)y * BFM_GL_VRAM_W + v->dx0]);
    x->PixelStorei(GL_UNPACK_ALIGNMENT, 1);
    v->dirty = 0;
}

/* The render target for a command target, sized for the batch. */
static Target *target_for(BfmGlExec *x, const BfmGlBatch *b, int target) {
    Target *t;
    int w, h;
    if (target == BFM_GL_TARGET_VRAM) return &x->tgt[0];
    if (target != BFM_GL_TARGET_SCENE0 && target != BFM_GL_TARGET_SCENE1) return NULL;
    t = &x->tgt[target];
    bfm_gl_batch_target_size(b, target, &w, &h);
    if ((t->w != w || t->h != h) && target_alloc(x, t, w, h) != BFM_PLAT_OK)
        return NULL;
    return t;
}

static void set_blend(BfmGlExec *x, int mode) {
    BfmGlBlendState s;
    if (mode < 0) {
        x->Disable(GL_BLEND);
        return;
    }
    s = bfm_gl_blend_state(mode);
    x->Enable(GL_BLEND);
    x->BlendEquation(s.equation == BFM_GL_FUNC_REVERSE_SUBTRACT
                         ? GL_FUNC_REVERSE_SUBTRACT : GL_FUNC_ADD);
    x->BlendFunc(s.src == BFM_GL_CONSTANT_COLOR ? GL_CONSTANT_COLOR : GL_ONE,
                 s.dst == BFM_GL_CONSTANT_COLOR ? GL_CONSTANT_COLOR : GL_ONE);
    x->BlendColor(s.constant, s.constant, s.constant, s.constant);
}

/* Draws one command list's commands for a bound target. win_vp: for the
 * window target, the viewport (x, y, w, h) in window pixels. */
static void run_cmds(BfmGlExec *x, const BfmGlBatch *b, int dither,
                     const int *win_vp) {
    size_t i;
    GLuint bound_repl = (GLuint)-1;
    int cur_target = -1, scale = x->scale;
    x->UseProgram(x->prog);
    x->Uniform1i(x->u_vram, 0);
    x->Uniform1i(x->u_repl, 1);
    x->Uniform1i(x->u_scale, scale);
    x->ActiveTexture(GL_TEXTURE0);
    x->BindTexture(GL_TEXTURE_2D, x->vram_tex);
    x->BindVertexArray(x->vao);
    for (i = 0; i < b->nc; i++) {
        const BfmGlCmd *c = &b->c[i];
        int w, h;
        if (c->target != cur_target) {
            if (c->target == BFM_GL_TARGET_WINDOW) {
                if (!win_vp) continue;
                x->BindFramebuffer(GL_FRAMEBUFFER, 0);
                x->Viewport(win_vp[0], win_vp[1], win_vp[2], win_vp[3]);
                x->Disable(GL_SCISSOR_TEST);
                bfm_gl_batch_target_size(b, BFM_GL_TARGET_WINDOW, &w, &h);
                x->Uniform1i(x->u_flip, 1);
                x->Uniform1i(x->u_scale, 1);
            } else {
                Target *t = target_for(x, b, c->target);
                if (!t) continue;
                x->BindFramebuffer(GL_FRAMEBUFFER, t->fbo);
                x->Viewport(0, 0, t->w * scale, t->h * scale);
                x->Enable(GL_SCISSOR_TEST);
                w = t->w;
                h = t->h;
                x->Uniform1i(x->u_flip, 0);
                x->Uniform1i(x->u_scale, scale);
            }
            x->Uniform2f(x->u_size, (float)w, (float)h);
            cur_target = c->target;
        }
        if (c->target != BFM_GL_TARGET_WINDOW)
            x->Scissor(c->rect.x * scale, c->rect.y * scale, c->rect.w * scale,
                       c->rect.h * scale);
        if (c->kind == BFM_GL_CMD_FILL) {
            if (c->target == BFM_GL_TARGET_WINDOW) continue;
            x->ClearColor((float)(c->rgb & 0xFF) / 255.0f,
                          (float)((c->rgb >> 8) & 0xFF) / 255.0f,
                          (float)((c->rgb >> 16) & 0xFF) / 255.0f, 1.0f);
            x->Clear(GL_COLOR_BUFFER_BIT);
            continue;
        }
        if (!c->count) continue;
        {
            GLuint want = x->white_tex;
            if (c->repl && b->repl && b->repl->r[c->repl - 1].live)
                want = b->repl->r[c->repl - 1].id;
            if (want != bound_repl) {
                x->ActiveTexture(GL_TEXTURE1);
                x->BindTexture(GL_TEXTURE_2D, want);
                x->ActiveTexture(GL_TEXTURE0);
                bound_repl = want;
            }
        }
        x->Uniform4i(x->u_win, c->win.x, c->win.y, c->win.w, c->win.h);
        x->Uniform1i(x->u_dither, dither && c->dither);
        if (c->split_stp) {
            /* textured semi-transparency: texels without STP are opaque */
            set_blend(x, -1);
            x->Uniform1i(x->u_pass, 1);
            x->DrawArrays(GL_TRIANGLES, (GLint)c->first, (GLsizei)c->count);
            set_blend(x, c->blend);
            x->Uniform1i(x->u_pass, 2);
            x->DrawArrays(GL_TRIANGLES, (GLint)c->first, (GLsizei)c->count);
        } else {
            set_blend(x, c->blend);
            x->Uniform1i(x->u_pass, 0);
            x->DrawArrays(GL_TRIANGLES, (GLint)c->first, (GLsizei)c->count);
        }
    }
    set_blend(x, -1);
    x->Disable(GL_SCISSOR_TEST);
    x->BindVertexArray(0);
    x->BindFramebuffer(GL_FRAMEBUFFER, 0);
}

static void upload_verts(BfmGlExec *x, const BfmGlBatch *b) {
    x->BindBuffer(GL_ARRAY_BUFFER, x->vbo);
    x->BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(b->nv * sizeof(BfmGlVertex)),
                  b->nv ? b->v : NULL, GL_STREAM_DRAW);
}

int bfm_gl_exec_run(BfmGlExec *x, const BfmGlBatch *b, int dither) {
    if (!x || !b) return BFM_PLAT_INVALID;
    if (!b->nc) return BFM_PLAT_OK;
    upload_verts(x, b);
    run_cmds(x, b, dither, NULL);
    note_err(x);
    return x->err ? BFM_PLAT_ERROR : BFM_PLAT_OK;
}

int bfm_gl_exec_readback(BfmGlExec *x, const BfmGlBatch *b, int target,
                         const BfmPlatRect *r, uint16_t *out) {
    Target *t;
    uint8_t *buf;
    int s, i, j;
    if (!x || !b || !r || !out || r->w <= 0 || r->h <= 0) return BFM_PLAT_INVALID;
    if (!(t = target_for(x, b, target))) return BFM_PLAT_INVALID;
    if (r->x < 0 || r->y < 0 || r->x + r->w > t->w || r->y + r->h > t->h)
        return BFM_PLAT_INVALID;
    s = x->scale;
    buf = (uint8_t *)malloc((size_t)r->w * s * (size_t)r->h * s * 4u);
    if (!buf) return BFM_PLAT_ERROR;
    x->BindFramebuffer(GL_FRAMEBUFFER, t->fbo);
    x->ReadPixels(r->x * s, r->y * s, r->w * s, r->h * s, GL_RGBA,
                  GL_UNSIGNED_BYTE, buf);
    x->BindFramebuffer(GL_FRAMEBUFFER, 0);
    for (j = 0; j < r->h; j++)
        for (i = 0; i < r->w; i++) {
            const uint8_t *p = buf + (((size_t)(j * s + s / 2) * (size_t)(r->w * s)) +
                                      (size_t)(i * s + s / 2)) * 4u;
            out[(size_t)j * r->w + i] = (uint16_t)((p[0] >> 3) | ((p[1] >> 3) << 5) |
                                                   ((p[2] >> 3) << 10));
        }
    free(buf);
    note_err(x);
    return x->err ? BFM_PLAT_ERROR : BFM_PLAT_OK;
}

uint32_t bfm_gl_exec_texture(BfmGlExec *x, uint32_t w, uint32_t h,
                             const uint8_t *rgba) {
    GLuint t = 0;
    if (!x || !w || !h || !rgba) return 0;
    x->GenTextures(1, &t);
    x->BindTexture(GL_TEXTURE_2D, t);
    x->TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei)w, (GLsizei)h, 0, GL_RGBA,
                  GL_UNSIGNED_BYTE, rgba);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    note_err(x);
    return t;
}

void bfm_gl_exec_texture_free(BfmGlExec *x, uint32_t id) {
    GLuint t = id;
    if (x && id) x->DeleteTextures(1, &t);
}

static void fit(int win_w, int win_h, double aspect, int vp[4]) {
    if (aspect <= 0.0) aspect = 4.0 / 3.0;
    if ((double)win_w / win_h > aspect) {
        vp[3] = win_h;
        vp[2] = (int)(win_h * aspect + 0.5);
    } else {
        vp[2] = win_w;
        vp[3] = (int)(win_w / aspect + 0.5);
    }
    vp[0] = (win_w - vp[2]) / 2;
    vp[1] = (win_h - vp[3]) / 2;
}

/* Clears the window and draws texture region (s0,t0)-(s1,t1), t0 = top,
 * into viewport vp. */
static void blit(BfmGlExec *x, GLuint tex, int win_w, int win_h, const int vp[4],
                 float s0, float t0, float s1, float t1) {
    x->BindFramebuffer(GL_FRAMEBUFFER, 0);
    x->Disable(GL_SCISSOR_TEST);
    x->Disable(GL_BLEND);
    x->Viewport(0, 0, win_w, win_h);
    x->ClearColor(0, 0, 0, 1);
    x->Clear(GL_COLOR_BUFFER_BIT);
    x->Viewport(vp[0], vp[1], vp[2], vp[3]);
    x->UseProgram(x->blit);
    x->Uniform1i(x->b_tex, 0);
    x->Uniform4f(x->b_src, s0, t0, s1, t1);
    x->ActiveTexture(GL_TEXTURE0);
    x->BindTexture(GL_TEXTURE_2D, tex);
    x->BindVertexArray(x->empty_vao);
    x->DrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    x->BindVertexArray(0);
}

int bfm_gl_exec_present_image(BfmGlExec *x, int w, int h, const uint8_t *rgba,
                              const BfmGlBatch *overlay, int win_w, int win_h,
                              double aspect) {
    int vp[4];
    if (!x || !rgba || w <= 0 || h <= 0 || win_w <= 0 || win_h <= 0)
        return BFM_PLAT_INVALID;
    if (!x->image_tex) {
        x->GenTextures(1, &x->image_tex);
        x->BindTexture(GL_TEXTURE_2D, x->image_tex);
        x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        x->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    x->BindTexture(GL_TEXTURE_2D, x->image_tex);
    x->TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgba);
    fit(win_w, win_h, aspect, vp);
    blit(x, x->image_tex, win_w, win_h, vp, 0.0f, 0.0f, 1.0f, 1.0f);
    if (overlay && overlay->nc) {
        upload_verts(x, overlay);
        run_cmds(x, overlay, 0, vp);
    }
    note_err(x);
    return x->err ? BFM_PLAT_ERROR : BFM_PLAT_OK;
}

int bfm_gl_exec_present(BfmGlExec *x, const BfmGlBatch *b,
                        const BfmGlBatch *overlay, int win_w, int win_h,
                        double aspect, int dither) {
    int slot, vp[4], ivp[4], tw;
    float s0, t0, s1, t1;
    Target *src;
    if (!x || !b || win_w <= 0 || win_h <= 0) return BFM_PLAT_INVALID;
    fit(win_w, win_h, aspect, vp);
    slot = bfm_gl_batch_scene_at(b, b->disp.x, b->disp.y);
    if (slot >= 0 && (src = target_for(x, b, BFM_GL_TARGET_SCENE0 + slot)) != NULL) {
        s0 = 0.0f; t0 = 0.0f; s1 = 1.0f; t1 = 1.0f;
        tw = src->w;
        /* the 4:3 display area inside the wide image, for the overlay */
        ivp[0] = vp[0] + (int)((double)vp[2] * b->margin / tw + 0.5);
        ivp[2] = (int)((double)vp[2] * b->disp.w / tw + 0.5);
    } else {
        src = &x->tgt[0];
        s0 = (float)b->disp.x / BFM_GL_VRAM_W;
        s1 = (float)(b->disp.x + b->disp.w) / BFM_GL_VRAM_W;
        t0 = (float)b->disp.y / BFM_GL_VRAM_H;
        t1 = (float)(b->disp.y + b->disp.h) / BFM_GL_VRAM_H;
        ivp[0] = vp[0];
        ivp[2] = vp[2];
    }
    ivp[1] = vp[1];
    ivp[3] = vp[3];
    blit(x, src->tex, win_w, win_h, vp, s0, t0, s1, t1);
    if (overlay && overlay->nc) {
        upload_verts(x, overlay);
        run_cmds(x, overlay, dither, ivp);
    }
    note_err(x);
    return x->err ? BFM_PLAT_ERROR : BFM_PLAT_OK;
}
