#ifndef HELLO_MODULE
#define HELLO_MODULE

int size;

int array[1000];
int weights[1000];


void swap(int* a, int* b);

void heapify(int size, int i);

void enqueue(int newNum, int weight);

int dequeue();

#endif