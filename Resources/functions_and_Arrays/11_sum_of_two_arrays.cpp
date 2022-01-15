#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1;
    int* a1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>a1[i];
    }
    
    cin>>n2;
    int* a2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>a2[i];
    }
    
    int m = n1 > n2 ? n1 : n2;
    int* sum = new int[m];
    
    int i = n1 - 1;
    int j = n2 - 1;
    int k  = m - 1;
    int carry = 0;
    
    while(k >= 0){
        int digit = carry;
        if(i >= 0){
            digit += a1[i];
        }
        
        if(j >= 0){
            digit += a2[j];
        }
        
        int quotient = digit / 10;
        int rem = digit % 10;
        
        sum[k] = rem;
        carry = quotient;
        
        i--; j--; k--;
    }
        if(carry > 0){
            cout << carry << endl;
        }
        
        for(int i = 0; i < m; i++){
            cout << sum[i] << endl;
        }
    
}