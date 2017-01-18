#include "graph.h"

int main()
{
	int option;
	bool flag=true;
	int V=9;
    Graph *g = new Graph(V);
 
    g->addEdge(0, 1, 4);
    g->addEdge(0, 7, 8);
    g->addEdge(1, 2, 8);
    g->addEdge(1, 7, 11);
    g->addEdge(2, 3, 7);
    g->addEdge(2, 8, 2);
    g->addEdge(2, 5, 4);
    g->addEdge(3, 4, 9);
    g->addEdge(3, 5, 14);
    g->addEdge(4, 5, 10);
    g->addEdge(5, 6, 2);
    g->addEdge(6, 7, 1);
    g->addEdge(6, 8, 6);
    g->addEdge(7, 8, 7);
 
	while(1 && flag)
	{
		cout<<"Graph Programming Questions: \n";
		cout<<"1. Breadth First Traversal.\n";
		cout<<"2. Depth First Traversal. \n";
		cout<<"3. Use Kruskal's Algorithm to find the Minimal Spanning Tree\n";
		cout<<"4. Exit the program.\n";
		cout<<"Enter your choice: ";
		cin>>option;
		
		switch(option)
		{
			case 1: cout<<"\nThe breadth first traversal of graph beginning from vertex 0 is as follows: \n";
				g->BFS();
				cout<<endl<<endl;
				break;

			case 2: cout<<"\nThe depth first traversal of graph is as follows: \n";
				g->DFS();
				cout<<endl<<endl;
				break;

			case 3: g->kruskalMST();
				cout<<endl;
				break;

			case 4: delete g;
				cout<<"\nExiting the program.\n\n";
				flag=false;
				break;

			default: cout<<"Wrong input! Exiting!\n";
		}
	}

	return 0;
}