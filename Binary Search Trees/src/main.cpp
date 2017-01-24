#include "tree.h"

int main()
{
	Tree *tobj= new Tree;
	int option, num;
	bool flag=true;

	
	while(flag)
	{
		cout<<"\nBinary Search Tree Programming\n";
		cout<<"\nWhat would you like to do?";
		cout<<"\n1. Enter a new element to the tree.";
		cout<<"\n2. Display the tree.";
		cout<<"\n3. Search for an element in the tree.";
		cout<<"\n4. Exit the program.";
		cout<<"\nEnter your choice: ";
		cin>>option;
		
		switch(option)
		{
			case 1: cout<<"\nEnter the element you want to insert in the tree: ";
				cin>>num;
				tobj->insert(num);
				cout<<"\nElement "<<num<<" has been inserted into the tree.\n";
				break;
			
			case 2: cout<<"\nThe elements of the tree are:\n";
				tobj->print();
				cout<<endl;
				break;

			case 3: cout<<"\nEnter the element you want to search for: ";
				cin>>num;
				
				if(tobj->search(num))
					cout<<"\nThe element "<<num<<" exists in the tree.\n";
				else
					cout<<"\nThe element "<<num<<" does not exist in the tree.\n";
				break;

			case 4: delete tobj;
				flag = false;
				break;

			default: cout<<"\nWrong input.\n";
		}	
	}

	return 0;
}