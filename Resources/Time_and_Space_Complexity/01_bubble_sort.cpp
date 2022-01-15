#include<bits/stdc++.h>
using namespace std;

void Swap(int* arr, int i, int j){
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    swap(arr[i], arr[j]);
}

bool isSmaller(int* arr, int i, int j){
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    if(arr[i] < arr[j]){
        return true;
    }
    else{
        return false;
    }
}

void bubbleSort(int* arr, int n){
    // we have to do n-1 iterations to get the sorted result but in each iteration one of the element from the last will be sorted so we are decreasing our number of elements to sort in each iteration.
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(isSmaller(arr, j + 1, j)){
                Swap(arr, j + 1, j);
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}