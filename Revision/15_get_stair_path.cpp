#include<bits/stdc++.h>
using namespace std;

vector<string> getStairPaths(int n){
    if(n == 0){
        vector<string>base;
        base.push_back("");
        return base;
    }
    if(n < 0){
        vector<string>base;
        return base;
    }
    
    vector<string>ans1 = getStairPaths(n-1);
    vector<string>ans2 = getStairPaths(n-2);
    vector<string>ans3 = getStairPaths(n-3);

    vector<string>ans;
    for(auto i : ans1){
        ans.push_back("1" + i);
    }

    for(auto i : ans2){
        ans.push_back("2" + i);
    }

    for(auto i : ans3){
        ans.push_back("3" + i);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string>ans = getStairPaths(n);
    for(auto i : ans){
        cout << i << endl;
    }
}