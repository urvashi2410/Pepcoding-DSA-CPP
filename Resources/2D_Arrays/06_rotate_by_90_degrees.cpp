#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    // Transpose
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    
    // reversing the row elements 
    for(int i = 0; i < n; i++){
        int left = 0;
        int right = n - 1;
        
        while(left < right){
            swap(arr[i][left], arr[i][right]);
            
            left++; right--;
        }
    }
    
    // print the array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}