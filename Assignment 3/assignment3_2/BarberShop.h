#pragma once
#include <iostream>
#include "Customer.h"
#include "LinkedStack.h"
using namespace std;

class BarberShop {
	LinkedStack<Customer> s1;
	LinkedStack<Customer> s2;
public:
	void addCustomer(Customer&);
	Customer nextCustomer();
	BarberShop() {
	}
};

void BarberShop::addCustomer(Customer& customer) {
	s1.push(customer);
}

Customer BarberShop::nextCustomer() {
	while (!s1.isEmpty()) {
		Customer temp = s1.pop();
		s2.push(temp);
	}
	Customer custToPop = s2.pop();
	while (!s2.isEmpty()) {
		Customer temp = s2.pop();
		s1.push(temp);
	}
	return custToPop;;
}
