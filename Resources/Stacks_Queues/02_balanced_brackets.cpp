#include<bits/stdc++.h>
using namespace std;

void balancedBrackets(string str){
    stack<char>s;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            // if stack is empty means open bracket km hn or agar top me opening nhi mila matching ka iska mtlb gadbad h balanced nhi h
            if(s.size() == 0 || s.top() != '('){
                cout << false << endl;
                return;
            }
            else{
                s.pop();
            }
        }
        else if(str[i] == '}'){
            if(s.size() == 0 || s.top() != '{'){
                cout << false << endl;
                return;
            }
            else{
                s.pop();
            }
        }
        else if(str[i] == ']'){
            if(s.size() == 0 || s.top() != '['){
                cout << false << endl;
                return;
            }
            else{
                s.pop();
            }
        }
    }
    
    if(s.size() == 0){
        cout << true << endl;
    }
    else{
        cout << false << endl;
    }
}

int main(){
    string str;
    cin >> str;
    
    balancedBrackets(str);
}