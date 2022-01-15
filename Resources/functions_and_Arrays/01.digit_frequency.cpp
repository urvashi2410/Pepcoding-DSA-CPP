#include <iostream>
using namespace std;

int getDigitFrequency(int number, int digit){
    int frequency = 0;
    
    while(number > 0){
        int remainder = number % 10;
        number /= 10;
        
        if(remainder == digit){
            frequency++;
        }
    }
    return frequency;
}

int main() {
	int number, digit;
	cin >> number >> digit;
	
	int ans = getDigitFrequency(number, digit);
	cout << ans;
	return 0;
}
