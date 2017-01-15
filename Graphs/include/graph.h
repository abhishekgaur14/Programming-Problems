#ifndef GRAPH_H
#define GRAPH_H
#include <list>

using namespace std;

class Graph
{
	private:
		int V;					//V - Number of vertices in the graph
		list<int> *adj;				//Adjacency list to hold the adjacent nodes of a vertex

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void BFS(int s);
		void DFS(int v);
		void DFSUtil(int v, bool visited[]);
};

#endif	