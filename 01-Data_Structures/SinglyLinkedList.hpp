#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {    
	T       data;
	Node*   next;
	
	Node()
		: next(NULL)
	{}
	Node(T const& data, Node* next = NULL)
		: data(data), next(next)
	{}
};
	
template<typename T>
class SinglyLinkedList {

	private:
		Node<T>* head;
		int nbElements;
		
	public:
		SinglyLinkedList();
		~SinglyLinkedList();
		
		Node<T>* front();
		Node<T>* back();
		Node<T>* getAt(int);
		int size();
		
		void push_back(Node<T>*);
		void push_front(Node<T>*);
		void insertAt(Node<T>*, int);
		
		void pop_back();
		void pop_front();
		void removeAt(int);
};


template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = NULL;
	nbElements = 0;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	Node<T> * current = head;	
	
	while (current){
		Node<T>* tmp = current;
		current = current->next;
		delete tmp;
	}
	
	head = NULL;
}

template<typename T>
int SinglyLinkedList<T>::size() {
	return nbElements;
}

template<typename T>
Node<T>* SinglyLinkedList<T>::front() {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	
	return head;
}

template<typename T>
Node<T>* SinglyLinkedList<T>::back() {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	
	Node<T> * current = head;	
	
	while (current->next){
		current = current->next;
	}
	
	return current;
}

template<typename T>
Node<T>* SinglyLinkedList<T>::getAt(int iIdx) {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	else if (iIdx < 0) {
		throw std::runtime_error("Negative index"); 
	}
	else if (nbElements <= iIdx) {
		throw std::runtime_error("Out of bound access"); 
	}
	
	Node<T> * current = head;
	int counter = iIdx;
	
	while (current->next && counter) {
		current = current->next;
		--counter;
	}
	
	return current;
}

template<typename T>
void SinglyLinkedList<T>::push_back(Node<T>* iNode) {
	if (head == NULL) {
		head = iNode;
	}
	else {
		Node<T> * current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = iNode;
	}
	++nbElements;
}

template<typename T>
void SinglyLinkedList<T>::push_front(Node<T>* iNode) {	
	iNode->next = head;
	head = iNode;
	
	++nbElements;
}

template<typename T>
void SinglyLinkedList<T>::insertAt(Node<T>* iNode, int iIdx) {
	if (iIdx < 0) {
		throw std::runtime_error("Negative index"); 
	}
	else if (nbElements < iIdx) {
		throw std::runtime_error("Out of bound insert"); 
	}
	
	Node<T>* previous = NULL;
	Node<T>* current = head;
	int counter = iIdx;
	
	while (current && counter) {
		previous = current;
		current = current->next;
		--counter;
	}
	
	// List is empty
	if (current == NULL && previous == NULL) {
		head = iNode;
	}
	// Insert at the beginning of the list
	else if (previous == NULL) {
		iNode->next = current;
		head = iNode;
	}
	// Insert at the end of the list
	else if (current == NULL) {
		previous->next = iNode;
	}
	// Normal case
	else {
		previous->next = iNode;
		iNode->next = current;
	}
	++nbElements;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	
	Node<T> * previous = NULL;
	Node<T> * current = head;

	while (current->next) {
		previous = current;
		current = current->next;
	}
	
	if (previous) {
		previous->next = NULL;
	}
	else {
		head = NULL;
	}
	
	delete current;
	
	--nbElements;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	
	Node<T> * tmp = head;
	head = head->next;
	
	delete tmp;
	
	--nbElements;
}

template<typename T>
void SinglyLinkedList<T>::removeAt(int iIdx) {
		if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	else if (iIdx < 0) {
		throw std::runtime_error("Negative index"); 
	}
	else if (nbElements <= iIdx) {
		throw std::runtime_error("Out of bound access"); 
	}
	
	Node<T> * previous = NULL;
	Node<T> * current = head;
	int counter = iIdx;
	
	while (current && counter) {
		previous = current;
		current = current->next;
		--counter;
	}
	
	if (previous == NULL) {
		head = current->next;
	}
	else {
		previous->next = current->next;
	}
	
	delete current;
	
	--nbElements;
}

#endif