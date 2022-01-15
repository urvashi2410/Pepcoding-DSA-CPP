//   *
//   **
// *****
//   **
//   *

#include <iostream>
using namespace std;

int main() {
	int n, first_row_stars = 1;
	cin >> n;
	int first_row_spaces = n/2;
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=first_row_spaces; j++){
	        if(i == n/2 + 1){
	            cout<<"*";
	        }
	        else{
	            cout<<" ";
	        }
	    }
	    
	    for(int j=1; j<=first_row_stars; j++){
	        cout<<"*";
	    }
	    
	    if(i <= n/2){
	        first_row_stars++;
	    }
	    else{
	        first_row_stars--;
	    }
	    
	    cout<<endl;
	}
	return 0;
}
