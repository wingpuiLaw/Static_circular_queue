#include "queue.h"

/* message queue */
void init_queue(S_CIRCULAR_QUEUE *queue){
	queue->head = 0;
	queue->tail = 0;
}

bool is_full(S_CIRCULAR_QUEUE *queue){
	return (queue->tail+1) % MAX_QUEUE_SIZE == queue->head;
}

bool is_empty(S_CIRCULAR_QUEUE *queue){
	return queue->head == queue->tail;
}

bool input_queue(S_CIRCULAR_QUEUE *queue, S_QUEUE_DATA *tempData){
	if (is_full(queue))
		return false;
	
	if (queue->tail != MAX_QUEUE_SIZE - 1)  //not the end of the queue
		queue->data[(queue->tail)++] = *tempData;
	else{
		queue->data[MAX_QUEUE_SIZE-1] = *tempData;
		queue->tail = 0;
	}
	return true;
}

S_QUEUE_DATA output_queue(S_CIRCULAR_QUEUE *queue){  //Need to check isEmpty() before use it.
	S_QUEUE_DATA tempData;

	if (queue->head != MAX_QUEUE_SIZE - 1){
		tempData = queue->data[queue->head];
		++(queue->head);
	}
	else{
		tempData = queue->data[queue->head];
		queue->head = 0;
	}
	return tempData;
}

void clean_queue(S_CIRCULAR_QUEUE *queue){
	queue->head = queue->tail = 0;
	memset(queue->data, 0, sizeof(S_QUEUE_DATA)*MAX_QUEUE_SIZE);
}
