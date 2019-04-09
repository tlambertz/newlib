#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H
#ifdef __cplusplus
extern "C" {
#endif

#define MAP_FAILED NULL

#define PROT_NONE       0
#define PROT_READ       1
#define PROT_WRITE      2
#define PROT_EXEC       4

#define MAP_FILE        0
#define MAP_SHARED      1
#define MAP_PRIVATE     2
#define MAP_TYPE        0xf
#define MAP_FIXED       0x10
#define MAP_ANONYMOUS   0x20
#define MAP_ANON        MAP_ANONYMOUS

/* Flags for msync. */
#define MS_ASYNC        1
#define MS_SYNC         2
#define MS_INVALIDATE   4

void *mmap (void *, size_t, int, int, int, off_t);
int munmap (void *, size_t);
int mlock(const void *, size_t);

int mlockall(int);

int mprotect(void *, size_t, int);

int msync(void *, size_t, int);

int munlock(const void *, size_t);

int munlockall(void);

// int posix_madvise(void *, size_t, int);

// int posix_mem_offset(const void *restrict, size_t, off_t *restrict, size_t *restrict, int *restrict);
// int posix_typed_mem_get_info(int, struct posix_typed_mem_info *);
// int posix_typed_mem_open(const char *, int, int);

// int shm_open(const char *, int, mode_t);
// int shm_unlink(const char *);

#ifdef __cplusplus
}
#endif
#endif
