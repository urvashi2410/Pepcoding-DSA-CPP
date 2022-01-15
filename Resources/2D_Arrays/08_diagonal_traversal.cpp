#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j;
    cin >> n;
    
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int g = 0; g < n; g++){
        for(i = 0, j = i + g; j < n; i++, j++){
            cout << arr[i][j] << endl;
        }
    }
}