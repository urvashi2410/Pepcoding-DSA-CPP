// dividing the array into two parts left one as sorted and right one unsorted. In each iteration we will take one element from right array and place it at its respective position.

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

void insertionSort(int* arr, int n){
    for(int i = 1; i < n; i++){
        // hr ek ko uthaya or usse peeche wale se first tk sbse compare kiya or shi jgah patak diya
        for(int j = i - 1; j >= 0; j--){
            if(isSmaller(arr, j + 1, j)){
                Swap(arr, j, j + 1);
            }
            else{
                break;
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
    
    insertionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}