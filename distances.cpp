#include "distances.h"
#include <iostream>
#include <cmath>
using namespace std;

struct VertexHeapNode* newVertexHeapNode(int v, float dist, int color)
{
	struct VertexHeapNode* vertexHeapNode = new VertexHeapNode;
	vertexHeapNode->v = v;
	vertexHeapNode->dist = dist;
	vertexHeapNode->color = color;
	return VertexHeapNode;
}

// A utility function to create a vertex Heap
struct VertexHeap* createVertexHeap(int capacity)
{
	struct VertexHeap* vertexHeap = new VertexHeap;
	vertexHeap->pos = new int[capacity];
	vertexHeap->size = 0;
	vertexHeap->capacity = capacity;
	vertexHeap->array = newVertexHeapNode*[capacity];
	return vertexHeap;
}

void swapVertexHeapNode(struct VertexHeapNode** a, struct VertexHeapNode** b)
{
	struct VertexHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void vertexHeapify(struct VertexHeap* vertexHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < vertexHeap->size && vertexHeap->array[left]->dist < vertexHeap->array[smallest]->dist )
		smallest = left;

	if (right < vertexHeap->size && vertexHeap->array[right]->dist < vertexHeap->array[smallest]->dist )
		smallest = right;

	if (smallest != idx)
	{
		// The nodes to be swapped in vertex heap
		VertexHeapNode *smallestNode = vertexHeap->array[smallest];
		VertexHeapNode *idxNode = vertexHeap->array[idx];

		// Swap positions
		vertexHeap->pos[smallestNode->v] = idx;
		vertexHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		swapVertexHeapNode(&vertexHeap->array[smallest], &vertexHeap->array[idx]);

		vertexHeapify(vertexHeap, smallest);
	}
}

int isEmpty(struct VertexHeap* vertexHeap)
{
	return vertexHeap->size == 0;
}

bool isInVertexHeap(struct VertexHeap *vertexHeap, int v)
{
	if (vertexHeap->pos[v] < vertexHeap->size)
		return true;
	return false;
}

void insertKey(struct VertexHeap *vertexHeap, int capacity, int vertex, float distance)
{
    if (vertexHeap->size == capacity)
    {
        return;
    }
  
    // First insert the new key at the end
    vertexHeap->size++;
    int i = vertexHeap->size - 1;
    vertexHeap->pos[vertex] = vertex;
    vertexHeap->array[i]->v = vertex;
    vertexHeap->array[i]->dist = distance;
  
    // Fix the vertex heap property if it is violated
    while (i != 0 && vertexHeap->array[(i-1)/2] > vertexHeap->array[i])
    {
       vertexHeap *heapOne = vertexHeap->array[(i-1)/2];
       vertexHeap *heapTwo = vertexHeap->array[i];
       
       swapVertexHeapNode(&heapOne, &heapTwo);
       i = (i-1)/2;
    }
}

struct VertexHeapNode* extractMinVertex(struct VertexHeap *vertexHeap)
{
	if (isEmpty(vertexHeap))
		return NULL;

	// Store the root node
	struct VertexHeapNode* root = vertexHeap->array[0];

	// Replace root node with last node
	struct VertexHeapNode* lastNode = vertexHeap->array[vertexHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node
	vertexHeap->pos[root->v] = vertexHeap->size-1;
	vertexHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--vertexHeap->size;
	vertexHeapify(vertexHeap, 0);

	return root;
}

void decreaseVertexKey(struct VertexHeap* vertexHeap,int v, float dist)
{
	// Get the index of v in heap array
	int i = vertexHeap->pos[v];

	// Get the node and update its dist value
	vertexHeap->array[i]->dist = dist;

	// Travel up while the complete
	// tree is not hepified.
	// This is a O(Logn) loop
	while (i && vertexHeap->array[i]->dist < vertexHeap->array[(i - 1) / 2]->dist)
	{
		// Swap this node with its parent
		vertexHeap->pos[vertexHeap->array[i]->v] = (i-1)/2;
		vertexHeap->pos[vertexHeap->array[(i-1)/2]->v] = i;
		swapVertexHeapNode(&vertexHeap->array[i], &vertexHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}
