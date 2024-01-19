#include<bits/stdc++.h>
#define MAX 10
using namespace std;

typedef struct{
    int top;
    int data[MAX];
}Stack;

int peek(Stack *s){

    return s->data[s->top - 1];
}

bool empty(Stack *s){
    if(s->top == 0) return true;
    return false;
}

bool full(Stack *s){
    if(s->top == MAX) return true;
    return false;
}

void push(Stack *s, int temp){
    if(full(s))
        cout << "The Stack is full" << endl;
    else{
        s->data[s->top] = temp;
        s->top += 1;
    }
    return;
}

int pop(Stack *s){
    int temp = 0;
    if(empty(s))
        cout << "The Stack is empty" << endl;
    else{
        s->top -= 1;
        temp = s->data[s->top];
    }
    return temp;
}

int main()
{
    int n;
    Stack my_stack, *p;
    p = &my_stack;
    p->top = 0;
    do{
        cout << "1 to see peek value\n2 to check if the stack is empty or not\n3 to check if the stack is full or not\n4 to push value\n5 to pop value\n6 to see the containts of stack\n7 to clear screen\n0 to exit the system" << endl;
        cout << "Enter your choice: "; cin >> n;
        switch(n){
            case 1:{
                int temp = peek(p);
                cout << "Peek value: " << temp << endl;
                break;
            }
            case 2:{
                if(empty(p))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            }
            case 3:{
                if(full(p))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            }
            case 4:{
                int temp;
                cout << "Enter a value: "; cin >> temp;
                push(p, temp);
                break;
            }
            case 5:{
                int temp = pop(p);
                cout << "POPED: " << temp << endl;
                break;
            }
            case 6:{
                for(int i = p->top-1; i >= 0; i--)
                    cout << p->data[i] << " ";
                cout << endl;
                break;
            }
            case 7:{
                system("clear");
                break;
            }
            case 0:{
                break;
            }
        }
    }while(n != 0);
    return 0;
}

/*

 complexity
 insertion [push()] and delation [pop()] = O(1)

*/
