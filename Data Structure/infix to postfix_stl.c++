#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vector vector<char>
#define stack stack<char>
using namespace std;

int prec(char a){
    if(a == '%' || a == '^') return 4;
    else if(a == '*' || a == '/') return 3;
    else if(a == '+' || a == '-') return 2;
    else return 1;
}

int32_t main()
{
    stack s;
    vector vec;
    cout << "Enter the infix  operator: ";
    string str;
    cin >> str;
    for(int i = 0; str[i]; i++){
        if(! ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))){
            if(str[i] == '('){
                s.push(str[i]);
            }
            else if(str[i] == ')'){
                while(s.top() != '('){
                    vec.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            else{
                if(s.top() == '\0'){
                    s.push(str[i]);
                    continue;
                }
                while(prec(s.top()) >= prec(str[i])){
                    vec.push_back(s.top());
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        else{
            vec.push_back(str[i]);
        }
    }
    while(!s.empty()){
        if(s.top() != '('){
            vec.push_back(s.top());
            s.pop();
        }
        s.pop();
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
    cout << endl;
    return 0;
}