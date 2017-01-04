//Q4. Partition the Linked List around a value x, such that 
//all nodes less than x come before all node greater than or equal to x.

#include <iostream>
#include "ctci.h"

using namespace std;

Node* partition(Node* head, int x)
{
	if(head == NULL)
		return NULL;

	LinkedList* smaller = new LinkedList();
	LinkedList* greater = new LinkedList();
	Node* current = head;

	while(current)
	{
		if(current->data < x)
			smaller->insert(current->data,-1);

		else
			greater->insert(current->data,-1);

		current = current->next;
	}

	current = smaller->head;
	Node* lowNode = smaller->head;

	while(lowNode->next)
		lowNode=lowNode->next;

	lowNode->next = greater->head;
	
	return current;
}