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
        cout << "The memory allocating request could not be generated successfully" << endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next= n;
    return new_node;
}

Node *append(int item, Node *head){
    Node *new_node = creat_node(item, head);
    if(new_node == NULL){
        return new_node;
    }
    Node *current_node = head;
    while(current_node != NULL){
        current_node = current_node->next;
    }
    current_node = new_node;
    return current_node;
}

void printlist(Node *n){
    Node *current_node = n;
    while(current_node != NULL){
        cout << "Data part: " << current_node->data << endl;
        current_node = current_node->next;
    }
    return;
}

int main()
{
    Node *n1, *head, *n2, *n3;
    int item1, item2, item3;
    cin >> item1;
    n1 = creat_node(item1, NULL);
    head = n1;
    cin >> item2;
    n2 = creat_node(item2, NULL);
    n1->next = n2;
    printlist(head);
    cout << "Enter the data item of your new node: ";
    cin >> item3;
    n3 = append(item3, head);
    n2->next = n3;
    n3->next = NULL;
    printlist(head);
    return 0;
}