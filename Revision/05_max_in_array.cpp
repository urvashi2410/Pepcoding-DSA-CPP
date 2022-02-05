#include <bits/stdc++.h>
using namespace std;

int maxArray(int* A, int n){
    if(n == 1){
        return A[0];
    }

    int smallAns = maxArray(A, n-1);
    int end = A[n-1];
    int maxi = max(end, smallAns);
    return maxi;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << maxArray(A, n);
}