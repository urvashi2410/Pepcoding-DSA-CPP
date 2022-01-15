#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(int* arr, int n){
    stack<int>s;
    vector<int>ans(n);
    s.push(0);
    ans[0] = -1;
    
    for(int i = 1; i < n; i++){
        while(s.size() > 0 && arr[i] <= arr[s.top()]){
            s.pop();
        }
        
        if(s.size() == 0){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> NSR(int* arr, int n){
    stack<int>s;
    vector<int>ans(n);
    s.push(n - 1);
    ans[n - 1] = n;
    
    for(int i = n - 2; i >= 0; i--){
        while(s.size() > 0 && arr[i] <= arr[s.top()]){
            s.pop();
        }
        
        if(s.size() == 0){
            ans[i] = n;
        }
        else{
            ans[i] = s.top();
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
    vector<int>right = NSR(arr, n);
    vector<int>left = NSL(arr, n);
    
    int maximum = 0;
    for(int i = 0; i < n; i++){
        int width = right[i] - left[i] - 1;
        int area = width * arr[i];
        if(area > maximum){
            maximum = area;
        }
    }
    
    cout << maximum << endl;
}