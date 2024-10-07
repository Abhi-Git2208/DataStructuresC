#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef unsigned char datatype;

int main(){
    int size, choice;
    datatype data;
    printf("Enter Queue Size - ");
    scanf("%d", &size);

    Queue* ptr = createQueue(size);

    while(1){
        printf("\n________________________________________________\n1. Display Queue \n2. InQueue element into queue \n3. DeQueue element from Queue \n4. Exit \nEnter your choice - ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                display(ptr);
                break;

            case 2:
                printf("Enter data - ");
                scanf("%d", &data);
                if(inQueue(ptr, data)){
                    printf("InQueued successfully !! \n");
                }
                break;
            
            case 3:
                data = deQueue(ptr);
                printf("%d", data);
                break;

            case 4:
                goto EXIT;
        }

    }

    EXIT : 
    printf("Program Terminated !!\n");
    deleteQueue(ptr);
    // display(ptr);

    return 0;
}