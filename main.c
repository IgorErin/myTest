#include "queue.h"
#include <stdio.h>


int main()
{
    struct queue* pToQueue = createQueue();

    enqueue(pToQueue, 5, 5);
    enqueue(pToQueue, 4, 6);
    enqueue(pToQueue, 7, 4);
    enqueue(pToQueue, 1, 10);
    enqueue(pToQueue, 2, 9);
    enqueue(pToQueue, 3, 8);
    enqueue(pToQueue, 4, 7);
    enqueue(pToQueue, 8, 3);

    int queueStatus = 0;

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