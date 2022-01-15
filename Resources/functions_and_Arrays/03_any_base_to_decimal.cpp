#include <iostream>
using namespace std;

int anyBaseToDecimal(int number, int base){
    int resultedNumber = 0;
    
    int power = 1;
    while(number > 0){
        int remainder = number % 10;
        number /= 10;
        resultedNumber += power * remainder;
        power *= base;
    }
    
    return resultedNumber;
}

int main() {
	int number, base;
	cin >> number >> base;
	
	int ans = anyBaseToDecimal(number, base);
	cout << ans;
	return 0;
}