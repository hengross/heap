#include <iostream>
#include "MemoryManager.hpp"
#include "LinkedList.h"
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

MemoryManager m;

/*
print heap and heap headers 
to see heap data, allocated place, blocks sizes and bytes.
*/
void printintArray() { //print int array
	for (int i = 0; i<m.getArraysize(); i++) {
		cout << m.getintArry()[i] << ",";
	}
}

void printArray() { //print the data array - the heap!
	for (int i = 0; i<m.getArraysize(); i++) {
		cout << m.getcharArry()[i] << ",";
	}
}

void printbytesArray() { //print the bytes array
	for (int i = 0; i<m.getArraysize(); i++) {
		cout << m.getbytesArry()[i] << ",";
	}
}

void* operator new (size_t n) {
	//cout << "here1 \n";
	//change the size to n%8==0 !
	// ...
	//int a = n % 8;
	//int nnew = n + a;
	cout << n << "hfdsfdjfds";
	int n8 = n;
	if (n == 1) n8 = 1;
	else if (n == 2) n8 = 2;
	else if (n<=4) n8 = 4;
	else if (n<=8)
		n8 = 8;
	else if (n<=16)
		n8 = 16;
	else if (n<=32)
		n8 = 32;
	else if (n<=64)
		n8 = 64;
	else if (n<=128)
		n8 = 128;
	else if (n<=256)
		n8 = 256;
	else if (n<=512)
		n8 = 512;
	else
		n8 = 1028;
	cout << n8 << " n8 hfdsfdjfds";
	bool canAdd = false;
	size_t i = 0;
	for (i = 0; i<m.getArraysize(); i++) {
		if ((m.getbytesArry()[i] == '0')&& m.getintArry()[i] == 0) {
			int d = m.countHowMantEmpt(i); //how many bytes are free
			if (d >= n8) {
				m.getintArry()[i] = n8;
				for (size_t j = i; j <i+ n8; j++) {
					m.getcharArry()[j] = '1';
					m.getbytesArry()[j] = '1';
				}
				canAdd = true;
				break;
			}
		}
		
	}
	if (canAdd) {
		cout << "found place to allocate \n";
		m.setallocblocks(n8);
		m.setallocbytes(n8);
		//m.setVecOfSizes(nnew);
	}
	else
		cout << "can't find place to allocate \n";
	printArray();
	cout << "char in new \n";
	printintArray();
	cout << "int in new \n";
	printbytesArray();
	cout << "bytes int new \n";
	return &m.getcharArry()[i];
}
void operator delete (void* del) {
	if (!del)
		return;
	unsigned long ptr1 = (unsigned long)del;
	unsigned long ptr2 = (unsigned long)(m.getcharArry());
	unsigned long block = ptr1-ptr2;
	int godel = m.getintArry()[block];
	m.getintArry()[block] = 0;
	cout << "block: " << block << " godel: " << godel << "\n";
	for (size_t i = block; i <(godel + block); i++) {
		//cout << "del \n";
		m.getcharArry()[i] = '0';
		m.getbytesArry()[i] = '0';
	}
	
	cout << block << "block ";
	printArray();
	cout << "char in del \n";
	printintArray();
	cout << "int in del \n";
	//printbytesArray();
	//cout << "bytes int del \n";
}

void* operator new[](size_t n) {
	cout << n << "hfdsfdjfds";
	int n8 = n;
	if (n == 1) n8 = 1;
	else if (n == 2) n8 = 2;
	else if (n <= 8)
		n8 = 8;
	else if (n <= 16)
		n8 = 16;
	else if (n <= 32)
		n8 = 32;
	else if (n <= 64)
		n8 = 64;
	else if (n <= 128)
		n8 = 128;
	else if (n <= 256)
		n8 = 256;
	else if (n <= 512)
		n8 = 512;
	else
		n8 = 1028;
	cout << n8 << " n8 hfdsfdjfds";
	bool canAdd = false;
	size_t i = 0;
	for (i = 0; i<m.getArraysize(); i++) {
		if ((m.getbytesArry()[i] == '0') && m.getintArry()[i] == 0) {
			int d = m.countHowMantEmpt(i); //how many bytes are free
			if (d >= n8) {
				m.getintArry()[i] = n8;
				for (size_t j = i; j <i + n8; j++) {
					m.getcharArry()[j] = '1';
					m.getbytesArry()[j] = '1';
				}
				canAdd = true;
				break;
			}
		}

	}
	if (canAdd) {
		cout << "found place to allocate \n";
		m.setallocblocks(n8);
		m.setallocbytes(n8);
	}
	else
		cout << "can't find place to allocate \n";
	printArray();
	cout << "char in new \n";
	printintArray();
	cout << "int in new \n";
	//printbytesArray();
	//cout << "bytes int new \n";
	return &m.getcharArry()[i];
}
void operator delete[] (void* del) {
	if (!del)
		return;
	unsigned long ptr1 = (unsigned long)del;
	unsigned long ptr2 = (unsigned long)(m.getcharArry());
	unsigned long block = ptr1 - ptr2;
	int godel = m.getintArry()[block];
	m.getintArry()[block] = 0;
	cout << "block: " << block << " godel: " << godel << "\n";
	for (size_t i = block; i <(godel + block); i++) {
		//cout << "del \n";
		m.getcharArry()[i] = '0';
		m.getbytesArry()[i] = '0';
	}

	cout << block << "block ";
	printArray();
	cout << "char in del \n";
	printintArray();
	cout << "int in del \n";
	printbytesArray();
	cout << "bytes int del \n";
}

int alloceted = 0;
int allocBytes = 0;
//map<int, int> leak;
/*
the number of blocks that are not free and the number of bytes 
and a list of places that we allocated those leaking blocks
*/
//האם זה האפס האחרון במערך - כי לפניו כל הבלוקים האלו מוקצים
int LeakyBlocks() {
	alloceted = 0;
	for (int i = 0; i < m.getArraysize(); i++) {
		if (m.getintArry()[i] != 0) {
			//leak[i] = m.getintArry()[i];
			alloceted++;
			allocBytes += m.getintArry()[i];
		}
		//else
			//i = i + m.getintArry()[i] - 1;
	}
	return alloceted;
}

int leakyBytes() {
	return allocBytes;
}

/*
analyse heap memory. show number of blocks and bytes we have allocated on the heap. show number of blocks and bytes we have not free yet-leaky blocks.
*/
void valgring() {
	cout << "numbre of blocks that was allocated :" << m.getallocblocks() << "\n";
	cout << "numbre of bytes that was allocated :" << m.getallocbytes() << "\n";
	cout << "all different sizes of blocks:" << "\n";
	for (int i = 0; i < m.getArraysize() && (m.getVecOfSizes()[i]!=0); i++) {
		cout << m.getVecOfSizes()[i] << ",";
	}
	cout << "\n"; 
	alloceted = LeakyBlocks();
	allocBytes = leakyBytes();
	cout << "numbre of leaking blocks :" << alloceted << "\n";
	cout << "numbre of leaking bytes :" << allocBytes << "\n";
	for (int i = 0; i < m.getArraysize(); i++) {
		if (m.getintArry()[i] != 0)
			cout << "in place: " << i << "allocated leaky block in size of: " << m.getintArry()[i] << "\n";
	}
}



int main(int argc, char* argv[]) {
	//cout << "\n";
	//int* n = new int();
	
	//cout << "\n";
	//m.printArray();
	//cout << "\n";
	//delete n;
	//delete d;
	//char* c = new char();
	
	//int* nn = new int();
	
	//char* c2 = new char();
	//delete d;
	//char* c5 = new char();
	//int* nnn = new int();
	/*
	char* d = new char('a');
	double* l = new double(1.0);
	char* c1 = new char();
	char* c3 = new char();
	char* c4 = new char();
	delete d;
	char* c6 = new char();
	delete c3;
	char* c7 = new char();
	delete l;
	int* n = new int();
	int* nnn = new int(5);
	*/

	//LinkedList<int> *l = new LinkedList<int>();
	//int *a = new int(5);
	//l->add(*a);
	//l->add(8);

	/*
	int memorySize;
	cout << "Please enter size for heap: ";
	cin >> memorySize;

	mm(memorySize);
*/
	m = MemoryManager(stoi(argv[2]));
	/*
	LinkedList<double> *l = new LinkedList<double>();
	double *d = new double(7);
	l->add(8.9);
	double* c6 = new double(8);
	l->add(*c6);
	l->remove(8.9);
	double* c7 = new double();
	double* c1 = new double();
	double* c3 = new double();
	l->add(*c7);
	l->remove(8);
	//double* c1 = new double();
	//l->add(1);
	//double* c3 = new double();
	//l->add(9);
	//delete c6;
	//delete d;
	//double* c4 = new double();
	//l->add(3);
	//delete c7;
//	*/
	
//	m = MemoryManager(500);
	LinkedList<pair<char *, long *> *> ll = LinkedList<pair<char *, long *> *>();
//	char* c = new char(8);
//	/*
//	/*
	char *a = new char('a');
	char *b = new char('b');
	char *c = new char('c');
	char *d = new char('d');
	char *e = new char('e');
	char *f = new char('f');

	long *l1 = new long(1);
	long *l2 = new long(2);
	long *l3 = new long(3);
	long *l4 = new long(4);
	long *l5 = new long(5);
	long *l6 = new long(6);


	pair<char *, long *> *p1 = new pair<char *, long *>(a, l1);
	pair<char *, long *> *p2 = new pair<char *, long *>(b, l2);
	pair<char *, long *> *p3 = new pair<char *, long *>(c, l3);
	pair<char *, long *> *p4 = new pair<char *, long *>(d, l4);
	pair<char *, long *> *p5 = new pair<char *, long *>(e, l5);
	pair<char *, long *> *p6 = new pair<char *, long *>(f, l6);

	ll.add(p1);
	ll.add(p2);
	ll.add(p3);
	ll.add(p4);
	ll.add(p5);
	ll.add(p6);

	ll.remove();
	ll.remove();
	ll.remove();
	ll.remove();
	ll.remove();
	ll.remove();

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;

	delete l1;
	delete l2;
	delete l3;
	delete l4;
	delete l5;
	delete l6;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
//	*/
	valgring();
	getchar();
	return 1;
}
