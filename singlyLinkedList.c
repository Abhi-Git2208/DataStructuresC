#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList node;

// Creates a linked list for the given datatype - in this case float
typedef float datatype;

struct linkedList
{
    datatype data;
    node* next;
};

// Creates a Node
node* createNode(datatype data){
    node* new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Appends a Node at the end of the linked list
void append(node* head, datatype data){
    node* curr = head;
    node* new = createNode(data);
    while(curr->next != NULL){
        curr = curr->next;
    }
    if(curr->next == NULL){
        curr->next = new;
        new->next = NULL;
    }
}

// Finds the node previous to the required location
static int findprevious(node** head, int pos){
    for(int i = 0; i < pos - 1; i++){
        if(NULL == (*head)->next){
            return 0;
        }
        (*head) = (*head)->next;
    }
    return 1;
}

// Removes the node at the end
int Remove(node* head){
    node* curr = head;
    if(curr->next == NULL){
        free(curr);
        return 0;
    }
    while((curr->next)->next != NULL){
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return 1;
}

// Removes the node at the Nth spot
int RemoveN(node* head, int pos){
    node* temp;
    if(! findprevious(&head, pos)){
        printf("\n Error : Position of node out of bounds !!");
        return 0;
    }
    temp = (head->next)->next;
    free(head->next);
    head->next = temp;
    return 1;
}

// Displays the entire linked list
int Print(node* head){
    while(head->next != NULL){
        printf("|%f -> ", head->data);
        head = head->next;
    }
    if(head->next == NULL){
        if(head->data){
            printf("|%f \n", head->data);
        }
        else{
            printf("Error : Invalid value for node !!");
            return 0;
        }
    }
    return 1;
}

// Inserts new node at the required position
int Insert(node* head, datatype data, int pos){
    if(pos < 0){
        printf("\nError : Position out of bounds !!");
        return 0;
    }
    
    node* new = createNode(data);
    
    if(pos == 0){
        printf("in\n");
        float temp;
        new->next = head->next;
        temp = head->data;
        head->data = new->data;
        head->next = new;
        new->data = temp;
    }

    else if(! findprevious(&head, pos)){
        head->next = new;
    }
    else{
        node* temp = head->next;
        head->next = new;
        new->next = temp;
    }
    return 1;
    
}
