#include <iostream>
#include "graph.h"

int main()
{
	/* Let us create following weighted graph
	         10
	    0--------1
	    |  \     |
	   6|   5\   |15
	    |      \ |
	    2--------3
	        4       */


	int option;
	bool flag=true;
	int V=4, E=5;

	Graph* graph= new Graph(V,E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	graph->addEdge(0,1);
	graph->addEdge(0,2);
	graph->addEdge(0,3);
	graph->addEdge(1,3);
	graph->addEdge(2,3);

	while(1 && flag)
	{
		cout<<"Graph Programming Questions: \n";
		cout<<"1. Breadth First Traversal.\n";
		cout<<"2. Depth First Traversal. \n";
		cout<<"3. Check if the graph has a cycle. \n";
		cout<<"4. Exit the program.\n";
		cout<<"Enter your choice: ";
		cin>>option;
		
		switch(option)
		{
			case 1: cout<<"\nThe breadth first traversal of graph beginning from vertex 0 is as follows: \n";
					graph->BFS(0);
					cout<<endl<<endl;
					break;

			case 2: cout<<"\nThe depth first traversal of graph is as follows: \n";
					graph->DFS();
					cout<<endl<<endl;
					break;

			case 3: if(graph->isCycle())
						cout<<"\nThe graph has a cycle.\n\n";
					else
						cout<<"\nThe graph doesn't have a cycle.\n\n";
					break;

			case 4: delete graph;
					cout<<"\nExiting the program.\n\n";
					flag=false;
					break;

			default: cout<<"Wrong input! Exiting!\n";
		}
	}

	return 0;
}