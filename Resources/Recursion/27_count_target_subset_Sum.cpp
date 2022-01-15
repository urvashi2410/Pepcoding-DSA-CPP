#include <bits/stdc++.h>
using namespace std;

int countTargetSubsetSum(int *A, int n, int sum, int tar, int idx, int count){
    if(idx == n){
        if(sum == tar){
            count++;
        }
        return count;
    }
    count = countTargetSubsetSum(A, n, sum + A[idx], tar, idx + 1, count);
    count = countTargetSubsetSum(A, n, sum, tar, idx + 1, count);
    return count;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int tar;
    cin >> tar;
    int count = countTargetSubsetSum(A, n, 0, tar, 0, 0);
    cout << count << endl;
}