#include <bits/stdc++.h>
using namespace std;

void printMazePath(int n, int m, int i, int j, string psf){
    if(i == n-1 && j == m-1){
        cout << psf << endl;
        return;
    }

    if(i < n){
        printMazePath(n, m, i+1, j, psf+"v");
    }
    if(j < m){
        printMazePath(n, m, i, j+1, psf+"h");
    }
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    printMazePath(n, m, 0, 0, "");
    return 0;
}