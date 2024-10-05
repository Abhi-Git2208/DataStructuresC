
typedef unsigned char byte;

struct Stack{
    byte* array;
    int size;
    int top;
};

typedef struct Stack Stack;

Stack* createStack(int size);

void deleteStack(Stack* ptr);

int push(Stack* ptr, byte data);

byte pop(Stack* ptr);

byte peek(Stack * ptr);

void display(Stack* ptr);