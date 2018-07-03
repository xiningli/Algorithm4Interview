
#include "mmheap.h"
#ifdef MYPRO
#include <math.h>
#include <iostream>
using namespace minmaxheap;

mmheap::mmheap(uint32_t capacity)
{
	_capacity = capacity;
	_arr = new int[_capacity];
	_size = 0;
}
mmheap::~mmheap()
{
	//delete
}
void mmheap::buildHeap(const std::vector<int32_t> &vals)
{
	for (int i = 0;i < vals.size() || i == _capacity;i++)
	{
		_arr[i] = vals[i];
		int temp = _arr[i];
	}
	_size = vals.size();
	for (int index = _size / 2 - 1; index >= 0; index--)
		percolateDown(index);
	//int breakPoint=0;
}
int32_t mmheap::getMin() const
{
	if (_size != 0)
		return _arr[0];
	else
		return 0;
}

int32_t mmheap::getMax() const
{
	if (_size == 0)
		return 0;
	else if (_size == 1)
		return _arr[0];
	else if (_size == 2)
		return _arr[1];
	else
		return _arr[1] > _arr[2] ? _arr[1] : _arr[2];
}
void mmheap::insert(int32_t val)
{
	_arr[_size] = val;
	percolateUp(_size);
	_size++;
}
void mmheap::deleteMin()
{
	_arr[0] = _arr[_size - 1];
	_size--;
	percolateDown(0);
}
void mmheap::deleteMax()
{
	if (_size == 1 || _size == 2)
		//return _arr[1];
		_size--;
	else
	{
		uint32_t maxIndex = _arr[1] > _arr[2] ? 1 : 2;
		_arr[maxIndex] = _arr[_size - 1];
		_size--;
		percolateDown(maxIndex);
	}
}

void minmaxheap::mmheap::printHeap()
{
	int level = 0;
	for (int i = 0;i < _size;i++)
	{
		std::cout << _arr[i] << '-';
		if (i+1 == pow(2, level+1) - 1)
		{
			std::cout << std::endl;
			level++;
		}
	}
}

bool mmheap::isAtMinLevel(uint32_t index) const
{
	int i = 1;
	int temp = 0;
	//for (;index - 1 < pow(2, i);i++);
	for (;;i++)
	{
		temp = pow(2, i);
		if (temp > index + 1)
			break;
	}
	int level = i - 1;
	if (level % 2 == 0)
		return true;
	else
		return false;
}
void mmheap::percolateDown(uint32_t index)
// called when build heap, 
// check the order of a node and its children and grandchildren
{
	if (isAtMinLevel(index))
		percolateDownMin(index);
	else
		percolateDownMax(index);
	int breakPoint=0;
}
void mmheap::percolateDownMin(uint32_t index)
{
	if (2 * index + 1 > _size - 1)				// if index has no child, exit
		return;
	int32_t minIndex = findMinInChildrenAndGrandchildren(index);
	if (minIndex > 2 * index + 2)				// if minIndex is grandChildren of index
	{
		if (_arr[minIndex] < _arr[index])
		{
			swap(&_arr[minIndex], &_arr[index]);
			int32_t minIndexParent = (minIndex - 1) / 2;
			if (_arr[minIndex] > _arr[minIndexParent])
				swap(&_arr[minIndex], &_arr[minIndexParent]);
			percolateDownMin(minIndex);
		}
	}
	else									// if minIndex is children of index
											// when traversal in the 2nd level(min) from bottom
	{
		if (_arr[minIndex] < _arr[index])
			swap(&_arr[minIndex], &_arr[index]);
	}
	
}
void mmheap::percolateDownMax(uint32_t index)
{
	int32_t maxIndex = findMaxInChildrenAndGrandchildren(index);
	if (maxIndex > 2 * index + 2)
	{
		if (_arr[maxIndex] > _arr[index])
		{
			swap(&_arr[maxIndex], &_arr[index]);
			int32_t maxIndexParent = (maxIndex - 1) / 2;
			if (&_arr[maxIndex] < &_arr[maxIndexParent])
				swap(&_arr[maxIndex], &_arr[maxIndexParent]);
			percolateDownMax(maxIndex);
		}
	}
	else
	{
		if (_arr[maxIndex] > _arr[index])
			swap(&_arr[maxIndex], &_arr[index]);
	}
}
void mmheap::percolateUp(uint32_t index)
// called when insert new element
{
	if (index == 0)	return;					// if index is root, stop percolateUp process
	int32_t indexParent = (index + 1) / 2 - 1;
	if (isAtMinLevel(index))	
	{
		if (_arr[index] > _arr[indexParent])	// if index>parent(index), index should be insert into maxHeap
		{
			swap(&_arr[index], &_arr[indexParent]);
			percolateUpMax(indexParent);
		}
		else								// if index<parent(index), index should be insert into minHeap
		{
			percolateUpMin(index);
		}
	}
	else //max level
	{
		if (_arr[index] < _arr[indexParent])	// if index<parent(index), index should be insert into minHeap
		{
			swap(&_arr[index], &_arr[indexParent]);
			percolateUpMin(indexParent);
		}
		else								// if index>parent(index), index should be insert into maxHeap
		{
			percolateUpMax(index);
		}
	}
}
void mmheap::percolateUpMin(uint32_t index)
{
	if (index < 3)	return;					// if index do not have grandparent in minHeap, exit
	int32_t indexParent = (index + 1) / 2 - 1;
	int32_t indexGrandarent = (indexParent + 1) / 2 - 1;
	//int32_t grandparent = (index / 2) / 2;
	if (_arr[index] < _arr[indexGrandarent])
		swap(&_arr[index], &_arr[indexGrandarent]);
	percolateUpMin(indexGrandarent);
}
void mmheap::percolateUpMax(uint32_t index)
{
	if (index < 3)	return;					// if index do not have grandparent in minHeap, exit
	int32_t indexParent = (index + 1) / 2 - 1;
	int32_t indexGrandarent = (indexParent + 1) / 2 - 1;
	if (_arr[index] > _arr[indexGrandarent])
		swap(&_arr[index], &_arr[indexGrandarent]);
	percolateUpMax(indexGrandarent);
}

void minmaxheap::mmheap::swap(int32_t* x, int32_t* y)
{
	int32_t tmp = *y;
	*y = *x;
	*x = tmp;
}

bool minmaxheap::mmheap::isNULL(uint32_t index)
{
	if (index > _size - 1)
		return true;
	else
		return false;
}

int32_t minmaxheap::mmheap::findMinInChildrenAndGrandchildren(uint32_t index)
{
	int32_t minIndex = 2 * index + 1;
	if (!isNULL(2 * index + 2))		minIndex = _arr[2 * index + 2] < _arr[minIndex] ? 2 * index + 2 : minIndex;
	if (!isNULL(4 * index + 3))		minIndex = _arr[4 * index + 3] < _arr[minIndex] ? 4 * index + 3 : minIndex;
	if (!isNULL(4 * index + 4))		minIndex = _arr[4 * index + 4] < _arr[minIndex] ? 4 * index + 4 : minIndex;
	if (!isNULL(4 * index + 5))		minIndex = _arr[4 * index + 5] < _arr[minIndex] ? 4 * index + 5 : minIndex;
	if (!isNULL(4 * index + 6))		minIndex = _arr[4 * index + 6] < _arr[minIndex] ? 4 * index + 6 : minIndex;
	return minIndex;
}

int32_t minmaxheap::mmheap::findMaxInChildrenAndGrandchildren(uint32_t index)
{
	int32_t maxIndex = 2 * index + 1;
	if (!isNULL(2 * index + 2))		maxIndex = _arr[2 * index + 2] > _arr[maxIndex] ? 2 * index + 2 : maxIndex;
	if (!isNULL(4 * index + 3))		maxIndex = _arr[4 * index + 3] > _arr[maxIndex] ? 4 * index + 3 : maxIndex;
	if (!isNULL(4 * index + 4))		maxIndex = _arr[4 * index + 4] > _arr[maxIndex] ? 4 * index + 4 : maxIndex;
	if (!isNULL(4 * index + 5))		maxIndex = _arr[4 * index + 5] > _arr[maxIndex] ? 4 * index + 5 : maxIndex;
	if (!isNULL(4 * index + 6))		maxIndex = _arr[4 * index + 6] > _arr[maxIndex] ? 4 * index + 6 : maxIndex;
	return maxIndex;
}
#endif

#ifdef MENG
#include "mmheap.h"
using namespace minmaxheap;
mmheap::mmheap(uint32_t capacity) {
	_capacity = capacity;
	_arr = new int[_capacity];
	_size = 0;
}

mmheap:: ~mmheap() {
	delete[] _arr;
}

uint32_t mmheap::findSmallest(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6) {
	int answer = a1;
	if (a2 <= _size && _arr[a2] < _arr[answer]) answer = a2;
	if (a3 <= _size && _arr[a3] < _arr[answer]) answer = a3;
	if (a4 <= _size && _arr[a4] < _arr[answer]) answer = a4;
	if (a5 <= _size && _arr[a5] < _arr[answer]) answer = a5;
	if (a6 <= _size && _arr[a6] < _arr[answer]) answer = a6;
	return answer;
}

uint32_t mmheap::findBiggest(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6) {
	int answer = a1;
	if (a2 <= _size && _arr[a2] > _arr[answer]) answer = a2;
	if (a3 <= _size && _arr[a3] > _arr[answer]) answer = a3;
	if (a4 <= _size && _arr[a4] > _arr[answer]) answer = a4;
	if (a5 <= _size && _arr[a5] > _arr[answer]) answer = a5;
	if (a6 <= _size && _arr[a6] > _arr[answer]) answer = a6;
	return answer;
}

void mmheap::swap(uint32_t index1, uint32_t index2) {
	int temp;
	temp = _arr[index1];
	_arr[index1] = _arr[index2];
	_arr[index2] = temp;
}

bool mmheap::isAtMinLevel(uint32_t index) const {
	int count = -1;
	while (index > 0) {
		index = index / 2;
		count = count + 1;
	}
	if (count % 2 == 0)
		return true;
	else
		return false;
}

bool mmheap::isALeafNode(uint32_t index) const {
	if (2 * index > _size)
		return true;
	else
		return false;
}

bool mmheap::hasAParent(uint32_t index) {
	if (index < 2) return false;
	else return true;
}

bool mmheap::hasAGrandparent(uint32_t index) {
	if (index < 4) return false;
	else return true;
}

void mmheap::percolateDown(uint32_t index) {
	if (isAtMinLevel(index) == true)
		percolateDownMin(index);
	else
		percolateDownMax(index);
}

void mmheap::percolateDownMin(uint32_t index) {
	if (isALeafNode(index) == false) {
		int m = findSmallest(2 * index, 2 * index + 1, 4 * index, 4 * index + 1, 4 * index + 2, 4 * index + 3);
		if (m != 2 * index && m != (2 * index + 1)) {
			if (_arr[m] < _arr[index]) {
				swap(m, index);
				if (_arr[m] > _arr[m / 2]) {
					swap(m, m / 2);
				}
				percolateDownMin(m);
			}
		}
		else {
			if (_arr[m] < _arr[index]) {
				swap(index, m);
			}
		}
	}
}

void mmheap::percolateDownMax(uint32_t index) {
	if (isALeafNode(index) == false) {
		int m = findBiggest(2 * index, 2 * index + 1, 4 * index, 4 * index + 1, 4 * index + 2, 4 * index + 3);
		if (m != 2 * index && m != (2 * index + 1)) {
			if (_arr[m] > _arr[index]) {
				swap(m, index);
				if (_arr[m] < _arr[m / 2]) {
					swap(m, m / 2);
				}
				percolateDownMax(m);
			}
		}
		else {
			if (_arr[m] > _arr[index]) {
				swap(index, m);
			}
		}
	}
}

void mmheap::percolateUp(uint32_t index) {
	if (isAtMinLevel(index) == true) {
		if ((hasAParent(index) == true) && (_arr[index] > _arr[index / 2])) {
			swap(index, index / 2);
			percolateUpMax(index / 2);
		}
		else {
			percolateUpMin(index);
		}
	}
	else {
		if ((hasAParent(index) == true) && (_arr[index] < _arr[index / 2])) {
			swap(index, index / 2);
			percolateUpMin(index / 2);
		}
		else {
			percolateUpMax(index);
		}
	}
}

void mmheap::percolateUpMin(uint32_t index) {
	if (hasAGrandparent(index) == true) {
		if (_arr[index] < _arr[index / 4]) {
			swap(index, index / 4);
			percolateUpMin(index / 4);
		}
	}
}

void mmheap::percolateUpMax(uint32_t index) {
	if (hasAGrandparent(index) == true) {
		if (_arr[index] > _arr[index / 4]) {
			swap(index, index / 4);
			percolateUpMax(index / 4);
		}
	}
}

void mmheap::buildHeap(const std::vector<int32_t> &vals) {
	_size = vals.size();

	for (int32_t i = 0; i < _size; i++) {
		_arr[i + 1] = vals[i];
	}

	for (int32_t i = _size / 2; i > 0; i--) {
		percolateDown(i);
	}
}

int32_t mmheap::getMin() const {
	if (_size == 0)
		return 0;
	else return _arr[1];
}

int32_t mmheap::getMax() const {
	if (_size == 0)
		return 0;
	else if (_size == 1)
		return _arr[1];
	else if (_size == 2)
		return _arr[2];
	else if (_arr[2] > _arr[3])
		return _arr[2];
	else return _arr[3];
}

void mmheap::insert(int32_t val) {
	_size++;
	_arr[_size] = val;
	percolateUp(_size);
}

void mmheap::deleteMin() {
	if (_size == 0)
		return;
	else if (_size >= 1) {
		_arr[1] = _arr[_size];
		_size--;
		percolateDown(1);
	}
}

void mmheap::deleteMax() {
	if (_size == 0)
		return;
	else if (_size < 3) {
		_size--;
	}
	else if (_arr[2] > _arr[3]) {
		_arr[2] = _arr[_size];
		_size--;
		percolateDown(2);
	}
	else {
		_arr[3] = _arr[_size];
		_size--;
		percolateDown(3);
	}
}
#endif // MENG
