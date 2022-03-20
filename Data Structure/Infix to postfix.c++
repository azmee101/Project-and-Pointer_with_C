#include<bits/stdc++.h>
using namespace std;

#define MAX 20
char stuck[MAX];
int top = -1;
string postfix = "";

int prec(char a){
    if(a == '^') return 4;
    else if(a == '*' || a == '/') return 3;
    else if(a == '+' || a == '-' || a == '%') return 2;
    else return 1;
}

bool empty(){
    if(top == -1) return true;
    else return false;
}

void push(char a){
    top += 1;
    stuck[top] = a;
}

char pop(){
    char a = stuck[top];
    top -= 1;
    return a;
}

int main()
{
    cout << "Enter your Infix expression: ";
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){

        if(! ((str[i] >= 97 && str[i] <=122) || (str[i] >= 65 && str[i] <= 90)) ){

            if(str[i] == '('){
                push(str[i]);
            }

            else if(str[i] == ')'){

                while(stuck[top] != '('){
                    char a = pop();
                    postfix += a;
                }
                pop();
            }
            //if any operator
            else{
                if(top == -1){
                    push(str[i]);
                    continue;
                }
                while(prec(stuck[top]) >= prec(str[i])){
                    char a = pop();
                    postfix += a;
                }
                push(str[i]);
            }
        }
        else{
            //if it is any alphabate
            postfix += str[i];
        }
    }
    while(!empty()){
        if(stuck[top] != '('){
            char a = pop();
            postfix += a;
        }
        else pop();
    }
    cout << endl;
    cout << postfix << endl;
    return 0;
}