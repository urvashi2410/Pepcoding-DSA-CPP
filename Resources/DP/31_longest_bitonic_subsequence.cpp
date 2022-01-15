#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // calculating longest increasing subsequence
    int* lis = new int[n];
    for(int i = 0; i < n; i++){
        int maximum = 0;
        
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                if(lis[j] > maximum){
                    maximum = lis[j];
                }
            }
        }
        
        lis[i] = maximum + 1;
    }
    
    // calculating longest decreasing subsequence
    int* lds = new int[n];
    for(int i = n - 1; i >= 0; i--){
        int maximum = 0;
        for(int j = n - 1; j > i; j--){
            if(arr[j] <= arr[i]){
                if(lds[j] > maximum){
                    maximum = lds[j];
                }
            }
        }
        lds[i] = maximum + 1;
    }
    
    int overallMaximum = 0;
    
    for(int i = 0; i < n; i++){
        if(lis[i] + lds[i] - 1 > overallMaximum){
            overallMaximum = lis[i] + lds[i] - 1;
        }
    }
    
    cout << overallMaximum << endl;
  
}