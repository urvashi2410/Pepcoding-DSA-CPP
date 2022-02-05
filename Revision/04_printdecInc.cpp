#include <bits/stdc++.h>
using namespace std;

void print_decInc(int n){
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    print_decInc(n-1);
    cout << n << endl;
}

int main(){
    int n;
    cin >> n;
    print_decInc(n);
}