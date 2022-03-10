#include <bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int n, int x){
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(A[mid] == x){
            return mid;
        }
        else if(A[mid] < x){
            low = mid+1;
        }
        else if(A[mid] > x){
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
    int x;
    cin >> x;
    cout << binarySearch(A, n, x);
}