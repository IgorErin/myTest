#include"queue.h"
#include<stdio.h>

size = 0;

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int size, int i)
{
    if (size > 1)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && weights[l] > weights[largest])
        {
            largest = l;
        }
        if (r < size && weights[r] > weights[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(&weights[i], &weights[largest]);
            swap(&array[i], &array[largest]);
            heapify(size, largest);
        }
    }
}

void enqueue(int newNum, int weight)
{
    if (size == 0)
    {
        array[0] = newNum;
        weights[0] = weight;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        weights[size] = weight;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(size, i);
        }
    }
}

int dequeue()
{
    if (size == 0)
    {
        printf("ERROR! queue is empty\n");
        return 0;
    }
    swap(&array[0], &array[size - 1]);
    swap(&weights[0], &weights[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(size, i);
    }
    return array[size];
}