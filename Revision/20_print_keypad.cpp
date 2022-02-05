#include <bits/stdc++.h>
using namespace std;

void printKeypads(string s, string codes[], string psf){
    if(s.size() == 0){
        cout << psf << endl;
        return;
    }

    char first = s[0];
    string rem = s.substr(1);
    string temp = codes[first - '0'];
    for(int i = 0; i < temp.size(); i++){
        printKeypads(rem, codes, psf+temp[i]);
    }
}

int main(){
    string s;
    cin >> s;
    string codes[]{
        ".;",
        "abc", 
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tu",
        "vwx",
        "yz"
    };
    printKeypads(s, codes, "");
    return 0;
}