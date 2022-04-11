#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];

int booleanParanthesis(string s, int n, int i, int j, bool find = true){
    if(i > j){
        return 0;
    }

    if(i == j){
        if(find == true){
            if(s[i] == 'T'){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            if(s[i] == 'F'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    if(dp[i][j][find] != -1){
        return dp[i][j][find];
    }

    int ans = 0;
    for(int k = i+1; k < j; k+=2){
        int leftT;
        int leftF;
        int rightT;
        int rightF;

        if(dp[i][k-1][1] != -1){
            leftT = dp[i][k-1][1];
        }
        else{
            leftT = booleanParanthesis(s, n, i, k-1, true);
            dp[i][k-1][1] = leftT;
        }

        if(dp[i][k-1][0] != -1){
            leftF = dp[i][k-1][0];
        }
        else{
            leftF = booleanParanthesis(s, n, i, k-1, false);
            dp[i][k-1][0] = leftF;
        }

        if(dp[k+1][j][1] != -1){
            rightT = dp[k+1][j][1];
        }
        else{
            rightT = booleanParanthesis(s, n, k+1, j, true);
            dp[k+1][j][1] = rightT;
        }

        if(dp[k+1][j][0] != -1){
            rightF = dp[k+1][j][0];
        }
        else{
            rightF = booleanParanthesis(s, n, k+1, j, false);
            dp[k+1][j][0] = rightF;
        }

        if(s[k] == '&'){
            if(find == true){
                ans = ans + leftT*rightT;
            }
            else{
                ans = ans + leftT*rightF + leftF*rightT + leftF*rightF;
            }
        }

        if(s[k] == '|'){
            if(find == true){
                ans = ans + leftT*rightF + leftT*rightT + leftF*rightT;
            }
            else{
                ans = ans + leftF*rightF;
            }
        }

        if(s[k] == '^'){
            if(find == true){
                ans = ans + leftT*rightF + leftF*rightT;
            }
            else{
                ans = ans + leftT*rightT + leftF*rightF;
            }
        }
    }

    return ans;
}

int booleanTrue(string s, int n, int i, int j, bool find = true){
    if(i > j){
        return 0;
    }

    if(i == j){
        if(find == true){
            if(s[i] == 'T'){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            if(s[i] == 'F'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    int ans = 0;
    for(int k = i+1; k < j; k += 2){
        int leftF = booleanTrue(s, n, i, k-1, false);
        int rightF = booleanTrue(s, n, k+1, j, false);
        int leftT = booleanTrue(s, n, i, k-1, true);
        int rightT = booleanTrue(s, n, k+1, j, true);

        if(s[k] == '&'){
            if(find == true){
                ans = ans + leftT*rightT;
            }
            else{
                ans = ans + leftT*rightF + leftF*rightT + leftF*rightF;
            }
        }

        if(s[k] == '|'){
            if(find == true){
                ans = ans + leftT*rightT + leftT*rightF + leftF*rightT;
            }
            else{
                ans = ans + leftF*rightF;
            }
        }

        if(s[k] == '^'){
            if(find == true){
                ans = ans + leftF*rightT + leftT*rightF;
            }
            else{
                ans = ans + leftT*rightT + leftF*rightF;
            }
        }
    }
    return ans;
}

int main(){

}