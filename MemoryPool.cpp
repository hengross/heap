#include "MemoryPool.h"

MemoryPool * MemoryPool::insatnce = nullptr;
char * MemoryPool::arraychar = nullptr;
int MemoryPool::size = 0;

MemoryPool* MemoryPool::getInstance(int _size) {
	if (insatnce == nullptr) {
		cout << "Im MemPool Constructor" << endl;
		insatnce = (MemoryPool*)malloc(sizeof(MemoryPool));
		insatnce->arraychar = (char*)malloc(_size);
		for (int i = 0; i < _size; i++) {
			arraychar[i] = '0';
		}
		size = _size;
	}
	return insatnce;
}

char * MemoryPool::getArray() {
	return arraychar;
}

int MemoryPool::getSize() {
	return size;
}

MemoryPool::~MemoryPool() {
	cout << "here in pool distructor" << endl;
	free(arraychar);
	free(insatnce);
}