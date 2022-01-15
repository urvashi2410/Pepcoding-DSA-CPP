#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        // finding min of the row
        
        // assuming first element to be minimum
        int min = arr[i][0];
        int smallest_value_j_index = 0;
        for(int j = 1; j < n; j++){
            if(arr[i][j] < min){
                min = arr[i][j];
                smallest_value_j_index = j;
            }
        }
        
        bool flag = true;
        // checking if it is the max value in its column
        for(int k = 0; k < n; k++){
            if(arr[k][smallest_value_j_index] > arr[i][smallest_value_j_index]){
                flag = false;
                break;
            }
        }
        
        if(flag == true){
            cout << arr[i][smallest_value_j_index] << endl;
        }
    }
}