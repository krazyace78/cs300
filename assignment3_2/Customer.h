#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer{
	string firstName, lastName;
	public:
		Customer() { ; }
		Customer(string firstName, string lastName){
			this->firstName = firstName;
			this->lastName = lastName;
		}
		string getName();
};

string Customer::getName(){
	string fullName = firstName + " " + lastName;
	return fullName;
}

