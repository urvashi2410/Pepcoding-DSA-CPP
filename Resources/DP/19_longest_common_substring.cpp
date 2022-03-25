#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string a, string b, int n, int m){
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
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
    cout << longestCommonSubstring(a, b, n, m);
}