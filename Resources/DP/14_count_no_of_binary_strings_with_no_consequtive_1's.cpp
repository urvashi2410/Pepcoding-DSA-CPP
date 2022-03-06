#include <bits/stdc++.h>
using namespace std;

int countStrings(int n){
    int end0[n];
    int end1[n];

    end0[0] = 1;
    end1[0] = 1;

    for(int i = 1; i < n; i++){
        end0[i] = end0[i-1] + end1[i-1];
        end1[i] = end0[i-1];
    }
    return end0[n-1] + end1[n-1];
}

int main(){
    int n;
    cin >> n;

    cout << countStrings(n) << endl;
}