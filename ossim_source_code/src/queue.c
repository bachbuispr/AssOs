#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q->size < MAX_QUEUE_SIZE) {  // Ensure queue is not full
        q->proc[q->size] = proc;      // Add the process to the end of the queue
        q->size++;                    // Increase the size of the queue
    }
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
	//return NULL;
        if (q->size == 0) return NULL;

    struct pcb_t *proc = q->proc[0];
    for (int i = 1; i < q->size; i++) {
        q->proc[i - 1] = q->proc[i];
    }
    q->size--;
    return proc;                   // Increase the size of the queue
    
}

