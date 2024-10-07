
typedef unsigned char datatype;
typedef struct Queue{
    datatype *array;
    int size;
    int top;
    int bottom;
} Queue;

Queue* createQueue(int size);

void deleteQueue(Queue* ptr);

int inQueue(Queue* ptr, datatype data);

datatype deQueue(Queue* ptr);

void display(Queue* ptr);