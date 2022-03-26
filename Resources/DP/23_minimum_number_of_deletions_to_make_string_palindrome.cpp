#include <bits/stdc++.h>
using namespace std;

int LCS(string a, int n){
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    string b = a;
    reverse(b.begin(), b.end());

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int j = 0; j <= n; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return (n - dp[n][n]);
}

int main(){
    string a;
    cin >> a;
    int n = a.size();
    cout << "Minimum number of deletions to make string palindrome is " << LCS(a, n);
}