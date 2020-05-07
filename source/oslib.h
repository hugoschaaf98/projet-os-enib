#ifndef _OSLIB_H_
#define _OSLIB_H_

#include <stddef.h>
#include "board.h"

/*****************************************************************************
 * Test
 *****************************************************************************/

int test_add(int a, int b);


/*****************************************************************************
 * General OS handling functions
 *****************************************************************************/

/* os_alloc
 *   heap memory allocation
 */
void* os_alloc(unsigned int req);

/* os_free
 *   heap memory deallocation
 */
void os_free(void *ptr);

/* os_start
 *   start the first created task
 */
void os_start();

/*****************************************************************************
 * Task handling functions
 *****************************************************************************/

// define the prototype of the processing function executed by a task
typedef void (*TaskCode)();

/* task_new
 *   create a new task :
 *   func      : task code to be run
 *   stacksize : task stack size
 *   returns the task id
 */
int32_t task_new(TaskCode func, uint32_t stacksize);

/* task_id
 *   returns id of task
 */
uint32_t task_id();

/* task_kill
 *   kill oneself
 */
void task_kill();

/* task_yield
 *   run scheduler to switch to another task
 */
void task_yield();

/* task_wait
 *   suspend the current task until timeout
 */
void  task_wait(uint32_t ms);


/*****************************************************************************
 * Semaphore handling functions
 *****************************************************************************/

typedef struct _Semaphore Semaphore;

/* sem_new
 *   create a semaphore
 *   init    : initial value
 */
Semaphore * sem_new(int32_t init);

/* sem_p
 *   take a semaphore
 */
void sem_p(Semaphore * sem);

/* sem_v
 *   release a semaphore
 */
void sem_v(Semaphore * sem);


/*****************************************************************************
 * IO device handling functions
 *****************************************************************************/
/*
 * File status flags: these are used by open(2), fcntl(2).
 */
#define O_RDONLY        0x00000001  /* open read only */
#define O_WRONLY        0x00000002	/* open for writing only */
#define O_RDWR          0x00000003  /* open in read/write mode */
#define	O_READ  		0x00000001	/* open for reading */
#define	O_WRITE         0x00000002	/* open for writing */
#define	O_NONBLOCK		0x00000004	/* no delay */
#define	O_APPEND		0x00000008	/* set append mode */
#define	O_SHLOCK		0x00000010	/* open with shared file lock */
#define	O_EXLOCK		0x00000020	/* open with exclusive file lock */
#define	O_ASYNC			0x00000040	/* signal pgrp when data ready */
#define	O_SYNC			0x00000080	/* synchronous writes */
#define	O_CREAT			0x00000200	/* create if nonexistent */
#define	O_TRUNC			0x00000400	/* truncate to zero length */
#define	O_EXCL			0x00000800	/* error if already exists */

#define F_IS_DIR		0x00010000	/* object is a directory */
#define F_IS_FILE		0x00020000	/* object is a regular file */
#define F_IS_DEV		0x00040000	/* object is a hardware device */
#define F_IS_DEVDIR		0x00080000	/* object is "/dev" directory */
#define F_IS_ROOTDIR	0x00100000	/* object is "/" directory */


/***************************************************************************
 * IO device / regular file / directory handling functions
 ***************************************************************************/
#ifndef _FAT_H_
int mount();

typedef struct {
	uint32_t	cluster;
	uint32_t	sindex;
	uint32_t	offset;
	char		entry[16];
	uint32_t	entry_size;
	uint32_t	entry_isdir;
} DIR;

/* readdir
 *   iterates over directory fd, returns 0 when ok, -1 else
 */
int readdir(int fd, DIR **dir);
#endif

/***************************************************************************
 * IO device / regular file / directory handling functions
 ***************************************************************************/
/* open
 *   returns a file descriptor for path name
 */
int open(char *path, int flags);

/* close
 *   close the file descriptor
 */
int close(int fd);

/* read
 *   read len bytes from fd into buf, returns actually read bytes
 */
int read(int fd, void *buf, size_t len);

/* write
 *   write len bytes from buf to fd, returns actually written bytes
 */
int write(int fd, void *buf, size_t len);

/* ioctl
 *   set/get parameter for fd
 */
int ioctl(int fd, int op, void** data);

/* lseek
 *   set the offset in fd
 */
int lseek(int fd, unsigned int offset);

#endif
