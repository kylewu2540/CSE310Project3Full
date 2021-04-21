#include "utility.h"
#include "shortestpathcomputation.h"
#include "minHeapShort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

void readFile(string fileName, struct Vertex **graph, string direction)
{
	string inputLine;	
	ifstream rFile;
	rFile.open(fileName);
	int i;
	
	string vertices, edges;
	int numVertices, numEdges;
	
	getline(rFile, inputLine);

	if(rFile.is_open())
	{
		rFile << vertices << edges;
	}
	
	numVertices = atoi(vertices.c_str());
	numEdges = atoi(edges.c_str());
	
	struct Vertex **graphArr = new Vertex*[numEdges];
	
	int i;
	for(i = 0; i < numEdges; i++)
	{
		graphArr[i] = NULL;
	}
	
	string vertex_v, vertex_u, edge, weight;
	
	if(direction.compare("directed") == 0)
	{
		if(rFile.is_open())
		{
			for(i = 0; i< numEdges; i++)
			{
				rFile >> edge >> vertex_u >> vertex_v >> weight;
				int u = atoi(vertex_u.c_str());
				int v = atoi(vertex_v.c_str());
				float weight = stof(weight);
				insertDirected(graphArr, u, weight);
			}
		}
	}
	if(direction.compare("undirected") == 0)
	{
		if(rFile.is_open())
		{
			for(i = 0; i< numEdges; i++)
			{
				rFile >> edge >> vertex_u >> vertex_v >> weight;
				int u = atoi(vertex_u.c_str());
				int v = atoi(vertex_v.c_str());
				float weight = stof(weight);
				insertDirected(graphArr, u, weight);
			}
		}
	}
}

void executeQueries()
{
	string writePathQuery = "write path";
	string findQuery = "find";
	string stopQuery = "stop";
	string line;
	int n = 2000;
	string queries[n];
	int indexArr = 0;
	
	while(getline(cin, line))
	{
		int source, dest;
		if(line.find(findQuery) != string::npos)
		{
			cout << "Query: " << line << endl;
			queries[indexArr] = line;
			indexArr++;
				
			size_t position = 0;
			string delim = " ";
			string token;
			int index = 0;
			
			while((position = line.find(delim)) != string::npos)
			{
				token = line.substr(0, position);
				line.erase(0, position + delim.length());
			}	
		}
		if(line.find(writePathQuery) != string::npos)
		{
			cout << "Query: " << line << endl;
			int indexArr = 0, s, d;
			queries[indexArr] = line;
			indexArr++;
			
			int k;
			for(k = 0; k < indexArr; k++)
			{
				if(queries[k].find(findQuery) != string::npos )
				{
					cout << "Error: no path computation done\n";
				}
			}
			
			
			
		}
		if(line.find(stopQuery) != string::npos)
		{
			break;
		}
	}
	
	deleteEverything(minHea)
}

void findSrcDest(struct MinHeap *minHeap, struct Vertex **graph, int src, int dest, int flag, int numVertices)
{
	int i;
	bool operation = false;
	
	for(i = 0; i < numVertices; i++)
	{
		if(graph[i].vertex_u == src)
		{
			operation = true;
		}
	}
	
	if(dest == src && (flag !=0 || flag != 1) )
	{
		operation = false;
	}
	
	if(operation == false)
	{
		cout << "Error: invalid find query\n";
		return;
	}

	shortestSinglePair(graph, src, dest, numVertices, flag);
	
}

void writePath(struct MinHeap *minHeap, struct Vertex **graph, int s, int d, int numVertices)
{
	
}

void deleteEverything(struct MinHeap *minHeap, struct Vertex **graph, struct VertexHeap *vertexHeap, int numEdges)
{
	delete[] minHeap->pos;
	delete[] minHeap->array;
	
	delete[] vertexHeap->pos;
	delete[] vertexHeap->array;
	
	delete minHeap;
	delete vertexHeap;
	
	for (int i = 0; i < numEdges; ++i)
	{
        struct Vertex *entry = graph[i];
        while (entry != NULL)
	    {
            struct Vertex* prev = entry;
            entry = entry->next;
            delete prev;
        }
	}
	
	delete[] graph;
}
