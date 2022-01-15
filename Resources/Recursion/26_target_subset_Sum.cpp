#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(int *arr, int idx, string set, int sos, int tar, int n) {
    if(idx == n){
        if(sos == tar){
            cout << set << endl;
        }
        return;
    }
    printTargetSumSubsets(arr, idx + 1, set, sos, tar, n);
    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + " ", sos + arr[idx], tar, n);
}


int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int tar;
    cin >> tar;
    printTargetSumSubsets(A, 0, "", 0, tar, n);
    return 0;
}