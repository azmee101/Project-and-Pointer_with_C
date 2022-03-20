#include<bits/stdc++.h>
#define MAX 10
using namespace std;

typedef struct{
    int head, tail;
    int data[MAX];
}Queue;

bool empty(Queue *q){
    if(q->head == q->tail) return true;
    return false;
}

bool full(Queue *q){
    if(q->tail == MAX) return true;
    return false;
}

void enqueue(Queue *q, int temp){
    if(full(q))
        cout << "The queue is full!" << endl;
    else{
        q->data[q->tail] = temp;
        q->tail += 1;
    }
    return;
}

int dequeue(Queue *q){
    int temp = 0;
    if(empty(q))
        cout << "The queue is empty!" << endl;
    else{
        temp = q->data[q->head];
        q->data[q->head] = int(NULL); // optional(maybe), but I would do!
        q->head += 1;
    }
    return temp;
}

int peek(Queue *q){
    return q->data[q->head];
}

int main()
{
    Queue my_queue, *p;
    p = &my_queue;
    p->head = 0, p->tail = 0;
    int n;
    do{
        cout << "1 to check is the queue is empty or not\n2 is the queue is full or not\n3 for enqueue\n4 for dequeue\n5 to see the peek value\n6 to see the queue status\n7 to clear screen\n0 to exit the programm" << endl;
        cout << "Enter your choice: ";
        cin >> n;
        switch(n){
            case 1:{
                if(empty(p))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            }
            case 2:{
                if(full(p))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            }
            case 3:{
                int temp;
                cout << "Enter a number: ";
                cin >> temp;
                enqueue(p, temp);
                break;
            }
            case 4:{
                int temp = dequeue(p);
                cout << temp << " is Dequeued!" << endl;
                break;
            }
            case 5:{
                int temp = peek(p);
                cout << temp << " is the peek value." << endl;
                break;
            }
            case 6:{
                for(int i = 0; i < p->tail; i++)
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