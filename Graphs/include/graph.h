#ifndef GRAPH_H
#define GRAPH_H
#include <list>

using namespace std;

// a structure to represent a weighted edge in graph
struct Edge
{
	int src, dest, weight;
};

// A structure to represent a subset for union-find
struct subset
{
	int parent;
	int rank;
};

class Graph
{
	private:
		int V,E;					//V - Number of vertices in the graph
		list<int> *adj;				//Adjacency list to hold the adjacent nodes of a vertex

	public:
		Edge *edge;
		Graph(int V, int E);
		~Graph();
		void addEdge(int v, int w);
		
		// A function for Breadth-First Traversal of the graph
		void BFS(int s);

		// Functions for Depth-First Traversal of the graph
		void DFS();
		void DFSUtil(int v, bool visited[]);

		// A utility function to find set of an element i
		// (uses path compression technique)
		int find(subset subsets[], int i);

		// A function that does union of two sets of x and y
		// (uses union by rank)
		void Union(subset subsets[], int x, int y);

		// A function to check whether the graph has a cycle or not
		int isCycle();
};

#endif	