
// #ifndef __TEST__

typedef struct linkedList node;

// Creates a linked list for the given datatype - in this case float
typedef float datatype;

struct linkedList{
    datatype data;
    node* next;
};

// Creates a Node
node* createNode(datatype data);

// Appends a Node at the end of the linked list
void append(node* head, datatype data);

// Removes the node at the Nth spot
int RemoveN(node* head, int pos);

// Removes the node at the end
int Remove(node* head);

// Displays the entire linked list
int Print(node* head);

// Inserts new node at the required position
int Insert(node* head, datatype data, int pos);

// #endif