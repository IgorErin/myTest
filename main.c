#include "queue.h"
#include <stdio.h>


int main()
{
    Queue* pToQueue = createQueue();

    int queueStatus = 0;

    enqueue(pToQueue, 5, 5, queueStatus);
    enqueue(pToQueue, 4, 6, queueStatus);
    enqueue(pToQueue, 7, 4, queueStatus);
    enqueue(pToQueue, 1, 10, queueStatus);
    enqueue(pToQueue, 2, 9, queueStatus);
    enqueue(pToQueue, 3, 8, queueStatus);
    enqueue(pToQueue, 4, 7, queueStatus);
    enqueue(pToQueue, 8, 3, queueStatus);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", dequeue(pToQueue, &queueStatus));
        if (queueStatus == 1)
        {
            break;
        }
    }

    free(pToQueue);
}