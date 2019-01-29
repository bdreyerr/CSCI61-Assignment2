#ifndef MINPQ_H
#define MINPQ_H
#include <iostream>
#include <climits>
using namespace std;

// Prototype of a utility function to swap two Keys
template<class Key>
void swap(Key *x, Key *y);

// A class for Min Heap 
template<class Key>
class minPQ 
{
	Key *pq; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int size; // Current number of elements in min heap 
public:
	// Constructor 
	minPQ(int capacity);

	// to heapify a subtree with the root at given index 
	void minPQify(int);

	int parent(int i) { return (i - 1) / 2; }

	// to get index of left child of node at index i 
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i 
	int right(int i) { return (2 * i + 2); }

	// to extract the root which is the minimum element 
	Key extractMin();

	// Returns the minimum key (key at root) from min heap 
	Key getMin() { return pq[0]; }

	// Deletes a key stored at index i 
	//void deleteKey(Key i);

	// Inserts a new key 'k' 
	void insert(Key k);

	bool isEmpty() {
		if (capacity == 0)
			return true;
		else
			return false;
	}
};

// Constructor: Builds a heap from a given array a[] of given size 
template <class Key>
minPQ<Key>::minPQ(int cap)
{
	size = 0;
	capacity = cap;
	pq = new Key[cap];
}

// Inserts a new key 'k' 
template <class Key>
void minPQ<Key>::insert(Key k)
{
	if (size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end 
	size++;
	int i = size - 1;
	pq[i] = k;

	// Fix the min heap property if it is violated 
	while (i != 0 && pq[parent(i)] > pq[i])
	{
		swap(&pq[i], &pq[parent(i)]);
		i = parent(i);
	}
}


// Method to remove minimum element (or root) from min heap 
template <class Key>
Key minPQ<Key>::extractMin()
{
	if (size <= 0)
		return NULL;
	if (size == 1)
	{
		size--;
		return pq[0];
	}

	// Store the minimum value, and remove it from heap 
	Key root = pq[0];
	pq[0] = pq[size - 1];
	size--;
	minPQify(0);

	return root;
}


//// This function deletes key at index i. It first reduced value to minus 
//// infinite, then calls extractMin() 
//template <class Key>
//void minPQ<Key>::deleteKey(Key i)
//{
//	decreaseKey(i, INT_MIN);
//	extractMin();
//}

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
template <class Key>
void minPQ<Key>::minPQify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < size && pq[l] < pq[i])
		smallest = l;
	if (r < size && pq[r] < pq[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&pq[i], &pq[smallest]);
		minPQify(smallest);
	}
}

// A utility function to swap two elements 
template <class Key>
void swap(Key *x, Key *y)
{
	Key temp = *x;
	*x = *y;
	*y = temp;
}

#endif 