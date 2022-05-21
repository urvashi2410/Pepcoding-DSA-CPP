#include <bits/stdc++.h>
using namespace std;

int lenOfLongestArr(int *arr, int n, int k){
    int maxLen = INT_MIN;
    int i = 0;
    int j = 0;
    int sum = 0;

    while(j < n){
        sum += arr[j];
        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if(sum > k){
            while(sum > k){
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return maxLen;
}

int main(){
    int A[] = {-5, 8, -14, 2, 4, 12};
    int n = sizeof(A)/sizeof(A[0]);
    int k = -5;
    cout<<lenOfLongestArr(A, n, k)<<endl;
    return 0;
}