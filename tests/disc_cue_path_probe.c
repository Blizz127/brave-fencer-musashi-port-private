/* A cue sheet's FILE entries resolve against the cue's own folder, not the
 * working directory, whichever separator the path uses (owner report
 * 2026-10-03: "C:\...\disc\disc.cue" from launch.cmd failed with "disc.bin
 * is missing" because only '/' was recognised). The probe writes a cue and a
 * small bin into a temporary folder, changes to a different folder and opens
 * the cue: a fixed resolver finds the bin and refuses it later (not the
 * retail size), the old one reports it missing. */
#include "musashi_disc_media.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <direct.h>
#define chdir _chdir
#define mkdir_one(p) _mkdir(p)
#else
#include <sys/stat.h>
#include <unistd.h>
#define mkdir_one(p) mkdir(p, 0700)
#endif

static int write_file(const char *path, const char *data, size_t size) {
    FILE *f = fopen(path, "wb");
    if (!f) return 0;
    if (fwrite(data, 1, size, f) != size) { fclose(f); return 0; }
    return fclose(f) == 0;
}

static int check(const char *cue, const char *label) {
    char why[512] = "";
    MusashiDiscMedia *media = musashi_disc_media_open_image(cue, why, sizeof why);
    if (media) { musashi_disc_media_close(media); printf("%s: opened?\n", label); return 1; }
    if (strstr(why, "is missing")) { printf("FAIL %s: %s\n", label, why); return 1; }
    printf("ok %s: %s\n", label, why);
    return 0;
}

int main(int argc, char **argv) {
    const char *root = argc > 1 ? argv[1] : "disc_cue_path_probe.tmp";
    char disc[1024], other[1024], cue[1100], bin[1100], back[1100];
    static const char sheet[] = "FILE \"disc.bin\" BINARY\r\n  TRACK 01 MODE2/2352\r\n    INDEX 01 00:00:00\r\n";
    char sector[2352] = {0};
    int bad = 0;
    size_t i;
    snprintf(disc, sizeof disc, "%s/disc", root);
    snprintf(other, sizeof other, "%s/elsewhere", root);
    mkdir_one(root); mkdir_one(disc); mkdir_one(other);
    snprintf(cue, sizeof cue, "%s/disc.cue", disc);
    snprintf(bin, sizeof bin, "%s/disc.bin", disc);
    if (!write_file(cue, sheet, sizeof sheet - 1) || !write_file(bin, sector, sizeof sector)) {
        printf("FAIL setup\n");
        return 1;
    }
    if (chdir(other) != 0) { printf("FAIL chdir\n"); return 1; }
    /* Absolute path of the cue from the new cwd: root may be relative. */
    if (root[0] != '/' && !(root[0] && root[1] == ':')) {
        snprintf(cue, sizeof cue, "../disc/disc.cue");
    }
    bad |= check(cue, "forward-slash path, cwd elsewhere");
#ifdef _WIN32
    snprintf(back, sizeof back, "%s", cue);
    for (i = 0; back[i]; ++i) if (back[i] == '/') back[i] = '\\';
    bad |= check(back, "backslash path, cwd elsewhere");
#else
    (void)back; (void)i;
#endif
    return bad;
}
