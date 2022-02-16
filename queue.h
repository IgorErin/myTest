#ifndef QUEUE
#define QUEUE

typedef struct StructQueue Queue;


Queue* createQueue();

void swap(int* a, int* b);

void heapify(Queue* pToQueue, int size, int i);

void enqueue(Queue* pToQueue, int newNum, int weight, int* queueStatus);

int dequeue(Queue* pToQueue, int* queueStatus);

#endif