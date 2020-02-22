#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (!q)
        return;
    list_ele_t *tmp = q->head;
    while (tmp) { /* free linked list elements */
        q->head = tmp->next;
        if (tmp->value) /* free the string if existed */
            free(tmp->value);
        free(tmp);
        tmp = q->head;
    }
    free(q); /* free the queue */
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q) /* ignore NULL queue */
        return false;
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    /* allocate space for the string and copy it */
    int length = strlen(s) + 1;
    newh->value = malloc(length * sizeof(char));
    if (!newh->value) {
        free(newh);
        return false;
    }
    strncpy(newh->value, s, length);
    /* insert element at head of queue */
    if (q->head == NULL) /* queue is empty */
        q->tail = newh;
    newh->next = q->head;
    q->head = newh;
    (q->size)++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (!q) /* ignore NULL queue */
        return false;
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    /* allocate space for the string and copy it */
    int length = strlen(s) + 1;
    newh->value = malloc(length * sizeof(char));
    if (!newh->value) {
        free(newh);
        return false;
    }
    strncpy(newh->value, s, length);
    /* insert element at tail of queue */
    if (q->head == NULL) { /* no element in the queue */
        q->head = newh;
        q->tail = newh;
    } else {
        q->tail->next = newh;
        q->tail = q->tail->next;
    }
    q->tail->next = NULL;
    (q->size)++;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (!q || !q->head) /* ignore NULL and empty queue */
        return false;
    list_ele_t *tmp = q->head;
    q->head = q->head->next;
    if (tmp->value) {
        if (sp != NULL) {
            strncpy(sp, tmp->value, (bufsize - 1));
            sp[bufsize - 1] = '\0';
        }
        free(tmp->value);
    }
    free(tmp);
    (q->size)--;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q)
        return 0;
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q || !q->head) /* ignore NULL and empty queue */
        return;
    if (!q->head->next)
        return;
    list_ele_t *tmp;
    list_ele_t *new = NULL;
    q->tail = q->head;
    while (q->head) {
        /* detach element from the head */
        tmp = q->head;
        q->head = q->head->next;
        /* reverse the queue */
        tmp->next = new;
        new = tmp;
    }
    q->head = new;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
