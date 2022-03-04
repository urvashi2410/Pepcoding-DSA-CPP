#include <bits/stdc++.h>
using namespace std;

int profit(int A[], int i, int j, int p, vector<vector<int>>&dp){
    if(i > j){
        return 0;
    }

    if(dp[i][j] != 0){
        return dp[i][j];
    }

    int choice1 = A[i]*p + profit(A, i+1, j, p+1, dp);
    int choice2 = A[j]*p + profit(A, i, j-1, p+1, dp);
    dp[i][j] = max(choice1, choice2);
    return max(choice1, choice2);
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    vector<vector<int>>dp(n, vector<int>(n, 0));
    cout << profit(A, 0, n-1, 1, dp);
}