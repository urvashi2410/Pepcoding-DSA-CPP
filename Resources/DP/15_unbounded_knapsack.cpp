#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int *val, int *wt, int n, int cap){
    int dp[n+1][cap+1];

    // agar bori hi 0 capacity ki hai to kya profit kamaoge bhai 
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    // agar chori krne k liye hi kuch nhi hai to kya daaloge bori me 
    for(int j = 0; j <= cap; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= cap; j++){
            if(j >= wt[i-1]){
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][cap];
}

int main(){
    int val[] = {10, 40, 50, 70};
    int wt[]  = {1, 3, 4, 5};
    int n = 4;
    int cap = 8;
    cout<<unboundedKnapsack(val, wt, n, cap)<<endl;
    return 0;
}