#ifndef MUSASHI_BIOS_MEMCARD_H
#define MUSASHI_BIOS_MEMCARD_H

/* BIOS memory-card file device ("bu00:") over a 128 KiB card image, in the
 * standard PS1 layout (16 blocks of 8 KiB, block 0 = header and directory).
 *
 * The game's own Sony libmcrd code runs unchanged; this module answers the
 * BIOS entries it calls (open/lseek/read/write/close, format, firstfile/
 * nextfile, erase, _card_info, _card_write, _new_card) and completes the
 * asynchronous ones through the BIOS event vector at the next VBlank, as the
 * kernel's card driver does. Only port 0 carries a card. The image is the
 * user's save file (bfm_card0.mcd); the module never invents card contents
 * beyond a factory-fresh formatted card. */

#include <stddef.h>
#include <stdint.h>

#include "musashi_bios_events.h"
#include "musashi_boot_memory.h"

#define MUSASHI_MEMCARD_SIZE 131072u
#define MUSASHI_MEMCARD_BLOCK 8192u
#define MUSASHI_MEMCARD_FRAME 128u
#define MUSASHI_MEMCARD_FDS 8u
#define MUSASHI_MEMCARD_NAME 20u

enum {
    MUSASHI_MEMCARD_EV_IOEND = 0x0004u,
    MUSASHI_MEMCARD_EV_ERROR = 0x8000u,
    MUSASHI_MEMCARD_EV_TIMEOUT = 0x0100u,
    MUSASHI_MEMCARD_EV_NEWCARD = 0x2000u
};

typedef struct MusashiMemcardFd {
    int used;
    uint16_t first_block;
    uint32_t size;
    uint32_t pos;
    uint32_t mode;
} MusashiMemcardFd;

typedef struct MusashiBiosMemcard {
    uint8_t image[MUSASHI_MEMCARD_SIZE];
    int present;              /* a card is in port 0 */
    int new_card;             /* _card_info reports "new card" once */
    int dirty;                /* image changed since the last persist */
    MusashiMemcardFd fds[MUSASHI_MEMCARD_FDS];
    /* Directory iteration for firstfile/nextfile. */
    char pattern[MUSASHI_MEMCARD_NAME + 1];
    unsigned dir_next;        /* next directory entry to examine (1..15) */
    int dir_active;
    /* Completion queued for the next VBlank: spec, or 0 when idle. */
    uint32_t pending_spec;
    /* Persistence: called after every successful change of the image. */
    int (*persist)(void *userdata, const uint8_t *image, size_t size);
    void *persist_userdata;
    /* Counters for logs and tests. */
    uint64_t opens, reads, writes, formats, erases, infos, delivered, persisted;
    uint64_t refusals;
} MusashiBiosMemcard;

/* Fresh storage; `present` chooses whether port 0 holds a card. */
void musashi_bios_memcard_init(MusashiBiosMemcard *mc, int present);
/* Load an image (exactly MUSASHI_MEMCARD_SIZE bytes) or format a fresh one. */
int musashi_bios_memcard_load_image(MusashiBiosMemcard *mc, const uint8_t *image, size_t size);
void musashi_bios_memcard_format_fresh(uint8_t *image);
int musashi_bios_memcard_is_formatted(const uint8_t *image);

/* BIOS entries. Each returns nonzero when it accepted the call and stored the
 * guest result in *result (a 0 return is a refusal: the runner stops). Guest
 * pointers are read and written through `memory` (KSEG0/KUSEG RAM). */
int musashi_bios_memcard_open(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                              uint32_t name_ptr, uint32_t mode, int32_t *result);
int musashi_bios_memcard_lseek(MusashiBiosMemcard *mc, int32_t fd, int32_t offset,
                               int32_t whence, int32_t *result);
int musashi_bios_memcard_read(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                              int32_t fd, uint32_t buf_ptr, uint32_t length, int32_t *result);
int musashi_bios_memcard_write(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                               int32_t fd, uint32_t buf_ptr, uint32_t length, int32_t *result);
int musashi_bios_memcard_close(MusashiBiosMemcard *mc, int32_t fd, int32_t *result);
int musashi_bios_memcard_format(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                uint32_t name_ptr, int32_t *result);
int musashi_bios_memcard_firstfile(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                   uint32_t name_ptr, uint32_t dirent_ptr, int32_t *result);
int musashi_bios_memcard_nextfile(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                  uint32_t dirent_ptr, int32_t *result);
int musashi_bios_memcard_erase(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                               uint32_t name_ptr, int32_t *result);
int musashi_bios_memcard_card_info(MusashiBiosMemcard *mc, int32_t chan, int32_t *result);
int musashi_bios_memcard_card_load(MusashiBiosMemcard *mc, int32_t chan, int32_t *result);
int musashi_bios_memcard_card_write(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                    int32_t chan, int32_t sector, uint32_t buf_ptr, int32_t *result);
int musashi_bios_memcard_new_card(MusashiBiosMemcard *mc, int32_t *result);

/* Deliver the queued completion (both the SwCARD F4000001 and HwCARD
 * F0000011 classes, as the kernel does) through the event vector. Returns 0
 * only when a delivery was refused. */
int musashi_bios_memcard_vblank(MusashiBiosMemcard *mc, MusashiBiosEvents *events,
                                MusashiBiosEventExecutor execute, void *userdata);

/* The BIOS device table the game's directory scan reads through kernel
 * words 0x150/0x154: one "bu" entry whose firstFile pointer is the libapi
 * firstfile stub. Written into low RAM once at start. */
int musashi_bios_memcard_install_device_table(MusashiBootMemory *memory);

#endif
