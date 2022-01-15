    //         *	
    //     *		*	
    // *				*	
    //     *		*	
    //         *	

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int outer_spaces = n/2, inner_spaces = -1;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= outer_spaces; j++){
	        cout<<"\t";
	    }
	    cout<<"*\t";
	    for(int j = 1; j <= inner_spaces; j++){
	        cout<<"\t";
	    }
	    if(i>1 && i<n){
	        cout<<"*\t";
	    }
	    if(i <= n/2){
	        outer_spaces--;
	        inner_spaces += 2;
	    }
	    
	    else{
	        outer_spaces++;
	        inner_spaces -= 2;
	    }
	    cout<<endl;
	}
}