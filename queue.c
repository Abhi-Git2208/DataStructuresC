#include <stdio.h>
#include <stdlib.h>

typedef unsigned char datatype;
typedef struct Queue{
    datatype *array;
    int size;
    int top;
    int bottom;
} Queue;

Queue* createQueue(int size){
    Queue* ptr = (Queue *) malloc(sizeof(Queue));
    ptr->array = (datatype*) malloc(size * sizeof(datatype));
    ptr->top = 0;
    ptr->bottom = 0;
    ptr->size = size;
    return ptr;
}

void deleteQueue(Queue* ptr){
    free(ptr->array);
    free(ptr);
}

static int isEmpty(Queue* ptr){
    return(ptr->top == ptr->bottom);
}

static int isFull(Queue* ptr){
    return((ptr->top - ptr->bottom + 1) >= ptr->size);
}

int inQueue(Queue* ptr, datatype data){
    if(isFull(ptr)){
        printf("\nError : Queue is Full !!");
        return 0;
    }
    ptr->array[ptr->top] = data;
    ptr->top += 1;
    return 1;
}

datatype deQueue(Queue* ptr){
    if(isEmpty(ptr)){
        printf("\nError : Queue is Empty !!");
        return 0;
    }
    datatype data = ptr->array[ptr->bottom];
    // free(ptr->array[ptr->bottom]);
    ptr->bottom += 1;
    return data;
}

void display(Queue* ptr){
    if(isEmpty(ptr)){
        printf("|   | \n");
    }
    else{
        for(int i = (ptr->top) - 1; i >= ptr->bottom; i--){
            printf("| %d |\n", ptr->array[i]);
        }
    }
}