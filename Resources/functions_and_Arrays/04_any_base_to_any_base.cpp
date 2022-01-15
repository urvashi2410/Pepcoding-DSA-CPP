#include <iostream>
using namespace std;

int anyBaseToDecimal(int number, int base){
    int decimalNumber = 0;
    
    int power = 1;
    while(number > 0){
        int remainder = number % 10;
        number /= 10;
        decimalNumber += power * remainder;
        power *= base;
    }
    
    return decimalNumber;
}

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
	int number, base1, base2, decimalNumber;
	cin >> number >> base1 >> base2;
	
	decimalNumber = anyBaseToDecimal(number, base1);
	int ans = decimalToAnyBaseNumber(decimalNumber, base2);
	
	cout << ans;
	return 0;
}
