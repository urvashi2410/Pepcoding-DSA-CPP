// question is to seperate smaller and greater elements on the basis of a gievn pivot.

#include <bits/stdc++.h>
using namespace std;

void Swap(int* arr, int i, int j){
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    swap(arr[i], arr[j]);
}

void partition(int* arr, int n, int pivot){
    // 0 to j -1 -> all elements are smaller or equal to pivot
    // j to i - 1 -> all elements are greater than pivot
    // i to n - 1 -> unknown elements
    // in each iteration we are taking one element from the unknown array
    // putting it either in the smaller one or in the greater one
    
    // to put in the smaller side we swap the first greatest with the element
    
    int i = 0, j = 0;
    while(i < n){
        if(arr[i] <= pivot){
            Swap(arr, i, j);
            i++; j++;
        }
        else{
            i++;
        }
    }
}


int main(){
    int n, pivot;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> pivot;
    partition(arr, n, pivot);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}