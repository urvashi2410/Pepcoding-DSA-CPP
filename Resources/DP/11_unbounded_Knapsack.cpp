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
    
    int* dp = new int[capacity + 1];
    
    for(int i = 1; i <= capacity; i++){
        for(int j = 0; j < n; j++){
            int value = values[j];
            int weight = weights[j];
            
            if(i >= weight){
                if(dp[i - weight] + value > dp[i]){
                    dp[i] = dp[i - weight] + value;
                }
            }
        }
    }
    
    cout << dp[capacity] << endl;
}