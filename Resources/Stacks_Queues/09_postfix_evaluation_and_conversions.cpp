#include <bits/stdc++.h>
using namespace std;

int operation(int v1, int v2, char op){
    if(op == '+'){
        return v1 + v2
;    }
    else if(op == '-'){
        return v1 - v2;
    }
    else if(op == '*'){
        return v1 * v2;
    }
    else{
        return v1 / v2;
    }
}

int main(){
    string exp;
    cin >> exp;
    
    stack<int> value;
    stack<string> infix;
    stack <string> prefix;
    
    for(int i = 0; i < exp.size(); i++){
        char ch = exp[i];
        
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int v2 = value.top();
            value.pop();
            int v1 = value.top();
            value.pop();
            int val = operation(v1, v2, ch);
            
            value.push(val);
            
            string inv2 = infix.top();
            infix.pop();
            string inv1 = infix.top();
            infix.pop();
            string inv = "(" + inv1 + ch + inv2 + ")";
            infix.push(inv);
            
            string prev2 = prefix.top();
            prefix.pop();
            string prev1 = prefix.top();
            prefix.pop();
            string prev = ch + prev1 + prev2;
            prefix.push(prev);
        }
        
        else{
            value.push(ch - '0');
            infix.push(ch + "");
            prefix.push(ch + "");
        }
    }
    
    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout << prefix.top() << endl;
}