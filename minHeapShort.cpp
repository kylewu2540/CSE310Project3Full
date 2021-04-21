#include "minHeapShort.h"
#include <iostream>
#include <cmath>
using namespace std;

struct MinHeapNode* newMinHeapNode(int v, float dist, int color)
{
	struct MinHeapNode* minHeapNode = new MinHeapNode;
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	minHeapNode->color = color;
	return minHeapNode;
}

// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = new MinHeap;
	minHeap->pos = new int[capacity];
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = newMinHeapNode*[capacity];
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist )
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist )
		smallest = right;

	if (smallest != idx)
	{
		// The nodes to be swapped in min heap
		MinHeapNode *smallestNode = minHeap->array[smallest];
		MinHeapNode *idxNode = minHeap->array[idx];

		// Swap positions
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

bool isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

void insertMinKey(struct MinHeap *minHeap, int capacity, int vertex, float distance)
{
    if (minHeap->size == capacity)
    {
        return;
    }
  
    // First insert the new key at the end
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->pos[vertex] = vertex;
    minHeap->array[i]->v = vertex;
    minHeap->array[i]->dist = distance;
  
    // Fix the min heap property if it is violated
    while (i != 0 && minHeap->array[(i-1)/2] > minHeap->array[i])
    {
       minHeap *heapOne = minHeap->array[(i-1)/2];
       minHeap *heapTwo = minHeap->array[i];
       
       swapMinHeapNode(&heapOne, &heapTwo);
       i = (i-1)/2;
    }
}

struct MinHeapNode* extractDestination(struct MinHeap *minHeap, int dest)
{
	if (isEmpty(minHeap))
		return NULL;

	struct MinHeapNode* root = minHeap->array[dest];

	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[size] = lastNode;

	// Update position of last node
	minHeap->pos[root->v] = minHeap->size-1;
	minHeap->pos[lastNode->v] = dest;

	// Reduce heap size and heapify root
	--minHeap->size;
	minHeapify(minHeap, dest);

	return root;
}

