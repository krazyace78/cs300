//Not printing every digit. If the sum of both numbers is 10, it will print out 2 digits. I don't account for that
//when printing out the sum. My sum stack is the same size as the number stacks

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {
	LinkedStack<int> number1;
	LinkedStack<int> number2;
	LinkedStack<int> sum;
	int number1Count = 0;
	int number2Count = 0;
	string largeNumber1, largeNumber2, numberSum;
	cout<<"Enter a very large number: ";
	cin>>largeNumber1;
	cout<<"Enter a very large number: ";
	cin>>largeNumber2;

//This loop tokenizes the string provided by the user and splits each digit of the number into individual characters
//pushing them into two different stacks.
	for(int i = 0; i <= largeNumber1.length()-1; i++){
		char ch1 = largeNumber1[i];
		int charToInt1 = ch1-'0';
		number1.push(charToInt1);
		number1Count++;
	}
	for(int i = 0; i <= largeNumber2.length()-1; i++){
		char ch2 = largeNumber2[i];
		int charToInt2 = ch2-'0';
		number2.push(charToInt2);
		number2Count++;
	}
	cout<<"number1count = "<<number1Count<<endl;
	cout<<"number2count = "<<number2Count<<endl;
	if(number1Count > number2Count){
		while(!number1.isEmpty()){
			int sumNumbers = number1.pop() + number2.pop();
			sum.push(sumNumbers);
		}
	}else{
		while(!number2.isEmpty()){
			int sumNumbers = number2.pop() + number1.pop();
			sum.push(sumNumbers);
		}
	}
	while(!sum.isEmpty()){
		cout<<sum.pop();
	}
	return 0;
}
