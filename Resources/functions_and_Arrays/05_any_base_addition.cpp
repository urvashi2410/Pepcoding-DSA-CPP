#include <iostream>
using namespace std;

int anyBaseAddition(int number1, int number2, int base){
    int result = 0, carry = 0;
    
    int power = 1;
    while(number1 > 0 || number2 > 0 || carry > 0){
        int rem1 = number1 % 10;
        int rem2 = number2 % 10;
        number1 /= 10;
        number2 /= 10;
        
        int rem = rem1 + rem2 + carry;
        carry = rem / base;
        rem = rem % base;
        
        result += rem * power;
        power *= 10;
    }
    
    return result;
}

int main() {
	int number1, number2, base;
	cin >> base >> number1 >> number2;
	int ans = anyBaseAddition(number1, number2, base);
	cout << ans;
	
	return 0;
}
