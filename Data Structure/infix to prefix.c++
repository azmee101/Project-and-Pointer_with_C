#include<bits/stdc++.h>
using namespace std;

#define MAX 20
int stuck[MAX];
int top = -1;
string prefix = "";

int prec(char a){
    if(a == '^' || a == '%') return 4;
    else if(a == '*' || a == '/') return 3;
    else if(a == '+' || a == '-') return 2;
    else return 1;
}
void push(char a){
    top += 1;
    stuck[top] = a;
}
char pop(){
    char temp = stuck[top];
    top -= 1;
    return temp;
}
bool empty(){
    if(top == -1) return true;
    else false; 
}
int main()
{
    string str;
    cout << "Enter your Infix expression: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    for(int i = 0; str[i]; i++){
        if(! ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))){

            if(str[i] == ')'){
                push(str[i]);
            }
            else if(str[i] == '('){
                while(stuck[top] != ')'){
                    char temp = pop();
                    prefix += " ";
                    prefix += temp;
                }
                pop();
            }
            else{
                if(top == -1){
                    push(str[i]);
                    continue;
                }
                while(prec(stuck[top]) > prec(str[i])){
                    char temp = pop();
                    prefix += " ";
                    prefix += temp;
                }
                push(str[i]);
            }
        }
        else{
            prefix += " ";
            prefix+= str[i];
        }
    }
    while(!empty()){
        if(stuck[top] != ')'){
            char temp = pop();
            prefix += " ";
            prefix += temp;
        }
        else{
            pop();
        }
    }
    cout << prefix << endl;
    cout << endl;
    reverse(prefix.begin(), prefix.end());
    cout << prefix << endl;
    cout << endl;
    return 0;
}