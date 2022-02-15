#include "queue.h"
#include <stdio.h>


struct queue
{
    int size;

    int array[1000];
    int weights[1000];
};

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

struct queue* createQueue()
{
    struct queue* pToNewQueue = (struct queue*)malloc(sizeof(struct queue));
    pToNewQueue->size = 0;
    return pToNewQueue;
}

void heapify(struct queue * pToQueue, int size, int i)
{
    if (size <= 1)
    {
        return;
    }
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && pToQueue->weights[left] > pToQueue->weights[largest])
    {
        largest = left;
    }
    if (right < size && pToQueue->weights[right] > pToQueue->weights[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&pToQueue->weights[i], &pToQueue->weights[largest]);
        swap(&pToQueue->array[i], &pToQueue->array[largest]);
        heapify(pToQueue, size, largest);
    }
  
}

void enqueue(struct queue* pToQueue, int newNum, int weight)
{
    if (pToQueue->size == 0)
    {
        pToQueue->array[0] = newNum;
        pToQueue->weights[0] = weight;
        pToQueue->size += 1;
        return;
    }
    
    pToQueue->array[pToQueue->size] = newNum;
    pToQueue->weights[pToQueue->size] = weight;
    pToQueue->size += 1;
    for (int i = pToQueue->size / 2 - 1; i >= 0; i--)
    {
        heapify(pToQueue, pToQueue->size, i);
    }
    
}

int dequeue(struct queue* pToQueue, int * queueStatus)
{
    if (pToQueue->size == 0)
    {
        *queueStatus = 1;
        return 0;
    }
    swap(&pToQueue->array[0], &pToQueue->array[pToQueue->size - 1]);
    swap(&pToQueue->weights[0], &pToQueue->weights[pToQueue->size - 1]);
    pToQueue->size -= 1;
    for (int i = pToQueue->size / 2 - 1; i >= 0; i--)
    {
        heapify(pToQueue, pToQueue->size, i);
    }
    return pToQueue->array[pToQueue->size];
}