// #include <iostream>
// using namespace std;

// int countSubsetSum(int A[], int tar, int n){
//     int dp[n+1][tar+1];

//     for(int j = 0; j < tar; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 0; i <= n; i++){
//         for(int j = 1; j <= tar; j++){
//             if(j > A[i-1]){
//                 dp[i][j] = dp[i-1][j] + dp[i-1][j-A[i-1]];
//             }
//             else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     return dp[n][tar];
// }

// int main(){
//     int a[] = {3,3,3,3};
//     int sum = 6;
//     int n = sizeof(a)/sizeof(a[0]);
//     cout << countSubsetSum(a, n, sum);
// }