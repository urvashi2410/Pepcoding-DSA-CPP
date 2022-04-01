#include <bits/stdc++.h>
using namespace std;

void kthMinMax(int *A, int n, int k){
    sort(A, A+n);
    cout << k << "th minimum element is " << A[k-1] << endl;
    cout << k << "th maximum element is " << A[n-k] << endl;
}

int main(){
    int n; 
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int k;
    cin >> k;
    kthMinMax(A, n, k);
}