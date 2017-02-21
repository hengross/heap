#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
	T value;
	Node<T> * next;
	Node<T> * prev;
public:
	Node(T _value, Node * _next, Node * _prev);
	T getValue();
	Node<T> * getNext();
	Node<T> * getPrev();
	void setValue(const T _value);
	void setNext(Node<T> * _next);
	void setPrev(Node<T> * _prev);
};

template <class T>
Node<T>::Node(T _value, Node * _next, Node * _prev) {
	value = _value;
	next = _next;
	prev = _prev;
}

template <class T>
T Node<T>::getValue() {
	return value;
}

template <class T>
Node<T> * Node<T>::getNext() {
	return next;
}

template <class T>
Node<T> * Node<T>::getPrev() {
	return prev;
}

template <class T>
void Node<T>::setValue(const T _value) {
	value = _value;
}

template <class T>
void Node<T>::setNext(Node<T> * _next) {
	next = _next;
}

template <class T>
void Node<T>::setPrev(Node<T> * _prev) {
	prev = _prev;
}

#endif