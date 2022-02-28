#include <bits/stdc++.h>
using namespace std;

vector<int> stock(int A[], int n){
    vector<int>ans;
    stack<pair<int, int>>s;

    for(int i = 0; i < n; i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top().first > A[i]){
            ans.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first <= A[i]){
            while(!s.empty() && s.top().first <= A[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({A[i], i});
    }

    for(int i = 0; i < ans.size(); i++){
        ans[i] = i - ans[i];
    }
    return ans;
}

int main(){
    int A[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;
    vector<int> v = stock(A, n);
    for(int i : v) {
        cout<<i<<" ";
    }
    return 0;
}