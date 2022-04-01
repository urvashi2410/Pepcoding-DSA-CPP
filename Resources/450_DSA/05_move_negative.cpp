#include <bits/stdc++.h>
using namespace std;

void moveRight(int *A, int n){
    int j = n-1;
    for(int i = 0; i < n; i++){
        if(A[i] < 0){
            if(i != j){
                swap(A[i], A[j]);
            }
            j--;
        }
    }
}

void moveLeft(int *A, int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(A[i] < 0){
            if(i != j){
                swap(A[i], A[j]);
            }
            j++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    moveRight(A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
}