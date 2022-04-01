#include <bits/stdc++.h>
using namespace std;

void sort012(int *A, int n){
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    for(int i = 0; i < n; i++){
        if(A[i] == 0){
            c0++;
        }
        else if(A[i] == 1){
            c1++;
        }
        else{
            c2++;
        }
    }

    int k = 0;
    for(int i = 0; i < c0; i++){
        A[k++] = 0;
    }

    for(int i = 0; i < c1; i++){
        A[k++] = 1;
    }

    for(int i = 0; i < c2; i++){
        A[k++] = 2;
    }
}

int main(){
    int n;
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort012(A, n);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    return 0;
}