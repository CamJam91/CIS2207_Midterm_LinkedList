#pragma once
#include "ListInterface.h"
#include "PrecondViolatedExcep.h"
#include "Node.h"
template<typename T>
class LinkedList : public ListInterface<T>
{
private:
	Node<T>* headNode;
	Node<T>* tailNode;
	int count;
		//getters
	Node<T>* getNodeAt(int position);
		//setters
	void clearHelper(Node<T>* node);
public:
		//constructors
	LinkedList();
		//Getters
	bool isEmpty() const override;
	int getLength() const override;
	T getEntry(int position) throw (PrecondViolatedExcep) override;

		//Setters
	bool insert(int position, const T& element) override;
	void push(const T element);
	bool remove(int position) override;
	void clear() override;
	void setEntry(int position, const T& newEntry) throw (PrecondViolatedExcep) override;
};

	//constructors
template<typename T>
LinkedList<T>::LinkedList() {
	headNode = nullptr;
	tailNode = headNode;
	count = 0;
}

	//Getters
template<typename T>
Node<T>* LinkedList<T>::getNodeAt(int position){
	Node<T>* currentNode;
	if (position <= count / 2) {
		currentNode = headNode;
		for (int count = 1; count < position; count++)
			currentNode = currentNode->getNext();
	}
	else {
		currentNode = tailNode;
		for (int count = this->count; count > position; count--)
			currentNode = currentNode->getPrevious();
	}
	return currentNode;
}

template<typename T>
bool LinkedList<T>::isEmpty() const{
	return count == 0;
}

template<typename T>
int LinkedList<T>::getLength() const{
	return count;
}

template<typename T>
T LinkedList<T>::getEntry(int position) throw (PrecondViolatedExcep){
	if (position < 1 || position > count)
		throw PrecondViolatedExcep("Get Entry called on invalid position.");
	return getNodeAt(position)->getElement();
}

	//Setters
template<typename T>
bool LinkedList<T>::insert(int position, const T& element) {
	bool ableToInsert = (position >= 1) && (position <= count + 1);
	if (ableToInsert) {
		if (position == 1)
			headNode = new Node<T>(element, headNode);
		else if (position == count + 1) {
			push(element);
		}else {
			Node<T>* previousNode = getNodeAt(position-1);
			Node<T>* newNode = new Node<T>(element,previousNode->getNext(), previousNode);
			previousNode->setNext(newNode);
		}
		count++;
		return true;
	}
	return false;
}

template<typename T>
void LinkedList<T>::push(const T element) {
	if (count == 0) { 
		headNode = new Node<T>(element);
		tailNode = headNode;
	}
	else { //list is not empty so we create new tail, and link them to eachother
		Node<T>* newTail = new Node<T>(element, tailNode, nullptr);
		tailNode->setNext(newTail);
		tailNode = newTail;
	}
	count++;
}

template<typename T>
bool LinkedList<T>::remove(int position) {
	bool ableToRemove = (position >= 1) && (position <= count);
	if (ableToRemove) {
		if (count == 1) {
			delete headNode;
		}
		else if (position == count) {
				//delete reference to tail then delete tail
			tailNode->getPrevious()->setNext(nullptr);
			delete tailNode;
		}
		else {
			Node<T>* removeNode;
			if (position == 1) {
				removeNode = headNode;
				headNode = headNode->getNext();
			}
			else {
				Node<T>* previousNode = getNodeAt(position - 1);
				removeNode = previousNode->getNext();
				previousNode->setNext(getNodeAt(position + 1));
			}
		delete removeNode;
		removeNode = nullptr;
		}
		count--;
		return true;
	}
	return false;
}

	//recursively call helper to delete node data and nodes
template<typename T>
void LinkedList<T>::clear() {
	clearHelper(tailNode);
	count = 0;
}

template<typename T>
void LinkedList<T>::clearHelper(Node<T>* node) {
	if (node->getPrevious() != nullptr){
		clearHelper(node->getPrevious());
	}
	delete node; //delete memory
	node = nullptr; //delete pointer
}

template<typename T>
void LinkedList<T>::setEntry(int position, const T& element) throw (PrecondViolatedExcep){
	if (position < 1 || position > this->count)
		throw new PrecondViolatedExcep("Set Entry called on invalid position.");
	Node<T>* replaceNode = getNodeAt(position);
	replaceNode->setElement(element);
}
