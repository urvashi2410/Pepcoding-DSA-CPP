#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n], maximum = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maximum = max(arr[i], maximum);
    }
    
    for(int i = 0; i < maximum; i++){
        for(int value : arr){
            if(value >= maximum - i){
                cout<< "*\t";
            }
            else{
                cout << "\t";
            }
        }
        cout << endl;
    }
}