#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int* values = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    
    int* weights = new int[n];
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    
    int capacity;
    cin >> capacity;
    
    int dp[n + 1][capacity + 1];
    
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= capacity; j++){
            dp[i][j] = 0;
        }
    }
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            
            // i - 1 le rhe hn kyunki dp ka i array k i - 1 se coincide kr rha h
            int val = values[i - 1];
            int weight = weights[i - 1];
            
            if(j >= weight){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + val);
            }
            
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[n][capacity] << endl;
}