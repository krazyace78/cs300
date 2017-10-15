//Stuart Larsen
//Assignment 1
//CS 300 Fall Quarter 2017 with Dr. Fatma Serce


// Used for verifying Array is of proper size
// cout<<sizeof(contactArray)/sizeof(contactArray[0]);

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
using namespace std;

class Contacts {
private:
	string contactName;
	string contactNumber;
//	string line;

public:
	Contacts() {}
	Contacts(string contactName, string contactNumber) {
		this->contactName = contactName;
		this->contactNumber = contactNumber;
	}
	void setContactName(string);
	void setContactNumber(string);
	string getContactName();
	string getContactNumber();
};

void Contacts::setContactName(string name) {
	contactName = name;
}

void Contacts::setContactNumber(string number) {
	contactNumber = number;
}

string Contacts::getContactName() {
	return contactName;
}

string Contacts::getContactNumber() {
	return contactNumber;
}

//Overrides the << opertor allowing the program to print the array of contacts directly with cout<<Contact object
ostream &operator<<(ostream& out, Contacts c){
	out<<c.getContactName()<< " " <<c.getContactNumber()<<endl;
}

//Takes array and length parameters, copies the old array and creates a new array with length+1, and adds the user input into the new array
Contacts* addContact(Contacts *contactArray, int *length) {
	Contacts *newContactArray=new Contacts[*length +1];
	for(int i = 0; i < *length; i++){
		newContactArray[i] = contactArray[i];
	}
	delete [] contactArray;

	string fName, lName, fullName;
	string number;
	cout << "Enter name: ";
	cin>>fName>>lName;
	fullName = fName + " " + lName;
	cout<<fullName<<endl;
	cout << "Enter number: ";
//	cin.ignore(1000, '\n\r');
	cin>>number;
	cout<<fullName<<endl;
	cout<<number<<endl;

	Contacts c;
	c.setContactName(fullName);
	c.setContactNumber(number);
	newContactArray[*length] = c;

	cout<<newContactArray[*length].getContactName();
	cout<<newContactArray[*length].getContactNumber();

	(*length)++;

	return newContactArray;



}

//Searches through array list of contacts and returns a phone number
//if Contacts.getContactName == (user input) return phone number associated with contact
string searchContact(Contacts contactArray[], int length) {
	string fName, lName, fullName;
	char userOption;
	cout<<"Enter Name: ";
	cin>>fName>>lName;
	fullName = fName + " " + lName;
	for(int i = 0; i < length; i++){
		if(fullName == contactArray[i].getContactName()){
			return contactArray[i].getContactNumber();
//		}else{
//			cout<<"The name you entered does not exist in your phonebook. Would you like to add this contact? (Y/N):";
//			cin>>userOption;
//			userOption = toupper(userOption);
//			if(userOption == 'Y'){
//				addContact(contactArray, &length);
//			}
		}
	}
	cout<<'\n';
	return 0;
}

//Searches through array list of contacts and deletes the phone number
void deleteContact(Contacts contactArray[], int length) {
	string fName, lName, fullName;
	cout<<"Enter name: ";
	cin>>fName>>lName;
	fullName = fName + " " + lName;
	for(int i = 0; i < length; i++){
		if(fullName == contactArray[i].getContactName()){
			contactArray[i].setContactName(" ");
			contactArray[i].setContactNumber(" ");
		}
	}
}

//Lists all contacts in the array list of contacts
void listContacts(Contacts contactArray[], int length){
	for (int i = 0; i < length; i++){
		cout<<contactArray[i];
//		cout << contactArray[i].getContactName() + " " + contactArray[i].getContactNumber() + '\n';
	}
}

int main() {
//Read through phonebook.txt and store the number of entries in the "counter" variable.
	int counter = 0;
	ifstream inFile;
//	inFile.open("phonebook_test.txt");
	inFile.open("phonebook.txt");

	while (!inFile.eof()) {
		string line;
		getline(inFile, line);
		counter++;
	}
	inFile.seekg(0);
	cout << "counter = " << counter << endl;

//Create array of size "Counter" and store the names of the entires in each element
	Contacts *contactArray=new Contacts[counter];
	int i = 0;
	while (!inFile.eof()) {
		string fName, lName, fullName;
		string number;
		Contacts c;
		inFile >> fName >> lName >> number;
		fullName = fName + " " + lName;
		c.setContactName(fullName);
		c.setContactNumber(number);
		contactArray[i] = c;
		i++;
	}
//	for (int i = 0; i < counter; i++) {
//		cout << contactArray[i].getContactName() + " " + contactArray[i].getContactNumber() + '\n';
//	}

	char userOption;
	do {

		cout << "***MY PHONEBOOK APPLICATION***" << endl;
		cout << "Please choose an operation:" << endl;
		cout << "A(add) | S(Search) | D(Delete) | L(List) | Q(Quit):";
		cin >> userOption;
		userOption = toupper(userOption);

		if (userOption == 'A') {
			cout << "You selected Add" << endl;
			contactArray = addContact(contactArray, &counter);
			cout<<'\n';
//			cout<<"Length of array:"<<sizeof(contactArray)/sizeof(contactArray[0]);
			cout<<"Counter: "<<counter;

		}
		else if (userOption == 'S') {
			cout << "You selected Search" << endl;
			cout<<searchContact(contactArray, counter);
			cout<<'\n';
		}
		else if (userOption == 'D') {
			cout << "You selected Delete" << endl;
			deleteContact(contactArray, counter);
			cout<<'\n';
		}
		else if (userOption == 'L') {
			cout << "You selected List" << endl;
			listContacts(contactArray, counter);
			cout<<'\n';
		}
		else
			cout << "You've decided to Quit searching";
	} while (userOption != 'Q');

}
