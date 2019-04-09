/*
 * Copyright (c) 2019, Jonathan Klimt, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of the University nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include <reent.h>
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include "syscall.h"
#include "warning.h"

#include "sys/mman.h"
#define MAP_FAILED NULL

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
	return MAP_FAILED;
}

int munmap(void *addr, size_t length) {
	return -1;
}

int mlock(const void *, size_t);

int mlockall(int);

int mprotect(void *, size_t, int);

int msync(void *, size_t, int);

int munlock(const void *, size_t);

int munlockall(void);

/* int posix_madvise(void *, size_t, int); */

/* int posix_mem_offset(const void *restrict, size_t, off_t *restrict, size_t *restrict, int *restrict); */
/* int posix_typed_mem_get_info(int, struct posix_typed_mem_info *); */
/* int posix_typed_mem_open(const char *, int, int); */

/* int shm_open(const char *, int, mode_t); */
/* int shm_unlink(const char *); */
