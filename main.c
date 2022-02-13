#include"queue.h"
#include<stdio.h>


int main()
{
    enqueue(5, 2);
    enqueue(4, 5);
    enqueue(7, 8);
    enqueue(1, 10);
    enqueue(2, 0);
    enqueue(3, -1);
    enqueue(4, 1);
    enqueue(8, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", dequeue());
    }
}