#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *creat_node(int item, Node *n){
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    if(new_node == NULL){
        cout << "you know what is happining!" << endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next = n;
    return new_node;
}

void printlist(Node *n){
    Node *current_node = n;
    while(current_node != NULL){
        cout << "Data: " << current_node->data << endl;
        current_node = current_node->next;
    }
    return;
}

void insert(int item, Node *n){
    Node *new_node = creat_node(item, n->next);
    n->next = new_node;
    return;
}

int main()
{
    Node *n1, *head, *n2, *n3, *n4;
    int item1, item2, item3, item4;
    cin >> item1;
    n1 = creat_node(item1, NULL);
    head = n1;
    cin >> item2;
    n2 = creat_node(item2, NULL);
    n1->next = n2;
    cin >> item3;
    n3 = creat_node(item3,NULL);
    n2->next = n3;
    printlist(head);
    cout << "Enter the data item of your new node: "; cin >> item4;
    insert(item4, n1); // here i want to add the new node after n1 node
    printlist(head);
    return 0;
}