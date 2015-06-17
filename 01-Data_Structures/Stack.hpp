#ifndef STACK
#define STACK

#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {

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
	
	private:
		Node* top;
		int nbElements;
		
	public:
		Stack();
		~Stack();
		
		T& peek();
		void pop();
		void push(T&);
		int size();
};


template<typename T>
Stack<T>::Stack() {
	top = NULL;
	nbElements = 0;
}

template<typename T>
Stack<T>::~Stack() {
	Node * current = top;	
	
	while (current){
		Node * tmp = current;
		current = current->next;
		delete tmp;
	}
	
	top = NULL;
}

template<typename T>
int Stack<T>::size() {
	return nbElements;
}

template<typename T>
T& Stack<T>::peek() {
	if (top == NULL) {
		throw std::runtime_error("Empty stack"); 
	}
	
	return top->data;
}

template<typename T>
void Stack<T>::push(T& iData) {
	Node * node = new Node (iData);

	node->next = top;
	top = node;		
	
	++nbElements;
}

template<typename T>
void Stack<T>::pop() {
	if (top == NULL) {
		throw std::runtime_error("Empty stack"); 
	}
	Node * tmp = top;
	top = top->next;
	
	delete tmp;
	
	--nbElements;
}

#endif