// *
// **
// ***
// ***
// ** 
// *  

#include <iostream>
using namespace std;

int main() {
	int n,k,i,j;
	cin >> n;
	
	for(i = 1,k=n/2 + 1; i<= n/2 + 1; i++,k++){
	    for(j=n/2 + 1; j<=n; j++){
	        if(j<=k && j>= n/2 + 1){
	            cout<<"*";
	        }
	        else{
	            cout<<"";
	    }
	    }
	    cout<<endl;
	}

    for(i = n/2 + 1,k=1; i<= n; i++,k++){
    	    for(j=n/2 + 1; j<=n; j++){
    	        if(j<=n - k + 1 && j>= n/2+1){
    	            cout<<"*";
    	        }
    	        else{
    	            cout<<" ";
    	    }
    	    }
    	    cout<<endl;
    	}
	return 0;
}
