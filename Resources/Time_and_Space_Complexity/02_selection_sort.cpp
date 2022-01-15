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

void selectionSort(int* arr, int n){
    // we have to do n-1 iterations to get the sorted result because last element will itself get sorted. In each iteration one of the element from the starting will be sorted so we are decreasing our number of elements to sort in each iteration and starting from i + 1.
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(isSmaller(arr, j, minIndex)){
                minIndex = j;
            }
        }
        Swap(arr, i, minIndex);
    }
}


int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    selectionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}