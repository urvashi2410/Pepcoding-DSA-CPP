#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    vector<int>dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1]*i;
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << fact(n);
}