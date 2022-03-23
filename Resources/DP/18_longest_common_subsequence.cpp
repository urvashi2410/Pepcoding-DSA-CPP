#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }

    if(a[n-1] == b[m-1]){
        return 1 + lcs(a, b, n-1, m-1);
    }

    return max(lcs(a, b, n-1, m), lcs(a, b, n, m-1));
}

int lcsMemorisation(string a, string b, int n, int m, vector<vector<int>>dp){
    if(n == 0 || m == 0){
        return 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(a[n-1] == b[m-1]){
        dp[n][m] = 1 + lcsMemorisation(a, b, n-1, m-1, dp);
        return dp[n][m];
    }

    dp[n][m] = max(lcsMemorisation(a, b, n-1, m, dp), lcsMemorisation(a, b, n, m-1, dp));
    return dp[n][m];
}


int lcsTopDown(string a, string b, int n, int m){
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    int n = a.size();
    int m = b.size();

    // vector<vector<int>>dp(n+1, vector<int>(m+1));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         dp[i][j] = -1;
    //     }
    // }

    // cout << lcsMemorisation(a, b, n, m, dp) << endl;

    cout << lcsTopDown(a, b, n, m) << endl;
    return 0;
}