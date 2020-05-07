#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/* Test example ...

int id=0;

typedef struct _Task {
    struct _Task *  prev;             // lien vers bloc précédent
    struct _Task *  next;             // lien vers bloc suivant
    int             id;               // identificateur
} Task;

Task * task_new()
{
	Task *t=(Task*)malloc(sizeof(Task));

	if (t) {
		t->id=id++;
		return t;
	}

	return NULL;
}


int main()
{
	Task *t0, *t1, *t2, *t, *l=NULL;

	t0=task_new();
	t1=task_new();
	t2=task_new();


	if (t0 && t1 && t2) {
		printf("head insertion\n\n");
		l=list_insert_head(l,t0);
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_insert_head(l,t1);
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_insert_head(l,t2);
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_remove_head(l,&t);
		if (l==t1 && t==t2) printf("ok\n");
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_remove_head(l,&t);
		if (l==t0 && t==t1) printf("ok\n");
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_remove_head(l,&t);
		if (l==NULL && t==t0) printf("ok\n");
		printf("%d elements\n",list_size(l));
		list_display(l);
	}
	if (t0 && t1 && t2) {
		printf("\ntail insertion\n\n");
		l=list_insert_tail(l,t0);
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_insert_tail(l,t1);
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_insert_tail(l,t2);
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_remove_tail(l,&t);
		if (l==t0 && t==t2) printf("ok\n");
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_remove_tail(l,&t);
		if (l==t0 && t==t1) printf("ok\n");
		printf("%d elements\n",list_size(l));
		list_display(l);
		l=list_remove_tail(l,&t);
		if (l==NULL && t==t0) printf("ok\n");
		printf("%d elements\n",list_size(l));
		list_display(l);
	}
	else printf("mem problem\n");
	return 0;
}
*/

/* list_insert_head
 *   insert at head, return new head cell
 */
Task * list_insert_head(Task * list, Task * cell)
{
    if (list) {
        cell->next=list;
        cell->prev=list->prev;
        list->prev->next=cell;
        list->prev=cell;
    } else {
        cell->next=cell;
        cell->prev=cell;
    }
    return cell;
}

/* list_remove_head
 *   remove cell from head, returns new list head and a pointer to removed cell
 */
Task * list_remove_head(Task * list, Task ** cell)
{
    if (!list) {
        *cell=NULL;
        return NULL;
    }

    if (list->prev==list) { /* only one cell */
        *cell=list;
        return NULL;
    }

    list->next->prev=list->prev;
    list->prev->next=list->next;
    *cell=list;

    return list->next;
}

/* list_insert_tail
 *   insert at tail, return head cell
 */
Task * list_insert_tail(Task * list, Task * cell)
{
    if (list) {
        cell->next=list;
        cell->prev=list->prev;
        list->prev->next=cell;
        list->prev=cell;
        return list;
    }

    cell->next=cell;
    cell->prev=cell;
    return cell;
}

/* list_remove_tail
 *   remove cell from tail, returns list head and a pointer to removed cell
 */
Task * list_remove_tail(Task * list, Task ** cell)
{
    Task * tail_cell;

    if (!list) {
        *cell=NULL;
        return NULL;
    }

    if (list->prev==list) { /* only one cell */
       	*cell=list;
        return NULL;
    }

    tail_cell=list->prev;
    tail_cell->next->prev=tail_cell->prev;
    tail_cell->prev->next=tail_cell->next;
    *cell=tail_cell;

    return list;
}

/* list_size
 * 	 returns number of nodes in the list
 */
int list_size(Task *list)
{
	Task *l=list;

	if (l) {
		int size=1;
		while (l->next!=list) {
			size++;
			l=l->next;
		}
		return size;
	}

	return 0;
}

/* list_display
 * 	 iterates through the list and display the node id
 */
void list_display(Task *list)
{
	Task *l=list;
	char s[8] = "-> 0 ";
	int i;

	if (list==NULL) {
		printf("liste vide\r\n");
		return;
	}

	for (i=0;i<list_size(l);i++) {
        s[3]=l->id+0x30;
		printf(s);
		l=l->next;
	}

	printf("\r\n");
}


