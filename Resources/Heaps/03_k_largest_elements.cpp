#include <bits/stdc++.h>
using namespace std;

vector<int>kth_largest(int A[], int n, int k){
    priority_queue<int, vector<int>, greater<int>>minh;

    for(int i = 0; i < n; i++){
        minh.push(A[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }

    vector<int>v;
    while(!minh.empty()){
        int top = minh.top();
        minh.pop();
        v.push_back(top);
    }
    return v;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int k;
    cin >> k;

    vector<int>ans = kth_largest(A, n, k);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}