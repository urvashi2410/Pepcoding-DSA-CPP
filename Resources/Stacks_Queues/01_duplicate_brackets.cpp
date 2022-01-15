#include<bits/stdc++.h>
using namespace std;

void duplicateBrackets(string str){
    stack<char>s;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ')'){
            // seedha hi opening bracket aa gya mtlb dupliate h
            if(s.top() == '('){
                cout << true << endl;
                return;
            }
            else{
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }
        }
        else{
            s.push(str[i]);
        }
    }
    cout << false << endl;
}

int main(){
    string str;
    cin >> str;
    
    duplicateBrackets(str);
}