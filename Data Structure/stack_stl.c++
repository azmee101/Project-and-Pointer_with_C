#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vector vector<int>
using namespace std;


int32_t main()
{
    cout << "1 to see peek value\n2 to check if the stack is empty or not\n3 to push value\n4 to pop value\n5 to see the containts of stack(the stack would be empty, though there is no direct way in C++ to accessing stack randomly(without accessing top))\n0 to exit the system" << endl;
    stack<int> s;
    int n;
    cin >> n;
    while(true){
        switch(n){
            case 1:{
                if(s.empty()){
                    cout << "The stack is empty" << endl;
                }
                else{
                    cout << s.top() << endl;
                }
                cout << "Enter again: "; cin >> n;
                break;
            }
            case 2:{
                if(s.empty()){
                    cout << "The stack is empty" << endl;
                }
                else{
                    cout << "The stack is not empty, it's size : " << s.size() << endl;
                }
                cout << "Enter again: "; cin >> n;
                break;
            }
            case 3:{
                cout << "Enter a value: ";
                int temp; cin >> temp;
                s.push(temp); // stack acts dynamically in C++, so need to check any condition
                cout << "Enter again: "; cin >> n;
                break;
            }
            case 4:{
                if(s.empty()){
                    cout << "No value exist in stack" << endl;
                }
                else{
                    s.pop();
                }
                cout << "Enter again: "; cin >> n;
                break;
            }
            case 5:{
                while(!s.empty()){
                    cout << s.top() << " ";
                    s.pop();
                }
                cout << endl;
                cout << "Enter again: "; cin >> n;
                break;
            }
            case 0:{
                return 0;
            }
            default:{
                cout << "Wrong Keyword!" << endl;
                cout << "Enter again: "; cin >> n;
                break;
            }
        }
    }
    return 0;
}