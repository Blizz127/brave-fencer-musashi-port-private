/* Complete SC02 retail span [8012A828,8012A860).
 * Script attach helper (dep of 848 cluster).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* From vendor shared ov (types reproduce bytes). */
/* func_8012A828 — shared body (overlay slot 0x80128158, h_exact 5f61e157). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
extern void func_8012AAAC();
void func_8012A828(s32 a0, void * a1)
{
    *(s32 *)((u8 *)a0 + 0x90) = a1;
    *(s32 *)((u8 *)a0 + 0x94) = 0;
    *(s32 *)((u8 *)a0 + 0x9C) = 0;
    *(s16 *)((u8 *)a0 + 0x9A) = 0;
    *(u16 *)((u8 *)a0 + 0x72) = *(u16 *)((u8 *)a0 + 0x72) & 0xF9FF;
    func_8012AAAC();
}
