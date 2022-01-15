#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    long same = k * 1;
    long diff = k * (k - 1);
    long total = same + diff;
    
    for(int i = 3; i <= n; i++){
        
        // number of ways in which this fence is painted same as old fence following
        //  the rule of more than 2
        same = diff * 1;
        
        // number of ways in which this fence can be painted different from old fence.
        diff = total * (k - 1);
        
        // number of ways in which this fence can be painted.
        total = same + diff;
    }
    
    cout << total << endl;
}