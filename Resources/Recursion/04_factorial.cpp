#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    
    int fact = factorial(n - 1);
    
    return n * fact;
    
}


int main(){
    int n; cin>>n;
    cout<<factorial(n);
}
