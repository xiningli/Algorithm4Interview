#pragma once
//#define MYPRO
//#define YOU
#define MENG
#ifdef MYPRO
#include <cstdint>
#include <vector>

namespace minmaxheap
{

	class mmheap
	{
	public:
		mmheap(uint32_t capacity);
		virtual ~mmheap();
		void buildHeap(const std::vector<int32_t> &vals);
		int32_t getMin() const;
		int32_t getMax() const;
		void insert(int32_t val);
		void deleteMin();
		void deleteMax();
		void printHeap();

	private:
		bool isAtMinLevel(uint32_t index) const;
		void percolateDown(uint32_t index);
		void percolateDownMin(uint32_t index);
		void percolateDownMax(uint32_t index);
		void percolateUp(uint32_t index);
		void percolateUpMin(uint32_t index);
		void percolateUpMax(uint32_t index);
		// add your own private functions here, if any
		void swap(int32_t* x, int32_t* y);
		bool isNULL(uint32_t index);
		int32_t findMinInChildrenAndGrandchildren(uint32_t index);
		int32_t findMaxInChildrenAndGrandchildren(uint32_t index);
	private:
		int32_t *_arr;
		uint32_t _capacity;
		uint32_t _size;
	};

} /* minmaxheap */
#endif
#ifdef YOU
#include <cstdint>
#include <vector>
#include <cmath>

namespace minmaxheap
{

	class mmheap
	{
	public:
		mmheap(uint32_t capacity) {
			_capacity = capacity;
			_arr = new int[_capacity];
			_size = 0;
		}

		virtual ~mmheap() {
			delete[] _arr;
		}

		void buildHeap(const std::vector<int32_t> &vals) {
			_size = vals.size();
			for (uint32_t i = 0; i < _size; i++) {
				_arr[i] = vals[i];
			}
			for (int i = (_size - 1) / 2; i >= 0; i--) {
				percolateDown(i);
			}
		}

		int32_t getMin() const {
			if (_size == 0)
				return 0;
			else
				return _arr[0];
		}

		int32_t getMax() const {
			if (_size == 0)
				return 0;
			else if (_size == 1)
				return _arr[0];
			else if (_size == 2)
				return _arr[1];
			else if (_arr[1] > _arr[2])
				return _arr[1];
			else
				return _arr[2];
		}

		void insert(int32_t val) {
			_arr[_size] = val;
			percolateUp(_size);
			_size++;
		}

		void deleteMin() {
			if (_size >= 0) {
				_arr[0] = _arr[_size - 1];
				_size--;
				percolateDown(0);
			}
		}

		void deleteMax() {
			if (_size <= 2) {
				_size--;
			}
			else if (_arr[1] > _arr[2]) {
				_arr[1] = _arr[_size - 1];
				_size--;
				percolateDown(1);
			}
			else {
				_arr[2] = _arr[_size - 1];
				_size--;
				percolateDown(2);
			}
		}

	private:
		bool isAtMinLevel(uint32_t index) const {
			int floor = log2(index + 1);
			if (floor == 0)
				return true;
			else
				return false;
		}

		void percolateDown(uint32_t index) {
			if (isAtMinLevel(index))
				percolateDownMin(index);
			else
				percolateDownMax(index);
		}

		void swap(uint32_t index1, uint32_t index2) {
			int32_t temp = _arr[index1];
			_arr[index1] = _arr[index2];
			_arr[index2] = temp;
		}

		uint32_t findsmallest(uint32_t index) {
			uint32_t c1 = index * 2 + 1;
			uint32_t c2 = index * 2 + 2;
			uint32_t gc1 = index * 4 + 3;
			uint32_t gc2 = index * 4 + 4;
			uint32_t gc3 = index * 4 + 5;
			uint32_t gc4 = index * 4 + 6;
			uint32_t smallest = c1;
			if (c2 <= _size && _arr[c2] < _arr[smallest])
				smallest = c2;
			if (gc1 <= _size && _arr[gc1] < _arr[smallest])
				smallest = gc1;
			if (gc2 <= _size && _arr[gc2] < _arr[smallest])
				smallest = gc2;
			if (gc3 <= _size && _arr[gc3] < _arr[smallest])
				smallest = gc3;
			if (gc4 <= _size && _arr[gc4] < _arr[smallest])
				smallest = gc4;
			return smallest;
		}

		uint32_t findbiggest(uint32_t index) {
			uint32_t c1 = index * 2 + 1;
			uint32_t c2 = index * 2 + 2;
			uint32_t gc1 = index * 4 + 3;
			uint32_t gc2 = index * 4 + 4;
			uint32_t gc3 = index * 4 + 5;
			uint32_t gc4 = index * 4 + 6;
			uint32_t biggest = c1;
			if (c2 <= _size && _arr[c2] > _arr[biggest])
				biggest = c2;
			if (gc1 <= _size && _arr[gc1] > _arr[biggest])
				biggest = gc1;
			if (gc2 <= _size && _arr[gc2] > _arr[biggest])
				biggest = gc2;
			if (gc3 <= _size && _arr[gc3] > _arr[biggest])
				biggest = gc3;
			if (gc4 <= _size && _arr[gc4] > _arr[biggest])
				biggest = gc4;
			return biggest;
		}

		void percolateDownMin(uint32_t index) {
			if (index * 2 + 1<_size) {
				int m = findsmallest(index);
				if ((m - 3) / 4 == index) {
					if (_arr[m] < _arr[index]) {
						swap(m, index);
						if (_arr[m] > _arr[(m - 1) / 2]) {
							swap(m, (m - 1) / 2);
						}
						percolateDownMin(m);
					}
				}
				else {
					if (_arr[m] < _arr[index]) {
						swap(m, index);
					}
				}
			}
		}

		void percolateDownMax(uint32_t index) {
			if (index * 2 + 1<_size) {
				int m = findbiggest(index);
				if ((m - 3) / 4 == index) {
					if (_arr[m] > _arr[index]) {
						swap(m, index);
						if (_arr[m] < _arr[(m - 1) / 2]) {
							swap(m, (m - 1) / 2);
						}
						percolateDownMax(m);
					}
				}
				else {
					if (_arr[m] > _arr[index]) {
						swap(m, index);
					}
				}
			}
		}

		void percolateUp(uint32_t index) {
			if (isAtMinLevel(index)) {
				if (index != 0 && _arr[index] > _arr[(index - 1) / 2]) {
					swap(_arr[index], _arr[(index - 1) / 2]);
					percolateUpMax((index - 1) / 2);
				}
				else
					percolateUpMin(index);
			}
			else {
				if (index != 0 && _arr[index] < _arr[(index - 1) / 2]) {
					swap(_arr[index], _arr[(index - 1) / 2]);
					percolateUpMin((index - 1) / 2);
				}
				else
					percolateUpMax(index);
			}
		}

		void percolateUpMin(uint32_t index) {
			if (index > 2) {
				if (_arr[index] < _arr[(index - 3) / 4]) {
					swap(_arr[index], _arr[(index - 3) / 4]);
					percolateUpMin(index);
				}
			}
		}

		void percolateUpMax(uint32_t index) {
			if (index > 2) {
				if (_arr[index] > _arr[(index - 3) / 4]) {
					swap(_arr[index], _arr[(index - 3) / 4]);
					percolateUpMax(index);
				}
			}
		}

	private:
		int32_t *_arr;
		uint32_t _capacity;
		uint32_t _size;
	};

} /* minmaxheap */

#endif // YOU
#ifdef MENG
#include <cstdint>
#include <vector>

namespace minmaxheap
{

	class mmheap
	{
	public:
		mmheap(uint32_t capacity);
		virtual ~mmheap();
		void buildHeap(const std::vector<int32_t> &vals);
		int32_t getMin() const;
		int32_t getMax() const;
		void insert(int32_t val);
		void deleteMin();
		void deleteMax();


	private:
		bool isAtMinLevel(uint32_t index) const;
		void percolateDown(uint32_t index);
		void percolateDownMin(uint32_t index);
		void percolateDownMax(uint32_t index);
		void percolateUp(uint32_t index);
		void percolateUpMin(uint32_t index);
		void percolateUpMax(uint32_t index);
		// add your own private functions here, if any
		bool isALeafNode(uint32_t index) const;
		bool hasAGrandparent(uint32_t index);
		bool hasAParent(uint32_t index);
		void swap(uint32_t index1, uint32_t index2);

		uint32_t findSmallest(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6);
		uint32_t findBiggest(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6);


	private:
		int32_t *_arr;
		uint32_t _capacity;
		uint32_t _size;
	};

} /* minmaxheap */

#endif // MENG
