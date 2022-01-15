#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    
    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    int minrow = 0, mincol = 0, maxrow = m - 1, maxcol = n - 1;
    int count = 0, totalElements = m * n;
    int i, j;
    while(count < totalElements){
        // left wall
        for(i = minrow, j = mincol; i <= maxrow && count < totalElements; i++){
            cout << arr[i][j] << endl;
            count++;
        }
        mincol++;
        
        // Bottom wall
        for(i = maxrow, j = mincol; j <= maxcol && count < totalElements; j++){
            cout << arr[i][j]<< endl;
            count++;
        }
        maxrow--;
        
        // Right wall
        for(i = maxrow, j = maxcol; i >= minrow && count < totalElements; i--){
            cout << arr[i][j]<< endl;
            count++;
        }
        maxcol--;
        
        // Top wall
        for(int j = maxcol, i = minrow; j >= mincol && count < totalElements; j--){
            cout << arr[i][j]<< endl;
            count++;
        }
        minrow++;
    }
}