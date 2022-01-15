// * * * * * *
// * *     * *
// *         *
// * *     * *
// * * * * * *

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int first_row_spaces = 1, first_row_stars = n/2 + 1;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= first_row_stars; j++){
	        cout<<"*\t";
	    }
	    for(int j = 1; j <= first_row_spaces; j++){
	        cout<<"\t";
	    }
	    for(int j = 1; j <= first_row_stars; j++){
	        cout<<"*\t";
	    }
	    
	    if(i <= n/2){
	        first_row_stars--;
	        first_row_spaces += 2;
	    }
	    
	    else{
	        first_row_stars++;
	        first_row_spaces -= 2;
	    }
	    cout<<endl;
	}
}
