#include <bits/stdc++.h>
using namespace std;

int countOccurrences(vector<int>v, int n, int x){
    int lbound = lower_bound(v.begin(), v.end(), x) - v.begin();
    int ubound = upper_bound(v.begin(), v.end(), x) - v.begin();

    int ans = 0;
    if(lbound >= 0 && lbound < n && ubound > 0 && ubound < n){
        ans = ubound - lbound;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    } 
    int x;
    cin >> x;
    cout << countOccurrences(v, n, x);
    return 0;
}