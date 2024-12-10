#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
    if (q == NULL)
        return 1;
    return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
    if (q->size >= MAX_QUEUE_SIZE)
        return;
    q->size++;
    q->proc[q->size - 1] = proc;
}

struct pcb_t *dequeue(struct queue_t *q)
{
    /* TODO: return a pcb whose priority is the highest
     * in the queue [q] and remember to remove it from q
     */
    if (empty(q))
        return NULL; // Return NULL if the queue is empty

    struct pcb_t *head = q->proc[0]; // Get the head of the queue

    // Shift all the remained processes to the left
    for (int i = 0; i < (q->size - 1); i++)
        q->proc[i] = q->proc[i + 1];

    q->proc[q->size - 1] = NULL; // Assign NULL value for the tail of the queue
    q->size--;                   // Decrese the size of the queue
    return head;                 // Return the head of the queue
}