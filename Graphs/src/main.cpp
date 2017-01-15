#include <iostream>
#include "graph.h"

int main()
{
	int option;
	bool flag=true;

	//Making an arbitrary graph consisting of 4 vertices 0,1,2,3
	Graph g(4);

	//defining the edges of the vertices of the graphs
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	while(1 && flag)
	{
		cout<<"Graph Programming Questions: \n";
		cout<<"1. Breadth First Traversal.\n";
		cout<<"2. Depth First Traversal. \n";
		cout<<"3. Exit the program.\n";
		cout<<"Enter your choice: ";
		cin>>option;
		
		switch(option)
		{
			case 1: cout<<"\nThe breadth first traversal of graph beginning from vertex 2 is as follows: \n";
					g.BFS(2);
					cout<<endl<<endl;
					break;

			case 2: cout<<"\nThe depth first traversal of graph beginning from vertex 2 is as follows: \n";
					g.DFS(2);
					cout<<endl<<endl;
					break;

			case 3: cout<<"\nExiting the program.\n\n";
					flag=false;
					break;

			default: cout<<"Wrong input! Exiting!\n";
		}
	}
	return 0;
}