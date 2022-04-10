#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

bool isPalindrome(string s, int i, int j){
    if(i == j){
        return true;
    }

    if(i > j){
        return true;
    }

    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromicPartition(string s, int n, int i, int j){
    if(i >= j){
        return 0;
    }

    if(isPalindrome(s, i, j)){
        return 0;
    }

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int p1 = palindromicPartition(s, n, i, k);
        int p2 = palindromicPartition(s, n, k+1, j);
        int ans = min(ans, p1+p2+1);
    }
    return ans;
}

int palindromicPartitionTopDown(string s, int n, int i, int j){
    if(i >= j){
        return 0;
    }

    if(isPalindrome(s, i, j)){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for(int k = i; k < j; k++){
        int left;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = palindromicPartitionTopDown(s, n, i, k);
            dp[i][k] = left;
        }

        int right;
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else{
            right = palindromicPartitionTopDown(s, n, k+1, j);
            dp[k+1][j] = right;
        }
        dp[i][j] = min(dp[i][j], left + right + 1);
    }
    return dp[i][j];
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    cout << palindromicPartitionTopDown(s, n, 1, n-1) << endl;
    return 0;
}