#include <bits/stdc++.h>
using namespace std;

vector<int> NGEL(int A[], int n){
    stack<int>s;
    vector<int>ans;

    for(int i = 0; i < n; i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top() > A[i]){
            ans.push_back(s.top());
        }
        else if(!s.empty() && s.top() <= A[i]){
            while(!s.empty() && s.top() <= A[i]){
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
    return ans;
}
int main(){
    int A[] = { 11, 13, 21, 3 };
    int n = 4;
    vector<int> v = NGEL(A, n);
    for(int i : v) {
        cout<<i<<" ";
    }
    return 0;
}