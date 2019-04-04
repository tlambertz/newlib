#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H
#ifdef __cplusplus
extern "C" {
#endif

#define MAP_FAILED NULL

void *mmap (void *, size_t, int, int, int, off_t);
int munmap (void *, size_t);

#ifdef __cplusplus
}
#endif
#endif
