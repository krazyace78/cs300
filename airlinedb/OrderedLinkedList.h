#pragma once
#include "LinkedList.h"
#include "Passenger.h"
#include <iostream>
#include <string>
#include <math.h>

template <class T>
class OrderedLinkedList : public LinkedList<T> {
public:
	void insert(T&);
	void deleteNode(T&);
	T* searchList(T&);
};


template <class T>
void OrderedLinkedList<T>::insert(T& item) {
	node<T> *newNode = new node<T>;
	node<T> *p, *q;
	newNode->data = item;
	newNode->next = NULL;
	if (LinkedList<T>::head == NULL) {
		LinkedList<T>::head = LinkedList<T>::last = newNode;
	}
	else if (item < LinkedList<T>::head->data) {
		newNode->next = LinkedList<T>::head;
		LinkedList<T>::head = newNode;
	}
	else {
		p = LinkedList<T>::head;
		q = p->next;
		while (q != NULL && q->data < item) {
			p = q;
			q = q->next;
		}
		p->next = newNode;
		newNode->next = q;
	}
}
//Currently only able to delete head node
template<class T>
void OrderedLinkedList<T>::deleteNode(T& item) {
	node<T> *p, *q;
	if (LinkedList<T>::head == NULL) {
		cerr << "Flight is empty";
	}
	else if (LinkedList<T>::head->data == item) {
		p = LinkedList<T>::head;
		LinkedList<T>::head = LinkedList<T>::head->next;
		delete p;
	}
	else {
		p = LinkedList<T>::head;
		q = p->next;
		while (q != NULL && q->data != item) {
			p = q;
			q = q->next;
		}
		if (q != NULL) {
			p->next = q->next;
			delete q;
		}
	}
}

template <class T>
T* OrderedLinkedList<T>::searchList(T& item) {
	if (LinkedList<T>::head == NULL) {
		cerr << "Empty Flight" << endl;
	}
	node<T> *p = LinkedList<T>::head;
	if (p->data == item) {
		return &p->data;
	}
	while (p != NULL && p->data != item) {
		p = p->next;
	}
	if (p != NULL) {
		return &p->data;
	}
	else
		cerr << "Passenger not found";
	return NULL;
}
