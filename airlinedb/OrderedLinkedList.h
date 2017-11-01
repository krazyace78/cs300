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
		void deleteNode(T&);
//		bool searchList(T&);
		T& searchList(T&);
};


template <class T>
void OrderedLinkedList<T>::insert(T& item){
	node<T> *newNode = new node<T>;
	node<T> *p, *q;
	newNode->data = item;
	newNode->next = NULL;
	if(LinkedList<T>::head == NULL){
		LinkedList<T>::head = LinkedList<T>::last = newNode;
	}else if(item < LinkedList<T>::head->data){
		newNode->next = LinkedList<T>::head;
		LinkedList<T>::head = newNode;
	}else{
		p = LinkedList<T>::head;
		q = p->next;
		while(q != NULL && q->data < item){
			p = q;
			q = q->next;
		}
		p->next = newNode;
		newNode->next = q;
	}
}
//template<class T>
//void OrderedLinkedList<T>::deleteNode(T& item){
//	node<T> *p, *q;
//	if(LinkedList<T>::head == NULL){
//		cerr<<"Flight is empty";
//	}else if(LinkedList<T>::head == item){
//		p = LinkedList<T>::head;
//		LinkedList<T>::head = LinkedList<T>::head->next;
//	}else{
//		if(p != NULL){
//			p = LinkedList<T>::head;
//
//		}else if(){
//			Somewhere in here I need to check if q->data != item
//		}
//	}
//}


template <class T>
T& OrderedLinkedList<T>::searchList(T& item){
//	if(LinkedList<T>::head == NULL)
//		cerr<<"empty list";
//	else{
		node<T> *p = LinkedList<T>::head;
		while(p != NULL && p->data != item){
			p = p->next;
		}
		cerr<<"Passenger not found";
		if(p != NULL){
			return p->data;
		}
//		return false;
//	}
}


#endif /* ORDEREDLINKEDLIST_H_ */
