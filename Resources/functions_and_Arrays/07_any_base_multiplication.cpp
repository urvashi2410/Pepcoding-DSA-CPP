#include <iostream>
using namespace std;

int singleDigitMultiplication(int number1, int rem2, int base){
    int result = 0, carry = 0;
    
    int power = 1;
    while(number1 > 0 || carry > 0){
        int rem1 = number1 % 10;
        number1 /= 10;
        
        int rem = rem1 * rem2 + carry;
        
        carry = rem / base;
        rem = rem % base;
        
        result += rem * power;
        power *= 10;
    }
    return result;
}

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

int anyBaseMultiplication(int number1, int number2, int base){
    int result, carry = 0;
    
    int power = 1;
    
    while(number2 > 0){
        int rem2 = number2 % 10;
        number2 /= 10;
        
        int singledigitproduct = singleDigitMultiplication(number1, rem2, base);
        result = anyBaseAddition(result, singledigitproduct * power, base);
        
        power *= 10;
    }
    
    return result;
}
int main() {
	int number1, number2, base;
	cin >> base >> number1 >> number2;
	int ans = anyBaseMultiplication(number1, number2, base);
	cout << ans;
	
	return 0;
}
