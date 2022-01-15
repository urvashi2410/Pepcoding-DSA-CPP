#include <iostream>
using namespace std;

int decimalToAnyBaseNumber(int decimalNumber, int base){
    int resultedNumber = 0;
    
    int power = 1;
    while(decimalNumber > 0){
        int remainder = decimalNumber % base;
        decimalNumber /= base;
        resultedNumber += power * remainder;
        power *= 10;
    }
    
    return resultedNumber;
}

int main() {
	int decimalNumber, base;
	cin >> decimalNumber >> base;
	
	int ans = decimalToAnyBaseNumber(decimalNumber, base);
	cout << ans;
	return 0;
}
