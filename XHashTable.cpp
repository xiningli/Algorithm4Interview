#include "XHashTable.h"

void XHashTable::initializeHashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		table[i] = 0;
		elementState[i] = EMPTY;
	}
}

int XHashTable::hash(int element)
{
	return element % tableSize;
}


XHashTable::XHashTable(int tableSize)
{
	this->tableSize = tableSize;
	table = new int[tableSize];
	elementState = new ElementState[tableSize];
	initializeHashTable();
}

XHashTable::~XHashTable()
{
}

int XHashTable::findElementPosition(int element)
{
	int key = hash(element);
	for (int i = 0;i < tableSize;i++)
	{
		if (table[key + i] == element&&elementState[key + i] == ACTIVE)
			return key+i;
		if (elementState[key + i] == EMPTY)
			return -1;				// no such element
	}
}

bool XHashTable::search(int element)
{
	int searchResult = findElementPosition(element);
	if (searchResult != -1)
		return true;
	else
		return false;
}

bool XHashTable::insert(int newElement)
{
	if (elementCount == tableSize)	// if table is full, return false
		return false;
	if (search(newElement))			// if the element already exists, return false
		return false;
	int key = hash(newElement);
	for (int i = 0;i < tableSize;i++)
	{
		if (elementState[key + i] == DELETED || elementState[key + i] == EMPTY)
		{
			table[key + i] = newElement;
			elementState[key + i] = ACTIVE;
			elementCount++;
			return true;
		}
	}
	return false;
}

bool XHashTable::del(int element)
{
	if (elementCount == 0)			// if table is empty, return false
		return false;
	int position = findElementPosition(element);
	if (position == -1)
		return false;					// if the element does not exists, return false
	else
	{
		table[position] = 0;
		elementState[position] = DELETED;
	}
	return true;
}

void XHashTable::printTable()
{
	for (int i = 0;i < tableSize;i++)
	{
		if (elementState[i] == ACTIVE)
			std::cout << table[i] << ' ';
		else
			std::cout << "- ";
	}
	std::cout << std::endl;
}

int XHashTable::getTableSize()
{
	return tableSize;
}
