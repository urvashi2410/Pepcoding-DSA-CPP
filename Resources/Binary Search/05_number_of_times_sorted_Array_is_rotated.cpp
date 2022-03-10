#include <bits/stdc++.h>
using namespace std;

int rotatedArray(int A[], int n){
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int prev = (mid-1+n) % n;
        int next = (mid + 1) % n;

        if(A[prev] > A[mid] && A[next] > A[mid]){
            return mid;
        }
        else if(A[mid] <= A[high]){
            low = mid+1;
        }
        else if(A[mid] >= A[high]){
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << rotatedArray(A, n);
}