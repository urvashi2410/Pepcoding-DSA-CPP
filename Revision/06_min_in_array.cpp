#include <bits/stdc++.h>
using namespace std;

int minArray(int* A, int n){
    if(n == 1){
        return A[0];
    }

    int smallAns = minArray(A, n-1);
    int end = A[n-1];
    int mini = min(end, smallAns);
    return mini;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << minArray(A, n);
}