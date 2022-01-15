// Brute force Time complexity - n^3

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, color;
    cin >> n >> color;
    
    int arr[n][color];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < color; j++){
            cin >> arr[i][j];
        }
    }
    
    int dp[n][color];
    
    // pehle ghr me saare color daalke dekhe 
    for(int j = 0; j < color; j++){
        dp[0][j] = arr[0][j];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < color; j++){
            int minimum  = INT_MAX;
            
            for(int k = 0; k < color; k++){
                if(k != j){
                    if(dp[i - 1][k] < minimum){
                        minimum = dp[i - 1][k];
                    }
                }
            }
            dp[i][j] = arr[i][j] + minimum;
        }
    }
    
    int minimum = INT_MAX;
    for(int k = 0; k < color; k++){
        if(dp[n - 1][k] < minimum){
            minimum = dp[n - 1][k];
        }
    }
    
    cout << minimum << endl;
}

// Optimised Time complexity - n^2

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, color;
    cin >> n >> color;
    
    int arr[n][color];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < color; j++){
            cin >> arr[i][j];
        }
    }
    
    int dp[n][color];
    
    int least = INT_MAX;
    int sleast = INT_MAX;
    
    // pehle ghr me saare color daalke dekhe 
    for(int j = 0; j < color; j++){
        dp[0][j] = arr[0][j];
        
        if(arr[0][j] <= least){
            sleast = least;
            least = arr[0][j];
        }
        
        else if(arr[0][j] <= sleast){
            sleast = arr[0][j];
        }
    }
    
    for(int i = 1; i < n; i++){
        
        int nleast = INT_MAX;
        int nsleast = INT_MAX;
        
        for(int j = 0; j < color; j++){
            if(least == dp[i - 1][j]){
                dp[i][j] = sleast + arr[i][j];
            }
            else{
                dp[i][j] = least + arr[i][j];
            }
            
            if(dp[i][j] <= nleast){
                nsleast = nleast;
                nleast = dp[i][j];
            }
            else if(dp[i][j] <= nsleast){
                nsleast = dp[i][j];
            }
        }
        least = nleast;
        sleast = nsleast;
    }
    
    cout << least << endl;
}