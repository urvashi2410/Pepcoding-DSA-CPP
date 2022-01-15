// 3*1=3
// 3*2=6
// 3*3=9
// 3*4=12
// 3*5=15
// 3*6=18
// 3*7=21
// 3*8=24
// 3*9=27
// 3*10=30

#include <iostream>
using namespace std;

int main() {
	int n,k=1;
	cin >> n;
	for(int i=1; i<=10; i++){
	    for(int j=1; j<=5; j++){
	        if(j==1){
	            cout<<n;
	        }
	        if(j==2){
	            cout<<"*";
	        }
	        if(j==3){
	            cout<<i;
	        }
	        if(j==4){
	            cout<<"=";
	        }
	        if(j==5){
	            cout<<(i)*n;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}

