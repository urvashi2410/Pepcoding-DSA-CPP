// question is to seperate smaller and greater elements on the basis of a gievn pivot.

#include <bits/stdc++.h>
using namespace std;

void Swap(int* arr, int i, int j){
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    swap(arr[i], arr[j]);
}

int partition(int* arr, int n, int pivot, int start, int end){
    // 0 to j -1 -> all elements are smaller or equal to pivot
    // j to i - 1 -> all elements are greater than pivot
    // i to n - 1 -> unknown elements
    // in each iteration we are taking one element from the unknown array
    // putting it either in the smaller one or in the greater one
    
    // to put in the smaller side we swap the first greatest with the element
    
    cout << "pivot -> " << pivot << endl;
    int i = start, j = start;
    while(i <= end){
        if(arr[i] <= pivot){
            Swap(arr, i, j);
            i++; j++;
        }
        else{
            i++;
        }
    }
    cout << "pivot index -> " << j - 1 << endl;
    return j - 1;
}

void quickSort(int* arr, int n, int start, int end){
    if(start > end){
        return;
    }
    int pivot = arr[end];
    int pivotIndex = partition(arr, n, pivot, start, end);
    quickSort(arr, n, start, pivotIndex - 1);
    quickSort(arr, n, pivotIndex + 1, end);
}

int main(){
    int n, pivot;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> pivot;
    quickSort(arr, n, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}