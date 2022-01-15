// https://www.geeksforgeeks.org/find-subarray-with-given-sum/

void subArraySumIndexes(int a[], int n, int sum){
    int current_sum;
    for(int i = 0; i < n; i++){
        current_sum = a[i];
        for(int j = i + 1; j <= n; j++){
            if(current_sum > sum || j == n){
                break;
            }
            current_sum += a[i];
            if(current_sum == sum){
                cout<<"Indexes are" << i << " " << j-1 << endl;
            }
        }
    }
}

// Second Approach = O(n) using sliding window

#include <iostream>
using namespace std;

int subArraySum(int *arr, int n, int sum){
    int curr_sum = arr[0];
    int start = 0;
    int i;
    
    for(i = 1; i < n; i++){
        while(curr_sum > sum){
            curr_sum = curr_sum - arr[start];
            start++;
        }
        
        if(curr_sum == sum){
            cout << "Subarray is between index " << start << " and " << i - 1 << endl;
            return 1;
        }
        
            curr_sum = curr_sum + arr[i];
    }
    
    cout << "No such subarray found" << endl;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	
	int sum;
	cin >> sum;
	
	subArraySum(arr, n, sum);
	
	return 0;
}
