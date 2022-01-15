// Problem to get logic for greedy algorithm, to understand that when you have to 
// ignore some path and choose other one.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int include = arr[0];
    int exclude = 0;
    
    for(int i = 1; i < n; i++){
        int newInclude = exclude + arr[i];
        int newExclude = max(exclude, include);
        
        include = newInclude;
        exclude = newExclude;
    }
    
    cout << max(include, exclude) << endl;
}