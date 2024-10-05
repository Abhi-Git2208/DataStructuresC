#include <stdio.h>
#include <stdlib.h>

#include "singlyLinkedList.h"

int main(){
    node* head = createNode(1.2f);
    // printf("%f", head->data);
    Print(head);
    append(head, 2.3f);
    append(head, 3.4f);
    append(head, 4.5f);
    append(head, 4.7f);

    // printf("\n%f", (head->next)->data);
    Print(head);

    Remove(head);
    Print(head);
    Insert(head, 5.6f, 3);
    Print(head);
    RemoveN(head, 2);
    Insert(head, 10.0f, 0);
    // Insert(head, 6.7f, 3);

    Print(head);

    return 0;
}
