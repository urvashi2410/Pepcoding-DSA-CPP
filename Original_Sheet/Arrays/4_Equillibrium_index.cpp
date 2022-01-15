// Equillibrium index is that index in an array from where left and right array sum are equal 

int EquillibriumIndex(int a[], int n){
    int leftSum = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    for(int i = 0; i < n; i++){
        // calculating right sum by subtracting current element
        sum -= a[i];
        
        if(leftSum == sum){
            return i;
        }
        
        // calculating leftsum by adding cuurent element
        leftSum += a[i];
    }
    return -1;
}