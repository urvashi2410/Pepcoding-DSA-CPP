#include <bits/stdc++.h>
using namespace std;

bool countSubsetWithPDiff(int A[], int n, int tar){
    int dp[n+1][tar+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int j = 0; j <= tar; j++){
        dp[0][j] = false;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= tar; j++){
            if(j > A[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][tar];
}

int main(){
    int n;
    cin >> n;
    int A[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }
    int diff;
    cin >> diff;

    int subset = (sum + diff)/2;
    if(countSubsetWithPDiff(A, n, subset)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}