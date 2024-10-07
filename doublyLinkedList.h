
typedef struct linkedList Node;
typedef unsigned char datatype;

struct linkedList{
    datatype data;
    Node* next;
    Node* previous;
};

Node* createNode(datatype data);

void forwardTraversal(Node* head);

void backwardTraversal(Node* head);

void link(Node* node1, Node* node2);

int length(Node* node);

void append(Node* head, datatype data);

int RemoveEnd(Node *node);

int RemoveBegin(Node* node);

int RemoveN(Node* head, int pos);

int Insert(Node* head, datatype data, int pos);