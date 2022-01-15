// 1
// 11
// 121
// 1331
// 14641

// Pascal's Right Triangle

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n][n];
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=i; j++){
	        if(j==1 || i==j){
	            a[i][j] = 1;
	        }
	        else{
	            a[i][j] = a[i-1][j-1] + a[i-1][j];
	        }
	        cout<<a[i][j];
	    }
	    cout<<endl;
	}
}