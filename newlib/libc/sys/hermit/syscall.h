/*
 * Copyright (c) 2011, Stefan Lankes, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
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

/**
 * @author Stefan Lankes
 * @file include/hermit/syscall.h
 * @brief System call number definitions
 *
 * This file contains define constants for every syscall's number.
 */

#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#ifdef __KERNEL__
#include <hermit/stddef.h>
#else
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#ifndef NORETURN
#define NORETURN	__attribute__((noreturn))
#endif

typedef unsigned int tid_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque structures (may point to Rust structures or be used to not clash with types defined by the C library) */
struct _HermitItimerval;
typedef struct _HermitItimerval HermitItimerval;

struct _HermitRecursiveMutex;
typedef struct _HermitRecursiveMutex HermitRecursiveMutex;

struct _HermitSemaphore;
typedef struct _HermitSemaphore HermitSemaphore;

struct _HermitSpinlock;
typedef struct _HermitSpinlock HermitSpinlock;

struct _HermitSpinlockIrqSave;
typedef struct _HermitSpinlockIrqSave HermitSpinlockIrqSave;

struct _HermitTimespec;
typedef struct _HermitTimespec HermitTimespec;

struct _HermitTimeval;
typedef struct _HermitTimeval HermitTimeval;


typedef void (*entry_point_t)(void*);
typedef void (*signal_handler_t)(int);


/* Task priorities */
#define HIGH_PRIO	3
#define NORMAL_PRIO	2
#define LOW_PRIO	1
#define IDLE_PRIO	0


/*
 * HermitCore is a libOS.
 * => classical system calls are realized as normal function
 * => forward declaration of system calls as function
 */
tid_t sys_getpid(void);
int sys_fork(void);
int sys_wait(int* status);
int sys_execve(const char* name, char * const * argv, char * const * env);
int sys_getprio(tid_t* id);
int sys_setprio(tid_t* id, int prio);
void NORETURN sys_exit(int arg);
ssize_t sys_read(int fd, char* buf, size_t len);
ssize_t sys_write(int fd, const char* buf, size_t len);
ssize_t sys_sbrk(ssize_t incr);
int sys_open(const char* name, int flags, int mode);
int sys_close(int fd);
int sys_fsync(int fd);
int sys_unlink(const char* name);
void sys_acquire_putchar_lock(void);
void sys_putchar(const unsigned char character);
void sys_release_putchar_lock(void);
int sys_lwip_get_errno();
void sys_lwip_register_tcpip_task(tid_t id);
void sys_lwip_set_errno(int errno);
void sys_usleep(unsigned long usecs);
int sys_nanosleep(const HermitTimespec* rqtp, HermitTimespec* rmtp);
void sys_msleep(unsigned int ms);
int sys_recmutex_init(HermitRecursiveMutex** recmutex);
int sys_recmutex_destroy(HermitRecursiveMutex* recmutex);
int sys_recmutex_lock(HermitRecursiveMutex* recmutex);
int sys_recmutex_unlock(HermitRecursiveMutex* recmutex);
int sys_sem_init(HermitSemaphore** sem, unsigned int value);
int sys_sem_destroy(HermitSemaphore* sem);
int sys_sem_post(HermitSemaphore* sem);
int sys_sem_trywait(HermitSemaphore* sem);
int sys_sem_timedwait(HermitSemaphore *sem, unsigned int ms);
#define sys_sem_wait(sem)	sys_sem_timedwait(sem, 0)
int sys_sem_cancelablewait(HermitSemaphore* sem, unsigned int ms);
int sys_spinlock_init(HermitSpinlock** lock);
int sys_spinlock_destroy(HermitSpinlock* lock);
int sys_spinlock_lock(HermitSpinlock* lock);
int sys_spinlock_unlock(HermitSpinlock* lock);
int sys_spinlock_irqsave_init(HermitSpinlockIrqSave** lock);
int sys_spinlock_irqsave_destroy(HermitSpinlockIrqSave* lock);
int sys_spinlock_irqsave_lock(HermitSpinlockIrqSave* lock);
int sys_spinlock_irqsave_unlock(HermitSpinlockIrqSave* lock);
int sys_spawn(tid_t* id, entry_point_t func, void* arg, unsigned char prio, unsigned int core_id);
int sys_clock_getres(unsigned long clock_id, HermitTimespec* res);
int sys_clock_gettime(unsigned long clock_id, HermitTimespec* tp);
int sys_clock_nanosleep(unsigned long clock_id, int flags, const HermitTimespec* rqtp, HermitTimespec* rmtp);
int sys_clock_settime(unsigned long clock_id, const HermitTimespec* tp);
int sys_clone(tid_t* id, void* ep, void* argv);
int sys_getpagesize(void);
int sys_gettimeofday(HermitTimeval* tp, void* tz);
size_t sys_get_processor_count(void);
unsigned short sys_get_processor_frequency(void);
off_t sys_lseek(int fd, off_t offset, int whence);
int sys_setitimer(int which, const HermitItimerval* value, HermitItimerval* ovalue);
void sys_yield(void);
int sys_kill(tid_t dest, int signum);
int sys_signal(signal_handler_t handler);
unsigned int sys_rand();

struct ucontext;
typedef struct ucontext ucontext_t;

void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...);
int swapcontext(ucontext_t *oucp, const ucontext_t *ucp);
int getcontext(ucontext_t *ucp);
int setcontext(ucontext_t *ucp);

#define __NR_exit 		0
#define __NR_write		1
#define __NR_open		2
#define __NR_close		3
#define __NR_read		4
#define __NR_lseek		5
#define __NR_unlink		6
#define __NR_getpid		7
#define __NR_kill		8
#define __NR_fstat		9
#define __NR_sbrk		10
#define __NR_fork		11
#define __NR_wait		12
#define __NR_execve		13
#define __NR_times		14
#define __NR_stat		15
#define __NR_dup		16
#define __NR_dup2		17
#define __NR_msleep		18
#define __NR_yield		19
#define __NR_sem_init		20
#define __NR_sem_destroy	21
#define __NR_sem_wait		22
#define __NR_sem_post		23
#define __NR_sem_timedwait	24
#define __NR_getprio		25
#define __NR_setprio		26
#define __NR_clone		27
#define __NR_sem_cancelablewait	28
#define __NR_get_ticks		29

#ifdef __cplusplus
}
#endif

#endif
