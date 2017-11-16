#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Passenger {
	string firstName, lastName, address, phoneNumber;

public:
	Passenger() {}
	Passenger(string lastName) {
		this->lastName = lastName;
	}
	Passenger(string lastName, string firstName) {
		this->lastName = lastName;
		this->firstName = firstName;
	}
	Passenger(string firstName, string lastName, string address, string phoneNumber) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->address = address;
		this->phoneNumber = phoneNumber;
	}
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void setAdress(string);
	string getAdress();
	void setPhoneNumber(string);
	string getPhoneNumber();
	friend bool operator==(Passenger&, Passenger&);
	friend bool operator<(Passenger&, Passenger&);
	friend ostream& operator<<(ostream&, Passenger&);
	friend bool operator!=(Passenger&, Passenger&);
	friend bool operator==(Passenger&, Passenger&);
};
//Getters and setters for all fields
void Passenger::setFirstName(string firstName) {
	this->firstName = firstName;
}
string Passenger::getFirstName() {
	return firstName;
}
void Passenger::setLastName(string lastName) {
	this->lastName = lastName;
}
string Passenger::getLastName() {
	return lastName;
}
void Passenger::setAdress(string address) {
	this->address = address;
}
string Passenger::getAdress() {
	return address;
}
void Passenger::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
string Passenger::getPhoneNumber() {
	return phoneNumber;
}

bool operator<(Passenger& p1, Passenger& p2) {
	if (p1.getLastName()[0] < p2.getLastName()[0]) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& os, Passenger& p) {
	cout << p.getFirstName() << " " << p.getLastName() << " [" << p.getAdress() << "] [+1" << p.getPhoneNumber() << "]";
	return os;
}

bool operator!=(Passenger& p1, Passenger& p2) {
	return p1.getFirstName().compare(p2.getFirstName()) != 0;
}

bool operator ==(Passenger& p1, Passenger &p2) {
	if (p1.getLastName() == p2.getLastName()) {
		return true;
	}
	return false;
}
