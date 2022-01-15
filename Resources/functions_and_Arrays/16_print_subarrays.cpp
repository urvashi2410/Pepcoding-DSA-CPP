#include<iostream>
using namespace std;

// first method
void printSubarrays(int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i; k <= j; k++){
                cout << arr[k] << "\t";
            }
            cout << endl;
        }
    }
}

// second method 
void printSubarrays(int* arr, int n, int start, int end){
    if(end == n){
        return;
    }
    
    else if(start > end){
        printSubarrays(arr, n, 0, end + 1);
    }
    
    else{
        for(int i = start; i < end; i++){
            cout << arr[i] << "\t";
        }
        cout << arr[end] << endl;
        printSubarrays(arr, n, start + 1, end);
    }
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    
    printSubarrays(arr, n);
    
}