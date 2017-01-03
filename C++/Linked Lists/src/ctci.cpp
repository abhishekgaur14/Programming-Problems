#include <iostream>
#include <unordered_map>
#include "ctci.h"

using namespace std;

void removeDuplicates(Node* head)
{
	if(head==NULL){
		cout<<"\nThe Linked List is empty.\n\n";
		return;
	}

	unordered_map<int, bool> map;
	int flag = 0;
	Node* current = head;

	map[current->data] = 1;

	while(current->next)
	{
		if(map[current->next->data]==0)
		{
			map[current->next->data] = 1;
			current = current->next;
		}

		else
		{
			flag = 1;
			Node* temp = current->next;
			current->next = current->next->next;
			cout<<"A duplicate of "<<temp->data<<" has been found and removed.\n";
			delete temp;
		}
	}
	cout<<endl;
	if(flag==0)
	{
		cout<<"No duplicates were found in the list\n\n";
	}
}