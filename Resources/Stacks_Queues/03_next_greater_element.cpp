#include<bits/stdc++.h>
using namespace std;

vector<int> NGER(int* arr, int n){
    stack<int>s;
    vector<int>ans(n);
    
    ans[n - 1] = -1;
    s.push(arr[n - 1]);
    
    // every number will do three things:
    // 1. pop all the smaller numbers already present in the array
    // 2. print the ans which will be the greatest at the top
    // 3. push itself in the stack as it can be the greatest for some other number
    
    for(int i = n - 2; i >= 0; i--){
        while(s.size() > 0 && arr[i] >= s.top()){
            s.pop();
        }
    
        if(s.size() > 0){
            ans[i] = s.top();
        }
        else{
            ans[i] = -1;
        }
        s.push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int>ans = NGER(arr, n);
    
    for(int i : ans){
        cout << i << endl;
    }
}