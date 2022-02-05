#include <bits/stdc++.h>
using namespace std;

int lastOccurrence(int* A, int n, int x, int idx){
    if(idx < 0){
        return -1;
    }

    if(A[idx] == x){
        return idx;
    }

    return lastOccurrence(A, n, x, idx-1);
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
    cout << lastOccurrence(A, n, x, n-1);
}