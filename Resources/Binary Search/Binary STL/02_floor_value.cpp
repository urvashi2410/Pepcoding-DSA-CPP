#include <bits/stdc++.h>
using namespace std;

int floorvalue(vector<int>v, int n, int x){
    int lbound = lower_bound(v.begin(), v.end(), x) - v.begin();

    if(lbound == x){
        return v[lbound];
    }
    lbound--;
    if(lbound >= 0){
        return v[lbound];
    }
    return -1;
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
    cout << floorvalue(v, n, x);
    return 0;
}