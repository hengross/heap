#pragma once
#include "MemoryPool.h"
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class MemoryManager {
private:
	//char* arraychar; //data in array  - the heap
	int* arrayint; //size of bytes in the begin (first place) they placed
	char* bytes10; //every block we allocted - so we can jump from block to block to find one free
	int arraysize;
	/*
	here we will investigate the the allocated, free and leaking blocks and bytes. 
	return information to main class in graphs. 
	*/
	int allocblocks = 0;//update every time we call new
	int allocbytes = 0; //update every time we call new
	//string* s ; 
	//vector<int> vecDifSize; //different sizes of blocks
	//vector<int> listOfLeakingBlocks; // leaking blocks - the place they allocated - place in memory
	int* diff;
	int i = 0;
	static MemoryPool* insatnce;
public:
	MemoryManager();
	MemoryManager(int size);
	char* getcharArry();
	char* getbytesArry();
	int* getintArry();
	int getArraysize();
	void setArraysize(int size);
	int countHowMantEmpt(int index);
	void setallocblocks(int blockSize);
	void setallocbytes(int bytes);
	//void setVecOfSizes(int difSize);
	//bool exist(int index);
	int getallocblocks();
	int getallocbytes();
	int* getVecOfSizes();
	//int leackingBlocks();
	//int leakingBytes();
};