#ifndef _DEVICE_H_
#define _DEVICE_H_

#include "oslib.h"
#include <stdlib.h>
//#include "fat.h"

#define MAX_OPENED_FDS      20
#define MAX_DEV_NAME_LEN    12
#define MAX_FILE_NAME_LEN   32


typedef struct _Device Device;
typedef struct _FileObject FileObject;


struct _Device {
    char            name[MAX_DEV_NAME_LEN];		/* name of device */
    int             refcnt;						/* reference count */
    Semaphore *     mutex;						/* access mutex */
    Semaphore *     sem_read;					/* blocking read semaphore */
    Semaphore *     sem_write;					/* blocking write semaphore */
    int             (*init)(Device *dev);
    int             (*open)(FileObject *f);
    int             (*close)(FileObject *f);
    int             (*read)(FileObject *f, void *buf, size_t len);
    int             (*write)(FileObject *f, void *buf, size_t len);
    int             (*ioctl)(FileObject *f, int op, void **data);
};

struct _FileObject {
    char *			name;						/* name of the file */
    unsigned int    flags;						/* file characteristics */
	unsigned int	offset;						/* offset in file */
#ifdef _FAT_H_
	FIL *			file;
	DIR *			dir;
#endif
    Device *        dev;
};


/* File name manipulation utilities */

char * dirname(char *path);				/* returns parent's name (everything 
										   before the last '/') */
char * basename(char *path);			/* returns the filename (everything 
										   after the last '/') */
#endif

