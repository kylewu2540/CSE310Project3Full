#ifndef MINHEAPSHORT_H
#define MINHEAPSHORT_H
#include <iostream>
using namespace std;

struct MinHeapNode *newMinHeapNode(int v, float dist, int color);
int isEmpty(struct MinHeap* minHeap);
struct MinHeap *createMinHeap(int capacity);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
void minHeapify(struct MinHeap* minHeap, int idx);
bool isInMinHeap(struct MinHeap *minHeap, int v);
void insertMinKey(struct MinHeap *minHeap, int capacity, int vertex, float distance);

struct MinHeapNode
{
	int v;
	float dist;
	int color;
};

// Structure to represent a min heap
struct MinHeap
{
	
	// Number of heap nodes present currently
	int size;	

	// Capacity of min heap
	int capacity;

	// This is needed for decreaseKey()
	int *pos;
	struct MinHeapNode **array;
};

#endif
