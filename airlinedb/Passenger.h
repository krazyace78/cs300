
#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Passenger{
	string firstName, lastName, address, phoneNumber;

public:
	Passenger(){}
	Passenger(string lastName){
		this->lastName = lastName;
	}
	Passenger(string lastName, string firstName){
		this->lastName = lastName;
		this->firstName = firstName;
	}
	Passenger(string firstName, string lastName, string address, string phoneNumber){
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
	friend bool operator>(Passenger&, Passenger&);
	friend ostream& operator<<(ostream&, Passenger&);
	friend bool operator!=(Passenger&, Passenger&);
};
//Getters and setters for all fields
void Passenger::setFirstName(string firstName){
	this->firstName = firstName;
}
string Passenger::getFirstName(){
	return firstName;
}
void Passenger::setLastName(string lastName){
	this->lastName = lastName;
}
string Passenger::getLastName(){
	return lastName;
}
void Passenger::setAdress(string address){
	this->address = address;
}
string Passenger::getAdress(){
	return address;
}
void Passenger::setPhoneNumber(string phoneNumber){
	this->phoneNumber = phoneNumber;
}
string Passenger::getPhoneNumber(){
	return phoneNumber;
}

bool operator>(Passenger& p1, Passenger& p2){
	for(int i = 0; i < fmax(p1.getLastName().length(), p2.getLastName().length()); i++){
		while(p1.getLastName()[i] != p2.getLastName()[i]){
			if(p1.getLastName()[i] > p2.getLastName()[i]){
				return true;
			}
		}
		while(p1.getLastName()[i] == p2.getLastName()[i]){
			i++;
			if(p1.getLastName()[i] < p2.getLastName()[i]){
				return false;
			}
		}
	}
}

ostream& operator<<(ostream& os, Passenger& p){
	cout<<p.getFirstName()<<" " <<p.getLastName()<<" "<<p.getAdress()<<" +1"<<p.getPhoneNumber()<<" ";
	return os;
}

bool operator!=(Passenger& p1, Passenger& p2){

	if((p1.getFirstName() != p2.getFirstName()) && (p1.getLastName() != p2.getLastName())){
		return true;
	}
//Unclear on how to print out passenger flight #
	cout<<"Flight number: "<<endl;
	cout<<"First name: "<<p1.getFirstName()<<endl;
	cout<<"Last name: "<<p1.getLastName()<<endl;
	cout<<"Address: "<<p1.getAdress()<<endl;
	cout<<"Phone number: "<<p1.getPhoneNumber()<<endl;
	return false;
}

#endif /* PASSENGER_H_ */
