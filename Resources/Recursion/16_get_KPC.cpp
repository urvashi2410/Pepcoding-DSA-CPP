#include <bits/stdc++.h>
using namespace std;

vector<string> getKeypadCode(string s, string codes[]){
    if(s.size() == 0){
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    
    char ch = s[0];
    string rem = s.substr(1);
    // expecting that it will give us all the paths after first typed letter 
    vector<string>smallAns = getKeypadCode(rem, codes);
    string target = codes[ch - '0'];
    vector<string>ans;
    for(int i = 0; i < target.size(); i++){
        char firstLetter = target[i];
        for(string remString : smallAns){
            string code = firstLetter + remString;
            ans.push_back(code);
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
        "yz",
        };
    vector<string> v = getKeypadCode(s, codes);
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}