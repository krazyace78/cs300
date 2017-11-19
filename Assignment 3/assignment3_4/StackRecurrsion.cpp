//This program solves a simple recursive reverseDigit problem.
#include <iostream>
#include "LinkedStack.h"
using namespace std;

void reverseDigits(int);

//the reverseDigits function takes a number provided by the user and recursively calls on itself in order to reverse the original number
void reverseDigits(int number){
	if(number == 0){
		return;
	}else{
		int onesDigit = number; //stores the original number in new variable onesDigit
		onesDigit %= 10;
		cout<<onesDigit; //prints out ones digit of original number
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
