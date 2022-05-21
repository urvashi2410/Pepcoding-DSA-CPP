#include <bits/stdc++.h>
using namespace std;

int count_anagrams(string s, string p){
    int ans = 0;
    int k = p.size();
    unordered_map<char, int> m;

    for(auto &x : p){
        m[x]++;
    }

    int count = m.size();
    int i = 0;
    int j = 0;
    int n = s.size();

    while(j < n){
        if(m.find(s[j]) != m.end()){
            m[s[j]]--;
            if(m[s[j]] == 0){
                count--;
            }
        }

        if(j - i + 1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(count == 0){
                ans++;
            }
            if(m.find(s[i]) != m.end()){
                m[s[i]]++;
                if(m[s[i]] == 1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    string s = "forxxorfxdofr";
    string p = "for";
    cout<<count_anagrams(s, p)<<endl;
    return 0;
}