#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
struct Stack
{
    byte* array;
    int size;
    int top;
};

typedef struct Stack Stack;

Stack* createStack(int size){
    Stack* ptr = (Stack*) malloc(sizeof(Stack));
    ptr->array = (byte*) malloc(size * sizeof(byte));
    ptr->size = size;
    ptr->top = 0;
    return ptr;
}

void deleteStack(Stack* ptr){
    free(ptr->array);
    free(ptr);
}

static int isEmpty(Stack* ptr){
    return(ptr->top == 0);
}

static int isFull(Stack* ptr){
    return(ptr->top == ptr->size);
}

int push(Stack* ptr, byte data){
    if(isFull(ptr)){
        printf("\n!! STACK OVERFLOW !!\n");
        return 0;
    }
    ptr->array[ptr->top] = data;
    (ptr->top)++;
    return 1;

}

byte pop(Stack* ptr){
    if(isEmpty(ptr)){
        printf("\n!! STACK EMPTY !!\n");
        return -1;
    }
    byte data = ptr->array[(ptr->top) - 1];
    (ptr->top)--;
    return data;
}

byte peek(Stack* ptr){
    if(isEmpty(ptr)){
        printf("\n!! STACK EMPTY !!\n");
        return -1;
    }
    byte data = ptr->array[(ptr->top) - 1];
    return data;
}

void display(Stack* ptr){
    if(! ptr){ 
        printf("\n!!STACK DOESN'T EXIST !!\n");
    }
    else if(isEmpty(ptr)){
        printf("|____| \n");
    }
    else{
        for(int i = (ptr->top)-1; i >= 0; i--){
            printf("| %d | \n", ptr->array[i]);
        }
        printf("----- \n\n");
    }
}
