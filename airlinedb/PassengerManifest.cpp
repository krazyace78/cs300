#include <iostream>
#include <string>
#include "Passenger.h"
#include "OrderedLinkedList.h"
using namespace std;


int main() {
	OrderedLinkedList<Passenger> flight100;
	OrderedLinkedList<Passenger> flight200;
	OrderedLinkedList<Passenger> flight300;
	OrderedLinkedList<Passenger> flight400;

	char userOption;
	string flightNumber, firstName, lastName, address, phoneNumber;
	cout<<"***DELTA AIRLINES***"<<endl;
	cout<<"Please choose an operation:"<<endl;
	cout<<"A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
	cin>>userOption;
	do{
		if((userOption == 'A') || (userOption == 'a')){
			cout<<"Enter flight number: ";
			cin>>flightNumber;
			cout<<"Enter first name: ";
			cin>>firstName;
			cout<<"Enter last name: ";
			cin>>lastName;
			cout<<"Enter address: ";
			cin.ignore(1000, '\n');
			getline(cin, address);
			address[address.length()-1] = '\0';
			cout<<"Enter phone number: ";
			cin>>phoneNumber;
			Passenger p(firstName, lastName, address, phoneNumber);
			if(flightNumber == "100"){
				flight100.insert(p);
			}else if(flightNumber == "200"){
				flight200.insert(p);
			}else if(flightNumber == "300"){
				flight300.insert(p);
			}else if(flightNumber == "400"){
				flight400.insert(p);
			}

//Ask user for last name and first name
//Search all flights for passenger
//Print passenger's flight # along with passenger info
		}else if((userOption == 'S') || (userOption == 's')){
			bool flag = true;
			cout<<"You chose to Search"<<endl;
			cout<<"Enter last name: ";
			cin>>lastName;
			cout<<"Enter first name: ";
			cin>>firstName;
			Passenger searchPassenger(lastName, firstName);

//			Passenger p2 = flight100.searchList(searchPassenger);

			flight100.searchList(searchPassenger);
//			cout<<p2;
			flight200.searchList(searchPassenger);
			flight300.searchList(searchPassenger);
			flight400.searchList(searchPassenger);
//******************************
//Implement loop instead of calling the searchList function 4 times
//******************************
//			while(flag){
//				if(flight100.searchList(searchPassenger)){
//					Passenger p2 =
//					cout<<"Flight number: 100"<<endl;
//					flag = false;
//				}else if(flight200.searchList(searchPassenger)){
//					cout<<"Flight number: 200"<<endl;
//					flag = false;
//				}else if(flight300.searchList(searchPassenger)){
//					cout<<"Flight number: 300"<<endl;
//					flag = false;
//				}else if(flight400.searchList(searchPassenger)){
//					cout<<"Flight number: 400"<<endl;
//					flag = false;
//				}
//			}


//Ask user to input flight number
//Ask user to input last name
//Delete passenger from correct node
		}else if((userOption == 'D') || (userOption == 'd')){
			string flightNumber, lastName;
			cout<<"You chose to Delete"<<endl;
//			cout<<"Enter flight number: ";
//			cin>>flightNumber;
//			cout<<"Enter last name: ";
//			cin>>lastName;
//			Passenger deletePassenger(lastName);
//			if(flightNumber == "100"){
//				flight100.deleteNode(deletePassenger);
//			}else if(flightNumber == "200"){
//				flight200.deleteNode(deletePassenger);
//			}else if(flightNumber == "300"){
//				flight300.deleteNode(deletePassenger);
//			}else if(flightNumber == "400"){
//				flight400.deleteNode(deletePassenger);
//			}

//Ask user to input flight #
//Print flight number and list of passengers sorted by last name and include all passenger info
		}else if((userOption == 'L') || (userOption == 'l')){
			cout<<"You chose to List"<<endl;
			string searchFlightNumber;
			cout<<"Enter flight number: ";
			cin>>searchFlightNumber;
			if(searchFlightNumber == "100"){
				cout<<flight100;
			}else if(searchFlightNumber == "200"){
				cout<<flight200;
			}else if(searchFlightNumber == "300"){
				cout<<flight300;
			}else if(searchFlightNumber == "400"){
				cout<<flight400;
			}else{
				cerr<<"You have entered an invalid flight number";
			}
		}else if((userOption == 'Q') || (userOption == 'q')){
			cout<<"You have decided to Quit"<<endl;
		}else{
			cout<<"You've entered an invalid input";
		}
		cout<<"A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
		cin>>userOption;
	}while((userOption != 'Q') && (userOption != 'q'));
	return 0;
}
