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
    
    int* diff = new int[n2];
    
    int i = n1 - 1;
    int j = n2 - 1;
    int k  = n2 - 1;
    int carry = 0;
    
    while(k >= 0){
        int ivalue = (i >= 0)? a1[i] : 0;
        
        if(a2[j] + carry >= ivalue)
        {
            diff[k] = a2[j] + carry - ivalue;
            carry = 0;
        }
        else{
            diff[k] = a2[j] + carry + 10 - ivalue;
            carry = -1;
        }
        i--; j--; k--;
    }
    
    int index  = 0;
    while(index < n2){
        if(diff[index] != 0){
            break;
        }
        else{
            index++;
        }
    }
    
    while(index < n2){
        cout << diff[index] << endl;
        index++;
    }
    
}