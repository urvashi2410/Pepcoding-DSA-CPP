#include <bits/stdc++.h>
using namespace std;

int* reverse(int *A, int n){
    int low = 0;
    int high = n - 1;

    while(low < high){
        swap(A[low], A[high]);
        low++;
        high--;
    }
    return A;
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        reverse(A, n);
        for(int i = 0; i < n; i++){
            cout << A[i] << " ";
        }
    }
    return 0;
}