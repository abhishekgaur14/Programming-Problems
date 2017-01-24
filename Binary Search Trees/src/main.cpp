#include "tree.h"

int main()
{
	Tree *tobj= new Tree;
	int option, num, suboption;
	bool flag=true;

	
	while(flag)
	{
		cout<<"\nBinary Search Tree Programming\n";
		cout<<"\nWhat would you like to do?";
		cout<<"\n1. Enter a new element to the tree.";
		cout<<"\n2. Traverse the tree.";
		cout<<"\n3. Search for an element in the tree.";
		cout<<"\n4. Find the minimum element in the tree.";
		cout<<"\n5. Find the maximum element in the tree.";
		cout<<"\n6. Find the height of the tree.";
		cout<<"\n7. Check if a Binary Tree is a Binary Search Tree.";
		cout<<"\n8. Delete data from tree.";
		cout<<"\n9. Exit the program.";

		cout<<"\nEnter your choice: ";
		cin>>option;
		
		switch(option)
		{
			case 1: cout<<"\nEnter the element you want to insert in the tree: ";
				cin>>num;
				tobj->insert(num);
				cout<<"\nElement "<<num<<" has been inserted into the tree.\n";
				break;
			
			case 2: cout<<"\nHow would you like to traverse the tree?";
				cout<<"\n\t1. Breadth-First Traversal.";
				cout<<"\n\t2. Depth-First Traversal.";
				cout<<"\nEnter your choice: ";
				cin>>suboption;
				
				if(suboption == 1)
					tobj->BFS();
				
				else if(suboption==2)
					tobj->DFS();
				
				else
					cout<<"\nThe option entered is invalid.\n";
				
				cout<<endl;
				break;

			case 3: if(tobj->isEmpty())
					cout<<"\nThe tree is empty right now.\n"; 
				
				else
				{
					cout<<"\nEnter the element you want to search for: ";
					cin>>num;
					
					if(tobj->search(num))
						cout<<"\nThe element "<<num<<" exists in the tree.\n";
					else
						cout<<"\nThe element "<<num<<" does not exist in the tree.\n";
				}
				break;

			case 4: if(!tobj->isEmpty())
				{
					cout<<"\nThe minimum element in the tree is "<<tobj->findMin()<<".\n";
				}

				else
					cout<<"\nThe tree is empty right now.\n";

				break;

			case 5: if(!tobj->isEmpty())
				{
					cout<<"\nThe maximum element in the tree is "<<tobj->findMax()<<".\n";
				}

				else
					cout<<"\nThe tree is empty right now.\n";

				break;

			case 6: if(!tobj->isEmpty())
					cout<<"\nThe height of the tree is "<<tobj->findHeight()<<".\n";

				else
					cout<<"\nThe tree is empty right now. So the height is 0.\n";

				break;

			case 7:	if(!tobj->isEmpty())
				{ 
					if(tobj->isBST())
						cout<<"\nThe tree is a Binary Search Tree.\n";
					else
						cout<<"\nThe tree is a not a Binary Search Tree.\n";
				}

				else
					cout<<"\nThe tree is empty right now. You may call it a BST.\n";
				
				break;

			case 8: if(tobj->isEmpty())
					cout<<"\nThe tree is empty right now.\n";
				
				else
				{ 
					cout<<"\nEnter the element you want to delete: ";
					cin>>num;
					tobj->deleteNode(num);
					cout<<"\nElement "<<num<<" has been deleted from the tree.\n";
				}

				break;

			case 9: delete tobj;
				flag = false;
				break;

			default: cout<<"\nWrong input.\n";
		}	
	}

	return 0;
}