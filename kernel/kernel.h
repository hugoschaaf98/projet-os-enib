#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "board.h"

typedef enum {
    TASK_RUNNING,
    TASK_READY,
    TASK_SLEEPING,
    TASK_WAITING
} TaskState;

typedef struct _Task {
    struct _Task *  prev;           // link to the previous item
    struct _Task *  next;           // link to the following item
    uint32_t        id;             // identifier
    TaskState       status;         // task status : running, ready, ...
    uint32_t *      sp;				// current sp
    uint32_t *      splim;          // stack limit
    int32_t         delay;          // waiting delay (for timeouts)
} Task;


/*****************************************************************************
 * General OS handling functions
 *****************************************************************************/

#ifndef _OSLIB_H_
/* task code type
 */
typedef void (*TaskCode)();
#endif

/* sys_os_start
 *   start the first created task
 */
int32_t sys_os_start();


/*****************************************************************************
 * Task handling functions
 *****************************************************************************/

/* sys_task_new
 *   create a new task :
 *   func      : task code to be run
 *   stacksize : task stack size
 */
int32_t sys_task_new(TaskCode func, uint32_t stacksize);

/* sys_task_kill
 *   kill oneself
 */
int32_t sys_task_kill();

/* sys_task_id
 *   returns id of task
 */
int32_t sys_task_id();

/* sys_task_yield
 *   run scheduler to switch to another task
 */
int32_t sys_task_yield();

/* task_wait
 *   suspend the current task until timeout
 */
int32_t sys_task_wait(uint32_t ms);


/*****************************************************************************
 * Semaphore handling functions
 *****************************************************************************/
#ifndef _OSLIB_H_
typedef struct _Semaphore Semaphore;
#endif

struct _Semaphore {
    int32_t   count;
    Task *  waiting;
};

/* sys_sem_new
 *   create a semaphore
 *   init    : initial value
 */
Semaphore * sys_sem_new(int32_t init);

/* sys_sem_p
 *   take a token
 */
int32_t sys_sem_p(Semaphore * sem);

/* sys_sem_v
 *   release a token
 */
int32_t sys_sem_v(Semaphore * sem);

#endif
