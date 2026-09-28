"""Hand-maintained status of each Psy-Q entry point (read by tools/psyq_callsites.py).

status  "psycross"  PsyCross implements it: pc_port/platform/psyq/psyq_psycross.c
        "hle"       our own C: pc_port/platform/psyq/bfm_psyq_compat.c
        "stub-TBD"  no host version yet: the native lane refuses the PC and the
                    interpreter keeps running the retail code from the user's disc
                    against the device HLE (so a stub is slow, not broken).

INFERRED names addresses the vendor symbol files leave unnamed; each carries its
evidence. Nothing here is Psy-Q code: only names, argument counts and notes.
"""
from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class Status:
    status: str
    argc: int = 0
    returns: int = 0
    wrapper: str | None = None
    note: str = ""


# address -> (name, evidence)
INFERRED: dict[int, tuple[str, str]] = {
    0x8005C324: ("memcpy", "symbols.resident.txt: memcpy = 0x8005C324 (libc2 MEMCPY.o)"),
    0x8005C2C8: ("bzero", "only function of Psy-Q object BZERO.o"),
    0x8005C358: ("memset", "Psy-Q object MEMSET.o"),
    0x8005C4CC: ("strcmp", "Psy-Q object STRCMP.o"),
    0x8005C388: ("putchar", "Psy-Q object PUTCHAR.o"),
    0x8005C604: ("printf", "Psy-Q object PRNT.o"),
    0x80047CB4: ("InitGeom", "sets H=0x3E8, ZSF3/ZSF4, DQA/DQB, OFX=OFY=0 (asm/main.s func_80047CB4)"),
    0x800599B8: ("LoadImage", "called (RECT *, data) by func_800184F0 per texture record (vendor src/800.c:5761ff)"),
    0x80059CF4: ("DrawOTag", "main loop passes OT base + 0x3FFC after CatPrim (vendor src/boot.c)"),
    0x80059D68: ("PutDrawEnv", "main loop passes &state[buf * 92 + 0x38]: a 0x5C-byte DRAWENV (vendor src/boot.c)"),
    0x80059FC0: ("PutDispEnv", "main loop passes &state[buf * 20 + 0x14C]: a 0x14-byte DISPENV (vendor src/boot.c)"),
    0x80059BFC: ("ClearOTagR", "main loop: (OT base, 0x1000) and (OT, 4) each frame (vendor src/boot.c)"),
    0x800596F4: ("DrawSync", "main loop: func_800596F4(0) right before VSync (vendor src/boot.c)"),
    0x80059658: ("SetDispMask", "called with 1 after the first frame is set up (resident md_MAIN_003)"),
}

H = "hle"
P = "psycross"
S = "stub-TBD"

GPU_PTR = "packet/struct lives in guest RAM"
TABLE: dict[str, Status] = {
    # --- libgpu: packets and environments in guest RAM, rendered via bfm_plat_renderer
    "GetTPage": Status(H, 4, 1, "bfm_psyq_GetTPage", "pure: (tp<<7)|(abr<<5)|(y>>8<<4)|(x>>6)"),
    "GetClut": Status(H, 2, 1, "bfm_psyq_GetClut", "pure: (y<<6)|(x>>4)"),
    "AddPrim": Status(H, 2, 0, "bfm_psyq_AddPrim", GPU_PTR + "; 24-bit guest links"),
    "CatPrim": Status(H, 2, 0, "bfm_psyq_CatPrim", GPU_PTR),
    "SetSemiTrans": Status(H, 2, 0, "bfm_psyq_SetSemiTrans", GPU_PTR),
    "SetPolyF3": Status(H, 1, 0, "bfm_psyq_SetPolyF3", GPU_PTR + "; header len/code"),
    "SetPolyFT3": Status(H, 1, 0, "bfm_psyq_SetPolyFT3", GPU_PTR),
    "SetPolyG3": Status(H, 1, 0, "bfm_psyq_SetPolyG3", GPU_PTR),
    "SetPolyGT3": Status(H, 1, 0, "bfm_psyq_SetPolyGT3", GPU_PTR),
    "SetPolyF4": Status(H, 1, 0, "bfm_psyq_SetPolyF4", GPU_PTR),
    "SetPolyFT4": Status(H, 1, 0, "bfm_psyq_SetPolyFT4", GPU_PTR),
    "SetPolyG4": Status(H, 1, 0, "bfm_psyq_SetPolyG4", GPU_PTR),
    "SetPolyGT4": Status(H, 1, 0, "bfm_psyq_SetPolyGT4", GPU_PTR),
    "SetLineF2": Status(H, 1, 0, "bfm_psyq_SetLineF2", GPU_PTR),
    "SetLineG2": Status(H, 1, 0, "bfm_psyq_SetLineG2", GPU_PTR),
    "SetLineG3": Status(H, 1, 0, "bfm_psyq_SetLineG3", GPU_PTR + "; polyline terminator 0x55555555"),
    "SetLineG4": Status(H, 1, 0, "bfm_psyq_SetLineG4", GPU_PTR + "; polyline terminator 0x55555555"),
    "SetDefDispEnv": Status(H, 5, 1, "bfm_psyq_SetDefDispEnv", "fills a guest DISPENV; returns the guest pointer; 5th arg from guest stack"),
    "ClearOTagR": Status(H, 2, 1, "bfm_psyq_ClearOTagR", "reverse OT in guest RAM, terminator 0x00FFFFFF"),
    "LoadImage": Status(H, 2, 1, "bfm_psyq_LoadImage", "guest RECT + pixels -> bfm_plat_renderer_upload_vram (texture replacement applies)"),
    "StoreImage": Status(H, 2, 1, "bfm_psyq_StoreImage", "bfm_plat_renderer_download_vram into guest RAM"),
    "MoveImage": Status(H, 3, 1, "bfm_psyq_MoveImage", "download + upload through the renderer"),
    "DrawSync": Status(H, 1, 1, "bfm_psyq_DrawSync", "host rendering is synchronous: returns 0"),
    "SetDispMask": Status(H, 1, 0, "bfm_psyq_SetDispMask", "no-op on the host (display always on)"),
    "PutDrawEnv": Status(H, 1, 1, "bfm_psyq_PutDrawEnv", "guest DRAWENV -> BfmPlatDrawEnv; returns the guest pointer"),
    "PutDispEnv": Status(H, 1, 1, "bfm_psyq_PutDispEnv", "guest DISPENV -> BfmPlatDispEnv; returns the guest pointer"),
    "DrawOTag": Status(H, 1, 0, "bfm_psyq_DrawOTag", "walks the guest OT (24-bit links) and decodes GP0 packets to BfmPlatPrim; unknown codes skipped and counted"),
    "SetDrawEnv": Status(S, 0, 0, None, "builds a DR_ENV packet in guest RAM (TBD)"),
    "DrawSyncCallback": Status(S, 0, 0, None, "callback into guest code: needs the lane's guest-call thunk"),
    # --- libetc
    "VSync": Status(H, 1, 1, "bfm_psyq_VSync", "n>1 waits n fields via bfm_plat_timing_vsync; n=0 one field; n=1 returns 0 (no hcount); n<0 returns the field counter"),
    "ResetCallback": Status(S, 0, 0, None, "interrupt callbacks belong to the IRQ HLE"),
    "DMACallback": Status(S, 0, 0, None, "interrupt callbacks belong to the IRQ HLE"),
    "StopCallback": Status(S, 0, 0, None, "interrupt callbacks belong to the IRQ HLE"),
    # --- libcd
    "CdIntToPos": Status(H, 2, 1, "bfm_psyq_CdIntToPos", "pure: LBA -> BCD CdlLOC in guest RAM"),
    "CdPosToInt": Status(H, 1, 1, "bfm_psyq_CdPosToInt", "pure: BCD CdlLOC -> LBA"),
    "CdSearchFile": Status(H, 2, 1, "bfm_psyq_CdSearchFile", "bfm_plat_disc_find_file -> guest CdlFILE {pos, size, name}; returns the pointer or 0"),
    # --- libgte: only stateless math (PsyCross's GTE has its own register file)
    "ratan2": Status(P, 2, 1, "bfm_psyq_ratan2", "stateless (PsyCross table)"),
    "csqrt": Status(S, 0, 0, None, "stateless but not in PsyCross; fixed-point semantics to pin before an HLE"),
    "catan": Status(S, 0, 0, None, "stateless but not in PsyCross"),
    "SquareRoot12": Status(S, 0, 0, None, "stateless but not in PsyCross"),
    # GTE state through the bridge: PsyCross works on the gteRegs bank gte_owner leases
    "InitGeom": Status(P, 0, 0, "bfm_psyq_InitGeom", "GTE bridge (gte_owner lease)"),
    "SetGeomOffset": Status(P, 2, 0, "bfm_psyq_SetGeomOffset", "GTE bridge (gte_owner lease); the hook site also records the projection"),
    "SetGeomScreen": Status(P, 1, 0, "bfm_psyq_SetGeomScreen", "GTE bridge (gte_owner lease); the hook site also records the projection"),
    "ReadGeomOffset": Status(P, 2, 0, "bfm_psyq_ReadGeomOffset", "GTE bridge (gte_owner lease); reads C2_OFX/OFY"),
    "SetRotMatrix": Status(P, 1, 0, "bfm_psyq_SetRotMatrix", "GTE bridge (gte_owner lease)"),
    "SetTransMatrix": Status(P, 1, 0, "bfm_psyq_SetTransMatrix", "GTE bridge (gte_owner lease)"),
    "SetLightMatrix": Status(P, 1, 0, "bfm_psyq_SetLightMatrix", "GTE bridge (gte_owner lease)"),
    "ReadRotMatrix": Status(P, 1, 1, "bfm_psyq_ReadRotMatrix", "GTE bridge (gte_owner lease)"),
    "MulMatrix0": Status(P, 3, 1, "bfm_psyq_MulMatrix0", "GTE bridge (gte_owner lease); clobbers the rotation matrix like Psy-Q"),
    "MulRotMatrix": Status(P, 1, 1, "bfm_psyq_MulRotMatrix", "GTE bridge (gte_owner lease)"),
    "CompMatrix": Status(P, 3, 1, "bfm_psyq_CompMatrix", "GTE bridge (gte_owner lease)"),
    "CompMatrixLV": Status(P, 3, 1, "bfm_psyq_CompMatrixLV", "GTE bridge (gte_owner lease)"),
    "ApplyRotMatrix": Status(P, 2, 1, "bfm_psyq_ApplyRotMatrix", "GTE bridge (gte_owner lease)"),
    "ApplyRotMatrixLV": Status(P, 2, 1, "bfm_psyq_ApplyRotMatrixLV", "GTE bridge (gte_owner lease)"),
    "ApplyMatrixSV": Status(P, 3, 1, "bfm_psyq_ApplyMatrixSV", "GTE bridge (gte_owner lease); sets the rotation matrix like Psy-Q"),
    "RotTransSV": Status(P, 3, 0, "bfm_psyq_RotTransSV", "GTE bridge (gte_owner lease); long *flag via a host temporary"),
    "RotTransPers": Status(P, 4, 1, "bfm_psyq_RotTransPers", "GTE bridge (gte_owner lease); long *p/*flag via host temporaries"),
    "RotTransPers3": Status(P, 8, 1, "bfm_psyq_RotTransPers3", "GTE bridge (gte_owner lease); args 5-8 from the guest stack; long * via temporaries"),
    "RotTransPers4": Status(P, 10, 1, "bfm_psyq_RotTransPers4", "GTE bridge (gte_owner lease); args 5-10 from the guest stack; long * via temporaries"),
    "RotMatrixYXZ": Status(P, 2, 1, "bfm_psyq_RotMatrixYXZ", "stateless (PsyCross rcossin table)"),
    "RotMatrixX": Status(P, 2, 1, "bfm_psyq_RotMatrixX", "stateless"),
    "RotMatrixY": Status(P, 2, 1, "bfm_psyq_RotMatrixY", "stateless"),
    "RotMatrixZ": Status(P, 2, 1, "bfm_psyq_RotMatrixZ", "stateless"),
    "PushMatrix": Status(S, 0, 0, None, "PsyCross keeps its matrix stack host-side, the retail one is in guest RAM: mixing would desync"),
    "PopMatrix": Status(S, 0, 0, None, "PsyCross keeps its matrix stack host-side, the retail one is in guest RAM: mixing would desync"),
    # --- libc2
    "rand": Status(H, 0, 1, "bfm_psyq_rand", "Psy-Q LCG: next = next*1103515245 + 12345; (next>>16) & 0x7FFF; state is host-side (see notes)"),
    "strcpy": Status(H, 2, 1, "bfm_psyq_strcpy", "guest pointers"),
    "memcpy": Status(H, 3, 1, "bfm_psyq_memcpy", "guest pointers"),
    "memset": Status(H, 3, 1, "bfm_psyq_memset", "guest pointers"),
    "bzero": Status(H, 2, 0, "bfm_psyq_bzero", "guest pointers"),
    "strcmp": Status(H, 2, 1, "bfm_psyq_strcmp", "guest pointers"),
    "putchar": Status(H, 1, 1, "bfm_psyq_putchar", "to the platform log (line-buffered)"),
    "printf": Status(S, 0, 0, None, "guest varargs + format in guest RAM (TBD)"),
}

SEGMENT_NOTES = {
    "snd": "sound driver: runs as guest code over the SPU HLE",
    "libgs": "libgs: high-level on top of libgpu/libgte; guest code for now",
    "libgte": "not in PsyCross; an HLE on the gteRegs bank via the bridge is possible",
    "libgpu": "libgpu internal",
    "libcd": "CD: guest code over the CD controller HLE",
    "libetc": "libetc",
    "libapi": "BIOS calls: the BIOS HLE handles them",
    "libpad": "pad: guest code over the SIO HLE",
    "libmcrd": "memory card: guest code over the card HLE",
    "apicard": "memory card BIOS: card HLE",
    "libc2": "libc",
}


def lookup(name: str, segment: str | None) -> Status:
    if name in TABLE:
        return TABLE[name]
    for prefix, note in SEGMENT_NOTES.items():
        if segment and segment.startswith(prefix):
            return Status(S, note=note)
    return Status(S, note="not reviewed")
