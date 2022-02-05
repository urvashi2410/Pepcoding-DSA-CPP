#include <bits/stdc++.h>
using namespace std;

vector<int> allOccurrences(int *A, int n, int x, int idx, int count){
    if(idx == n){
        vector<int>base(count);
        return base;
    }

    vector<int>ans;
    if(A[idx] == x){
        allOccurrences(A, n, x, idx+1, count+1);
        ans[count] = idx; 
    }
    else{
        allOccurrences(A, n, x, idx+1, count);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int x;
    cin >> x;
    vector<int>v = allOccurrences(A, n, x, 0, 0);
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}