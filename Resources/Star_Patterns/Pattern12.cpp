// 0
// 11
// 235
// 8132134
// 5589144233377

#include <iostream>
using namespace std;

int main() {
	int n,a=-1,b=1,c;
	cin >> n;
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=i; j++){
	        c = a + b;
	        a = b;
	        b = c;
	        cout<<c;
	    }
	    cout<<endl;
	}
	return 0;
}
