#ifndef GRAPH_H
#define GRAPH_H
#include <list>

using namespace std;

class Graph
{
	private:
		int V;						//number of vertices in the graph
		list<int> *adj;				//adjacency list for holding adjacent vertices of a vertex

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void BFS(int s);
};

#endif	