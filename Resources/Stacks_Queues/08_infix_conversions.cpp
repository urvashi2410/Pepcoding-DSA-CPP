#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '+'){
        return 1;
    }
    else if(op == '-'){
        return 1;
    }
    else if(op == '*'){
        return 2;
    }
    else{
        return 2;
    }
}

int main(){
    string exp;
    cin >> exp;
    
    stack<string>post;
    stack<string>pre;
    stack<char>operators;
    
    int len = exp.size();
    for(int i = 0; i < len; i++){
        char ch = exp[i];
        
        if(ch == '('){
            operators.push(ch);
        }
        
        else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')){
            post.push(ch + "");
            pre.push(ch + "");
        }
        
        else if(ch == ')'){
            while(operators.size() > 0 && operators.top() != '('){
                char op = operators.top();
                operators.pop();
                
                string postval2 = post.top();
                post.pop();
                string postval1 = post.top();
                post.pop();
                
                post.push(postval1 + postval2 + op);
                
                string preval2 = pre.top();
                pre.pop();
                string preval1 = pre.top();
                pre.pop();
                
                pre.push(op + preval1 + preval2);
            }
            
            if(operators.size() > 0){
                operators.pop();
            }
        }
        
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(operators.size() > 0 && operators.top() != '(' && precedence(ch) <= precedence(operators.top())){
                char op = operators.top();
                operators.pop();
                
                string postval2 = post.top();
                post.pop();
                string postval1 = post.top();
                post.pop();
                
                post.push(postval1 + postval2 + op);
                
                string preval2 = pre.top();
                pre.pop();
                string preval1 = pre.top();
                pre.pop();
                
                pre.push(op + preval1 + preval2);
            }
            
            operators.push(ch);
        }
    }
    
    while(operators.size() > 0){
        char op = operators.top();
        operators.pop();
        
        string postval2 = post.top();
        post.pop();
        string postval1 = post.top();
        post.pop();
                
        post.push(postval1 + postval2 + op);
                
        string preval2 = pre.top();
        pre.pop();
        string preval1 = pre.top();
        pre.pop();
                
        pre.push(op + preval1 + preval2);
    }
    
    cout << post.top() << endl;
    cout << pre.top() << endl;
}
