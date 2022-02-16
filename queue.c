#include "queue.h"
#include <stdio.h>


struct StructQueue
{
    int size;
    int sizeArray;

    int *array;
    int *weights;
};

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

Queue* createQueue()
{
    Queue* pToNewQueue = (Queue*)malloc(sizeof(Queue));
    pToNewQueue->size = 0;
    pToNewQueue->sizeArray = 0;
    return pToNewQueue;
}

void heapify(Queue * pToQueue, int size, int i)
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

void enqueue(Queue* pToQueue, int newNum, int weight, int* queueStatus)
{
    
    if (pToQueue->size == 0)
    {
        pToQueue->array = (int*)malloc(sizeof(int));
        pToQueue->weights = (int*)malloc(sizeof(int));
        pToQueue->array[0] = newNum;
        pToQueue->weights[0] = weight;
        pToQueue->size += 1;
        pToQueue->sizeArray += 1;
        return;
    }

    if (pToQueue->size == pToQueue->sizeArray)
    {
        int* pForTest;
        pForTest = (int*)realloc(pToQueue->array, sizeof(int) * pToQueue->sizeArray * 2);
        if (pForTest == NULL)
        {
            *queueStatus = 2;
            return;
        }
        pToQueue->array = pForTest;
        pForTest = (int*)realloc(pToQueue->weights, sizeof(int) * pToQueue->sizeArray * 2);
        if (pForTest == NULL)
        {
            *queueStatus = 2;
            return;
        }
        pToQueue->weights = pForTest;
        pToQueue->sizeArray = pToQueue->sizeArray * 2;
    }
    pToQueue->array[pToQueue->size] = newNum;
    pToQueue->weights[pToQueue->size] = weight;
    pToQueue->size += 1;
    for (int i = pToQueue->size / 2 - 1; i >= 0; i--)
    {
        heapify(pToQueue, pToQueue->size, i);
    }
}

int dequeue(Queue* pToQueue, int * queueStatus)
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

void delQueue(Queue* pToQueue)
{
    free(pToQueue->array);
    free(pToQueue->weights);
    free(pToQueue);
}