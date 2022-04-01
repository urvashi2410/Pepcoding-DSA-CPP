#include <bits/stdc++.h>
using namespace std;

void minMax(int *A, int n){
    int max = INT_MIN;
    int min = INT_MAX;

    for(int i = 0; i < n; i++){
        if(A[i] > max){
            max = A[i];
        }

        if(A[i] < min){
            min = A[i];
        }
    }

    cout << "Minimum element is " << min << endl;
    cout << "Maximum element is " << max << endl;
}

void minMax2(int *A, int n){
    int max;
    int min;

    if(n == 1){
        min = A[0];
        max = A[0];
    }
    else{
        if(A[0] > A[1]){
            min = A[1];
            max = A[0];
        }
        else{
            min = A[0];
            max = A[1];
        }

        for(int i = 2; i < n; i++){
            if(min > A[i]){
                min = A[i];
            }

            if(max < A[i]){
                max = A[i];
            }
        }
    }
    cout << "Minimum element is " << min << endl;
    cout << "Maximum element is " << max << endl;
}

void minMax3(int *A, int n){
    int max;
    int min;
    int i;
    if(n % 2 == 0){
        if(A[0] > A[1]){
            max = A[0];
            min = A[1];
        }

        else{
            max = A[1];
            min = A[0];
        }
        i = 2;
    }
    else{
        max = A[0];
        min = A[0];
        i = 1;
    }

    while(i < (n-1)){
        if(A[i] > A[i+1]){
            if(A[i] > max){
                max = A[i];
            }

            if(A[i+1] < min){
                min = A[i];
            }
        }
        else{
            if(A[i] < min){
                min = A[i];
            }

            if(A[i+1] > max){
                max = A[i+1];
            }
        }

        i += 2;
    }
    cout << "Minimum element is " << min << endl;
    cout << "Maximum element is " << max << endl;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    minMax3(A, n);
    return 0;
}