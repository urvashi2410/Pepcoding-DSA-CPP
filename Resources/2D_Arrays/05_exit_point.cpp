#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> n >> m;
    
    int arr[m][n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    int i = 0, j = 0, direction = 0;
    
    while(true){
        direction = (direction + arr[i][j]) % 4;
        if(direction == 0){
            j++;
        }
        else if(direction == 1){
            i++;
        }
        else if(direction == 2){
            j--;
        }
        else if(direction == 3){
            i--;
        }
        
        if(i < 0){
            i++;
            break;
        }
        else if(j < 0){
            j++;
            break;
        }
        else if(i == m){
            i--;
            break;
        }
        else if(j == n){
            j--;
            break;
        }
    }
    
    cout << i << endl;
    cout << j << endl;
}