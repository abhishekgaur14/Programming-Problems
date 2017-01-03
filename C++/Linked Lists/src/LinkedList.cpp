#include <iostream>
#include "LinkedList.h"

using namespace std;

void LinkedList :: insert(int data, int pos)
{
	Node* newNode;
	newNode = new Node;
	newNode ->data = data; 
	newNode ->next = NULL;
	
	if(pos == 1){
		if(head==NULL)
		{
			head = newNode;
		}
		else{
			newNode ->next = head;
			head = newNode;
		}
	}

	else if(pos == -1)
	{
		if(head==NULL)
		{
			head = newNode;
		}
		else{
			Node* temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}

	else{
		Node* temp = head;
		
		for(int i=0;i<pos-2;i++)
		{
			temp = temp->next;
		}
		
		newNode->next = temp->next;
		temp->next = newNode;
	}
}


void LinkedList :: display()
{
	Node* temp = head;
	
	cout<<"The contents of the Linked List are:\n";
	while(temp != NULL)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL\n\n";
}


void LinkedList::deleteByPosition(int pos)
{
	Node* temp = head;

	if(pos==1)
	{
		head = temp->next;
		free(temp);
	}
	else{
		for(int i=0; i<pos-2; i++)
			temp = temp->next;

		Node *temp2 = temp->next;
		temp->next = temp2->next;
		free(temp2);
	}
}


void LinkedList::deleteByData(int data)
{
	Node *temp=head;

	if(temp->data == data)
	{
		head=temp->next;
		cout<<"\nElement deleted from the list.\n\n";
		free(temp);
	}

	else{
		Node *nextNode = temp->next;
		while(nextNode!= NULL)
		{
			if(nextNode->data == data)
			{
				temp->next=nextNode->next;
				free(nextNode);
				cout<<"\nElement deleted from the list.\n\n";
				return;
			}
			temp = nextNode;
			nextNode = nextNode->next;
		}
		cout<<"\nElement does not exist in the list.\n\n";
	}
}


void LinkedList::printReverse(Node* node)
{
	if(node == NULL)
	{	
		cout<<"NULL";
		return;
	}
	printReverse(node->next);
	cout<<" -> "<<node->data;
}


Node* LinkedList::getHead()
{
	return head;
}


bool LinkedList::isEmpty()
{
	if(head==NULL)
		return true;
	return false;
}


int LinkedList::getLength()
{
	if(isEmpty())
		return 0;
	Node* temp = head;
	int length = 0;
	while(temp!=NULL)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

/*utility funtion for recursive reversal*/
void LinkedList::reverseUtil(Node** head_ref)
{
	Node* first;
	Node* rest;
	  
	if (*head_ref == NULL)
	   return;   

	first = *head_ref;  
	rest  = first->next;

	/* List has only one node */
	if (rest == NULL)
	   return;   

	reverseUtil(&rest);
	first->next->next  = first;  
	first->next  = NULL;          

	*head_ref = rest;
}


void LinkedList::reverse(int flag)		//flag = 0: iterative reversal, 1: recursive reversal
{
	if(flag==0)
	{	
		cout<<"\nThe Linked List has been reversed iteratively.\n\n";
		Node *prev, *current, *nextNode;
		prev = NULL;
		current = head;

		while(current!=NULL)
		{
			nextNode = current->next;
			current->next = prev;
			prev = current;
			current = nextNode;
		}
		head = prev;
	}

	if(flag==1){
		cout<<"\nThe Linked List has been reversed recursively.\n\n";
		reverseUtil(&head);	
	}
}