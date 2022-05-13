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

    priority_queue<int>maxh;
    for(int i = 0; i < n; i++){
        maxh.push(A[i]);
        if(maxh.size() > k){
            maxh.pop();
        }
    }
    cout << maxh.top();
    return 0;
}