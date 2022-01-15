#include <bits/stdc++.h>
using namespace std;

void flood_fill(vector<vector<int>>input, vector<vector<bool>>visited, int i, int j, int n, int m, string psf){
    if(i >= n || j >= m || i < 0 || j < 0 || visited[i][j] || input[i][j] == 1){
        return;
    }
    
    if(i == n - 1 && j == m - 1){
        cout << psf << endl;
    }
    
    visited[i][j] = true;
    flood_fill(input, visited, i+1, j, n, m, psf + "d");
    flood_fill(input, visited, i, j+1, n, m, psf + "r");
    flood_fill(input, visited, i-1, j, n, m, psf + "t");
    flood_fill(input, visited, i, j-1, n, m, psf + "l");
    visited[i][j] = false;
}
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>>input(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input[i][j];
        }
    }
    vector<vector<bool>>visited(n, vector<bool>(m));
    flood_fill(input, visited, 0, 0, n, m, "");
}