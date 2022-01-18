#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>>v, int n, int row, string ans){
    if(row == n){
        cout << ans << endl;
        return;
    }
    for(int col = 0; col < n; col++){
        v[row][col] = 1;
        print_matrix(v, n, row + 1, ans + to_string(row) + '-' + to_string(col) + ", ");
        v[row][col] = 0;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n, vector<int>(n));
    print_matrix(v, n, 0, "");
    return 0;
}