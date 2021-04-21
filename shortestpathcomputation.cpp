#include "minHeapShort.h"
#include "shortestpathcomputation.h"
#include "distances.h"
#include <iosteam>
#include <cmath>
using namespace std;

void shortestSinglePair(struct Vertex **graph, int src, int dest, int numVertices, int flag)
{
	struct VertexHeap *vertexHeap = createVertexHeap(numVertices);  
	struct MinHeap *minHeap = createMinHeap(numVertices);
	
	float dist[numVertices];
	
	for(v = 0; v < numVertices; v++)
	{
		dist[v] = INT_MAX;
		vertexeap->array[v] = newVertexHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}
	
	array[src].distance = 0;
	int grey = 2;
	
	minHeap->array[src] = newMinHeapNode(src, dist[src], grey);
	minHeap->pos[src] = src;
	dist[src] = 0f;
	decreaseKey(minHeap, src, dist[src]);
	
	vertexHeap->array[src] = newVertexHeapNode(src, dist[src], grey);
	vertexHeap->pos[src] = src;
	dist[src] = 0f;
	decreaseVertexKey(vertexHeap, src, dist[src]);

	// Initially size of min heap is equal to 1
	minHeap->size = 1;

	while (!isEmpty(minHeap))
	{
		struct VertexHeapNode *minimum = extractMinVertex(vertexHeap);
		
		if(flag == 1)
		{
			cout << "Delete vertex " << minimum->v << ", key=" << setw(16) << setprecision(4) << minimum->dist << "\n";
		}
		
		int black = 3;
		minimum->color = black;
		
		int u = minimum->v;
		
		struct Vertex *node = graph[u];
		
		while (node != NULL)
		{
			int v = node->adjList.vertex_v;
			
			if(v == dest)
			{
				insertMinKey(minHeap, numVertices, v, dist[v])
				goto END;
			}
			
			int white = 1;
			
			if(node->adjList.color == white)
			{
				node->adjList.color = grey;
				dist[v] = dist[u] + node->adjList.weight;
				insertMinKey(minHeap, numVertices, v, dist[v]);
				
				
				if(flag == 1)
				{
					cout << "Insert Vertex " << v << ", key=" << setw(16) << setprecision(4) << dist[v] << "\n";	
				}
			}

			if (isInVertexHeap(vertexHeap, v) && dist[u] != INT_MAX && node->adjList.weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + node->adjList.weight;

				// update distance
				// value in min heap also
				
				decreaseVertexKey(vertexHeap, v, dist[v]);
				int index = vertexHeap->pos[v];
				float distDetermined = vertexHeap->array[i]->dist;
				
				if(flag == 1)
				{						
					cout << "Decrease key of vertex " << v << ", from " << setw(16) << setprecision(4) << dist[v] << " to "
					<< setw(16) << setprecision(4) << distDetermined << "\n";
				}
			}
			node = node->next;
		}
		
	}
	END:
}

void shortestSingleSource(struct Vertex **graph, int src, int numVertices, int flag)
{
	struct VertexHeap *vertexHeap = createVertexHeap(numVertices);  
	struct MinHeap *minHeap = createMinHeap(numVertices);
	
	float dist[numVertices];
	
	for(v = 0; v < numVertices; v++)
	{
		dist[v] = INT_MAX;
		vertexeap->array[v] = newVertexHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}
	
	array[src].distance = 0f;
	
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0f;
	decreaseKey(minHeap, src, dist[src]);
	
	vertexHeap->array[src] = newVertexHeapNode(src, dist[src]);
	vertexHeap->pos[src] = src;
	dist[src] = 0f;
	decreaseVertexKey(vertexHeap, src, dist[src]);

	// Initially size of min heap is equal to 1
	minHeap->size = 1;

	while (!isEmpty(minHeap))
	{
		struct VertexHeapNode *minimum = extractMinVertex(vertexHeap);
		
		int u = minimum->v;
		
		struct Vertex *node = graph[u];
		
		while (node != NULL)
		{
			int v = node->adjList.vertex_v;

			if (isInVertexHeap(vertexHeap, v) && dist[u] != INT_MAX && node->adjList.weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + node->adjList.weight;

				// update distance
				// value in min heap also
				decreaseVertexKey(vertexHeap, v, dist[v]);
				insertMinKey(minHeap, numVertices, v, dist[v])
			}
			node = node->next;
		}
		
	}
}

void insertDirected(struct Vertex **graph, int u, float weight)
{
	struct Vertex *prev = NULL;
	struct Vertex *entry = graph[u];
    while (entry != NULL)
    {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL)
    {
        entry = new Vertex;
        entry.vertex_u = u;
        entry->adjList.weight = weight;
        entry->next = NULL;
        if (prev == NULL)
		{
            graph[u] = entry;
        }
	    else
	    {
            prev->next = entry;
        }
	}
    else
    {
        entry.vertex_u = u;
        entry->adjList.weight = weight;
	}	
}

void insertUndirected(struct Vertex **graph, int u, int v, float weight)
{
	struct Vertex *prev = NULL;
	struct Vertex *entry = graph[u];
    while (entry != NULL)
    {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL)
    {
        entry = new Vertex;
        entry.vertex_u = u;
        entry->adjList.vertex_v = v;
        entry->adjList.weight = weight;
        entry->next = NULL;
        if (prev == NULL)
		{
            graph[u] = entry;
        }
	    else
	    {
            prev->next = entry;
        }
	}
    else
    {
        entry.vertex_u = u;
        entry->adjList.vertex_v = v;
        entry->adjList.weight = weight;
	}
}
