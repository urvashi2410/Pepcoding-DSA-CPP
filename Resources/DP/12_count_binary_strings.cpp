#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // zeroes and ones at index 1
    int zeroes = 1;
    int ones = 1;
    
    for(int i = 2; i <= n; i++){
        int nzeroes = ones;
        int nones = ones + zeroes;
        
        zeroes = nzeroes;
        ones = nones;
    }
    
    cout << zeroes + ones << endl;
}