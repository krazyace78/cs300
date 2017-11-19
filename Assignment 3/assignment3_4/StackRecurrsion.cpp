#include <iostream>
#include "LinkedStack.h"
using namespace std;

void reverseDigits(int);

void reverseDigits(int number){
	if(number == 0){
		return;
	}else{
		int onesDigit = number;
		onesDigit %= 10;
		cout<<onesDigit;
		reverseDigits(number / 10);
	}
}

int main() {
	int userInput;
	cout<<"Enter a number: ";
	cin>>userInput;
	reverseDigits(userInput);
	return 0;
}
