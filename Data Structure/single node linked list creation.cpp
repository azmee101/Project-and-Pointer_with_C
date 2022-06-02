#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *creat_node(int item, Node *n){
    // n will capture the address of next node which is after the "new node"
    // , so it's a commonsence that we have to creat it's data type as Node
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    //allocating the memory for the new node which takes the siz of "Node"
    if(new_node == NULL){
        cout << "The memory allocated request could'nt gererated successfully" << endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next = n;
    return new_node;
}

int32_t main()
{
    Node *n;
    // n will capture a new node's address, we denote n as head
    int item; cin >> item;
    n = creat_node(item, NULL);
    // this function returns a address of a new making node
    cout << n->data <<" "<< n->next << endl;
    return 0;
}