#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int MCM(int *A, int n, int i, int j){
    if(i >= j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int cost1 = MCM(A, n, i, k);
        int cost2 = MCM(A, n, k+1, j);
        int costMat = A[i-1]*A[k]*A[j];
        int totalCost = cost1 + cost2 + costMat;
        ans = min(ans, totalCost);
    }
    return ans;
}

int MCM_Memorised(int *A, int n, int i, int j){
    if(i >= j){
        return 0;
    }

    int dp[i][j] = INT_MAX;

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    for(int k = i; k < j; k++){
        dp[i][j] = min(MCM_Memorised(A, n, i, k)+ MCM_Memorised(A, n, k, j)+ A[i-1]*A[k]*A[j], dp[i][j]);
    }

    return dp[i][j];
}

int MCM_TopDown(int *A, int n, int i, int j){
    if(i >= j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for(int k = i; k < j; k++){
        int left;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = MCM_TopDown(A, n, i, k);
            dp[i][k] = left;
        }

        int right;
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else{
            right = dp[k+1][j];
            dp[k+1][j] = right;
        }
        int mul = A[i-1]*A[k]*A[j];
        int temp = left + right + mul;
        dp[i][j] = min(dp[i][j], temp);
    }
    return dp[i][j];
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << MCM_TopDown(A, n, 1, n-1) << endl;
}