#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    int dp[n][m];
    
    for(int j = m - 1; j >= 0; j--){
        for(int i = n - 1; i >= 0; i--){
            // at last column
            if(j == m - 1){
                dp[i][j] = arr[i][j];
            }
            // at last row
            else if(i == n - 1){
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            // first row
            else if(i == 0){
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else{
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
            }
        }
    }
    
    int maximum = dp[0][0];
    for(int i = 1; i < n; i++){
        maximum = max(maximum, dp[i][0]);
    }
    cout << maximum << endl;
}