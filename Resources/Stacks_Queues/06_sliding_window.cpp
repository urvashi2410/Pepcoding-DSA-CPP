#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // k is the length of the window
    int k;
    cin >> k;
    
    // array to store index of next greater element of every element
    int nge[n];
    
    stack<int>s;
    s.push(n - 1);
    nge[n - 1] = n;
    
    // pop kro jb tk smaller h stack me or then agar stack khali mtlb next greater h hi nhi koi 
    // to last index ko bhrdo(infinity jaise) or agar stack me h kuch bda to use ans me
    // bhro or last me is element ko bhi bhrdo kyunki ye bhi kisi ka  next greater ho skta hna
    for(int i = n - 2; i >= 0; i--){
        while(s.size() > 0 && arr[i] >= arr[s.top()]){
            s.pop();
        }
        
        if(s.size() == 0){
            nge[i] = n;
        }
        else{
            nge[i] = s.top();
        }
        
        s.push(i);
    }
    
    int j = 0;
    
    // n - k tk kyunki i me hum store kr rhe hn hr ek window ka starting index or last window ka starting index hoga n - k.
    for(int i = 0; i <= n - k; i++){
        if(j < i){
            j = i;
        }
        
        // if next greater element window k andr pd rha h tb usi ka index store krdo
        while(nge[j] < i + k){
            j = nge[j];
        }
        
        cout << arr[j] << endl;
    }
}