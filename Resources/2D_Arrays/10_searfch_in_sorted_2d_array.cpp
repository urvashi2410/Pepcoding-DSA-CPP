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
    
    int x;
    cin >> x;
    
    int i = 0;
    int j = n - 1;
    
    while(i < n && j >= 0){
        if(x == arr[i][j]){
            cout << i << endl << j << endl;
            break;
        }
        else if(x > arr[i][j]){
            i++;
        }
        else{
            j--;
        }
    }
}