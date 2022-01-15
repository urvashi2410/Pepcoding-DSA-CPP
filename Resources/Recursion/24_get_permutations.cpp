#include <bits/stdc++.h>
using namespace std;

vector<string> getPermutations(string s){
    if(s.size() == 0){
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    vector<string>ans;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        string remPermutations = s.substr(0, i) + s.substr(i + 1);
        vector<string>smallAns = getPermutations(remPermutations);
        for(string j : smallAns){
            ans.push_back(j + ch);
        }
    }
    return ans;
}

int main() {
	string s;
	cin >> s;
	vector<string>ans = getPermutations(s);
	for(string i : ans){
	    cout << i << endl;
	}
	return 0;
}
