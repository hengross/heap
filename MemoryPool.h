#pragma once
#include <iostream>
using namespace std;
class MemoryPool {
private:
	static char* arraychar;
	static MemoryPool* insatnce;
	static int size;
public:
	~MemoryPool();
	static MemoryPool* getInstance(int _size);
	static char * getArray();
	static int getSize();
};