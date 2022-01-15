#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    if(n == 0 || k == 0 || n < k){
        cout << 0 << endl;
    }
    
    long dp[k + 1][n + 1];
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            if(i == 1 || j == 1 || i == j){
                dp[i][j] = 1;
            }
            
            else{
                dp[i][j] = dp[i - 1][j - 1] + i * dp[i][j - 1];
            }
        }
    }
    
    cout << dp[k][n] << endl;
}