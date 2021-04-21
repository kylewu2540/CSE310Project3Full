#ifndef SHORTESTPATHCOMPUTATION_H
#define SHORTESTPATHCOMPUTATION_h
#include <iostream>
using namespace std;

void shortestSinglePair(struct Vertex **graph, int src, int dest, int numVertices, int flag);
void shortestSingleSource(struct Vertex **graph, int src, int numVertices, int flag);
void insertDirected(struct Vertex **graph, int u, float weight);
void insertUndirected(struct Vertex **graph, int u, int v, float weight);

struct AdjListNode
{
	int vertex_v;
	float weight;
	int color;
};

struct Vertex
{
	int vertex_u;
	struct AdjListNode adjList;
	struct Vertex *next;
};


#endif
