#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePath(int n, int m, int i, int j){
    if(i == n-1 && j == m-1){
        vector<string>base;
        base.push_back("");
        return base;
    }

    vector<string>ans;
    if(i < n){
        vector<string>ans1 = getMazePath(n, m, i+1, j);
        for(auto s : ans1){
            ans.push_back("v" + s);
        }
    }

    if(j < m){
        vector<string>ans2 = getMazePath(n, m, i, j+1);
        for(auto s : ans2){
            ans.push_back("h" + s);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<string>ans = getMazePath(n, m, 0, 0);
    for(auto s : ans){
        cout << s << endl;
    }

    return 0;
}