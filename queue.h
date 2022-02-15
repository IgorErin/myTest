#ifndef QUEUE
#define QUEUE

struct queue;


void swap(int* a, int* b);

void heapify(struct queue* pToQueue, int size, int i);

void enqueue(struct queue* pToQueue, int newNum, int weight);

int dequeue(struct queue* pToQueue, int* queueStatus);

#endif