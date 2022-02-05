#include <bits/stdc++.h>
using namespace std;

void print_increasing(int n){
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    print_increasing(n-1);
    cout << n << endl;
}

int main(){
    int n;
    cin >> n;
    print_increasing(n);
}