// Q3. Remove a node in the middle of Linked List, given only access to that node.

#include <iostream>
#include "ctci.h"

using namespace std;

bool removeFromMiddle(Node* node)
{
	if(node == NULL || node->next == NULL)	//this algorithm doesn't work for last element of the Linked List
		return false;						

	Node* temp = node->next;
	node->data = temp->data;
	node->next = temp->next;

	delete temp;
	return true;
}