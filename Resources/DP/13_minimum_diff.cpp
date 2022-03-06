#include <bits/stdc++.h>
using namespace std;

int minDiff(int A[], int n, int tar){
    bool dp[n+1][tar+1];

    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int j = 0; j <= tar; j++){
        dp[0][j] = false;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= tar; j++){
            if(j >- A[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int i = n;
    int s1 = 0;

    for(int j = (tar)/2; j >= 0; j--){
        if(dp[i][j] == true){
            s1 = j;
            break;
        }
    }

    int diff = tar - 2*s1;
    return diff;
}

int main(){
    int n; 
    cin >> n;

    int A[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }

    cout << minDiff(A, n, sum);
}