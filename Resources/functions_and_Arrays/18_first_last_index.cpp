#include<iostream>
using namespace std;

void firstLastIndex(int* arr, int n, int data){
    int first_index = -1, left = 0, right = n - 1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(data == arr[mid]){
            first_index = mid;
            right = mid - 1;
        }
        else if(data > arr[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    int last_index = -1; 
    left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(data == arr[mid]){
            last_index = mid;
            left = mid + 1;
        }
        else if (data > arr[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    cout << first_index << endl;
    cout << last_index << endl;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    
    firstLastIndex(arr, n, data);
    
}