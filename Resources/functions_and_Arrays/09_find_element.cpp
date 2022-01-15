#include <iostream>
using namespace std;

int main() {
	int n, number_to_be_find;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	
	cin >> number_to_be_find;
	int index = -1;
	for(int i = 0; i < n; i++){
	    if(arr[i] == number_to_be_find){
	        index = i;
	        break;
	    }
	}
	cout << index;
	return 0;
}
