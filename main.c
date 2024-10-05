#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
    int size, choice;
    unsigned char data;
    printf("Enter Stack Size - ");
    scanf("%d", &size);

    Stack* ptr = createStack(size);

    while(1){
        printf("\n________________________________________________\n1. Display Stack \n2. Push element into stack \n3. Pop element from stack \n4. Peek into the stack \n5. Exit \nEnter your choice - ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                display(ptr);
                break;

            case 2:
                printf("Enter data - ");
                scanf("%d", &data);
                if(push(ptr, data)){
                    printf("Pushed successfully !! \n");
                }
                break;
            
            case 3:
                data = pop(ptr);
                printf("%d", data);
                break;

            case 4:
                printf("%d", peek(ptr));
                break;

            case 5:
                goto EXIT;
        }

    }

    EXIT : 
    printf("Program Terminated !!\n");
    deleteStack(ptr);
    // display(ptr);

    return 0;
}