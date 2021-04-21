#ifndef DISTANCES_H
#define DISTANCES_H
#include <iostream>
using namespace std;	

struct vertexHeapNode *newVertexHeapNode(int v, float dist, int color);
int isEmptyVertex(struct VertexHeap *vertHeap);
struct vertexHeap *createVertexHeap(int capacity);
void swapVertexHeapNode(struct VertexHeapNode** a, struct VertexHeapNode** b);
void vertexHeapify(struct VertexHeap* minHeap, int idx);
bool isInVertexHeap(struct VertexHeap *vertHeap, int v);
struct VertexHeapNode* extractMinVertex(struct VertexHeap *vertexHeap);
void decreaseVertexKey(struct VertexHeap* vertexHeap,int v, float dist);

struct VertexHeapNode
{
	int v;
	float dist;
	int color; //1 for white, 2 for grey, 3 black
};

// Structure to represent a min heap
struct VertexHeap
{
	
	// Number of heap nodes present currently
	int size;	

	// Capacity of min heap
	int capacity;

	// This is needed for decreaseKey()
	int *pos;
	struct vertexHeapNode **array;
};

#endif
