#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int  *arr = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int overallMax = 0;
    int *dp = new int[n];
    for(int i = 0; i < n; i++){
        int maximum = 0;
        
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                if(dp[j] > maximum){
                    maximum = dp[j];
                }
            }
        }
        
        dp[i] = maximum + 1;
        
        if(dp[i] > overallMax){
            overallMax = dp[i];
        }
    }
    
    cout << overallMax << endl;
}