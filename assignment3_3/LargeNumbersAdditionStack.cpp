//Not printing every digit. If the sum of both numbers is 10, it will print out 2 digits. I don't account for that
//when printing out the sum. My sum stack is the same size as the number stacks

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {
	LinkedStack<int> number1;
	LinkedStack<int> number2;
	LinkedStack<int> sum;
	string largeNumber1, largeNumber2, numberSum;
	cout<<"Enter a very large number: ";
	cin>>largeNumber1;
	cout<<"Enter a very large number: ";
	cin>>largeNumber2;

	for(int i = 0; i <= largeNumber1.length()-1; i++){
		char ch1 = largeNumber1[i];
		int charToInt1 = ch1-'0';
		number1.push(charToInt1);
//		cout<<"Top of Number 1 stack is "<<number1.stackTop()<<endl;

		char ch2 = largeNumber2[i];
		int charToInt2 = ch2-'0';
		number2.push(charToInt2);
//		cout<<"Top of Number 2 stack is "<<number2.stackTop()<<endl;
	}

//	for(int i = 0; i <= largeNumber1.length()-1; i++){
	while(!number1.isEmpty()){
		int sumNumbers = number1.pop() + number2.pop();
		sum.push(sumNumbers);
	}
	while(!sum.isEmpty()){
		cout<<sum.pop();
	}
	return 0;
}
