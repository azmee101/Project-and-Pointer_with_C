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
        cout << "Memory allocation request could not be completed" << endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next = n;
    return new_node;
}

Node *pretend(int item, Node *n){
    Node *new_node = creat_node(item, n);
    return new_node;
}

void print_linked_list(Node *n){
    Node *current_node = n;
    while(current_node != NULL){
        cout << "Item : " << current_node->data << endl;
        current_node = current_node->next;
    }
    return;
}

int main()
{
    Node *n1, *n2, *head;
    n1 = creat_node(10, NULL);
    head = n1;
    n2 = pretend(20, head);
    head = n2;
    print_linked_list(head);
    return 0;
}