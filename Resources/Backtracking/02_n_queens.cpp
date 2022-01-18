#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>v, int row, int col, int n){
    // upwards
    for(int i = row - 1, j = col; i >= 0; i--){
        if(v[i][j] == 1){
            return false;
        }
    }
    // leftwards
    for(int j = col - 1, i = row; j >= 0; j--){
        if(v[i][j] == 1){
            return false;
        }
    }
    // diagonally left-upwards
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(v[i][j] == 1){
            return false;
        }
    }
    // diagonally right-upwards
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
        if(v[i][j] == 1){
            return false;
        }
    }
    return true;
}

void n_queens(vector<vector<int>>v, int n, int row, string ans){
    if(row == n){
    cout << ans << endl;
    return;
    }
    
    for(int col = 0; col < n; col++){
        if(isSafe(v, row, col, n)){
            v[row][col] = 1;
            n_queens(v, n, row + 1, ans + to_string(row) + '-' + to_string(col) + ", ");
            v[row][col] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n, vector<int>(n));
    n_queens(v, n, 0, "");
    return 0;
}