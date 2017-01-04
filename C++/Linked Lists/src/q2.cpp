// Q2. Program to find the nth node to the last node of the Linked List.

#include <iostream>
#include "ctci.h"

using namespace std;


//Recursive solution
//Time Complexity: O(n)
Node* nthToLast_r(Node* head, int k, int& i)
{
	if(head==NULL)
		return NULL;

	Node* nthToLastNode = nthToLast_r(head->next, k, i);
	i += 1;
	if(i==k)
	{
		return head;
	}

	return NULL;
}


//Iterative Solution
//Time Complexity: O(n)
Node* nthToLast_i(Node* head, int k)
{
	if(head==NULL)
		return NULL;

	if(k<=0)
		return NULL;

	Node* p1 = head;
	Node* p2 = head;

	for(int i=0;i<k-1;i++)
	{
		if(p2==NULL)
			return NULL;
		p2 = p2->next;
	}

	if(p2==NULL)
		return NULL;

	while(p2->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}

	return p1;
}


//Alternate Solution
Node* nthToLast_alt(Node* head, int k)
{
	if (head==NULL)
		return NULL;

	int length = 0;
	Node* temp = head;
	while(temp)
	{
		length++;
		temp=temp->next;
	}

	temp = head;

	if(k<1 || k>length)
		return NULL;

	int count = 0;
	while(length - count != k)
	{
		count++;
		temp=temp->next;
	}

	return temp;
}