/*Cameron Murphy | CIS 2207N02
* Node class for use in linked lists*/
#pragma once

template<typename T>
class Node {
private:
	T element;
	Node* next;
	Node* previous;

public:
		//constructors
	Node() {};
	Node(const T element);
	Node(const T element, Node* next);
	Node(const T element, Node* previous, Node* next);
		//getters
	T getElement() const;
	Node* getNext();
	Node* getPrevious();
		//setters
	void setElement(const T element);
	void setNext(Node* next);
	void setPrevious(Node* previous);
};

	//constructors
template<typename T>
Node<T>::Node(const T element) {
	this->element = element;
	next = nullptr;
	previous = nullptr;
}
template<typename T>
Node<T>::Node(const T element, Node* next) {
	this->element = element;
	this->next = next;
	previous = nullptr;
}
template<typename T>
Node<T>::Node(const T element, Node* previous, Node* next) {
	this->element = element;
	this->next = next;
	this->previous = previous;
}

	//getters
template<typename T>
T Node<T>::getElement() const{
	return element;
}
template<typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template<typename T>
Node<T>* Node<T>::getPrevious() {
	return previous;
}
	//setters
template<typename T>
void Node<T>::setElement(const T element) {
	this->element = element;
}
template<typename T>
void Node<T>::setNext(Node* next) {
	this->next = next;
}
template<typename T>
void Node<T>::setPrevious(Node* previous) {
	this->previous = previous;
}
