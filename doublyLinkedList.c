#include <stdio.h>
#include <stdlib.h>

// Creates a doubly linked list for the given datatype - in this case unsigned char
typedef unsigned char datatype;
typedef struct linkedList Node;

struct linkedList{
    datatype data;
    Node* next;
    Node* previous;
};

// Creates a Node
Node* createNode(datatype data){
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->previous = NULL;
    new_node->next = NULL;
    return new_node;
}

// Appends a Node at the end of the linked list
void append(Node* head, datatype data){
    Node* curr = head;
    Node* new = createNode(data);
    while(curr->next != NULL){
        curr = curr->next;
    }
    if(curr->next == NULL){
        curr->next = new;
        new->next = NULL;
        new->previous = curr;
    }
}

void forwardTraversal(Node* head){
    Node* curr = head;
    while(curr->next != NULL){
        printf("%d - ", curr->data);
        curr = curr->next;
    }
    if(curr->next == NULL){
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void backwardTraversal(Node* head){
    Node* curr = head;
    while(curr->previous != NULL){
        printf("%d - ", curr->data);
        curr = curr->previous;
    }
    if(curr->previous == NULL){
        printf("%d", curr->data);
        curr = curr->previous;
    }
    printf("\n");
}

// Returns the length of the linked list given any node
int length(Node* node){
    Node* curr = node;
    int count_up = 0, count_down = 0;

    while(curr->next != NULL){
        curr = curr->next;
        count_up += 1;
        // printf("Up %d, data %d\n", count_up, curr->data);
    }
    curr = node;
    while(curr->previous != NULL){
        curr = curr->previous;
        count_down += 1;
        // printf("Down %d, data %d\n", count_down, curr->data);
    }
    return(count_up + count_down + 1);
}

// Removes the last node
int RemoveEnd(Node *node){
    if(node->next == NULL){
        free(node);
        return 0;
    }
    while((node->next)->next != NULL){
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
    return 1;
}

// Removes the 1st node
int RemoveBegin(Node* node){
    while((node->previous)->previous != NULL){
        node = node->previous;
    }
    (node->previous)->next = node->next;
    node->previous->data = node->data;
    (node->next)->previous = node->previous;
    free(node);
    return 1;
}

// Removes the node at the Nth position
int RemoveN(Node* head, int pos){
    Node* temp;
    if(head->previous != NULL){
        printf("\nThis is not head pointer !!");
        return -1;
    }
    if(pos == 0){
        return RemoveBegin(head);
    }
    if(pos == length(head)){
        return RemoveEnd(head);
    }
    for(int i = 0; i < pos; i++){
        if(head->next == NULL){
            printf("\nThe specified position doesn't exist !!");
            return 0;
        }
        head = head->next;
    }
    if(head->next == NULL){
        (head->previous)->next = NULL;
    }else{
        (head->previous)->next = head->next;
        (head->next)->previous = head->previous;
        free(head);
    }
    return 1;
}

// Links 2 nodes with node1 being the 1st and node2 being the 2nd
void link(Node* node1, Node* node2){
    node1->next = node2;
    node2->previous = node1;
}

int Insert(Node* head, datatype data, int pos){
    if(head->previous != NULL){
        printf("\nError : Required head Node");
        return -1;
    }
    if(pos < 0 || pos > length(head)){
        printf("\nError : Position out of bounds!!");
        return 0;
    }

    Node* new = createNode(data);

    if(pos == 0){
        datatype temp;
        new->next = head->next;
        temp = head->data;
        head->data = new->data;
        head->next = new;
        new->data = temp;
        new->previous = head;
    }

    else{
        for(int i = 0; i < pos - 1; i++){
            head = head->next;
        }
        new->next = head->next;
        (head->next)->previous = new;
        new->previous = head;
        head->next = new;
    }
    return 1;
}