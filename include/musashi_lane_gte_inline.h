/* Strict native-lane host stand-ins for the PsyQ inline_c.h GTE macros that
 * MATCH C embeds as asm. Used only after tools/native_lane_gen.py rewrites the
 * asm #defines; the retail bytes stay in the MATCH source. */
#ifndef MUSASHI_LANE_GTE_INLINE_H
#define MUSASHI_LANE_GTE_INLINE_H

#ifdef __cplusplus
extern "C" {
#endif

void musashi_lane_gte_ldv0(const void *r0);
void musashi_lane_gte_ldlv0(const void *r0);
void musashi_lane_gte_SetRotMatrix(const void *r0);
void musashi_lane_gte_SetTransMatrix(const void *r0);
void musashi_lane_gte_ldv3(const void *r0, const void *r1, const void *r2);
void musashi_lane_gte_ldv3c(const void *r0);
void musashi_lane_gte_rtps(void);
void musashi_lane_gte_rtpt(void);
void musashi_lane_gte_nclip(void);
void musashi_lane_gte_stsxy(void *r0);
void musashi_lane_gte_stsxy3(void *r0, void *r1, void *r2);
void musashi_lane_gte_stsxy3c(void *r0);
void musashi_lane_gte_stsz3(void *r0, void *r1, void *r2);
void musashi_lane_gte_stsz4(void *r0, void *r1, void *r2, void *r3);
void musashi_lane_gte_stszotz(void *r0);
void musashi_lane_gte_stflg(void *r0);
void musashi_lane_gte_stopz(void *r0);

#define gte_ldv0(r0) musashi_lane_gte_ldv0((const void *)(r0))
#define gte_ldlv0(r0) musashi_lane_gte_ldlv0((const void *)(r0))
#define gte_SetRotMatrix(r0) musashi_lane_gte_SetRotMatrix((const void *)(r0))
#define gte_SetTransMatrix(r0) musashi_lane_gte_SetTransMatrix((const void *)(r0))
#define gte_ldv3(r0, r1, r2) musashi_lane_gte_ldv3((const void *)(r0), (const void *)(r1), (const void *)(r2))
#define gte_ldv3c(r0) musashi_lane_gte_ldv3c((const void *)(r0))
#define gte_rtps() musashi_lane_gte_rtps()
#define gte_rtpt() musashi_lane_gte_rtpt()
#define gte_nclip() musashi_lane_gte_nclip()
#define gte_stsxy(r0) musashi_lane_gte_stsxy((void *)(r0))
#define gte_stsxy3(r0, r1, r2) musashi_lane_gte_stsxy3((void *)(r0), (void *)(r1), (void *)(r2))
#define gte_stsxy3c(r0) musashi_lane_gte_stsxy3c((void *)(r0))
#define gte_stsz3(r0, r1, r2) musashi_lane_gte_stsz3((void *)(r0), (void *)(r1), (void *)(r2))
#define gte_stsz4(r0, r1, r2, r3) musashi_lane_gte_stsz4((void *)(r0), (void *)(r1), (void *)(r2), (void *)(r3))
#define gte_stszotz(r0) musashi_lane_gte_stszotz((void *)(r0))
#define gte_stflg(r0) musashi_lane_gte_stflg((void *)(r0))
#define gte_stopz(r0) musashi_lane_gte_stopz((void *)(r0))

#ifdef __cplusplus
}
#endif

#endif
