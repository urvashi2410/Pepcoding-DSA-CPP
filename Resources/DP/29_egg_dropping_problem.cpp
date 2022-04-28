#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int eggDrop(int e, int f){
    if(f == 0 || f == 1){
        return f;
    }

    if(e == 1){
        return f;
    }

    if(dp[e][f] != -1){
        return dp[e][f];
    }

    int ans = INT_MAX;
    for(int k = 1; k <= f; k++){
        int breakMinAttempts = eggDrop(e-1, k-1);
        int notBreakMinAttempts = eggDrop(e, f-k);

        int smallAns = max(breakMinAttempts, notBreakMinAttempts) + 1;
        ans = min(smallAns, ans);
        dp[e][f] = ans;
    }

    return dp[e][f];
}

int main(){

}