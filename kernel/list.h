#ifndef _LIST_H_
#define _LIST_H_

#include "kernel.h"

/* list_insert_head
 *   insert at head, return new head cell
 */
Task * list_insert_head(Task * list, Task * cell);

/* list_remove_head
 *   remove cell from head, returns new list head and a pointer to removed cell
 */
Task * list_remove_head(Task * list, Task ** cell);

/* list_insert_tail
 *   insert at tail, return head cell
 */
Task * list_insert_tail(Task * list, Task * cell);

/* list_remove_tail
 *   remove cell from tail, returns list head and a pointer to removed cell
 */
Task * list_remove_tail(Task * list, Task ** cell);

/* list_size
 * 	 returns number of nodes in the list
 */
int list_size(Task *list);

/* list_display
 * 	 iterates through the list and display the node id
 */
void list_display(Task * list);

#endif
