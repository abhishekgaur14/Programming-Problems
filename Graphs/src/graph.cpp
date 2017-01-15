#include "graph.h"
#include <iostream>

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

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