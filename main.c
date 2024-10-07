#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main(){
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    Node* node5 = createNode(0);
    link(head, node1);
    link(node1, node2);
    link(node2, node3);
    link(node3, node4);
    link(node4, node5);
    printf("\nLength of linked list = %d", length(node2));

    printf("\nForward Traversal = ");
    forwardTraversal(head);

    printf("\nBackward Traversal = ");
    backwardTraversal(node5);

    append(head, 10);
    append(head, 11);
    append(head, 12);
    printf("\nUpdation (append) = ");
    forwardTraversal(head);

    RemoveBegin(node2);
    printf("\nRemove Begin = ");
    forwardTraversal(head);
    RemoveEnd(node3);
    printf("\nRemove End = ");
    forwardTraversal(head);

    RemoveN(head, 4);
    printf("\nRemove N = ");
    forwardTraversal(head);

    Insert(head, 13, 4);
    printf("\nInsertion = ");
    forwardTraversal(head);

    return 0;
}