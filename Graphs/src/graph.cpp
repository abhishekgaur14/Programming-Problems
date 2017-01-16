#include "graph.h"
#include <iostream>

//Constructor
Graph::Graph(int V, int E)
{
	this->V = V;
	this->E = E;
	this->edge = new Edge[E];
	adj = new list<int>[V];
}

Graph::~Graph()
{
	cout<<"\nDeleting the graph from the memory.\n";
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


// A utility function to find set of an element i
// (uses path compression technique)
int Graph::find(subset subsets[], int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}


// A function that does union of two sets of x and y
// (uses union by rank)
void Graph::Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent=yroot;

	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent=xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


//Breadth First Traversal
//Time Complexity: O(V+E), where V = number of vertices and E = number of edges
void Graph::BFS(int s)
{
	bool *visited = new bool[V];

	//Mark all nodes as not visited
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	//queue for BFS
	list<int> queue;

	//Mark current node as visited and enqueue it
	visited[s]=true;
	queue.push_back(s);

	//list iterator
	list<int>::iterator i;


	while(!queue.empty())
	{
		//dequeue and print the value
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(i=adj[s].begin(); i!=adj[s].end(); ++i)
		{
			//if the vertex is not visited, mark it as visited and push it onto queue
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
}


//Depth First Traversal
//Time Complexity: O(V+E), where V = number of vertices and E = number of edges
void Graph::DFS()
{
	bool *visited = new bool[V];
	
	//Mark all nodes as not visited	
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	//call the DFS Utility funtion for all unvisited vertices
	//we do this because all vertices may not be reachable from a given vertex (Undirected Graph)
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
			DFSUtil(i, visited);
	}
}

void Graph::DFSUtil(int v, bool visited[])
{
	//mark current vertex as visited and display it
	visited[v]=true;
	cout<<v<<" ";

	//list iterator
	list<int>::iterator i;

	for(i=adj[v].begin(); i!=adj[v].end(); ++i)
	{
		//if the adjacent vertex/vertices of current vertex is/are not visited, 
		//recursively call the DFSUtil function for all adjacent vertices.
		if(!visited[*i])
			DFSUtil(*i, visited);
	}
}


// A function to check whether the graph has a cycle or not
int Graph::isCycle()
{
	int V = this->V;
	int E = this->E;

	subset *subsets = new subset[V];

	for(int v=0; v<V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	for(int e=0; e<E; e++)
	{
		int x = find(subsets, edge[e].src);
		int y = find(subsets, edge[e].dest);

		if(x==y)
			return 1;

		Union(subsets,x,y);
	}

	return 0;
}