#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include "LinkedList.h"
#include "Passenger.h"
#include <iostream>
#include <string>
#include <math.h>

template <class T>
class OrderedLinkedList: public LinkedList<T>{
	public:
		void insert(T&);
//		void deleteNode(T&);
		bool searchList(T&);
};


template <class T>
void OrderedLinkedList<T>::insert(T& item){
	node<T> *newNode = new node<T>;
	newNode->data = item;
	newNode->next = LinkedList<T>::head;
	node<T> *temp = LinkedList<T>::head;
	LinkedList<T>::head = newNode;
//	cout<<"Not entering While Loop"<<endl;
//	while(temp != NULL){
//		cout<<"temp != NULL";
//		if(newNode->data > temp->data){
//			newNode = temp;
//			temp = temp->next;
//			cout<<"Temp != NULL";
//	////	return true if not alphabetical
//		}else if(temp == NULL){
//			newNode->next = LinkedList<T>::head;
//			LinkedList<T>::head = newNode;
//			cout<<"Temp == NULL";
//		}else{
//			temp->next = newNode;
//			newNode->next = temp;
//		}
//	}
//	if(temp==NULL){
//		temp = newNode;
//		cout<<"temp = newNode"<<endl;
//	}


//	node<T> *newNode = new node<T>;
//	newNode->data = item;
//	newNode->next = LinkedList<T>::head;
//	LinkedList<T>::head = newNode;
//	node<T> *temp = LinkedList<T>::head;
//	node<T> *temp2 = NULL;
//	cout<<"Not entering While Loop"<<endl;
//	while(temp != NULL){
//		if(temp->data > item){
//			temp2 = temp;
//			temp = temp->next;
//			cout<<"Temp != NULL";
//////	return true if not alphabetical
//		}else if(temp2 == NULL){
//			newNode->next = LinkedList<T>::head;
//			LinkedList<T>::head = newNode;
//			cout<<"Temp == NULL";
//		}else{
//			temp2->next = newNode;
//			newNode->next = temp;
//		}

	//return false and move node into correct place
	//			temp = temp->next;
//	}
//	if(LinkedList<T>::last==NULL){
//		LinkedList<T>::last = newNode;
//		cout<<"Last node = newNode"<<endl;
//	}
}
//template<class T>
//void OrderedLinkedList<T>::deleteNode(T& item){


template <class T>
bool OrderedLinkedList<T>::searchList(T& item){
	if(LinkedList<T>::head == NULL)
//		cerr<<"empty list";
		cout<<endl;
	else{
		node<T> *p = LinkedList<T>::head;
		while(p->data != item){
			p = p->next;
		}

	}
}


#endif /* ORDEREDLINKEDLIST_H_ */
