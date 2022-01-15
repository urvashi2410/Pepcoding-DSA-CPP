#include <iostream>
using namespace std;

void printMazePaths(int i, int j, int n, int m, string psf){
    if(i == n-1 && j == m-1){
        cout << psf << endl;
        return;
    }
    if(j < m){
        printMazePaths(i, j + 1, n, m, psf+ 'h');
    }
    if(i < n){
        printMazePaths(i + 1, j, n, m, psf + 'v');
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n, m, "");
}