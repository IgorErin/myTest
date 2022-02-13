#include "queue.h"
#include <stdio.h>


int main()
{
    enqueue(5, 5);
    enqueue(4, 6);
    enqueue(7, 4);
    enqueue(1, 10);
    enqueue(2, 9);
    enqueue(3, 8);
    enqueue(4, 7);
    enqueue(8, 3);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", dequeue());
    }
}