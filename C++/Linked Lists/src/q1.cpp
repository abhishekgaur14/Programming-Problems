#include <iostream>
#include <unordered_map>
#include "ctci.h"

using namespace std;

/*-------------Q1. Program to remove the duplicates from the Linked List----------------*/

//Duplicate Removal using extra buffer 
//Uncomment this and comment the next function (removeDuplicates) to use this fucntion
//Time Complexity : O(N)
//Space Complexty : O(N)

/*void removeDuplicates(Node* head)
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
*/

//Duplicate Removal without using extra buffer 
//Uncomment this and comment the previous function (removeDuplicates) to use this fucntion
//Time Complexity : O(N^2)
//Space Complexty : O(1)
void removeDuplicates(Node* head)
{
	if(head==NULL){
		cout<<"\nThe Linked List is empty.\n\n";
		return;
	}

	Node* current = head;
	Node* runner;
	int flag = 0;

	while(current)
	{
		runner = current;
		while(runner->next)
		{
			if(current->data == runner->next->data)
			{
				flag = 1;
				Node* temp = runner->next;
				runner->next = runner->next->next;
				cout<<"A duplicate of "<<temp->data<<" has been found and removed.\n";
				delete temp;
			}

			else
			{
				runner = runner->next;
			}
		}
		current = current->next;
	}
	cout<<endl;
	if(flag==0)
	{
		cout<<"No duplicates were found in the list\n\n";
	}
}

/*---------------------------------------End of Q1------------------------------------------------*/