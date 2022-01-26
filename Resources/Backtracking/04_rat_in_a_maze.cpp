#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>v, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printPath(vector<vector<int>> v, int i, int j, int n, vector<vector<int>>ans){
    // rat is out of maze || at the position where he can't enter || at a position he already visited then just return 
    if(i < 0 || j < 0 || i >= n || j >= n || v[i][j] == 0 || ans[i][j] == 1){
        return;
    }

    // when rat completed the maze and reached at the end just display the path
    if(i == n-1 && j == n-1){
        ans[i][j] = 1;
        display(ans, n);
        ans[i][j] = 0;
        return;
    }

    ans[i][j] = 1;
    // bottom
    printPath(v, i+1, j, n, ans);
    // up 
    printPath(v, i-1, j, n, ans);
    // right 
    printPath(v, i, j+1, n, ans);
    // left 
    printPath(v, i, j-1, n, ans);
    // backtrack
    ans[i][j] = 0;
}
int main(){
    vector<vector<int>> v = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1},
    };

    int n = 4;
    vector<vector<int>> ans(n, vector<int>(n));
    printPath(v, 0, 0, n, ans);
    return 0;
}