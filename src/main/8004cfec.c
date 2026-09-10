/* PSY-Q ratan2 retail span [8004CFEC,8004D16C) from the SLUS executable.
 * SHA256(span)=7c71d5c7b60dcceae3b2c20983d1b6461a6b85e35997511c5408ea821f584a74.
 * Word export only: the native seam needs the retail instruction stream so the
 * guest can execute the library routine it calls. There is no C match claim
 * here - recovering ratan2 as C (it uses the 0x80071F1C table and guarded
 * signed division) is separate work.
 */
