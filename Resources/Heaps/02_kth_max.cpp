#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>>minh;
    for(int i = 0; i < n; i++){
        minh.push(A[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }
    cout << minh.top();
    return 0;
}