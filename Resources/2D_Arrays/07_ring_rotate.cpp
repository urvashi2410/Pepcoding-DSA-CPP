// buggy code

#include<bits/stdc++.h>
using namespace std;

int m, n; 

int* fillLinear(int** arr, int s){
    
    int rowShell = m - 2 * (s - 1);
    int colShell = n - 2 * (s - 1);
    int sizeOfShell = 2 * (rowShell + colShell) - 4;
    
    int* linearArr = new int[sizeOfShell];
    
    int rmin = s - 1;
    int cmin = s - 1;
    int rmax = m - 1 - (s - 1);
    int cmax = n - 1 - (s - 1);
    
    // filling linear array by traversing all the walls of the shell which has to be rotated 
    int idx = 0;
    // left wall
    for(int i = rmin; i <= rmax; i++){
        linearArr[idx] = arr[i][cmin];
        idx++;
    }
    
    // bottom wall 
    for(int j = cmin + 1; j <= cmax; j++){
        linearArr[idx] = arr[rmax][j];
        idx++;
    }
    
    // right wall 
    for(int i = rmax - 1; i >= rmin; i--){
        linearArr[idx] = arr[i][cmax];
        idx++;
    }
    
    // top wall
    for(int j = cmax - 1; j >= cmin + 1; j--){
        linearArr[idx] = arr[rmin][j];
        idx++;
    }
    
    return linearArr;
}

int* fill2d(int** arr, int* linearArr, int s){

    int rmin = s - 1;
    int cmin = s - 1;
    int rmax = m - 1 - (s - 1);
    int cmax = n - 1 - (s - 1);
    
    // filling that empty shell again by traversing the linear array
    int idx = 0;
    // left wall
    for(int i = rmin; i <= rmax; i++){
        arr[i][cmin] = linearArr[idx];
        idx++;
    }
    
    // bottom wall 
    for(int j = cmin + 1; j <= cmax; j++){
        arr[rmax][j] = linearArr[idx];
        idx++;
    }
    
    // right wall 
    for(int i = rmax - 1; i >= rmin; i--){
        arr[i][cmax] = linearArr[idx];
        idx++;
    }
    
    // top wall
    for(int j = cmax - 1; j >= cmin + 1; j--){
        arr[rmin][j] = linearArr[idx];
        idx++;
    }
}

void reverse(int* arr, int left, int right){
    while(left < right){
        swap(arr[left], arr[right]);
        
        left++; right--;
    }
}

void rotate(int* linearArr, int r){
    r = r % linearArr.size();
    if(r < 0){
        r += linearArr.size();
    }
    
    reverse(linearArr, 0, linearArr.size() - 1 - r);
    reverse(linearArr, linearArr.size() - r, linearArr.size() - 1);
    reverse(linearArr, 0, linearArr.size() - 1);
}

void shellRotate(int** arr, int s, int r){
    int* linearArr = fillLinear(arr, s);
    rotate(linearArr, r);
    fill2d(arr, linearArr, s);
}

void display(int** arr){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> m >> n;
    
    int arr[m][n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    // s is specified ring which has to be rotated, r is the no of rotations
    int s, r;
    cin >> s >> r;
    
    shellRotate(arr, s, r);
    display(arr);
    
}