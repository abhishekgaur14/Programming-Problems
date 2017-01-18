#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Item;
	head->next = NULL;
	length = 0;
}	

LinkedList::~LinkedList()
{
	Item* current = head;

	while (current)
	{ 
	    Item* next = current->next;
	    delete current;
	    current = next;
	}

	head = NULL;

	//cout << "List successfully deleted from memory.\n" << endl;
}

void LinkedList :: insertItem(string itemKey)
{
	Item* newItem;
	newItem = new Item;
	newItem->key = itemKey;
	newItem ->next = NULL;
	
	if(head==NULL)
	{
		head = newItem;
	}

	else{
		Item* temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newItem;
	}
	length++;
}


void LinkedList :: display()
{
	if(head == NULL)
	{
		cout<<"\n{ }\n";
		return;
	}

	Item* temp = head;
	
	
	while(temp != NULL)
	{
		cout<<temp->key<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL\n";
}


bool LinkedList::removeItem(string itemKey)
{
	if(head == NULL)
	{
		cout<<"\nThe hash table is empty.\n\n";
		return false;
	}

	Item *temp=head;

	if(temp->key == itemKey)
	{
		head=temp->next;
		cout<<"\nElement '"<<itemKey<<"' deleted from the hash table.\n\n";
		free(temp);
		length--;
		return true;
	}

	else{
		Item *nextNode = temp->next;
		while(nextNode!= NULL)
		{
			if(nextNode->key == itemKey)
			{
				temp->next=nextNode->next;
				free(nextNode);
				cout<<"\nElement '"<<itemKey<<"' deleted from the hash table.\n\n";
				length--;
				return true;
			}
			temp = nextNode;
			nextNode = nextNode->next;
		}
		cout<<"\nElement '"<<itemKey<<"' does not exist in the hash table.\n\n";
		return false;
	}
}


Item* LinkedList::getItem(string itemKey)
{
	if(head == NULL)
	{
		cout<<"\nThe hash table is empty.\n\n";
		return NULL;
	}

	Item* itemNode = head;

	while(itemNode)
	{
		if(itemNode->key == itemKey)
			return itemNode;
		itemNode = itemNode->next;
	}

	return NULL;
}


int LinkedList::getLength()
{
	return length;
}