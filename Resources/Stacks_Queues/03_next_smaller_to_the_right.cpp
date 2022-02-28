#include <bits/stdc++.h>
using namespace std;

vector<int> NSER(int A[], int n){
    vector<int>ans;
    stack<int>s;

    for(int i = (n-1); i >= 0 ; i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top() < A[i]){
            ans.push_back(s.top());
        }
        else if(!s.empty() && s.top() >= A[i]){
            while(!s.empty() && s.top() >= A[i]){
                s.pop();

                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top());
                }
            }
        }
        s.push(A[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int A[] = { 11, 13, 21, 3 };
    int n = 4;
    vector<int> v = NSER(A, n);
    for(int i : v) {
        cout<<i<<" ";
    }
    return 0;
}