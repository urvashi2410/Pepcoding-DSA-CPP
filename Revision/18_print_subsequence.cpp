#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string s, string psf){
    if(s.size() == 0){
        cout << psf << endl;
        return;
    }

    char first = s[0];
    string rem = s.substr(1);
    printSubsequences(rem, psf + "");
    printSubsequences(rem, psf + first);
}

int main(){
    string s;
    cin >> s;
    printSubsequences(s, "");
    return 0;
}