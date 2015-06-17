#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {    
	T       data;
	Node*   next;
	Node*   previous;
	
	Node()
		: next(NULL)
	{}
	Node(T const& data, Node* next = NULL, Node* previous = NULL)
		: data(data), next(next), previous(previous)
	{}
};
	
template<typename T>
class DoubleLinkedList {

	private:
		Node<T>* head;
		int nbElements;
		
	public:
		DoubleLinkedList();
		~DoubleLinkedList();
		
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
DoubleLinkedList<T>::DoubleLinkedList() {
	head = NULL;
	nbElements = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	Node<T> * current = head;	
	
	while (current){
		Node<T>* tmp = current;
		current = current->next;
		delete tmp;
	}
	
	head = NULL;
}

template<typename T>
int DoubleLinkedList<T>::size() {
	return nbElements;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::front() {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	
	return head;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::back() {
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
Node<T>* DoubleLinkedList<T>::getAt(int iIdx) {
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
void DoubleLinkedList<T>::push_back(Node<T>* iNode) {
	if (head == NULL) {
		head = iNode;
	}
	else {
		Node<T> * current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = iNode;
		iNode->previous = current;
	}
	++nbElements;
}

template<typename T>
void DoubleLinkedList<T>::push_front(Node<T>* iNode) {	
	iNode->next = head;
	head = iNode;
	iNode->next->previous = iNode;
	
	++nbElements;
}

template<typename T>
void DoubleLinkedList<T>::insertAt(Node<T>* iNode, int iIdx) {
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
		iNode->next->previous = iNode;
	}
	// Insert at the end of the list
	else if (current == NULL) {
		previous->next = iNode;
		iNode->previous = previous;
	}
	// Normal case
	else {
		previous->next = iNode;
		iNode->previous = previous;
		iNode->next = current;
		current->previous = iNode;
	}
	++nbElements;
}

template<typename T>
void DoubleLinkedList<T>::pop_back() {
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
void DoubleLinkedList<T>::pop_front() {
	if (head == NULL) {
		throw std::runtime_error("Empty list"); 
	}
	
	Node<T> * tmp = head;
	head = head->next;
	head->previous = NULL;
	
	delete tmp;
	
	--nbElements;
}

template<typename T>
void DoubleLinkedList<T>::removeAt(int iIdx) {
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
		head->previous = NULL;
	}
	else {
		previous->next = current->next;
		previous->next->previous = previous;
	}
	
	delete current;
	
	--nbElements;
}

#endif