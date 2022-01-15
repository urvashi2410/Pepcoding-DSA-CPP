#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    
    long red = arr[0][0];
    long blue = arr[0][1];
    long green = arr[0][2];
    
    for(int i = 1; i < n; i++){
        long nred = arr[i][0] + min(blue, green);
        long nblue = arr[i][1] + min(red, green);
        long ngreen = arr[i][2] + min(red, blue);
        
        red = nred;
        blue = nblue;
        green = ngreen;
    }
    
    cout << min(red, min(blue, green)) << endl;
}