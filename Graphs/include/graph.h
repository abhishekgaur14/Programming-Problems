#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

// a structure to represent a weighted edge in graph
typedef struct  
{
	int src;
	int dest;
	int weight;
}Edge;

// A structure to represent a subset for union-find
typedef struct 
{
	int parent;
	int rank;
}Subset;


class Graph
{
		int V;					//V - Number of vertices in the graph
		vector<Edge> edge;
		Subset *subset;
		
		int find(int i);
		void Union(int x, int y);

	public:
		
		Graph(int V);
		~Graph();
		void addEdge(int v, int w, int wt);
		void BFS();
		void DFS();
		void DFSUtil(int v, bool visited[], list<int> *adj);
		void kruskalMST();
};

#endif	