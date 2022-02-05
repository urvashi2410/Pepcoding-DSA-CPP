#include <bits/stdc++.h>
using namespace std;

vector<string> getKeypad(string s, string codes[]){
    if(s.size() == 0){
        vector<string>base;
        base.push_back("");
        return base;
    }

    char first = s[0];
    string rem = s.substr(1);
    vector<string>smallAns = getKeypad(rem, codes);
    vector<string>ans;
    string temp = codes[first - '0'];
    for(int i = 0; i < temp.size(); i++){
        char ch = temp[i];
        for(auto i : smallAns){
            ans.push_back(ch + i);
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    string codes[] = {
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

    vector<string>ans = getKeypad(s, codes);
    for(auto i :  ans){
        cout << i << endl;
    }
    return 0;
}