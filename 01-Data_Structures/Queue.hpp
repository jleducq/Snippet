#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {

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
		Node* tail;
		Node* head;
		int nbElements;
		
	public:
		Queue();
		~Queue();
		
		T& peek();
		void dequeue();
		void enqueue(T&);
		int size();
};


template<typename T>
Queue<T>::Queue() {
	head = NULL;
	tail = NULL;
	nbElements = 0;
}

template<typename T>
Queue<T>::~Queue() {
	Node * current = head;	
	
	while (current){
		Node * tmp = current;
		current = current->next;
		delete tmp;
	}
	
	head = NULL;
	tail = NULL;
}

template<typename T>
int Queue<T>::size() {
	return nbElements;
}

template<typename T>
T& Queue<T>::peek() {
	if (head == NULL) {
		throw std::runtime_error("Empty stack"); 
	}
	
	return head->data;
}

template<typename T>
void Queue<T>::enqueue(T& iData) {
	Node * node = new Node (iData);

	tail->next = node;
	if (head == tail) {
		head->next = node;
	}
	
	tail = node;		
	
	++nbElements;
}

template<typename T>
void Queue<T>::dequeue() {
	if (head == NULL) {
		throw std::runtime_error("Empty stack"); 
	}
	
	Node * tmp = head;
	head = head->next;
	
	if (head == NULL) {
		tail = NULL;
	}
	
	delete tmp;
	
	--nbElements;
}

template class Queue<int>;

#endif