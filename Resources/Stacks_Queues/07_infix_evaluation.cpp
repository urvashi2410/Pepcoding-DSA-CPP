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

int operation(int val1, int val2, char op){
    if(op == '+'){
        return val1 + val2;
    }
    else if(op == '-'){
        return val1 - val2;
    }
    else if(op == '*'){
        return val1 * val2;
    }
    else{
        return val1 / val2;
    }
}
int main(){
    string exp;
    cin >> exp;
    
    stack<int> operands;
    stack<char> operators;
    
    int len = exp.length();
    for(int i = 0; i < len; i++){
        char ch = exp[i];
        
        if(ch == '('){
            operators.push(ch);
        }
        else if(isdigit(ch)){
            operands.push(ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // pehle apne se upr ki precedence walo ko solve kra rha h
            while(operators.size() > 0 && operators.top() != '(' && precedence(ch) <= precedence(operators.top())){
                
                int val2 = operands.top();
                operands.pop();
                int val1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int opval = operation(val1, val2, op);
                operands.push(opval);
                
            }
            
            // ab jaake khud push hua h
            operators.push(ch);
        }
        
        
        else if(ch == ')'){
            while(operators.size() > 0 && operators.top() != '('){
                int val2 = operands.top();
                operands.pop();
                int val1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int opval = operation(val1, val2, op);
                operands.push(opval);
            }
            
            if(operators.size() > 0){
                operators.pop();
            }
        }
    }
    
    while(operators.size() > 0){
        int val2 = operands.top();
        operands.pop();
        int val1 = operands.top();
        operands.pop();
        char op = operators.top();
        operands.pop();
        
        int opval = operation(val1, val2, op);
        
        operands.push(opval);
    }
    
    int val = operands.top();
    cout << val << endl;
}