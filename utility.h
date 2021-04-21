#ifndef UTILITY_H
#define UTILITY_H
#include "shortestpathcomputation.h"
#include "minHeapShort.h"
#include "distances.h"
#include <iostream>
#include <string>
using namespace std;

void readFile(string fileName, struct Vertex **graph, string direction);
void findSrcDest(struct MinHeap *minheap, struct Vertex **graph, int src, int dest, int flag, int numVertices);
void writePath(struct MinHeap *minheap, struct Vertex **graph, int src, int dest, int numVertices);
void executeQueries();
void deleteEverything(struct MinHeap *minheap, struct Vertex **graph, struct VertexHeap *vertexHeap, int numEdges);

#endif
