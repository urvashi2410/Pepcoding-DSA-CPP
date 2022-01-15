// we use count sort when we are having all th elements of a small specific range.

#include <bits/stdc++.h>
using namespace std;

void countSort(int* arr, int n, int min, int max){
    int range = max - min + 1;
    int ans[n];
    
    // make frequency array 
    int* freqArr = new int[range];
    for(int i = 0; i < n; i++){
        freqArr[arr[i] - min]++;
    }
    
    // convert the frequency array to prefix sum array and this prefix sum array 
    // will denote the end indexes upto which a particular value will be filled.
    for(int i = 1; i < range; i++){
        freqArr[i] += freqArr[i-1];
    }
    
    // stable sorting krenge(stable mtlb ki jaise 9 agar 4 baar aa rha h to after
    // sorting baad wala 9 baadme or pehele wala pehle hi aana chahiye)
    for(int i = n - 1; i >= 0; i--){
        int pos = freqArr[arr[i] - min] - 1;
        ans[pos] = arr[i];
        freqArr[arr[i] - min]--;
    }
    
    // filling the original array with the help of the ans array
    for(int i = 0; i < n; i++){
        arr[i] = ans[i];
    }
    
}
int main(){
    int n;
    cin >> n;
    
    int arr[n];
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maximum = max(arr[i], maximum);
        minimum = min(arr[i], minimum);
    }
    
    countSort(arr, n, minimum, maximum);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}