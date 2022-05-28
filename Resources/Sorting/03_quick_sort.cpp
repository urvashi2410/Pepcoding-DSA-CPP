#include <bits/stdc++.h>
using namespace std;

int paritition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int pIndx = paritition(arr, low, high);

        quickSort(arr, low, pIndx-1);
        quickSort(arr, pIndx+1, high);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}