#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // value of building and space at index 1
    long building = 1;
    long space = 1;
    
    for(int i = 2; i <= n; i++){
        long nbuilding = space;
        long nspace = space + building;
        
        building = nbuilding;
        space = nspace;
    }
    
    long oneside = building + space;
    cout << oneside * oneside << endl;
}