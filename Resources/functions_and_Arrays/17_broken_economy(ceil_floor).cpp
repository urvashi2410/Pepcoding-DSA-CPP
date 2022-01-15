#include<iostream>
using namespace std;

void ceilFloor(int* arr, int n, int left, int right, int data){
    int ceil = -1;
    int floor = -1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == data){
            ceil = data;
            floor = data;
            break;
        }
        
        else if(arr[mid] < data){
            floor = arr[mid];
            left = mid + 1;
        }
        
        else{
            ceil = arr[mid];
            right = mid - 1;
        }
    }
    
    cout << ceil << endl;
    cout << floor << endl;
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
    
    ceilFloor(arr, n, 0, n - 1, data);
    
}