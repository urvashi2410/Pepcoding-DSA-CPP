    //  *   *   *	*	*	
    //      *		*	
    //          *	
    //      *	*	*	
    //  *	*	*	*	*	

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int first_row_stars = n, first_row_spaces = 0;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= first_row_spaces; j++){
	        cout<<"\t";
	    }
	    for(int j = 1; j <= first_row_stars; j++){
	        if( i > 1 && i <= n / 2 && j > 1 && j < first_row_stars){
	            cout<<"\t";
	        }
	        else{
	            cout<<"*\t";
	        }
	    }
	    if(i <= n/2){
	        first_row_spaces++;
	        first_row_stars -= 2;
	    }
	    
	    else{
	        first_row_spaces--;
	        first_row_stars += 2;
	    }
	    cout<<endl;
	}
}