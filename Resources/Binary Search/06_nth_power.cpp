#include <bits/stdc++.h>
using namespace std;

double multiply(double m, int n){
    double ans = 1.0;
    for(int i = 0; i < n; i++){
        ans *= m;
    }
    return ans;
}

int nthPower(int m, int n){
    double low = 1;
    double high = m;
    double limit = 1e-6;

    while((high - low) > limit){
        double mid = low + (high - low)/2;
        if(multiply(mid, n) > m){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return low;
}

int main(){
    int m;
    cin >> m;
    int n;
    cin >> n;
    cout << nthPower(m, n);
    return 0;
}