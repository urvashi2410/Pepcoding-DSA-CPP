#include <bits/stdc++.h>
using namespace std;

int climbStairsMinMoves(int A[], int n){
    int dp[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = NULL;
    }
    dp[n] = 0;

    for(int i = (n-1); i >= 0; i--){
        if(A[i] > 0){
            int mini = INT_MAX;
            for(int j = 1; j <= A[i] && i+j <= n; j++){
                if(dp[i+j] != NULL){
                    mini = min(mini, dp[i+j]);
                }
            }

            if(mini != INT_MAX){
                dp[i] = 1 + mini;
            }
            else{
                dp[i] = 0;
            }
        }
    }
    return dp[0];
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << climbStairsMinMoves(A, n);
    return 0;
}