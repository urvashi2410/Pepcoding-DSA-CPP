#include <bits/stdc++.h>
using namespace std;

vector<string> getSubsequences(string s){
    if(s.size() == 0){
        vector<string>base;
        base.push_back("");
        return base;
    }

    char first = s[0];
    string rem = s.substr(1);
    vector<string>smallAns = getSubsequences(rem);
    vector<string>ans;
    for(auto i : smallAns){
        ans.push_back(first + i);
        ans.push_back("" + i);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string>ans = getSubsequences(s);
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}