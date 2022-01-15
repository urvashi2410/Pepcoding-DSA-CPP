#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int coins[n];
    
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    int amt;
    cin >> amt;
    
    int* dp = new int[amt + 1];
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= amt; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    
    cout << dp[amt] << endl;
}