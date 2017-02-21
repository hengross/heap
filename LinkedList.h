#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
private:
	Node<T> * head;
	Node<T> * tail;
	int size;
public:
	LinkedList();
	~LinkedList();
	void add(T _value);
	void remove(T _value);
	void remove();
	bool contains(T _value);
	void printList();
};

template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (size > 0) {
		remove();
	}
}

template <class T>
void LinkedList<T>::printList() {
	Node<T> * temp = head;
	for (int i = 0; i < size; i++) {
		cout << temp->getValue() << endl;
		temp = temp->getNext();
	}
}


template <class T>
void LinkedList<T>::add(T _value) {
	Node<T> * temp = new Node<T>(_value, nullptr, nullptr);
	if (head == nullptr) {
		head = temp;
		tail = temp;
		head->setPrev(tail);
		tail->setNext(head);
		size++;
	}
	else {
		tail->setNext(temp);
		temp->setPrev(tail);
		temp->setNext(head);
		tail = temp;
		size++;
	}
}

template <class T>
bool LinkedList<T>::contains(T _value) {
	Node<T> * temp = head;
	for (int i = 0; i < size; i++) {
		if (temp->getValue() == _value) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

template <class T>
void LinkedList<T>::remove(T _value) {
	if (contains(_value)) {
		Node<T> * temp = head;
		for (int i = 0; i < size; i++) {
			if (temp->getValue() == _value) {
				break;
			}
			temp = temp->getNext();
		}
		//If it's the head;
		if (temp == head) {
			//If head is the only node
			if (temp->getNext() == nullptr) {
				delete head;
				temp = nullptr;
				tail = nullptr;
				head = nullptr;
				size--;
				return;
			}
			//If head is not the only node
			else if (temp->getNext() != nullptr) {
				head = temp->getNext();
				head->setPrev(tail);
				temp->setNext(nullptr);
				temp->setPrev(nullptr);
				delete temp;
				temp = nullptr;
				size--;
				return;
			}
		} //If tail
		else if (temp == tail) {
			tail = tail->getPrev();
			temp->setNext(nullptr);
			temp->setPrev(nullptr);
			tail->setNext(head);
			delete temp;
			temp = nullptr;
			size--;
			return;
		} // not tail and not head
		else {
			temp->getPrev()->setNext(temp->getNext());
			temp->getNext()->setPrev(temp->getPrev());
			temp->setNext(nullptr);
			temp->setPrev(nullptr);
			delete temp;
			temp = nullptr;
			size--;
			return;
		}
	}
}

template <class T>
void LinkedList<T>::remove() {
	if (size == 0) {
		return;
	}
	else if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return;
	}
	else if (size == 2) {
		tail->setNext(nullptr);
		tail->setPrev(nullptr);
		head->setNext(nullptr);
		head->setPrev(nullptr);
		delete tail;
		tail = head;
		head->setPrev(tail);
		tail->setNext(head);
		size--;
	}
	else {
		Node<T> * temp = tail;
		tail = temp->getPrev();
		temp->setPrev(nullptr);
		tail->setNext(head);
		temp->setNext(nullptr);
		head->setPrev(tail);
		size--;
		delete temp;
		temp = nullptr;
		return;
	}
}

#endif