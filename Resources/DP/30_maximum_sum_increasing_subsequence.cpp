#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int overallMaximum = INT_MIN;
    int *dp = new int[n];
    
    for(int i = 0; i < n; i++){
        int maximum = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                if(maximum == 0){
                    maximum = dp[j];
                }
                else if(dp[j] > maximum){
                    maximum = dp[j];
                }
            }
        }
        
        if(maximum == 0){
            dp[i] = arr[i];
        }
        else{
            dp[i] = maximum + arr[i];
        }
        
        if(dp[i] > overallMaximum){
            overallMaximum = dp[i];
        }
    }
    cout << overallMaximum << endl;
    
}