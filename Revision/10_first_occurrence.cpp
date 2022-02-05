#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int* A, int n, int x, int idx){
    if(idx == n){
        return -1;
    }

    if(A[idx] == x){
        return idx;
    }

    return firstOccurrence(A, n, x, idx+1);
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int x;
    cin >> x;
    cout << firstOccurrence(A, n, x, 0);
}