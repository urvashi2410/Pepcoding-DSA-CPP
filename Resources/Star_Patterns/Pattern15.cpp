    //          1	
    //     2	3	2	
    // 3   4	5	4	3	
    //     2	3	2	
    //          1	

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int first_row_spaces = n/2, first_row_stars = 1, k=1, a;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= first_row_spaces; j++){
	        cout<<"\t";
	    }
	    a = k;
	    for(int j = 1; j <= first_row_stars; j++){
	        cout<<a<<"\t";
	        if(j <= first_row_stars/2){
	            a++;
	        }
	        else{
	            a--;
	        }
	    }
	    if(i <= n/2){
	        first_row_spaces--;
	        first_row_stars += 2;
	        k++;
	    }
	    
	    else{
	        first_row_spaces++;
	        first_row_stars -= 2;
	        k--;
	    }
	    cout<<endl;
	}
}