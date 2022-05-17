#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int *arr, int n, int k){
    int i = 0;
    int j = 0;
    int maxi = INT_MIN;
    int sum = 0;

    while(j < n){
        sum += arr[j];
        if(j - i + 1 == k){
            maxi = max(maxi, sum);
            sum -= arr[i];
            i++;
        }
        j++;
    }
    return maxi;
}

int main(){
    int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout<<maxSubarraySum(arr, n, k)<<endl;
    return 0;
}