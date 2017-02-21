#include "MemoryManager.hpp"

MemoryPool* MemoryManager::insatnce = nullptr;

MemoryManager::MemoryManager() {

}
MemoryManager::MemoryManager(int size) {
	cout << "in constructor\n";
	arraysize = size;
	insatnce = insatnce->getInstance(arraysize);
	//arraychar = (char *)malloc(arraysize * sizeof(char));
	bytes10 = (char *)malloc(arraysize * sizeof(char));
	arrayint = (int *)malloc(arraysize * sizeof(int));
	diff = (int *)malloc(arraysize * sizeof(int));
	//empty = (int *)malloc(size * sizeof(int));
	for (int i = 0; i<arraysize; i++) {
		//arraychar[i] = '0';
		arrayint[i] = 0;
		bytes10[i] = '0';
		diff[i] = 0;
	}
}

int MemoryManager::getArraysize() {
	return arraysize;
}

void MemoryManager::setArraysize(int size) {
	arraysize = size;
}

char* MemoryManager::getbytesArry() {
	return bytes10;
}

char* MemoryManager::getcharArry() {
	return insatnce->getArray();
}
int* MemoryManager::getintArry() {
	return arrayint;
}

int MemoryManager::countHowMantEmpt(int index) {
	int counter = 0;
	for (int i = index; i < arraysize; i++) {
		while (arrayint[i] == 0 && i < arraysize) {
			counter++;
			i++;
		}
		return counter;
	}
}


void MemoryManager::setallocblocks(int blockSize) {
	allocblocks ++;
	diff[i++] = blockSize;
}

void MemoryManager::setallocbytes(int bytes) {
	allocbytes = allocbytes + bytes;
}

int MemoryManager::getallocblocks() {
	return allocblocks;
}

int MemoryManager::getallocbytes() {
	return allocbytes;
}

int* MemoryManager::getVecOfSizes() {
	return diff;
}
