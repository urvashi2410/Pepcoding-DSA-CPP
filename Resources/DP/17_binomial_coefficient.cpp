#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int r){
    int m = pow(10, 9) + 7;
    if(r > n){
        return 0;
    }

    int dp[n+1][r+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= r; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else if(j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= r; j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % m;
        }
    }
    return dp[n][r];
}

int main(){
    int n = 5, r = 2;
    cout << "Value of C(" << n << ", " << r << ") is " << binomialCoeff(n, r) << endl;
    return 0;
} 