//   *
//  **
// ***
//  **
//   *

#include <iostream>
using namespace std;

int main() {
	int n,k,i,j;
	cin >> n;
	for(i = 1; i<=n/2 + 1; i++){
	    for(j=1; j<= n/2 + 1; j++){
	        if(j >= n/2-i+2){
	            cout<<"*";
	        }
	        else{
	            cout<<" ";
	        }
	    }
	    cout<<endl;
	}
	
	for(i = 1,k=n/2 + 1; i<= n/2 + 1; i++,k++){
	    for(j=n/2 + 1; j<=n; j++){
	        if(j<=k){
	            cout<<" ";
	        }
	        else{
	            cout<<"*";
	    }
	    }
	    cout<<endl;
	}
}
