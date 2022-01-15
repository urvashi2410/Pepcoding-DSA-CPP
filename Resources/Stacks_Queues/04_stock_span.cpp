#include<bits/stdc++.h>
using namespace std;

vector<int> span(int* arr, int n){
    stack<int>s;
    vector<int>ans(n);
    s.push(0);
    ans[0] = 1;
    
    for(int i = 1; i < n; i++){
        while(s.size() > 0 && arr[i] > arr[s.top()]){
            s.pop();
        }
        
        // agar ise nhi mila isse koi bda isse pehle stack me to ans hoga index + 1 otherwise ans hoga doori
        if(s.size() == 0){
            ans[i] = i + 1;
        }
        else{
            ans[i] = i - s.top();
        }
        s.push(i);
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
    vector<int>ans = span(arr, n);
    
    for(int i : ans){
        cout << i << endl;
    }
}