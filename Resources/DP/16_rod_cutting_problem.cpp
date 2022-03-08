#include <bits/stdc++.h>
using namespace std;

int rodCutting(int *price, int *l, int n, int len){
    int dp[n+1][len+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int j = 0; j <= len; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= len; j++){
            if(j >= l[i-1]){
                dp[i][j] = max(price[i-1] + dp[i][j-l[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}

int main(){
    int l[] = {1 ,  2,   3 ,  4 ,  5 ,  6,   7 ,  8};
    int price[] = {1 ,  5 ,  8,   9,  10,  17,  17,  20};
    int n = 8;
    int len = 8;
    cout<<rodCutting(price, l, n, len)<<endl;
    return 0;
}