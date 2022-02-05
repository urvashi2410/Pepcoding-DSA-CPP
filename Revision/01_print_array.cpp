#include <bits/stdc++.h>
using namespace std;

void print_array(int* A, int n){
    if(n == 1){
        cout << A[0] << endl;
        return;
    }

    print_array(A, n-1);
    cout << A[n-1] << endl;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    print_array(A, n);
}