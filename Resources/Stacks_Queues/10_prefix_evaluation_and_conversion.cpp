#include <bits/stdc++.h>
using namespace std;

int operation(int v1, int v2, char op){
   if(op == '+'){
       return v1 + v2;
   } 
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
    stack<string> postfix;
    
    for(int i = exp.size() - 1; i >= 0; i--){
        char ch = exp[i];
        
        if(ch == '-' || ch == '+' || ch == '*' || ch == '/'){
            int v1 = value.top();
            value.pop();
            int v2 = value.top();
            value.pop();
            int val = operation(v1, v2, ch);
            value.push(val);
            
            string inv1 = infix.top();
            infix.pop();
            string inv2 = infix.top();
            infix.pop();
            string inv = '(' + inv1 + ch + inv2 + ')';
            infix.push(inv);
            
            string postv1 = postfix.top();
            postfix.pop();
            string postv2 = postfix.top();
            postfix.pop();
            string postv = postv1 + postv2 + ch;
            postfix.push(postv);
        }
        
        else{
            value.push(ch - '0');
            infix.push(ch + "");
            postfix.push(ch + "");
        }
    }
    
    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout << postfix.top() << endl;
}