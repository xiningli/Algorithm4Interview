#pragma once
#include <iostream>
#include <string>
enum ElementState { EMPTY, ACTIVE, DELETED };
class XHashTable
{
private:	
	int* table;
	ElementState* elementState;
	int tableSize;
	int elementCount;
	int hash(int element);

public:
	XHashTable(int tableSize);
	~XHashTable();
	void initializeHashTable();
	int findElementPosition(int element);
	bool search(int element);
	bool insert(int newElement);
	bool del(int element);
	void printTable();
	int getTableSize();
};

