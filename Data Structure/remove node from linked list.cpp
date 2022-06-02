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
        cout << "The memory allocating request could not be successfully generated" << endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next = n;
    return new_node;
}

void printlist(Node *head){

    Node *current_node = head;
    while(current_node != NULL){
        cout << "DATA: "<< current_node->data << endl;
        current_node = current_node->next;
    }
    return;
}

Node *find_node(Node *head, int pos){

    Node *current_node = head;
    int cnt = 1; // because current node is pointing the 1st node of the linked list initially
    while(current_node != NULL){
        if(cnt == pos){
            break;
        }
        current_node = current_node->next;
        cnt++;
    }
    return current_node;
}

Node *remove_node(Node *head, Node *node){

    //it's mean i want to delet the node
    if(node == head){
        head = node->next;
        free(node);
        return head;
    }
    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node == NULL){
        // i dont find the removal node (parameter "node")
        return head;
    }
    current_node->next = node->next;
    free(node);
    return head;
}

int main()
{
    Node *n1, *n2, *n3, *head, *rmv;
    int item1, item2, item3, pos;
    cin >> item1;
    n1 = creat_node(item1, NULL);
    head = n1;
    cin >> item2;
    n2 = creat_node(item2, NULL);
    n1->next = n2;
    cin >> item3;
    n3 = creat_node(item3, NULL);
    n2->next = n3;
    printlist(head);
    cout << "Enter the position of the node that you want to remove: ";
    cin >> pos;
    rmv = find_node(head, pos);
    head = remove_node(head, rmv);
    cout << "After removing the node" << endl;
    printlist(head);
    return 0;
}