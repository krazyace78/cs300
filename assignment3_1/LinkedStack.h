#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
    T data;
    node<T>* next;
};

template <class T>
class LinkedStack{
      node<T> *top;
   public:
      //provide function prototypes for a Stack here
      LinkedStack();
      bool isEmpty();
      void push(T&);
      T pop();
      T stackTop();
      void destroy();
      //~Stack();
};
//provide function implementations here
template <class T>
LinkedStack<T>::LinkedStack(){
	top = NULL;
}

template <class T>
bool LinkedStack<T>::isEmpty(){
	if(top == NULL){
		return true;
	}
	return false;
}

template <class T>
void LinkedStack<T>::push(T& item){
	node<T> *newNode = new node<T>;
	newNode->data = item;
	newNode->next = top;
	top = newNode;
}
template <class T>
T LinkedStack<T>::pop(){
	if(!isEmpty()){
		node<T> *temp = top;
		top = top->next;
		return temp->data;
		delete temp;
	}
}

template <class T>
T LinkedStack<T>::stackTop(){
	return top->data;
}

template <class T>
void LinkedStack<T>::destroy(){
	node<T> *temp = top;
	if(top == NULL){
		cout<<"Stack is empty"<<endl;
	}
	while(top != NULL){
		top = top->next;
		delete temp;
		temp = top;
	}
}
#endif /* LINKEDSTACK_H_ */
