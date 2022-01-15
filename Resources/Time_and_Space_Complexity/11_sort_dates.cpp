// we use count sort when we are having all th elements of a small specific range.

#include <bits/stdc++.h>
using namespace std;

void print(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int* arr, int n, int expo){
    int ans[n];
    
    // make frequency array 
    // frequency array 10 size ka liya h kyunki 10 hi digit hoti hn 0-9 unhi ki
    // frequency krni h store isme
    int* freqArr = new int[10];
    
    // hr ek place se bhrni h frequency
    for(int i = 0; i < n; i++){
        freqArr[(arr[i] / expo) % 10]++;
    }
    
    // convert the frequency array to prefix sum array and this prefix sum array 
    // will denote the end indexes upto which a particular value will be filled.
    for(int i = 1; i < 10; i++){
        freqArr[i] += freqArr[i-1];
    }
    
    // stable sorting krenge(stable mtlb ki jaise 9 agar 4 baar aa rha h to after
    // sorting baad wala 9 baadme or pehele wala pehle hi aana chahiye)
    for(int i = n - 1; i >= 0; i--){
        int pos = freqArr[(arr[i] / expo) % 10] - 1;
        ans[pos] = arr[i];
        freqArr[(arr[i] / expo) % 10]--;
    }
    
    // filling the original array with the help of the ans array
    for(int i = 0; i < n; i++){
        arr[i] = ans[i];
    }
    
    cout << "After sorting on " << expo << " place -> ";
    
    print(arr, n);
}

void radixSort(int* arr, int n){
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++){
        maximum  = max(maximum, arr[i]);
    }
    
    // call countSort for every digit from right to left(ones place se)
    for(int expo = 1; maximum / expo > 0; expo *= 10){
        countSort(arr, n, expo);
    }
}


int main(){
    int n;
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    radixSort(arr, n);
    print(arr, n);
}