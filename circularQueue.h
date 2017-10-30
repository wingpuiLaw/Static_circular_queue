#ifndef _QUEUE_H
#define _QUEUE_H

#include "define.h"

#define MAX_QUEUE_SIZE 1024
#define MAX_RECEIVE_BUFF 512
#define MAX_QUEUE_DATA_BUFF 102400  //100 KByte
#define MAX_HANDOVERQUEUE_FLAG 5

#define MAX_LOG_SIZE 1024

/*I from tail, and O from head*/
typedef struct S_QUEUE_DATA{  //I was used to store udp packet's datas
	// U8 identity[12];
	U8 receive[MAX_RECEIVE_BUFF];
	U32 lenth;  //buffer lenth
	int sockfd;
	struct sockaddr_in ipAddr;
}S_QUEUE_DATA;

typedef struct S_CIRCULAR_QUEUE{
	S_QUEUE_DATA data[MAX_QUEUE_SIZE];
	U32 head;
	U32 tail;
}S_CIRCULAR_QUEUE;

void init_queue(S_CIRCULAR_QUEUE *queue);
bool is_full(S_CIRCULAR_QUEUE *queue);
bool is_empty(S_CIRCULAR_QUEUE *queue);
bool input_queue(S_CIRCULAR_QUEUE *queue, S_QUEUE_DATA *tempData);
S_QUEUE_DATA output_queue(S_CIRCULAR_QUEUE *queue);
void clean_queue(S_CIRCULAR_QUEUE *queue);
