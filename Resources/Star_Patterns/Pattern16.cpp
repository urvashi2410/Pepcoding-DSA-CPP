// 1						1	
// 1	2				2	1	
// 1	2	3		3	2	1	
// 1	2	3	4	4	3	2

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int first_row_spaces = 2*n - 3, first_row_stars = 1,k=1;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= first_row_stars; j++){
	        cout<<k<<"\t";
	        k++;
	    }
	    for(int j = 1; j <= first_row_spaces; j++){
	        cout<<"\t";
	    }
	    if(i == n){
	        first_row_stars--;
	    }
	    for(int j = 1; j <= first_row_stars; j++){
	        --k;
	        cout<<k<<"\t";
	    }
	    first_row_spaces -= 2;
	    first_row_stars++;
	    cout<<endl;
	}
}