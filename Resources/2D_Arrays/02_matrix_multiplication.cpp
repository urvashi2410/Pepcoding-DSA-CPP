#include <bits/stdc++.h>
using namespace std;

int main(){
    int m1, n1;
    cin >> m1 >> n1;
    int arr1[m1][n1];
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n1; j++){
            cin >> arr1[i][j];
        }
    }
    int m2, n2;
    cin >> m2 >> n2;
    int arr2[m2][n2];
    for(int i = 0; i < m2; i++){
        for(int j = 0; j < n2; j++){
            cin >> arr2[i][j];
        }
    }
    
    if(n1 != m2){
        cout << "Invalid input" << endl;
    }
    
    int product[m1][n2];
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n2; j++){
            product[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n2; j++){
           for(int k = 0; k < n1; k++){
               product[i][j] += arr1[i][k] * arr2[k][j];
           }
        }
    }
    
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n2; j++){
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
}