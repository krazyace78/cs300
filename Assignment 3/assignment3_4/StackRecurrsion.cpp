#include <iostream>
#include "LinkedStack.h"
using namespace std;

LinkedStack<int> firstStack;
LinkedStack<int> stackToReverse;
int counter = 0;

void reverseDigits(int);

void reverseDigits(int x){
	int pushValue;
	int y;
	if(x == 0){
		while(firstStack.isEmpty()){
		y = firstStack.pop();
		stackToReverse.push(y);
		}
	}
	else{
		pushValue = x % 10;
		x /= 10;
		firstStack.push(pushValue);
		reverseDigits(x);
		cout<<stackToReverse.pop();
	}
}

int main() {
	int userInput;
	cout<<"Enter a number: ";
	cin>>userInput;
	reverseDigits(userInput);
	return 0;
}
